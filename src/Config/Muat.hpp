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
#include "Pemain/Pemain.hpp"
#include "Matrix/Penyimpanan.hpp"
#include "Matrix/Ladang.hpp"
#include "Matrix/Peternakan.hpp"

using namespace std;
class Muat: virtual SimpanMuat{
    public:
        static string readPath();
        static void muat();
        static void read(ifstream& inputFile);
        static void setUp();
        static void cekMuat();
        static void setUpPetani(Pemain*& player, string nama);
        static void setUpPeternak(Pemain*& player, string nama);
        static void setUpWalikota(Pemain*& player, string nama);
        static void setUpInventory(Pemain*& pemain);
        static Item* universalConstructor(string nama);
};

#endif