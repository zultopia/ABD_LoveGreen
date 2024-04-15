#ifndef __LADANG_HPP__
#define __LADANG_HPP__

#include <map>
#include "../Tanaman/Tanaman.hpp"
#include "Penyimpanan.hpp"

class Ladang : public Penyimpanan {
    private:
        Grid<Tanaman> grid;

    public:
        Ladang();

        Ladang(int numRows, int numCols);

        void cetakInfo() override;

        void cetakKeteranganTanaman();

        void tambahTanaman(int row, int col, Tanaman* jenis);

        Grid<Tanaman> getGrid() const;

        Tanaman* ambilTanaman(int row, int col);

        void tambahTanaman(Tanaman* jenisTanaman);

        void menanamTanaman(Item* item);

        map<string, int> hitungJumlahTanamanPanen();

        void operator+(Tanaman* tanaman);

        // daftar isi ladang
        vector<tuple<string,string,int> > getDaftarIsi();
};

#endif