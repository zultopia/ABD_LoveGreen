#include "Hewan.hpp"

// ctor
Hewan::Hewan() : Item(), idHewan(0), weightToHarvest(0), currentWeight(0), typeHewan("") {}

// dtor
Hewan::~Hewan() {}

// getter
int Hewan::getIdHewan() const {return idHewan;}
int Hewan::getWeightToHarvest() const {return weightToHarvest;}
int Hewan::getCurrentWeight() const {return currentWeight;}
string Hewan::getTypeHewan() const {return typeHewan;}

// setter
void Hewan::setIdHewan(int id) {this->idHewan = id;}
void Hewan::setWeightToHarvest(int weight) {this->weightToHarvest = weight;}
void Hewan::setCurrentWeight(int weight) {this->currentWeight = weight;}
void Hewan::setTypeHewan(string typeHewan) {this->typeHewan = typeHewan;}

// other operations
bool Hewan::eatable() const {return false;} // masih belum jadi produk ga bisa dimakan

bool Hewan::isCanEat(Produk& p) const {return false;} // masih ga bisa makan belum tergolong herb, omn, karn

void Hewan::eat(Produk& p) {
    if (!isCanEat(p)) {
        throw InvalidEatingException(getName(), p.getName());
    } else {
        setCurrentWeight(getCurrentWeight() + p.getAddedWeight());
        cout << getName() << " sudah diberi makan dan beratnya menjadi " << getCurrentWeight() << endl;
    }
}

bool Hewan::isHarvest() const {
    if (getCurrentWeight() >= getWeightToHarvest()) {
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, Hewan hewan) {
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