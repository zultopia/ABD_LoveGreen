#include "Toko.hpp"

Toko::Toko(){}

// tambahkan tanaman atau hewan baru
void Toko::tambahTanamanHewan(string nama, int Price){
    tanamanHewan.insert(pair(nama, Price));
}

// tambah harga tanaman atau hewan
void Toko::aturHargaTanamanHewan(string nama, int Price){
    tanamanHewan.at(nama) = Price;
}

// tambahkan Produk baru
void Toko::tambahProduk(string nama, int Price, int Quantity){
    produk.insert(pair(nama, pair(Price,Quantity)));
}

// atur jumlah Produk
void Toko::aturJumlahProduk(string nama, int Quantity){
    produk.at(nama).second = Quantity;
}

// atur harga Produk
void Toko::aturHargaProduk(string nama, int Price){
    produk.at(nama).first = Price;
}

// tambahkan Bangunan baru
void Toko::tambahBangunan(string nama, int Price, int Quantity){
    bangunan.insert(pair(nama, pair(Price,Quantity)));
}

// atur jumlah Bangunan
void Toko::aturJumlahBangunan(string nama, int Quantity){
    bangunan.at(nama).second = Quantity;
}

// atur harga Bangunan
void Toko::aturHargaBangunan(string nama, int Price){
    bangunan.at(nama).first = Price;
}

// cetak hal yang dapat dibeli 
// tiap jenis pemain beda yang dicetak
// pake method yang sesuai dengan current user
void Toko::CetakWalikota(){
    cout << "Selamat datang di toko!!\n";
    cout << "Berikut merupakan hal yang dapat Anda Beli\n";
    int i = 0;
    auto itr = tanamanHewan.begin();
    while(itr != tanamanHewan.end()){
        cout << i << ". " << itr->first << " - " << itr->second << endl;
        itr++;
        i++;
    }
    auto itr2 = produk.begin();
    while(itr2 != produk.end()){
        cout << i << ". " << itr2->first << " - " << itr2->second.first << " (" << itr2->second.second << ")\n";
        itr2++;
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
