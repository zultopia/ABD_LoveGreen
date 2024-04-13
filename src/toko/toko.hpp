#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
// #include "../Config/Config.cpp"
// #include "../Config/Muat.cpp"
// #include "TokoException.cpp"
#include "../Config/Config.hpp"
#include "../Config/Muat.hpp"
#include "TokoException.hpp"



using namespace std;

class Toko{
    private:
        // map<namaBarang,tuple<Price,Quantity>>
        static map<string,pair<int,int> > barang;
        static vector<string> urutan;
        


    public:

        Toko();
        static void setUpToko();
        static void setUpTokoMuat();

        // tambahkan tanaman atau hewan baru
        static void tambahTanamanHewan(string nama, int Price);

        // tambahkan Produk yang mempunyai kuantitas baru
        static void tambahProduk(string nama, int Price, int Quantity);

        // atur harga barang
        static void aturHargaBarang(string nama, int Price);

        // atur jumlah Barang yang terbatas
        static void aturJumlahBarang(string nama, int Quantity);

        // cetak hal yang dapat dibeli 
        // tiap jenis pemain beda yang dicetak
        // pake method yang sesuai dengan current user
        static int CetakWalikota();
        static int CetakPeternakPetani();
        // Produk yang dibeli
        // mengembalikan jumlah uang yang harus dibayarkan untuk membeli
        static int BeliWalikota(int no, int Quantity);
        static int BeliPeternakPetani(int no, int Quantity);
        static string getBarangNoUrutWalikota(int no);
        static string getBarangNoUrutPeternakPetani(int no);
        // batal melakukan pembelian
        static void batalBeli(string nama, int Quantity);

        // menjual ke toko
        // mengembalikan jumlah uang yang akan diterima dari penjualan
        static int Jual(string nama, int Quantity);

        // batal melakukan penjualan
        static void batalJual(string nama, int Quantity);

        // mengembalikan jumlah Produk yang tersedia
        static int getQuantity(string nama);

        // mengembalikan harga
        static int getPrice(string nama);

        static map<string,pair<int,int> >& getBarang();
        static vector<string>& getUrutan();

        // return map isi dari toko
        static map<string,int> getIsiToko();

        // print isi toko
        static void displayIsiToko();

};


#endif
