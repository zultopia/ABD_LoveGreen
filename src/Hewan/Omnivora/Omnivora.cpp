#include "Omnivora.hpp"

Omnivora::Omnivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "OMNIVORE") {}

Omnivora::~Omnivora() {}

bool Omnivora::isCanEat(Produk& p) const {
    if (p.getTypeProduk() == "PRODUCT_ANIMAL") {
        cout << "Herbivora bisa makan brou" << endl;
        return true;
    } else {
        cout << "ga bisa makan itu" << endl;
        return false;
    }  
}