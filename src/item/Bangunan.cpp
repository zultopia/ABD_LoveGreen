#include "Bangunan.hpp"

// Constructor default
Bangunan::Bangunan() : id(0), price(0) {}

// Constructor dengan parameter
Bangunan::Bangunan(int id, int price, string code, string name, const vector<pair<string, int> >& materials)
    : id(id), price(price), code(code), name(name), materials(materials) {}

// Destructor
Bangunan::~Bangunan() {}

// Getter untuk id
int Bangunan::getId() {
    return id;
}

// Getter untuk price
int Bangunan::getPrice() {
    return price;
}

// Getter untuk code
string Bangunan::getCode() {
    return code;
}

// Getter untuk name
string Bangunan::getName() {
    return name;
}

// Getter untuk materials
vector<pair<string, int> > Bangunan::getMaterials() {
    return materials;
}

// Setter untuk id
void Bangunan::setId(int id) {
    this->id = id;
}

// Setter untuk price
void Bangunan::setPrice(int price) {
    this->price = price;
}

// Setter untuk code
void Bangunan::setCode(string code) {
    this->code = code;
}

// Setter untuk name
void Bangunan::setName(string name) {
    this->name = name;
}

// Setter untuk materials
void Bangunan::setMaterials(const vector<pair<string, int> >& materials) {
    this->materials = materials;
}

// Operator overloading untuk ostream
ostream& operator<<(ostream& os, Bangunan& bangunan) {
    os << "ID: " << bangunan.getId() << endl;
    os << "Code: " << bangunan.getCode() << endl;
    os << "Name: " << bangunan.getName() << endl;
    os << "Price: " << bangunan.getPrice() << endl;
    os << "Materials:" << endl;
    for (const pair<string, int>& material : bangunan.getMaterials()) {
        os << "- " << material.first << ": " << material.second << endl;
    }
    return os;
}