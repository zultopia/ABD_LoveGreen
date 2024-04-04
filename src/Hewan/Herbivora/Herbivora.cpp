#include "Herbivora.hpp"

Herbivora::Herbivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "HERBIVORE") {}

Herbivora::~Herbivora() {}

bool Herbivora::isCanEat(Produk p) const {
    cout << "Herbivora bisa makan?" << endl;
    if (p.getType() == "PRODUCT_FRUIT_PLANT") return true;
    return false;    
}