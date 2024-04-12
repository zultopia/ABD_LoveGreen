#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <vector> 
#include <string>
#include "Item.hpp"

using namespace std;

class Bangunan {
private:
    int id;
    Item* item; 
    vector<pair<string, int> > materials;

public:
    // Constructor
    Bangunan();
    Bangunan(int id, Item* item, const vector<pair<string, int> >& materials);

    // Destructor
    ~Bangunan();

    // Getter
    int getId();
    Item* getItem();
    vector<pair<string, int> > getMaterials();

    // Setter
    void setId(int id);
    void setItem(Item* item);
    void setMaterials(const vector<pair<string, int> >& materials);

    // Operator overloading untuk ostream
    friend ostream& operator<<(ostream& os, Bangunan& bangunan);
};

#endif