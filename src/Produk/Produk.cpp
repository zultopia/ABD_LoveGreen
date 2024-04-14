#include "Produk.hpp"

// ctor
Produk::Produk() : Item(), idProduk(0), addedWeight(0), typeProduk(""), origin("")  {}

// dtor
Produk::~Produk() {}

// getter
int Produk::getIdProduk() {return idProduk;}
int Produk::getAddedWeight() {return addedWeight;}
string Produk::getTypeProduk() {return typeProduk;}
string Produk::getOrigin() {return origin;}

// setter
void Produk::setIdProduk(int id) {this->idProduk = id;}
void Produk::setAddedWeight(int weight) {this->addedWeight = weight;}
void Produk::setTypeProduk(string type) {this->typeProduk = type;}
void Produk::setOrigin(string origin) {this->origin = origin;}

