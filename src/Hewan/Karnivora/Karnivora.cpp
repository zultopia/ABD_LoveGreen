#include "Karnivora.hpp"

Karnivora::Karnivora(int id, int weigth_to_harvest, int price, string code, string name) : 
    Hewan(id, weigth_to_harvest, price, code, name, "CARNIVORE") {}

Karnivora::~Karnivora() {}

bool Karnivora::isCanEat(Produk& p) const {
    if (p.getTypeProduk() == "PRODUCT_ANIMAL")  {
        cout << "Herbivora bisa makan brou" << endl;
        return true;
    } else {
        cout << "ga bisa makan itu" << endl;
        return false;
    }  
}