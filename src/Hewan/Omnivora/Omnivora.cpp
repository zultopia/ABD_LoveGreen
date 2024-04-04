#include "Omnivora.hpp"

Omnivora::Omnivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "OMNIVORE") {}

Omnivora::~Omnivora() {}

bool Omnivora::isCanEat(Produk p) const {
    cout << "Omnivora bisa makan?" << endl;
    if (p.getType() == "PRODUCT_ANIMAL") return true;
    return false;    
}