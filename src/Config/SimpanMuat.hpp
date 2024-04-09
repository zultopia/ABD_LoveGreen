#ifndef SIMPAN_MUAT_HPP
#define SIMPAN_MUAT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>
#include "ConfigException.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Toko/Toko.hpp"

class SimpanMuat{
    protected: 
        static vector<string> pemain;
        static map<string,tuple<string,int,int>> dataPemain;
        static map<string, vector<string>> inventory;
        static map<string,vector<tuple<string,string,int>>> LadangdanTernak;
        static map<string,int> toko;
    public:
        static vector<string>& getPemain();
        static map<string,tuple<string,int,int>>& getDataPemain();
        static map<string, vector<string>>& getInventory();
        static map<string,vector<tuple<string,string,int>>>& getLadangdanTernak();
        static map<string,int>& getToko();
        void update(const std::vector<std::string>& newPemain,
                const std::map<std::string, std::tuple<std::string, int, int>>& newDataPemain,
                const std::map<std::string, std::vector<std::string>>& newInventory,
                const std::map<std::string, std::vector<std::tuple<std::string, std::string, int>>>& newLadangdanTernak,
                const std::map<std::string, int>& newToko);
};

#endif