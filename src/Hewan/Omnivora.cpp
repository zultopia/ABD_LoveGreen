#include "Omnivora.hpp"
#include "../Item/Item.hpp"
#include "../Config/Config.hpp"
#include "../Produk/Produk.hpp"

Omnivora::Omnivora(string nama) : Hewan() {
    setIdHewan(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeHewan(Config::getType(nama));
    setWeightToHarvest(Config::getWeightHarvest(nama));
    setPrice(Config::getPrice(nama));
}

Omnivora::Omnivora(string nama, int berat) : Hewan(berat) {
    setIdHewan(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeHewan(Config::getType(nama));
    setWeightToHarvest(Config::getWeightHarvest(nama));
    setPrice(Config::getPrice(nama));
}

Omnivora::~Omnivora() {}

bool Omnivora::isCanEat(Produk& p) const {
    if (p.eatable()) {
        if (p.getTypeProduk() == "PRODUCT_MATERIAL_PLANT") {
            return false;
        }
    }
    return true;
}

// overloading
ostream& operator<<(ostream& os, Omnivora hewan) {
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