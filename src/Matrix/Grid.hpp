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

#endif