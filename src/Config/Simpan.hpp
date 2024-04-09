#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>
#include "SimpanMuat.hpp"

class Simpan : virtual SimpanMuat{
    public:
        static void simpan(std::string path);
};

#endif 
