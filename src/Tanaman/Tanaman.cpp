#include "Tanaman.hpp"
#include "../Item/Item.hpp"
#include "../Produk/Produk.hpp"
#include "../Config/Config.hpp"
// ctor
Tanaman::Tanaman() : Item(), idTanaman(0), durationToHarvest(0), currentDuration(0), typeTanaman("") {}
Tanaman::Tanaman(string nama) {
    setIdTanaman(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeTanaman(Config::getType(nama));
    setDurationToHarvest(Config::getDuration(nama));
    setCurrentDuration(0);
    setPrice(Config::getPrice(nama));
}

Tanaman::Tanaman(string nama, int currentDuration) {
    this->currentDuration = currentDuration;
    setIdTanaman(Config::getId(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    setTypeTanaman(Config::getType(nama));
    setDurationToHarvest(Config::getDuration(nama));
    setPrice(Config::getPrice(nama));
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

ostream& operator<<(ostream& os, Tanaman tanaman) {
    os << "=+=+= PROFIL PRODUK =+=+=" << endl;
    os << "id                     : " << tanaman.getIdTanaman() << endl;
    os << "code                   : " << tanaman.getCode() << endl;
    os << "name                   : " << tanaman.getName() << endl;
    os << "type                   : " << tanaman.getTypeTanaman() << endl;
    os << "current duration       : " << tanaman.getCurrentDuration() << endl;
    os << "duration to harvest    : " << tanaman.getDurationToHarvest() << endl;
    os << "price                  : " << tanaman.getPrice() << endl;
    return os;
}