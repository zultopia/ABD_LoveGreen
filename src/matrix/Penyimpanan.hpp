#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "item/Item.hpp"

using namespace std;

// Kode warna untuk menandakan apakah siap panen atau tidak
#define RESET   "\033[0m"
#define RED     "\033[31m"  // Belum siap panen
#define GREEN   "\033[32m"  // Siap panen

template<class T>
class Grid {
    private:
        vector<vector<T> > grid;

    public:
        Grid() {}

        Grid(int numRows, int numCols) : grid(numRows, vector<T>(numCols)) {}

        void updateCell(int row, int col, const T& value) {
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
                grid[row][col] = value;
            }
        }

        const T& getCell(int row, int col) const {
            return grid[row][col];
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
        Grid<string> grid;

    public:
        Penyimpanan();

        Penyimpanan(int numRows, int numCols);

        virtual void cetakInfo();

        void updateCell(int row, int col, const string& value);

        int hitungSlotKosong();

        string ambilItem(int row, int col);

        void tambahItem(const string& jenisItem);

        void operator+(const string& item);
};

class Ladang : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Ladang();

        Ladang(int numRows, int numCols);

        void cetakInfo() override;

        void cetakKeteranganTanaman();

        void tanamTanaman(int row, int col, const string& jenis);

        string ambilTanaman(int row, int col);

        void tambahTanaman(const string& jenisTanaman);

        void operator+(const string& tanaman);
};

class Peternakan : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Peternakan();

        Peternakan(int numRows, int numCols);

        void cetakInfo() override;

        void cetakLokasiHewan();

        void ternakHewan(int row, int col, const string& jenis);

        string ambilTernak(int row, int col);

        void tambahTernak(const string& jenisTernak);

        void operator+(const string& ternak);
};