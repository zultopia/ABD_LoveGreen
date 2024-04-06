#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "item/Item.hpp"
#include "Tanaman.hpp"
#include "Hewan.hpp"

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

        void updateCell(int row, int col, const T& value) {
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

        void updateCell(int row, int col, const Item& value);

        int hitungSlotKosong();

        Item* ambilItem(int row, int col);

        void tambahItem(const Item& jenisItem);

        void operator+(const Item& item);
};

class Ladang : public Penyimpanan {
    private:
        Grid<Tanaman> grid;

    public:
        Ladang();

        Ladang(int numRows, int numCols);

        void cetakInfo() override;

        void cetakKeteranganTanaman();

        void tanamTanaman(int row, int col, const Tanaman& jenis);

        Tanaman* ambilTanaman(int row, int col);

        void tambahTanaman(const Tanaman& jenisTanaman);

        void operator+(const Tanaman& tanaman);
};

class Peternakan : public Penyimpanan {
    private:
        Grid<Hewan> grid;

    public:
        Peternakan();

        Peternakan(int numRows, int numCols);

        void cetakInfo() override;

        void cetakLokasiHewan();

        void ternakHewan(int row, int col, const Hewan& jenis);

        Hewan* ambilTernak(int row, int col);

        void tambahTernak(const Hewan& jenisTernak);

        void operator+(const Hewan& ternak);
};