#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <iostream>
#include "../Item/Item.hpp"
#include "../Config/Config.hpp"

using namespace std;

class Produk : public Item  {
    private:
        int idProduk;
        int addedWeight;
        string typeProduk;
        string origin;
    
    public:
        // ctor
        Produk();

        // dtor
        ~Produk();

        // getter
        int getIdProduk();
        int getAddedWeight();
        string getTypeProduk();
        string getOrigin();

        // setter
        void setIdProduk(int id);
        void setAddedWeight(int weight);
        void setTypeProduk(string type);
        void setOrigin(string origin);

        // other operations
        bool eatable() const override;
        friend ostream& operator<<(ostream& os, Produk produk);
};

#endif