#include "Hewan.hpp"

// ctor
Hewan::Hewan() {}
Hewan::Hewan(int id, int weightToHarvest, int price, string code, string name, string type) {
    setId(id);
    setWeightToHarvest(weightToHarvest);
    setPrice(price);
    setCurrentWeight(0);
    setCode(code);
    setName(name);
    setType(type);
}

// dtor
Hewan::~Hewan() {}

// getter
int Hewan::getId() const {return id;}
int Hewan::getWeightToHarvest() const {return weightToHarvest;}
int Hewan::getPrice() const {return price;}
int Hewan::getCurrentWeight() const {return currentWeight;}
string Hewan::getCode() const {return code;}
string Hewan::getName() const {return name;}
string Hewan::getType() const {return type;}

// setter
void Hewan::setId(int id) {this->id = id;}
void Hewan::setWeightToHarvest(int weight) {this->weightToHarvest = weight;}
void Hewan::setPrice(int price) {this->price = price;}
void Hewan::setCurrentWeight(int weight) {this->currentWeight = weight;}
void Hewan::setCode(string code) {this->code = code;}
void Hewan::setName(string name) {this->name = name;}
void Hewan::setType(string type) {this->type = type;}

// other operations
bool Hewan::isCanEat(Produk p) const {return false;}

void Hewan::eat(Produk p) {
    if (isCanEat(p)) setCurrentWeight(getCurrentWeight() + p.getAddedWeight());
    cout << "nyam nyam nyam" << endl;
}

bool Hewan::isHarvest() const {
    if (getCurrentWeight() >= getWeightToHarvest()) return true;
    return false;
}

Produk Hewan::harvest() {
    ConfigProduk cp;
    Produk result = cp.findProduk(code);
    return result;
}

ostream& operator<<(ostream& os, Hewan& hewan) {
    os << "id: " << hewan.getId() << endl;
    os << "code: " << hewan.getCode() << endl;
    os << "name: " << hewan.getName() << endl;
    os << "type: " << hewan.getType() << endl;
    os << "current weight: " << hewan.getCurrentWeight() << endl;
    os << "weight to harvest: " << hewan.getWeightToHarvest() << endl;
    os << "price: " << hewan.getPrice() << endl;
    return os;
}