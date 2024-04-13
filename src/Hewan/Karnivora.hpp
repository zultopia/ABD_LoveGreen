#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

#include "Hewan.hpp"
#include <iostream>

using namespace std;

class Karnivora : public Hewan {
    public:
        // ctor
        Karnivora(string nama);
        Karnivora(string nama, int berat);

        // dtor
        ~Karnivora();

        // validator
        bool isCanEat(Produk& p) const override;

        // overloading
        friend ostream& operator<<(ostream& os, Karnivora hewan);
        
};

#endif
