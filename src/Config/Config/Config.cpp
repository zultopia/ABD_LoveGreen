#include "Config.hpp"

Config::Config() {}     // ctor
Config::~Config() {}    // dtor

void Config::loadFarm(string fileName) {
    string getPath = "C:/Users/naufn/Documents/gitHub/ABD_LoveGreen/src/Config/Berkas/" + fileName;
    ifstream file(getPath);
    if (!file.is_open()) {
        cerr << "ex handler nih gagal membuka file Animal.txt" << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream iss(line);
        string id, toHarvest, price, code, name, type;
        iss >> id >> code >> name >> type >> toHarvest >> price;
        listFarm[code] = make_tuple(stoi(id), code, name, type, stoi(toHarvest), stoi(price));
    }
    file.close();
}

void Config::loadProduk(string fileName) {
    string getPath = "C:/Users/naufn/Documents/gitHub/ABD_LoveGreen/src/Config/Berkas/" + fileName;
    ifstream file(getPath);
    if (!file.is_open()) {
        cerr << "ex handler nih gagal membuka file Animal.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string id, code, name, type, origin, addedWeight, price;
        iss >> id >> code >> name >> type >> origin >> addedWeight >> price;
        listProduk[name] = make_tuple(stoi(id), code, name, type, origin, stoi(addedWeight), stoi(price));
    }
    file.close();
}

const tuple<int, string, string, string, int, int> Config::getFromFarm(string code) const {
    auto it = listFarm.find(code);
    if (it != listFarm.end()) {
        return it->second;
    }
    throw out_of_range("Code not found in listFarm");
}

const tuple<int, string, string, string, string, int, int> Config::getFromProduk(string name) const {
    auto it = listProduk.find(name);
    if (it != listProduk.end()) {
        return it->second;
    }
    throw out_of_range("Code not found in listProduk");
}