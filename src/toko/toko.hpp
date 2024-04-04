#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Toko{
    private:
        // map<namaProduk,tuple<Price,Quantity>>
        static map<string,pair<int,int>> produk;
        // map<namaBangunan,tuple<Price,Quantity>>
        static map<string,pair<int,int>> bangunan;
        // map<namaProduk, Price>
        static map<string,int> tanamanHewan;
        

    public:

        Toko();

        // tambahkan tanaman atau hewan baru
        void tambahTanamanHewan(string nama, int Price);

        // tambah harga tanaman atau hewan
        void aturHargaTanamanHewan(string nama, int Price);

        // tambahkan Produk baru
        void tambahProduk(string nama, int Price, int Quantity);

        // atur jumlah Produk
        void aturJumlahProduk(string nama, int Quantity);

        // atur harga Produk
        void aturHargaProduk(string nama, int Price);

        // tambahkan Bangunan baru
        void tambahBangunan(string nama, int Price, int Quantity);

        // atur jumlah Bangunan
        void aturJumlahBangunan(string nama, int Quantity);

        // atur harga Bangunan
        void aturHargaBangunan(string nama, int Price);


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
