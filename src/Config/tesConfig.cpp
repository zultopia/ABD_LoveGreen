#include "Config.hpp"

int main(){
    Config::bacaPlant();
    for(auto i = Config::plant.cbegin(); i != Config::plant.cend(); i++){
        cout << get<0>(i->second) << i->first << get<1>(i->second) << get<2>(i->second) << get<3>(i->second) << get<4>(i->second) << endl;
    }
}