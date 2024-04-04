#include "Produk.hpp"

// ctor
Produk::Produk() : id(0), added_weight(0), price(0), code(""), name(""), origin(""), type("") {}
Produk::Produk(int id, int added_weight, int price, string code, string name, string origin, string type) {
    this->id = id;
    this->added_weight = added_weight;
    this->price = price;
    this->code = code;
    this->name = name;
    this->origin = origin;
    this->type = type;
}

// dtor
Produk::~Produk() {}

// getter
int Produk::getId() {return id;}
int Produk::getAddedWeight() {return added_weight;}
int Produk::getPrice() {return price;}
string Produk::getCode() {return code;}
string Produk::getName() {return name;}
string Produk::getOrigin() {return origin;}
string Produk::getType() {return type;}

// setter
void Produk::setId(int id) {this->id = id;}
void Produk::setAddedWeight(int weight) {this->added_weight = weight;}
void Produk::setPrice(int price) {this->price = price;}
void Produk::setCode(string code) {this->code = code;}
void Produk::setName(string name) {this->name = name;}
void Produk::setOrigin(string origin) {this->origin = origin;}
void Produk::setType(string type) {this->type = type;}

// other operations
// <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <ADDED_WEIGHT> <PRICE>
ostream& operator<<(ostream& os, Produk& produk) {
    os << "id: " << produk.id << endl;
    os << "code: " << produk.code << endl;
    os << "name: " << produk.name << endl;
    os << "type: " << produk.type << endl;
    os << "origin: " << produk.origin << endl;
    os << "added weight: " << produk.added_weight << endl;
    os << "price: " << produk.price << endl;
    return os;
}