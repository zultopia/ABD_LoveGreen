#include "Bangunan.hpp"

// Constructor
Bangunan::Bangunan() {}

Bangunan::Bangunan(int id, Item* item, const vector<pair<string, int> >& materials)
    : id(id), item(item), materials(materials) {}

// Destructor
Bangunan::~Bangunan() {
    delete item; 
}

// Getter
int Bangunan::getId() {
    return id;
}

Item* Bangunan::getItem() {
    return item;
}

vector<pair<string, int> > Bangunan::getMaterials() {
    return materials;
}

// Setter
void Bangunan::setId(int id) {
    this->id = id;
}

void Bangunan::setItem(Item* item) {
    this->item = item;
}

void Bangunan::setMaterials(const vector<pair<string, int> >& materials) {
    this->materials = materials;
}

// Operator overloading untuk ostream
ostream& operator<<(ostream& os, Bangunan& bangunan) {
    os << "ID: " << bangunan.id << endl;
    os << "Item: " << bangunan.item->getName() << endl; // Akses nama item menggunakan pointer
    os << "Materials:" << endl;
    for (const auto& material : bangunan.materials) {
        os << material.first << " - " << material.second << endl;
    }
    return os;
}