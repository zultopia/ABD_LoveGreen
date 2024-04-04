#ifndef KARNIVORA_HPP
#define KARNIVORA_HPP

#include "../BaseHewan/Hewan.hpp"
#include <iostream>

using namespace std;

class Karnivora : public Hewan {
    public:
        Karnivora(int id, int weight_to_harvest, int price, string code, string name);
        ~Karnivora();
        bool isCanEat(Produk p) const override;
};

#endif
