#include "Config.cpp"

int main(){
    map<string,tuple<int,string,string,int,int>>& plant = Config::getPlantMap();
    map<string,tuple<int,string,string,int,int>>& animal = Config::getAnimalMap();
    map<string,tuple<int,string,string,string,int,int>>& product = Config::getProductMap();
    map<string,tuple<int,string,int,map<string,int>>>& recipe = Config::getRecipeMap();

    Config::bacaConfig();
    for(auto i = plant.cbegin(); i != plant.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
    }
    cout << endl;
    for(auto i = animal.cbegin(); i != animal.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
    }
    cout << endl;
    for(auto i = product.cbegin(); i != product.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << " " << get<5>(i->second) << endl;
    }
    cout << endl;
    for(auto i = recipe.cbegin(); i != recipe.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " ";
        for(auto j = (get<3>(i->second)).cbegin(); j != (get<3>(i->second)).cend(); j++){
            cout << j->first << " " << j->second << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << Config::getJumlahUangWin() << endl;
    cout << Config::getBeratBadanWin() << endl;
    cout << Config::getBesarPenyimpanan().first << " " << Config::getBesarPenyimpanan().second << endl;
    cout << Config::getBesarLahan().first << " " << Config::getBesarLahan().second << endl;
    cout << Config::getBesarPeternakan().first << " " << Config::getBesarPeternakan().second << endl;
    
}