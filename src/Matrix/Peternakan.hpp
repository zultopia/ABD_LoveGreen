#ifndef __PETERNAKAN_HPP__
#define __PETERNAKAN_HPP__

#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "Grid.hpp"
#include <map>

class Peternakan : public Grid<Hewan> {
public:
    Peternakan();

    Peternakan(int numRows, int numCols);

    void cetakInfo();

    void cetakLokasiHewan();

    void tambahHewan(int row, int col, Hewan* jenis);

    Hewan* ambilTernak(int row, int col);

    void tambahHewan(Hewan* jenisTernak);

    void menanamTernak(Item* item);

    map<string, int> hitungJumlahHewanPanen();

    void operator+(Hewan* ternak);

    vector<tuple<string,string,int>> getDaftarIsi();

    void wabah();
};

#endif