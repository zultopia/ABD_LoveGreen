#include "ProdukUneatable.hpp"

// ctor
ProdukUneatable::ProdukUneatable() : Produk() {}
ProdukUneatable::ProdukUneatable(string code) : Produk() {
    setIdProduk(Config::getId(code));
    setCode(code);
    setName(Config::getNama(code));
    setTypeProduk(Config::getType(code));
    setOrigin(Config::getOrigin(code));
    setAddedWeight(Config::getAddedWeight(code));
    setPrice(Config::getPrice(code));
}

// dtor
ProdukUneatable::~ProdukUneatable() {}

// other operations
bool ProdukUneatable::eatable() const {return true;}