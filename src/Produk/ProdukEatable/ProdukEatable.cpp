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