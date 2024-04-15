#ifndef __PENYIMPANAN_HPP__
#define __PENYIMPANAN_HPP__

#include <algorithm>
#include "Grid.hpp"
#include "../Item/Item.hpp"

class Penyimpanan {
    protected:
        const int rows;
        const int cols;
        Grid<Item> grid;

    public:
        Penyimpanan();

        Penyimpanan(int numRows, int numCols);

        virtual void cetakInfo();

        void tambahItem(int row, int col, Item* jenisItem);

        int hitungSlotKosong();

        Grid<Item> getGrid() const;

        Item* ambilItem(int row, int col);

        Item* ambilItem(string koordinat);

        void tambahItem(Item* jenisItem);

        void operator+(Item* item);

        vector<string> getListPenyimpanan();

        static pair<int, int> konversiKoordinat(string koordinat);

        static vector<tuple<int, int>> parserListKoordinat(string input);

        int jumlahItem(string nama);

        bool checkMakanan(int row, int col);


};

#endif