#include "Hewan.hpp"
#include "../Exception/HewanException.hpp"
#include "../Item/Item.hpp"
#include "../Produk/Produk.hpp"
#include "../Config/Config.hpp"

// ctor
Hewan::Hewan() : Item(), idHewan(0), weightToHarvest(0), currentWeight(0), typeHewan("") {}
Hewan::Hewan(int currentWeight) : Item(), idHewan(0), weightToHarvest(0), currentWeight(currentWeight), typeHewan("") {}

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
