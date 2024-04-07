#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
#include "../Config/Config.hpp"
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"

using namespace std;

class Toko{
    private:
        // map<namaBarang,tuple<Price,Quantity>>
        map<string,pair<int,int>> barang;
        static int jumlah;


    public:

        Toko();

        // tambahkan tanaman atau hewan baru
        void tambahTanamanHewan(string kode, int Price);

        // tambahkan Produk yang mempunyai kuantitas baru
        void tambahProduk(string kode, int Price, int Quantity);

        // atur harga barang
        void aturHargaBarang(string kode, int Price);

        // atur jumlah Barang yang terbatas
        void aturJumlahBarang(string kode, int Quantity);

        // cetak hal yang dapat dibeli 
        // tiap jenis pemain beda yang dicetak
        // pake method yang sesuai dengan current user
        void CetakWalikota();
        void CetakPeternakPetani();
        void Cetak();
        // Produk yang dibeli
        // mengembalikan jumlah uang yang harus dibayarkan untuk membeli
        int BeliWalikota(int no, int Quantity);
        int BeliPeternakPetani(int no, int Quantity);

        int Beli(int no, int Quantity);

        // batal melakukan pembelian
        void batalBeli(string kode, int Quantity);

        // menjual ke toko
        // mengembalikan jumlah uang yang akan diterima dari penjualan
        int Jual(string kode, int Quantity);

        // batal melakukan penjualan
        void batalJual(string kode, int Quantity);

        // mengembalikan jumlah Produk yang tersedia
        int getQuantity(string kode);

        // mengembalikan harga
        int getPrice(string kode);

};


#endif
