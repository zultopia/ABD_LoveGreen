#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class Bangunan {
private:
    int id;
    int price;
    string code;
    string name;
    vector<pair<string, int> > materials; 

public:
    // Constructor
    Bangunan();
    Bangunan(int id, int price, string code, string name, const vector<pair<string, int> >& materials);

    // Destructor
    ~Bangunan();

    // Getter
    int getId();
    int getPrice();
    string getCode();
    string getName();
    vector<pair<string, int> > getMaterials();

    // Setter
    void setId(int id);
    void setPrice(int price);
    void setCode(string code);
    void setName(string name);
    void setMaterials(const vector<pair<string, int> >& materials); 

    // Operator overloading untuk ostream
    friend ostream& operator<<(ostream& os, Bangunan& bangunan);
};

#endif