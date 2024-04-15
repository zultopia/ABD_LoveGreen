#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>

#include "SimpanMuat.hpp"
#include "../Exception/ConfigException.hpp"

class Simpan : virtual SimpanMuat{
    public:
        static void simpan();
        static void update();
};

#endif 
