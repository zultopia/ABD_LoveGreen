#include "Toko.hpp"
#include "../Config/Config.hpp"
#include "../Config/SimpanMuat.hpp"
#include "../Exception/TokoException.hpp"

map<string,pair<int,int>> Toko::barang;
vector<string> Toko::urutan;

Toko::Toko(){}
void Toko::setUpToko(){
    const map<string,tuple<int,string,string,int,int>> plant = Config::getPlantMap();
    const map<string,tuple<int,string,string,int,int>> animal = Config::getAnimalMap();
    const map<string,tuple<int,string,string,string,int,int>> product = Config::getProductMap();
    const map<string,tuple<int,string,int,map<string,int>>> recipe = Config::getRecipeMap();
    for(auto i = plant.begin(); i != plant.end(); i++){
        tambahTanamanHewan(i->first,Config::getPrice(i->first));
    }
    for(auto i = animal.begin(); i != animal.end(); i++){
        tambahTanamanHewan(i->first,Config::getPrice(i->first));
    }
    for(auto i = product.begin(); i != product.end(); i++){
        tambahProduk(i->first,Config::getPrice(i->first), 0);
    }
    for(auto i = recipe.begin(); i != recipe.end(); i++){
        tambahProduk(i->first,Config::getPrice(i->first), 0);
    }
}

void Toko::setUpTokoMuat(){
    setUpToko();
    const map<string,int> temp = SimpanMuat::getToko();
    for(auto i = temp.begin(); i != temp.end(); i++){
        aturJumlahBarang(i->first, i->second);
    }

}

// tambahkan tanaman atau hewan baru
void Toko::tambahTanamanHewan(string nama, int Price){
    barang.insert(make_pair(nama, make_pair(Price, -1)));
    urutan.push_back(nama);
}

// tambahkan Produk yang mempunyai kuantitas baru
void Toko::tambahProduk(string nama, int Price, int Quantity){
    barang.insert(make_pair(nama, make_pair(Price,Quantity)));
    urutan.push_back(nama);
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
// mengembalikan jumlah item yang muncul
int Toko::CetakWalikota(){
    cout << "Selamat datang di toko!!\n";
    cout << "Berikut merupakan hal yang dapat Anda Beli\n";
    int i = 1;
    for(int j = 0; j < urutan.size(); j++){
        if(!Config::isExistRecipe(urutan[j]) && barang.at(urutan[j]).second != 0){
            cout << i << ". " << urutan[j] << " - " << barang.at(urutan[j]).first;
            if(barang.at(urutan[j]).second != -1){
                cout << " (" << barang.at(urutan[j]).second << ")\n";
            }else{
                cout << endl;
            }
            i++;
        }
        
    }
    return i;
}

// mengembalikan jumlah item yang muncul
int Toko::CetakPeternakPetani(){
    cout << "Selamat datang di toko!!\n";
    cout << "Berikut merupakan hal yang dapat Anda Beli\n";
    int i = 1;
    for(int j = 0; j < urutan.size(); j++){
        if(barang.at(urutan[j]).second != 0){
            cout << i << ". " << urutan[j] << " - " << barang.at(urutan[j]).first;
            if(barang.at(urutan[j]).second != -1){
                cout << " (" << barang.at(urutan[j]).second << ")\n";
            }else{
                cout << endl;
            }
            i++;
        }
        
    }
    cout << endl;
    return i;
}

// Produk yang dibeli
// mengembalikan jumlah uang yang harus dibayarkan untuk membeli
pair<string,int> Toko::BeliWalikota(int no, int Quantity){
    int i = 0;
    auto itr = urutan.begin();
    while(itr != urutan.end() && i < no){
        if(!Config::isExistRecipe(*itr) && barang.at(*itr).second != 0){
            i++;
        }
        itr++;
    }
    itr--;
    if(i != no){
        InvalidNumberTokoException e;
        throw e;
    }
    // itr = barang yang ditunjuk oleh no
    cout << (*itr) << " " << barang.at(*itr).second << endl;
    if(barang.at(*itr).second != -1){
        if(barang.at(*itr).second < Quantity){
            InvalidQuantityTokoException e;
            throw e;
        }
        barang.at(*itr).second -= Quantity;
    }
    // harga * quantity
    return make_pair((*itr),barang.at(*itr).first*Quantity);
}
pair<string,int> Toko::BeliPeternakPetani(int no, int Quantity){
    int i = 0;
    auto itr = urutan.begin();
    while(itr != urutan.end() && i < no){
        if(barang.at(*itr).second != 0){
            i++;
        }
        itr++;
    }
    itr--;
    if(i != no){
        InvalidNumberTokoException e;
        throw e;
    }
    // itr = barang yang ditunjuk oleh no
    if(barang.at(*itr).second != -1){
        if(barang.at(*itr).second < Quantity){
            InvalidQuantityTokoException e;
            throw e;
        }
        barang.at(*itr).second -= Quantity;
    }
    return make_pair((*itr),barang.at(*itr).first*Quantity);
}

// batal melakukan pembelian
void Toko::batalBeli(string nama, int Quantity){
    if(barang.at(nama).second != -1){
        (barang.at(nama)).second += Quantity;
    }
}



// menjual ke toko
// mengembalikan jumlah uang yang akan diterima dari penjualan
int Toko::Jual(string nama, int Quantity){
    if(barang.at(nama).second != -1){
        (barang.at(nama)).second += Quantity;
    }
    return barang.at(nama).first * Quantity;
}

// batal melakukan penjualan
void Toko::batalJual(string nama, int Quantity){
    if(barang.at(nama).second != -1){
        (barang.at(nama)).second -= Quantity;
    }
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
map<string,pair<int,int>>& Toko::getBarang(){
    return barang;
}
vector<string>& Toko::getUrutan(){
    return urutan;
}
map<string,int> Toko::getIsiToko(){
    map<string,int> temp;
    for(auto i = urutan.begin(); i != urutan.end(); i++){
        if(barang[*i].second != -1){
            temp[*i] = barang[*i].second;
        }
    }
    return temp;
}

void Toko::displayIsiToko(){
    int jumlah = urutan.size();
    int urut = 1;
    cout << "namaBarang | Harga | Jumlah " << endl;
    for(auto i = urutan.begin(); i != urutan.end(); i++){
        cout << urut << ". " << *i << " " << barang.at(*i).first << " ";
        if(barang.at(*i).second == -1){
            cout << "infinite" << endl;
        }else{
            cout << barang.at(*i).second << endl;
        }
        urut++;
    }
    cout << "Jumlah daftar item di Toko ada " << jumlah << " buah" << endl;
}