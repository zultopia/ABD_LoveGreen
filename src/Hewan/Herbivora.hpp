#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

#include <iostream>

using namespace std;
#include "Hewan.hpp"

class Herbivora : public Hewan {
    public:
        // ctor
        Herbivora(string nama);
        Herbivora(string nama, int berat);

        // dtor
        ~Herbivora();

        // validator
        bool isCanEat(Produk& p) const override;
        
        // overloading
        friend ostream& operator<<(ostream& os, Herbivora hewan);

};

#endif
