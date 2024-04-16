#ifndef __GRID_HPP__
#define __GRID_HPP__

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <tuple>

#include "../Item/Item.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Config/Config.hpp"

using namespace std;

// Kode warna untuk menandakan apakah siap panen atau tidak
#define RESET   "\033[0m"
#define RED     "\033[31m"  // Belum siap panen
#define GREEN   "\033[32m"  // Siap panen

template<class T>
class Grid {
    protected:
        vector<vector<T*> > grid;
        const int rows;
        const int cols;

    public:
        Grid(int numRows, int numCols) : grid(numRows, vector<T*>(numCols)), rows(numRows), cols(numCols) {}

        void updateCell(int row, int col, T* value){
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
                grid[row][col] = value;
            }
        }

        T* getCell(int row, int col) const{
            return grid[row][col];
        }

        void removeItem(int row, int col){
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
                delete grid[row][col];
                grid[row][col] = nullptr;
            }
        }

        vector<vector<T*> > getGrid() const{
            return grid;
        }

        int getRows() const{
            return grid.size();
        }

        int getCols() const{
            return grid.empty() ? 0 : grid[0].size();
        }

        vector<string> getListPenyimpanan() const {
            vector<string> listPenyimpanan;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] != nullptr) {
                        listPenyimpanan.push_back(grid[i][j]->getCode());
                    }
                }
            }
            return listPenyimpanan;
        }

        int hitungSlotKosong() const {
            int count = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] == nullptr) {
                        count++;
                    }
                }
            }
            return count;
        }

        static pair<int, int> konversiKoordinat(string koordinat) {
            int col = koordinat[0] - 'A';
            int row = stoi(koordinat.substr(1)) - 1;
            return make_pair(row, col);
        }

        static vector<tuple<int, int>> parserListKoordinat(string input) {
            vector<tuple<int, int>> listKoordinat;
            string temp = "";
            for (char c : input) {
                if (c != ' ' && c != ',') {
                    temp += c;
                } else if (c == ',' ){
                    int row = stoi(temp.substr(1)) - 1; 
                    int col = temp[0] - 'A';
                    listKoordinat.push_back(make_tuple(row, col));
                    temp = "";
                }
            }
            int row = stoi(temp.substr(1)) - 1; 
            int col = temp[0] - 'A';
            listKoordinat.push_back(make_tuple(row, col));
            
            return listKoordinat;
        }

        bool isCellKosong(int row, int col) {
            if (row >= 0 && row < getRows() && col >= 0 && col < getCols()) {
                return getCell(row, col) == nullptr;
            } else {
                return false;
            }
        }
};

#endif