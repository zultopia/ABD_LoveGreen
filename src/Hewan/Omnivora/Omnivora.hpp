#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Omnivora : public Hewan {
    public:
        Omnivora(string code);
        ~Omnivora();
        bool isCanEat(Produk& p) const override;
};

#endif
