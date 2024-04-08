#include "Item.hpp"

// ctor
Item::Item() : price(0), code(""), name("") {}

Item::Item(int price, string code, string name) {
    setPrice(price);
    setCode(code);
    setName(name);
}

// dtor
Item::~Item() {}

// getter
int Item::getPrice() {return price;}
string Item::getCode() const {return code;}
string Item::getName() const {return name;}

// setter
void Item::setPrice(int price) {this->price = price;}
void Item::setCode(string code) {this->code = code;}
void Item::setName(string name) {this->name = name;}