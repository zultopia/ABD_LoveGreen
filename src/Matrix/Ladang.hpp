#ifndef __LADANG_HPP__
#define __LADANG_HPP__

#include <map>
#include "../Tanaman/Tanaman.hpp"
#include "Grid.hpp"
#include "../Item/Item.hpp"

class Ladang : public Grid<Tanaman> {
    public:
        Ladang() : Grid<Tanaman>(Config::getBesarLahan().first, Config::getBesarLahan().second) {}

        Ladang(int numRows, int numCols) : Grid<Tanaman>(numRows, numCols) {}

        void cetakInfo();

        void cetakKeteranganTanaman();

        void tambahTanaman(int row, int col, Tanaman* jenis);

        Tanaman* ambilTanaman(int row, int col);

        void tambahTanaman(Tanaman* jenisTanaman);

        void menanamTanaman(Item* item);

        map<string, int> hitungJumlahTanamanPanen();

        void operator+(Tanaman* tanaman);

        // daftar isi ladang
        vector<tuple<string,string,int> > getDaftarIsi();
};

#endif