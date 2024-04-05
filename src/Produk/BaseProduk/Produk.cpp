#include "Produk.hpp"

// ctor
Produk::Produk() : Item(), idProduk(0), addedWeight(0), origin(""), typeProduk("") {}
Produk::Produk(int id, int addedWeight, int price, string code, string name, string origin, string type) {
    this->idProduk = id;
    this->addedWeight = addedWeight;
    this->origin = origin;
}
Produk::Produk(Config& config, string name) {
    tuple<int, string, string, string, string, int, int> item = config.getFromProduk(name);
    int id = std::get<0>(item);
    string code = std::get<1>(item);
    string type = std::get<3>(item);
    string origin = std::get<4>(item);
    int addedWeight = std::get<5>(item);
    int price = std::get<6>(item);
    setIdProduk(id);
    setCode(code);
    setName(name);
    setTypeProduk(type);
    setOrigin(origin);
    setAddedWeight(addedWeight);
    setPrice(price);
}

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

// other operations
bool Produk::eatable() const {return false;} // belum bisa dimakan

// <ID> <KODE_HURUF> <NAME> <TYPE> <ORIGIN> <addedWeight> <PRICE>
void Produk::print() {
    cout << "id           : " << getIdProduk() << endl;
    cout << "Code         : " << getCode() << endl;
    cout << "Name         : " << getName() << endl;
    cout << "type         : " << getTypeProduk() << endl;
    cout << "origin       : " << getOrigin() << endl;
    cout << "added weight : " << getAddedWeight() << endl;
    cout << "Price        : " << getPrice() << endl;
}