#include "Muat.hpp"

vector<string> Muat::pemain;
map<string,tuple<string,int,int>> Muat::dataPemain;
map<string, vector<string>> Muat::inventory;
map<string,vector<tuple<string,string,int>>> Muat::LadangdanTernak;
map<string,int> Muat::toko;

void Muat::muat(string path){
    ifstream inputFile(path);
    if(!inputFile.is_open()){
        ConfigException e("File state.txt tidak dapat dibuka.");
        throw e;
    }
    string line;
    getline(inputFile, line);
    stringstream s(line);
    string loop;
    s >> loop;
    for(int i = 0; i < stoi(loop); i++){
        read(inputFile);
    }
    // bagian toko
    getline(inputFile,line);
    string jumlah;
    stringstream s2(line);
    s2 >> jumlah;
    for(int i = 0; i < stoi(jumlah); i++){
        getline(inputFile,line);
        stringstream s(line);
        string namaItem, jumlahItem;
        s >> namaItem >> jumlahItem;
        toko.insert({namaItem,stoi(jumlahItem)});
    }
}

void Muat::read(ifstream& inputFile){
    string line;
    getline(inputFile, line);
    stringstream s(line);
    string username, role, weightPlayer, uang;
    s >> username >> role >> weightPlayer >> uang;
    pemain.push_back(username);
    dataPemain.insert({username, make_tuple(role,stoi(weightPlayer),stoi(uang))});
    getline(inputFile, line);
    stringstream s1(line);
    string jumlah;
    s1 >> jumlah;
    // bagian inventory
    vector<string> vectorInventorytemp;
    for(int i = 0; i < stoi(jumlah); i++){
        getline(inputFile,line);
        stringstream s(line);
        string inventoryTemp;
        s >> inventoryTemp;
        vectorInventorytemp.push_back(inventoryTemp);
    }
    inventory.insert({username,vectorInventorytemp});
    vectorInventorytemp.clear();
    // bagian ladang atau ternak
    if (role != "Walikota"){
        getline(inputFile,line);
        string jumlah;
        stringstream s(line);
        s >> jumlah;
        vector<tuple<string,string,int>> ladangTernaktTmp;
        for(int i = 0; i < stoi(jumlah); i++){
            getline(inputFile,line);
            stringstream s(line);
            string lokasi, namaT, umurBerat;
            s >> lokasi >> namaT >> umurBerat;
            ladangTernaktTmp.push_back(make_tuple(lokasi,namaT,stoi(umurBerat)));
        }
        LadangdanTernak.insert({username, ladangTernaktTmp});
        ladangTernaktTmp.clear();
    }

}
vector<string> Muat::getPemain(){
    return pemain;
}
map<string,tuple<string,int,int>> Muat::getDataPemain(){
    return dataPemain;
}
map<string, vector<string>> Muat::getInventory(){
    return inventory;
}
map<string,vector<tuple<string,string,int>>> Muat::getLadangdanTernak(){
    return LadangdanTernak;
}
map<string,int> Muat::getToko(){
    return toko;
}