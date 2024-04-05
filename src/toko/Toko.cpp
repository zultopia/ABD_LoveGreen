#include "Toko.hpp"

int Toko::jumlah = 1; 
Toko::Toko(){}

// tambahkan tanaman atau hewan baru
void Toko::tambahTanamanHewan(string nama, int Price){
    barang.insert(pair(nama, pair(Price, -1)));
}

// tambahkan Produk yang mempunyai kuantitas baru
void Toko::tambahProduk(string nama, int Price, int Quantity){
    barang.insert(pair(nama, pair(Price,Quantity)));
}

// atur harga barang
void Toko::aturHargaBarang(string nama, int Price){
    get<0>(barang.at(nama)) = Price;
}


// atur jumlah Barang yang terbatas
void Toko::aturJumlahBarang(string nama, int Quantity){
    if (barang.at(nama).first != -1){
        barang.at(nama).second = Quantity;
    } 
    
}


// cetak hal yang dapat dibeli 
// tiap jenis pemain beda yang dicetak
// pake method yang sesuai dengan current user
void Toko::CetakWalikota(){
    cout << "Selamat datang di toko!!\n";
    cout << "Berikut merupakan hal yang dapat Anda Beli\n";
    int i = 1;
    auto itr = barang.begin();
    while(itr != barang.end()){
        cout << i << itr->first << " - " << itr->second.first; 
        if ( itr->second.second != -1){
            cout << " (" << itr->second.second << ")\n";
        }
        i++;
    }
}
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
// dijamin ada ?
int Toko::getQuantity(string nama){
    return (produk.at(nama)).second;
}

// mengembalikan harga
// dijamin ada ?
int Toko::getPrice(string nama){
    if(produk.find(nama)!= produk.end()){
        return (produk.at(nama)).first;
    }else if(tanamanHewan.find(nama) != tanamanHewan.end()){
        return (tanamanHewan.at(nama));
    }
    // else{
    //     cout << "Tidak ada Produk/bangunan dengan nama tersebut.\n";
    //     return -1;
    // }
}
