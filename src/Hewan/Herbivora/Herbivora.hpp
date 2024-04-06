#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Herbivora : public Hewan {
    public:
        // ctor
        Herbivora(string code);

        // dtor
        ~Herbivora();

        // validator
        bool isCanEat(Produk& p) const override;
};

#endif
