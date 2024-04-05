#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <map>

using namespace std;

class Config {
    private:
        map<string, tuple<int, string, string, string, int, int>> listFarm; // untuk map ke tanaman dan hewan <ID> <KODE_HURUF> <NAME> <TYPE> <TO_HARVEST> <PRICE>
        map<string, tuple<int, string, string, string, string, int, int>> listProduk; // untuk map ke produk <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>

    public:
        // ctor
        Config();

        // dtor
        ~Config();

        // operations
        void loadFarm(string fileName);
        void loadProduk(string fileName);
        const tuple<int, string, string, string, int, int> getFromFarm(string code) const;
        const tuple<int, string, string, string, string, int, int> getFromProduk(string name) const;
};

#endif