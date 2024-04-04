#include "ProdukUneatable.hpp"

// ctor
ProdukUneatable::ProdukUneatable() : Produk() {}
ProdukUneatable::ProdukUneatable(int id, int addedWeight, int price, string code, string name, string origin, string type) :
    Produk(id, addedWeight, price, code, name, origin, type) {}

// dtor
ProdukUneatable::~ProdukUneatable() {}

// other operations
bool ProdukUneatable::eatable() const {return true;}