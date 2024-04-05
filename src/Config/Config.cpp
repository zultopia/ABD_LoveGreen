#include "Config.hpp"

map<string,tuple<int,string,string,int, int>> plant;
map<string,tuple<int,string,string,int,int>> animal;
map<string,tuple<int,string,string,string,int,int>> product;
map<string,tuple<int,string,int,map<string,int>>> recipe;
int jumlahUangWin;
int beratBadanWin;
pair<int,int> besarPenyimpanan;
pair<int,int> besarLahan;
pair<int,int> besarPeternakan;

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
        plant.insert({kode, make_tuple(stoi(id),name, type, stoi(duration), stoi(price))});
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
        animal.insert({kode, make_tuple(stoi(id),name, type, stoi(weight), stoi(price))});
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
        product.insert({kode, make_tuple(stoi(id),name, type, origin,stoi(weight), stoi(price))});
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
        for(int i = 4; i < counter-1; i++){
            tempMap.insert({temp[i],stoi(temp[i+1])});
        }
        recipe.insert({temp[1], make_tuple(stoi(temp[0]),temp[2],stoi(temp[3]),tempMap)});
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
    while(getline(inputFile, line)){
        stringstream s(line);
        string word;
        vector<int> temp;
        while(s, word, ' '){
            temp.push_back(stoi(word));
        }
        jumlahUangWin = temp[0];
        beratBadanWin = temp[1];
        besarPenyimpanan = make_pair(temp[2], temp[3]);
        besarLahan = make_pair(temp[4],temp[5]);
        besarPeternakan = make_pair(temp[6], temp[7]);

    }
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