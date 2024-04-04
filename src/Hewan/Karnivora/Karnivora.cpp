#include "Karnivora.hpp"

Karnivora::Karnivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "CARNIVORE") {}

Karnivora::~Karnivora() {}

bool Karnivora::isCanEat(Produk p) const {
    cout << "Karnivora bisa makan" << endl;
    if (p.getType() == "PRODUCT_ANIMAL") return true;
    return false;    
}