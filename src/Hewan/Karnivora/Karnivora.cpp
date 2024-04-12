#include "Karnivora.hpp"

Karnivora::Karnivora(string nama) : Hewan() {
    setIdHewan(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeHewan(Config::getType(nama));
    setWeightToHarvest(Config::getWeightHarvest(nama));
    setPrice(Config::getPrice(nama));
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