#ifndef Config_HPP
#define Config_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ConfigException.cpp"
#include "ConfigException.hpp"

using namespace std;

class Config{
    private:
        // map<nama,tuple<id,kode,type,duration,price>>
        static map<string,tuple<int,string,string,int,int>> plant;

        // map<nama,tuple<id,kode,type,weight,price>>
        static map<string,tuple<int,string,string,int,int>> animal;

        // map<nama,tuple<id,kode,type,origin,added_weight,price>>
        static map<string,tuple<int,string,string,string,int,int>> product;

        // map<nama,tuple<id,kode,price, map<material,quantity>>>
        static map<string,tuple<int,string,int,map<string,int>>> recipe;
        static int jumlahUangWin;
        static int beratBadanWin;
        static pair<int,int> besarPenyimpanan;
        static pair<int,int> besarLahan;
        static pair<int,int> besarPeternakan;
    public:
        Config();
        int static bacaPlant();
        int static bacaAnimal();
        int static bacaProduct();
        int static bacaRecipe();
        int static bacaMisc();
        static void bacaConfig();
        static bool isExistPlant(string key);
        static bool isExistAnimal(string key);
        static bool isExistProduct(string key);
        static bool isExistRecipe(string key);
        static map<string,tuple<int,string,string,int,int>>& getPlantMap();
        static map<string,tuple<int,string,string,int,int>>& getAnimalMap();
        static map<string,tuple<int,string,string,string,int,int>>& getProductMap();
        static map<string,tuple<int,string,int,map<string,int>>>& getRecipeMap();
        static int getId(string key);
        static string getNama(string key);
        static string getType(string key);
        static int getDuration(string key);
        static int getPrice(string key);
        static int getWeightHarvest(string key);
        static string getOrigin(string key);
        static int getAddedWeight(string key);
        static map<string,int>& getMaterialInfo(string key);
        static int getJumlahUangWin();
        static int getBeratBadanWin();
        static pair<int,int> getBesarPenyimpanan();
        static pair<int,int> getBesarLahan();
        static pair<int,int> getBesarPeternakan();
        
};

#endif