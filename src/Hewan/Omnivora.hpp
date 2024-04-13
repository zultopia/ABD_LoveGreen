#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

#include "Hewan.hpp"
#include <iostream>

using namespace std;

class Omnivora : public Hewan {
    public:
        // ctor
        Omnivora(string nama);
        Omnivora(string nama, int berat);

        // dtor
        ~Omnivora();

        // validator
        bool isCanEat(Produk& p) const override;

        // overloading
        friend ostream& operator<<(ostream& os, Omnivora hewan);

};

#endif
