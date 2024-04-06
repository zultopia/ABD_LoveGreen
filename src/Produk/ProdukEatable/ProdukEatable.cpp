#include "ProdukEatable.hpp"

// ctor
ProdukEatable::ProdukEatable() : Produk() {}
ProdukEatable::ProdukEatable(string code) : Produk() {
    setIdProduk(Config::getId(code));
    setCode(code);
    setName(Config::getNama(code));
    setTypeProduk(Config::getType(code));
    setOrigin(Config::getOrigin(code));
    setAddedWeight(Config::getAddedWeight(code));
    setPrice(Config::getPrice(code));
}

// dtor
ProdukEatable::~ProdukEatable() {}

// other operations
bool ProdukEatable::eatable() const {return true;}