#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Toko{
    private:
        // map<namaBarang,tuple<Price,Quantity>>
        map<string,pair<int,int>> barang;
        static int jumlah;


    public:

        Toko();

        // tambahkan tanaman atau hewan baru
        void tambahTanamanHewan(string nama, int Price);

        // tambahkan Produk yang mempunyai kuantitas baru
        void tambahProduk(string nama, int Price, int Quantity);

        // atur harga barang
        void aturHargaBarang(string nama, int Price);

        // atur jumlah Barang yang terbatas
        void aturJumlahBarang(string nama, int Quantity);

        // cetak hal yang dapat dibeli 
        // tiap jenis pemain beda yang dicetak
        // pake method yang sesuai dengan current user
        void CetakWalikota();
        void CetakPeternakPetani();

        // Produk yang dibeli
        // mengembalikan jumlah uang yang harus dibayarkan untuk membeli
        int Beli(string nama, int Quantity);

        // batal melakukan pembelian
        void batalBeli(string nama, int Quantity);

        // menjual ke toko
        // mengembalikan jumlah uang yang akan diterima dari penjualan
        int Jual(string nama, int Quantity);

        // batal melakukan penjualan
        void batalJual(string nama, int Quantity);

        // mengembalikan jumlah Produk yang tersedia
        int getQuantity(string nama);

        // mengembalikan harga
        int getPrice(string nama);

};


#endif
