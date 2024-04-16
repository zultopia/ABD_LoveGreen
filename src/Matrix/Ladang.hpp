#ifndef __LADANG_HPP__
#define __LADANG_HPP__

#include <map>
#include "../Tanaman/Tanaman.hpp"
#include "Grid.hpp"
#include "../Item/Item.hpp"

class Ladang : public Grid<Tanaman> {
    public:
        Ladang();

        Ladang(int numRows, int numCol);

        void cetakInfo();

        void cetakKeteranganTanaman();

        void tambahTanaman(int row, int col, Tanaman* jenis);

        Tanaman* ambilTanaman(int row, int col);

        void tambahTanaman(Tanaman* jenisTanaman);

        void menanamTanaman(Item* item);

        map<string, int> hitungJumlahTanamanPanen();

        void addDurationTanaman();

        void operator+(Tanaman* tanaman);

        // daftar isi ladang
        vector<tuple<string,string,int> > getDaftarIsi();
};

#endif