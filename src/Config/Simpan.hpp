#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>
#include "Muat.hpp"
#include "ConfigException.hpp"

class Simpan {
    public:
        static void simpan(std::string path);
};

#endif 
