#ifndef __PETERNAKAN_HPP__
#define __PETERNAKAN_HPP__

#include "Grid.hpp"
#include "Penyimpanan.hpp"

class Peternakan : public Penyimpanan {
    private:
        Grid<Hewan> grid;

    public:
        Peternakan();

        Peternakan(int numRows, int numCols);

        void cetakInfo() override;

        void cetakLokasiHewan();

        void ternakHewan(int row, int col,  Hewan* jenis);

        Grid<Hewan> getGrid() const;

        Hewan* ambilTernak(int row, int col);

        void tambahTernak( Hewan* jenisTernak);

        map<string, int> hitungJumlahHewanPanen();

        void operator+(Hewan* ternak);

        vector<tuple<string,string,int> > getDaftarIsi();
};

#endif