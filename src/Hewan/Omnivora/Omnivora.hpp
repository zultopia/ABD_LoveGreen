#ifndef OMNIVORA_HPP
#define OMNIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Omnivora : public Hewan {
    public:
        Omnivora(int id, int weight_to_harvest, int price, string code, string name);
        ~Omnivora();
        bool isCanEat(Produk p) const override;
};

#endif
