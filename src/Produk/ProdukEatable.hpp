#ifndef PRODUKEATABLE_HPP
#define PRODUKEATABLE_HPP

#include <iostream>
#include "Produk/Produk.hpp"

using namespace std;

class ProdukEatable : public Produk  {
    public:
        // ctor
        ProdukEatable();
        ProdukEatable(string code);

        // dtor
        ~ProdukEatable();

        // other operations
        bool eatable() const override;

        // overloading
        friend ostream& operator<<(ostream& os, ProdukEatable produk);
        
};

#endif