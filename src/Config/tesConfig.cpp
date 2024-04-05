#include "Config.hpp"

int main(){
    Config::bacaConfig();
    for(auto i = Config::plant.cbegin(); i != Config::plant.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
    }
    cout << endl;
    for(auto i = Config::animal.cbegin(); i != Config::animal.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
    }
    cout << endl;
    for(auto i = Config::product.cbegin(); i != Config::product.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << " " << get<5>(i->second) << endl;
    }
    cout << endl;
    for(auto i = Config::recipe.cbegin(); i != Config::recipe.cend(); i++){
        cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " ";
        for(auto j = (get<3>(i->second)).cbegin(); j != (get<3>(i->second)).cend(); j++){
            cout << j->first << " " << j->second << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << Config::jumlahUangWin << endl;
    cout << Config::beratBadanWin << endl;
    cout << Config::besarPenyimpanan.first << " " << Config::besarPenyimpanan.second << endl;
    cout << Config::besarLahan.first << " " << Config::besarLahan.second << endl;
    cout << Config::besarPeternakan.first << " " << Config::besarPeternakan.second << endl;
    
}