#include "Karnivora.hpp"

Karnivora::Karnivora(string code) : Hewan() {
    setIdHewan(Config::getId(code));
    setCode(code);
    setName(Config::getNama(code));
    setTypeHewan(Config::getType(code));
    setWeightToHarvest(Config::getWeightHarvest(code));
    setPrice(Config::getPrice(code));
}

Karnivora::~Karnivora() {}

bool Karnivora::isCanEat(Produk& p) const {
    if (p.eatable()) {
        if (p.getTypeProduk() == "PRODUCT_ANIMAL")  {
            return true;
        }
    }
    return false;
}