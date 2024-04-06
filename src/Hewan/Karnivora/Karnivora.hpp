#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Karnivora : public Hewan {
    public:
        Karnivora(string code);
        ~Karnivora();
        bool isCanEat(Produk& p) const override;
};

#endif
