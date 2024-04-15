#ifndef __PETERNAKAN_HPP__
#define __PETERNAKAN_HPP__

#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "Grid.hpp"
#include "Penyimpanan.hpp"
#include <map>

class Peternakan : public Grid<Hewan> {
public:
    Peternakan() : Grid<Hewan>(Config::getBesarPeternakan().first, Config::getBesarPeternakan().second) {}

    Peternakan(int numRows, int numCols) : Grid<Hewan>(numRows, numCols) {}

    void cetakInfo();

    void cetakLokasiHewan();

    void tambahHewan(int row, int col, Hewan* jenis);

    Hewan* ambilTernak(int row, int col);

    void tambahHewan(Hewan* jenisTernak);

    void menanamTernak(Item* item);

    map<string, int> hitungJumlahHewanPanen();

    void operator+(Hewan* ternak);

    vector<tuple<string,string,int>> getDaftarIsi();
};

#endif