#ifndef __PENYIMPANAN_HPP__
#define __PENYIMPANAN_HPP__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "../item/Item.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Hewan/BaseHewan/Hewan.hpp"

using namespace std;

// Kode warna untuk menandakan apakah siap panen atau tidak
#define RESET   "\033[0m"
#define RED     "\033[31m"  // Belum siap panen
#define GREEN   "\033[32m"  // Siap panen

template<class T>
class Grid {
    private:
        vector<vector<T*> > grid;

    public:
        Grid() {}

        Grid(int numRows, int numCols) : grid(numRows, vector<T*>(numCols)) {}

        void updateCell(int row, int col, T* value) {
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
                grid[row][col] = value;
            }
        }

        T* getCell(int row, int col) const {
            return grid[row][col];
        }

        void removeItem(int row, int col) {
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
                delete grid[row][col];
                grid[row][col] = nullptr;
            }
        }

        vector<vector<T*> > getGrid() const {
            return grid;
        }

        int getRows() const {
            return grid.size();
        }

        int getCols() const {
            return grid.empty() ? 0 : grid[0].size();
        }
};

class Penyimpanan {
    protected:
        const int rows;
        const int cols;
        Grid<Item> grid;

    public:
        Penyimpanan();

        Penyimpanan(int numRows, int numCols);

        virtual void cetakInfo();

        void updateCell(int row, int col, Item* value);

        int hitungSlotKosong();

        Grid<Item> getGrid() const;

        Item* ambilItem(int row, int col);

        void tambahItem(Item* jenisItem);

        void operator+(Item* item);
};

class Ladang : public Penyimpanan {
    private:
        Grid<Tanaman> grid;

    public:
        Ladang();

        Ladang(int numRows, int numCols);

        void cetakInfo() override;

        void cetakKeteranganTanaman();

        void tanamTanaman(int row, int col, Tanaman* jenis);

        Grid<Tanaman> getGrid() const;

        Tanaman* ambilTanaman(int row, int col);

        void tambahTanaman(Tanaman* jenisTanaman);

        map<string, int> hitungJumlahTanamanPanen();

        void operator+(Tanaman* tanaman);
};

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
};

#endif