#include "ProdukEatable.hpp"

// ctor
ProdukEatable::ProdukEatable() : Produk() {}
ProdukEatable::ProdukEatable(string nama) : Produk() {
    setIdProduk(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeProduk(Config::getType(nama));
    setOrigin(Config::getOrigin(nama));
    setAddedWeight(Config::getAddedWeight(nama));
    setPrice(Config::getPrice(nama));
}

// dtor
ProdukEatable::~ProdukEatable() {}

// other operations
bool ProdukEatable::eatable() const {return true;}

// overloading
ostream& operator<<(ostream& os, ProdukEatable produk) {
    os << "=+=+= PROFIL PRODUK =+=+=" << endl;
    os << "id           : " << produk.getIdProduk() << endl;
    os << "Code         : " << produk.getCode() << endl;
    os << "Name         : " << produk.getName() << endl;
    os << "type         : " << produk.getTypeProduk() << endl;
    os << "origin       : " << produk.getOrigin() << endl;
    os << "added weight : " << produk.getAddedWeight() << endl;
    os << "Price        : " << produk.getPrice() << endl;
    return os;
}