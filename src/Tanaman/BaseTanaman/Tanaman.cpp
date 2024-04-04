#include "Tanaman.hpp"

// ctor
Tanaman::Tanaman() : Item(), idTanaman(0), durationToHarvest(0), currentDuration(0), typeTanaman("") {}
Tanaman::Tanaman(int id, int durationToHarvest, int price, string code, string name, string type) :
    Item(price, code, name) {
    setIdTanaman(id);
    setDurationToHarvest(durationToHarvest);
    setCurrentDuration(0);
    setTypeTanaman(type);
}
Tanaman::Tanaman(Config& config, string code) {
    tuple<int, string, string, string, int, int> item = config.getFromFarm(code);
    int id = std::get<0>(item);
    string name = std::get<2>(item);
    string type = std::get<3>(item);
    int durationToHarvest = std::get<4>(item);
    int price = std::get<5>(item);
    setIdTanaman(id);
    setDurationToHarvest(durationToHarvest);
    setCurrentDuration(0);
    setTypeTanaman(type);
    setPrice(price);
    setCode(code);
    setName(name);
}

Tanaman::~Tanaman() {}

int Tanaman::getIdTanaman() const {return idTanaman;}
int Tanaman::getDurationToHarvest() const {return durationToHarvest;}
int Tanaman::getCurrentDuration() const {return currentDuration;}
string Tanaman::getTypeTanaman() const {return typeTanaman;}

void Tanaman::setIdTanaman(int id) {this->idTanaman = id;}
void Tanaman::setDurationToHarvest(int duration) {this->durationToHarvest = duration;}
void Tanaman::setCurrentDuration(int duration) {this->currentDuration = duration;}
void Tanaman::setTypeTanaman(string type) {this->typeTanaman = type;}

bool Tanaman::eatable() const {return false;}

void Tanaman::addDuration() {
    currentDuration++;
}

bool Tanaman::isHarvest() const {
    if (getCurrentDuration() >= getDurationToHarvest()) {
        return true;
    } else {
        return false;
    }
}

Produk Tanaman::harvest(Config& config) {
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

void Tanaman::print() {
    cout << "id                     : " << getIdTanaman() << endl;
    cout << "code                   : " << getCode() << endl;
    cout << "name                   : " << getName() << endl;
    cout << "type                   : " << getTypeTanaman() << endl;
    cout << "current duration       : " << getCurrentDuration() << endl;
    cout << "duration to harvest    : " << getDurationToHarvest() << endl;
    cout << "price                  : " << getPrice() << endl;
}