#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include <filesystem>
#include "SimpanMuat.hpp"
#include "../Toko/Toko.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"

class Simpan : virtual SimpanMuat{
    public:
        static void simpan(std::string path);
        static void update();
};

#endif 
