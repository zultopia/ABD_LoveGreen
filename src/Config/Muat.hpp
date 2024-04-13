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
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Item/Bangunan.hpp"
#include "Config.hpp"
using namespace std;
class Muat: virtual SimpanMuat{
    public:
        static string readPath();
        static void muat();
        static void read(ifstream& inputFile);
        static void setUp();
        static void setUpPetani(Pemain* player, string nama);
        static void setUpPeternak(Pemain* player, string nama);
        static void setUpWalikota(Pemain* player, string nama);
        static void setUpInventory(Pemain* pemain);
};

#endif