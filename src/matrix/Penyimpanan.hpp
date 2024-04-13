#ifndef __PENYIMPANAN_HPP__
#define __PENYIMPANAN_HPP__

#include "Grid.hpp"

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

        vector<string> getListPenyimpanan();

        bool checkMakanan(int row, int col);
};

#endif