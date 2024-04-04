#include "Hewan.hpp"

// ctor
Hewan::Hewan() : Item(), idHewan(0), weightToHarvest(0), currentWeight(0), typeHewan("") {}
Hewan::Hewan(int id, int weightToHarvest, int price, string code, string name, string typeHewan) :
    Item(price, code, name) {
    setIdHewan(id);
    setWeightToHarvest(weightToHarvest);
    setCurrentWeight(0);
    setTypeHewan(typeHewan);
}
Hewan::Hewan(Config& config, string code) {
    tuple<int, string, string, string, int, int> item = config.getFromFarm(code);
    int id = std::get<0>(item);
    string name = std::get<2>(item);
    string type = std::get<3>(item);
    int weightToHarvest = std::get<4>(item);
    int price = std::get<5>(item);
    setIdHewan(id);
    setWeightToHarvest(weightToHarvest);
    setCurrentWeight(0);
    setTypeHewan(type);
    setPrice(price);
    setCode(code);
    setName(name);
}

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
    if (isCanEat(p)) {
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

Produk Hewan::harvest(Config& config) {
    tuple<int, string, string, string, string, int, int> item = config.getFromProduk(getName());
    int id = std::get<0>(item);
    string code = std::get<1>(item);
    string name = std::get<2>(item);
    string type = std::get<3>(item);
    string origin = std::get<4>(item);
    int addedWeight = std::get<5>(item);
    int price = std::get<6>(item);
    Produk result(id, addedWeight, price, code, name, origin, type);
    return result;
}

void Hewan::print() {
    cout << "id                   : " << getIdHewan() << endl;
    cout << "code                 : " << getCode() << endl;
    cout << "name                 : " << getName() << endl;
    cout << "type                 : " << getTypeHewan() << endl;
    cout << "current weight       : " << getCurrentWeight() << endl;
    cout << "weight to harvest    : " << getWeightToHarvest() << endl;
    cout << "price                : " << getPrice() << endl;
}