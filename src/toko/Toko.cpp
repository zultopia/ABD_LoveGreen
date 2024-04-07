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
        // jika tidak ada di recipe bangunan
        if(!Config::isExistRecipe(itr->first) && itr->second.second != 0){
            cout << i << itr->first << " - " << itr->second.first; 
            if ( itr->second.second != -1){
                cout << " (" << itr->second.second << ")\n";
            }
            i++;
        }
        itr++;
    }
}
void Toko::CetakPeternakPetani(){
    cout << "Selamat datang di toko!!\n";
    cout << "Berikut merupakan hal yang dapat Anda Beli\n";
    int i = 1;
    auto itr = barang.begin();
    while(itr != barang.end() && itr->second.second != 0){
        cout << i << itr->first << " - " << itr->second.first; 
        if ( itr->second.second != -1){
            cout << " (" << itr->second.second << ")\n";
        }
        i++;
        itr++;
    }
}

void Toko::Cetak(){
    // if(typeid(CurrPemain) == typeid(Walikota)){
    //     CetakWalikota(no,Quantity);
    // }else{
    //     CetakPeternakPetani(no,Quantity);
    // }
}

// Produk yang dibeli
// mengembalikan jumlah uang yang harus dibayarkan untuk membeli
int Toko::BeliWalikota(int no, int Quantity){
    int i = 1;
    auto itr = barang.begin();
    while(itr != barang.end() && i < no){
        if(!Config::isExistRecipe(itr->first) && itr->second.second != 0){
            i++;
        }
        itr++;
    }
    // itr = barang yang ditunjuk oleh no
    itr->second.second--;
    return itr->second.first*Quantity;
}

int Toko::Beli(int no, int Quantity){
    // if(typeid(CurrPemain) == typeid(Walikota)){
    //     BeliWalikota(no,Quantity);
    // }else{
    //     BeliPeternakPetani(no,Quantity);
    // }
}


// batal melakukan pembelian
void Toko::batalBeli(string nama, int Quantity){
    (barang.at(nama)).second += Quantity;
}

// menjual ke toko
// mengembalikan jumlah uang yang akan diterima dari penjualan
int Toko::Jual(string nama, int Quantity){
    barang.at(nama).second += Quantity;
    return barang.at(nama).first * Quantity;
}

// batal melakukan penjualan
void Toko::batalJual(string nama, int Quantity){
    barang.at(nama).second -= Quantity;
}

// mengembalikan jumlah Produk yang tersedia
// dijamin ada 
// -1 berati infinite
int Toko::getQuantity(string nama){
    return (barang.at(nama)).second;
}

// mengembalikan harga
// dijamin ada 
int Toko::getPrice(string nama){
    return barang.at(nama).first;
}
