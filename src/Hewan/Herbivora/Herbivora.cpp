#include "Herbivora.hpp"

Herbivora::Herbivora(string nama) : Hewan() {
    setIdHewan(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeHewan(Config::getType(nama));
    setWeightToHarvest(Config::getWeightHarvest(nama));
    setPrice(Config::getPrice(nama));
}

Herbivora::~Herbivora() {}

bool Herbivora::isCanEat(Produk& p) const {
    if (p.eatable()) {
        if (p.getTypeProduk() == "PRODUCT_FRUIT_PLANT") {
            return true;
        }
    }
    return false;
}