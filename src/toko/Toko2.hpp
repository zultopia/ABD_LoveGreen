#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Toko{
    private:
        static map<string,int> storage;
        map<int, string> daftar; 
};

#endif