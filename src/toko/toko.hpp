#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Toko{
    private:
        static map<string,tuple<int,int>> tersedia;
        

    public:
        // cetak hal yang dapat dibeli
        void Cetak();

        // barang yang dibeli
        void Beli(string namaBarang, int Quantity);

        // batal melakukan pembelian
        void batalBeli(string namaBarang, int Quantity);

        // mengembalikan jumlah barang yang tersedia
        int getQuantity(string namaBarang);

        // mengembalikan harga barang
        int getPrice(string namaBarang);

};


#endif
