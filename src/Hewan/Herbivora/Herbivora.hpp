#ifndef HERBIVORA_HPP
#define HERBIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Herbivora : public Hewan {
    public:
        Herbivora(int id, int weight_to_harvest, int price, string code, string name);
        ~Herbivora();
        bool isCanEat(Produk p) const override;
};

#endif
