#ifndef MUAT_HPP
#define MUAT_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "SimpanMuat.hpp"
using namespace std;
class Muat: virtual SimpanMuat{
    public:
        static void muat(string path);
        static void read(ifstream& inputFile);
        
};

#endif