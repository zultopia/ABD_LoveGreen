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

void SimpanMuat::update(const std::vector<std::string>& newPemain,
                        const std::map<std::string, std::tuple<std::string, int, int>>& newDataPemain,
                        const std::map<std::string, std::vector<std::string>>& newInventory,
                        const std::map<std::string, std::vector<std::tuple<std::string, std::string, int>>>& newLadangdanTernak,
                        const std::map<std::string, int>& newToko) {
    // Memperbarui data pemain
    pemain = newPemain;

    // Memperbarui data pemain
    dataPemain = newDataPemain;

    // Memperbarui data inventory
    inventory = newInventory;

    // Memperbarui data ladang dan ternak
    LadangdanTernak = newLadangdanTernak;

    // Memperbarui data toko
    toko = newToko;
}