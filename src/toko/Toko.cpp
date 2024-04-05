#include "Toko.hpp"

int Toko::jumlah = 1; 
Toko::Toko(){}

// tambahkan tanaman atau hewan baru
void Toko::tambahTanamanHewan(string kode, int Price){
    barang.insert(pair(kode, pair(Price, -1)));
}

// tambahkan Produk yang mempunyai kuantitas baru
void Toko::tambahProduk(string kode, int Price, int Quantity){
    barang.insert(pair(kode, pair(Price,Quantity)));
}

// atur harga barang
void Toko::aturHargaBarang(string kode, int Price){
    get<0>(barang.at(kode)) = Price;
}


// atur jumlah Barang yang terbatas
void Toko::aturJumlahBarang(string kode, int Quantity){
    if (barang.at(kode).first != -1){
        barang.at(kode).second = Quantity;
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
        itr++;
    }
}
void Toko::CetakPeternakPetani(){
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
        itr++;
    }
}

// Produk yang dibeli
// mengembalikan jumlah uang yang harus dibayarkan untuk membeli
int Toko::BeliWalikota(int no, int Quantity){
    int i = 1;
    auto itr = barang.begin();
    while(itr != barang.end() && i < no){
        cout << i << itr->first << " - " << itr->second.first; 
        if ( itr->second.second != -1){
            cout << " (" << itr->second.second << ")\n";
        }
        i++;
    }
}

// batal melakukan pembelian
void batalBeli(string kode, int Quantity);

// menjual ke toko
// mengembalikan jumlah uang yang akan diterima dari penjualan
int Jual(string kode, int Quantity);

// batal melakukan penjualan
void batalJual(string kode, int Quantity);

// // mengembalikan jumlah Produk yang tersedia
// // dijamin ada ?
// int Toko::getQuantity(string kode){
//     return (produk.at(kode)).second;
// }

// // mengembalikan harga
// // dijamin ada ?
// int Toko::getPrice(string kode){
//     if(produk.find(kode)!= produk.end()){
//         return (produk.at(kode)).first;
//     }else if(tanamanHewan.find(kode) != tanamanHewan.end()){
//         return (tanamanHewan.at(kode));
//     }
//     // else{
//     //     cout << "Tidak ada Produk/bangunan dengan kode tersebut.\n";
//     //     return -1;
//     // }
// }
