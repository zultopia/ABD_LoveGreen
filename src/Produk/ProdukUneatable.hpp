#ifndef PRODUKUNEATABLE_HPP
#define PRODUKUNEATABLE_HPP

#include <iostream>
#include "Produk/Produk.hpp"

using namespace std;

class ProdukUneatable : public Produk  {
    public:
        // ctor
        ProdukUneatable();
        ProdukUneatable(string code);

        // dtor
        ~ProdukUneatable();

        // other operations
        bool eatable() const override;

        // overloading
        friend ostream& operator<<(ostream& os, ProdukUneatable produk);

};

#endif