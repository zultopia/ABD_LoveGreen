#ifndef MUAT_HPP
#define MUAT_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <filesystem>
#include "SimpanMuat.hpp"
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Hewan/Herbivora/Herbivora.hpp"
#include "../Hewan/Karnivora/Karnivora.hpp"
#include "../Hewan/Omnivora/Omnivora.hpp"
#include "../Produk/ProdukEatable/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable/ProdukUneatable.hpp"
#include "Config.hpp"
using namespace std;
class Muat: virtual SimpanMuat{
    public:
        static string readPath();
        static void muat();
        static void read(ifstream& inputFile);
        static void setUp();
        
};

#endif