#ifndef SIMPAN_MUAT_HPP
#define SIMPAN_MUAT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>
#include "ConfigException.hpp"
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
};

#endif