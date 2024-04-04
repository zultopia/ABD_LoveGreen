#ifndef PRODUKEATABLE_HPP
#define PRODUKEATABLE_HPP

#include <iostream>
#include "../BaseProduk/Produk.hpp"

using namespace std;

class ProdukEatable : public Produk  {
    public:
        // ctor
        ProdukEatable();
        ProdukEatable(int id, int added_weight, int price, string code, string name, string origin, string type);

        // dtor
        ~ProdukEatable();

        // other operations
        bool eatable() const override;
};

#endif