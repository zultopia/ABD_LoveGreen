#include "Herbivora.hpp"

Herbivora::Herbivora(string nama) : Hewan() {
    setIdHewan(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeHewan(Config::getType(nama));
    setWeightToHarvest(Config::getWeightHarvest(nama));
    setPrice(Config::getPrice(nama));
}

Herbivora::Herbivora(string nama, int berat) : Hewan(berat) {
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

// overloading
ostream& operator<<(ostream& os, Herbivora hewan) {
    os << "=+=+= PROFIL HEWAN =+=+=" << endl;
    os << "id                   : " << hewan.getIdHewan() << endl;
    os << "code                 : " << hewan.getCode() << endl;
    os << "name                 : " << hewan.getName() << endl;
    os << "type                 : " << hewan.getTypeHewan() << endl;
    os << "current weight       : " << hewan.getCurrentWeight() << endl;
    os << "weight to harvest    : " << hewan.getWeightToHarvest() << endl;
    os << "price                : " << hewan.getPrice() << endl;
    return os;
}