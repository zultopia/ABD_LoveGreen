#include "Herbivora.hpp"

Herbivora::Herbivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "HERBIVORE") {}

Herbivora::~Herbivora() {}

bool Herbivora::isCanEat(Produk& p) const {
    if (p.getTypeProduk() == "PRODUCT_FRUIT_PLANT") {\
        cout << "Herbivora bisa makan brou" << endl;
        return true;
    } else {
        cout << "ga bisa makan itu" << endl;
        return false;
    }  
}