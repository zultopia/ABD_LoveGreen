#include "SimpanMuat.hpp"

vector<string> SimpanMuat::pemain;
map<string,tuple<string,int,int>> SimpanMuat::dataPemain;
map<string, vector<string>> SimpanMuat::inventory;
map<string,vector<tuple<string,string,int>>> SimpanMuat::LadangdanTernak;
map<string,int> SimpanMuat::toko;

vector<string>& SimpanMuat::getPemain(){
    return pemain;
}
map<string,tuple<string,int,int>>& SimpanMuat::getDataPemain(){
    return dataPemain;
}
map<string, vector<string>>& SimpanMuat::getInventory(){
    return inventory;
}
map<string,vector<tuple<string,string,int>>>& SimpanMuat::getLadangdanTernak(){
    return LadangdanTernak;
}
map<string,int>& SimpanMuat::getToko(){
    return toko;
}