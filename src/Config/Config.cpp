#include "Config.hpp"

map<string,tuple<int,string,string,int, int>> Config::plant;
map<string,tuple<int,string,string,int,int>> Config::animal;
map<string,tuple<int,string,string,string,int,int>> Config::product;
map<string,tuple<int,string,int,map<string,int>>> Config::recipe;
int Config::jumlahUangWin;
int Config::beratBadanWin;
pair<int,int> Config::besarPenyimpanan;
pair<int,int> Config::besarLahan;
pair<int,int> Config::besarPeternakan;

Config::Config(){

}
int Config::bacaPlant(){
    ifstream inputFile("../../config/plant.txt");
    if(!inputFile.is_open()){
        return -1;
    }

    string line;
    while(getline(inputFile, line)){
        stringstream s(line);
        string id,kode,name,type,duration,price;
        s >> id >> kode >> name >> type >> duration >> price;
        Config::plant.insert({name, make_tuple(stoi(id),kode, type, stoi(duration), stoi(price))});
    }
    inputFile.close();        
    return 1;
}
int Config::bacaAnimal(){
    ifstream inputFile("../../config/animal.txt");
    if(!inputFile.is_open()){
        return -1;
    }

    string line;
    while(getline(inputFile, line)){
        stringstream s(line);
        string id,kode,name,type,weight,price;
        s >> id >> kode >> name >> type >> weight >> price;
        animal.insert({name, make_tuple(stoi(id),kode, type, stoi(weight), stoi(price))});
    }
    inputFile.close(); 
    return 1;
}
int Config::bacaProduct(){
    ifstream inputFile("../../config/product.txt");
    if(!inputFile.is_open()){
        return -1;
    }

    string line;
    while(getline(inputFile, line)){
        stringstream s(line);
        string id,kode,name,type,origin,weight,price;
        s >> id >> kode >> name >> type >> origin >> weight >> price;
        product.insert({name, make_tuple(stoi(id),kode, type, origin,stoi(weight), stoi(price))});
    }
    inputFile.close(); 
    return 1;
}
int Config::bacaRecipe(){
    ifstream inputFile("../../config/recipe.txt");
    if(!inputFile.is_open()){
        return -1;
    }

    string line;
    while(getline(inputFile, line)){
        stringstream s(line);
        string word;
        vector<string> temp;
        int counter = 0;
        while(getline(s, word, ' ')){
            temp.push_back(word);
            counter++;
        }
        map<string,int> tempMap;
        for(int i = 4; i < counter; i+=2){
            tempMap.insert({temp[i],stoi(temp[i+1])});
        }
        recipe.insert({temp[2], make_tuple(stoi(temp[0]),temp[1],stoi(temp[3]),tempMap)});
    }
    inputFile.close(); 
    return 1;
}
int Config::bacaMisc(){
    ifstream inputFile("../../config/misc.txt");
    if(!inputFile.is_open()){
        return -1;
    }

    string line;
    vector<int> temp;
    while(getline(inputFile, line)){
        stringstream s(line);
        string word;
        while(getline(s, word, ' ')){
            temp.push_back(stoi(word));
        }

    }
    jumlahUangWin = temp[0];
    beratBadanWin = temp[1];
    besarPenyimpanan = make_pair(temp[2], temp[3]);
    besarLahan = make_pair(temp[4],temp[5]);
    besarPeternakan = make_pair(temp[6], temp[7]);
    inputFile.close(); 
    return 1;
}

void Config::bacaConfig(){
    if(bacaPlant() == -1){
        
    }
    if(bacaAnimal() == -1){
        
    }
    if(bacaProduct() == -1){
        
    }
    if(bacaRecipe() == -1){
        
    }
    if(bacaMisc() == -1){
        
    }
}

map<string,tuple<int,string,string,int,int>>& Config::getPlantMap(){
    return plant;
}
map<string,tuple<int,string,string,int,int>>& Config::getAnimalMap(){
    return animal;
}
map<string,tuple<int,string,string,string,int,int>>& Config::getProductMap(){
    return product;
}
map<string,tuple<int,string,int,map<string,int>>>& Config::getRecipeMap(){
    return recipe;
}




bool Config::isExistPlant(string key){
    return(plant.find(key) != plant.end());
}
bool Config::isExistAnimal(string key){
    return(animal.find(key) != animal.end());
}
bool Config::isExistProduct(string key){
    return(product.find(key) != product.end());
}
bool Config::isExistRecipe(string key){
    return(recipe.find(key) != recipe.end());
}
int Config::getId(string key){
    if(plant.find(key) != plant.end()){
        return get<0>(plant.at(key));
    }else if(animal.find(key) != animal.end()){
        return get<0>(animal.at(key));
    }else if(product.find(key) != product.end()){
        return get<0>(product.at(key));
    }else if(recipe.find(key) != recipe.end()){
        return get<0>(recipe.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
// string Config::getNama(string key){
//     if(plant.find(key) != plant.end()){
//         return get<1>(plant.at(key));
//     }else if(animal.find(key) != animal.end()){
//         return get<1>(animal.at(key));
//     }else if(product.find(key) != product.end()){
//         return get<1>(product.at(key));
//     }else if(recipe.find(key) != recipe.end()){
//         return get<1>(recipe.at(key));
//     }else{
//         ConfigException e("Tidak ada key tersebut pada Config");
//         throw e;
//     }
// }
string Config::getType(string key){
    if(plant.find(key) != plant.end()){
        return get<2>(plant.at(key));
    }else if(animal.find(key) != animal.end()){
        return get<2>(animal.at(key));
    }else if(product.find(key) != product.end()){
        return get<2>(product.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
int Config::getDuration(string key){
    if(plant.find(key) != plant.end()){
        return get<3>(plant.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
int Config::getPrice(string key){
    if(plant.find(key) != plant.end()){
        return get<4>(plant.at(key));
    }else if(animal.find(key) != animal.end()){
        return get<4>(animal.at(key));
    }else if(product.find(key) != product.end()){
        return get<5>(product.at(key));
    }else if(recipe.find(key) != recipe.end()){
        return get<2>(recipe.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
int Config::getWeightHarvest(string key){
    if(animal.find(key) != animal.end()){
        return get<3>(animal.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
string Config::getOrigin(string key){
    if(product.find(key) != product.end()){
        return get<3>(product.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
int Config::getAddedWeight(string key){
    if(product.find(key) != product.end()){
        return get<4>(product.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
map<string,int>& Config::getMaterialInfo(string key){
    if(recipe.find(key) != recipe.end()){
        return get<3>(recipe.at(key));
    }else{
        ConfigException e("Tidak ada key tersebut pada Config");
        throw e;
    }
}
int Config::getJumlahUangWin(){
    return jumlahUangWin;
}
int Config::getBeratBadanWin(){
    return beratBadanWin;
}
pair<int,int> Config::getBesarPenyimpanan(){
    return besarPenyimpanan;
}
pair<int,int> Config::getBesarLahan(){
    return besarLahan;
}
pair<int,int> Config::getBesarPeternakan(){
    return besarPeternakan;
}