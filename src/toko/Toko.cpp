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
void Toko::batalBeli(string kode, int Quantity){
    (barang.at(kode)).second += Quantity;
}

// menjual ke toko
// mengembalikan jumlah uang yang akan diterima dari penjualan
int Toko::Jual(string kode, int Quantity){
    barang.at(kode).second += Quantity;
    return barang.at(kode).first * Quantity;
}

// batal melakukan penjualan
void Toko::batalJual(string kode, int Quantity){
    barang.at(kode).second -= Quantity;
}

// mengembalikan jumlah Produk yang tersedia
// dijamin ada 
// -1 berati infinite
int Toko::getQuantity(string kode){
    return (barang.at(kode)).second;
}

// mengembalikan harga
// dijamin ada 
int Toko::getPrice(string kode){
    return barang.at(kode).first;
}
