#ifndef PRODUKUNEATABLE_HPP
#define PRODUKUNEATABLE_HPP

#include <iostream>
#include "../BaseProduk/Produk.hpp"

using namespace std;

class ProdukUneatable : public Produk  {
    public:
        // ctor
        ProdukUneatable();
        ProdukUneatable(int id, int added_weight, int price, string code, string name, string origin, string type);

        // dtor
        ~ProdukUneatable();

        // other operations
        bool eatable() const override;
};

#endif