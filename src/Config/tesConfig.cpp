#include "Config.cpp"
#include "Muat.cpp"

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
    cout << endl;
    Muat::muat("../../config/state.txt");
    vector<string> pemain = SimpanMuat::getPemain();
    map<string,tuple<string,int,int>> dataPemain = SimpanMuat::getDataPemain();
    map<string, vector<string>> inventory = SimpanMuat::getInventory();
    map<string,vector<tuple<string,string,int>>> LadangdanTernak = SimpanMuat::getLadangdanTernak();
    map<string,int> toko = SimpanMuat::getToko();

    for(auto i = pemain.begin(); i != pemain.end(); i++){
        cout << *i << endl;
        cout << get<0>(dataPemain.at(*i)) << " " << get<1>(dataPemain.at(*i)) << " " << get<2>(dataPemain.at(*i)) << endl;
        for(auto j = inventory.at(*i).begin(); j != inventory.at(*i).end(); j++){
            cout << *j << endl;
        }
        if( get<0>(dataPemain.at(*i)) != "Walikota" ){
            for(auto j = LadangdanTernak.at(*i).begin(); j != LadangdanTernak.at(*i).end(); j++){
                cout << get<0>(*j) << " " << get<1>(*j) << " " << get<2>(*j) << endl;
            }
        }
        cout << endl;
    }
    for(auto j = toko.begin(); j != toko.end(); j++){
        cout << j->first << " " << j->second << endl;
    }
    
    
}