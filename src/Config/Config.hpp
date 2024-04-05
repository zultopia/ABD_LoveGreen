#ifndef Config_HPP
#define Config_HPP
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Config{
    public:
        static map<string,tuple<int,string,string,int, int>> plant;
        static map<string,tuple<int,string,string,int,int>> animal;
        static map<string,tuple<int,string,string,string,int,int>> product;
        static map<string,tuple<int,string,int,map<string,int>>> recipe;
        static int jumlahUangWin;
        static int beratBadanWin;
        static pair<int,int> besarPenyimpanan;
        static pair<int,int> besarLahan;
        static pair<int,int> besarPeternakan;
        Config();
        int static bacaPlant();
        int static bacaAnimal();
        int static bacaProduct();
        int static bacaRecipe();
        int static bacaMisc();
        static void bacaConfig();


};

#endif