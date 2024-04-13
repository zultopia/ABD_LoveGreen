#ifndef __GRID_HPP__
#define __GRID_HPP__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "../Item/Item.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Hewan/Hewan.hpp"

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
        Grid();

        Grid(int numRows, int numCols);

        void updateCell(int row, int col, T* value);

        T* getCell(int row, int col) const;

        void removeItem(int row, int col);

        vector<vector<T*> > getGrid() const;

        int getRows() const;

        int getCols() const;
};

#endif