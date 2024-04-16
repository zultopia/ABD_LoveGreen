#ifndef __PENYIMPANAN_HPP__
#define __PENYIMPANAN_HPP__

#include <algorithm>
#include "Grid.hpp"
#include "../Item/Item.hpp"

class Penyimpanan : public Grid<Item> {
    public:
        Penyimpanan();

        Penyimpanan(int numRows, int numCols);

        void cetakInfo();

        void tambahItem(int row, int col, Item* jenisItem);

        Item* ambilItem(int row, int col);

        Item* ambilJenisItem(string slot, string jenisItem);

        void tambahItem(Item* jenisItem);

        void operator+(Item* item);

        int jumlahItem(string nama);

        bool checkMakanan(int row, int col);
};

#endif