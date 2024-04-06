#include "Herbivora.hpp"

Herbivora::Herbivora(string code) : Hewan() {
    setIdHewan(Config::getId(code));
    setCode(code);
    setName(Config::getNama(code));
    setTypeHewan(Config::getType(code));
    setWeightToHarvest(Config::getWeightHarvest(code));
    setPrice(Config::getPrice(code));
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