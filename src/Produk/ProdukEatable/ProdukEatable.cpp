#include "ProdukEatable.hpp"

// ctor
ProdukEatable::ProdukEatable() : Produk() {}
ProdukEatable::ProdukEatable(int id, int addedWeight, int price, string code, string name, string origin, string type) :
    Produk(id, addedWeight, price, code, name, origin, type) {}

// dtor
ProdukEatable::~ProdukEatable() {}

// other operations
bool ProdukEatable::eatable() const {return true;}