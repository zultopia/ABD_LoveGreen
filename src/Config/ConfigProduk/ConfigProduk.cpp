#include "ConfigProduk.hpp"

// Konstruktor
ConfigProduk::ConfigProduk() {}

// Destruktor
ConfigProduk::~ConfigProduk() {}

void ConfigProduk::load() {
    ifstream file("C:/Users/naufn/Documents/gitHub/ABD_LoveGreen/src/Config/ConfigProduk/Produk.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file Produk.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id, added_weight, price;
        string code, name, origin, type;
        ss >> id >> code >> name >> type >> origin >> added_weight >> price;
        Produk product(id, added_weight, price, code, name, origin, type);
        listProduk[code] = product;
    }

    file.close();
}

Produk& ConfigProduk::findProduk(string code) {
    return listProduk[code];
}
