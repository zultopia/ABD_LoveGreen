#include "ProdukUneatable.hpp"

// ctor
ProdukUneatable::ProdukUneatable() : Produk() {}
ProdukUneatable::ProdukUneatable(string nama) : Produk() {
    setIdProduk(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeProduk(Config::getType(nama));
    setOrigin(Config::getOrigin(nama));
    setAddedWeight(Config::getAddedWeight(nama));
    setPrice(Config::getPrice(nama));
}

// dtor
ProdukUneatable::~ProdukUneatable() {}

// other operations
bool ProdukUneatable::eatable() const {return true;}