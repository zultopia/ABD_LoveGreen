#ifndef MUAT_HPP
#define MUAT_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ConfigException.hpp"
using namespace std;
class Muat{
    private: 
        static vector<string> pemain;
        static map<string,tuple<string,int,int>> dataPemain;
        static map<string, vector<string>> inventory;
        static map<string,vector<tuple<string,string,int>>> LadangdanTernak;
        static map<string,int> toko;
    public:
        static void muat(string path);
        static void simpan(string path);
        static void read(ifstream& inputFile);
        static void readPetani(ifstream& inputFile);
        static void readWalikota(ifstream& inputFile);
        static void readToko(ifstream& inputFile);
        static vector<string>& getPemain();
        static map<string,tuple<string,int,int>>& getDataPemain();
        static map<string, vector<string>>& getInventory();
        static map<string,vector<tuple<string,string,int>>>& getLadangdanTernak();
        static map<string,int>& getToko();
};

#endif