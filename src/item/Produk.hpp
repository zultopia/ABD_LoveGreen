#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <iostream>

using namespace std;

class Produk {
    private:
        int id;
        int added_weight;
        int price;
        string code;
        string name;
        string origin;
        string type;
    
    public:
        // ctor
        Produk();
        Produk(int id, int added_weight, int price, string code, string name, string origin, string type);

        // dtor
        ~Produk();

        // getter
        int getId();
        int getAddedWeight();
        int getPrice();
        string getCode();
        string getName();
        string getOrigin();
        string getType();

        // setter
        void setId(int id);
        void setAddedWeight(int weight);
        void setPrice(int price);
        void setCode(string code);
        void setName(string name);
        void setOrigin(string origin);
        void setType(string type);

        // other operations
        friend ostream& operator<<(ostream& os, Produk& produk);
};

#endif