#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include "../../Config/ConfigProduk/ConfigProduk.hpp"

using namespace std;

class Hewan {
    private:
        int id;
        int weightToHarvest;
        int price;
        int currentWeight;
        string code;
        string name;
        string type;

    public:
        // ctor
        Hewan();
        Hewan(int id, int weigth_to_harvest, int price, string code, string name, string type);

        // dtor
        ~Hewan();

        // getter
        int getId() const;
        int getWeightToHarvest() const;
        int getPrice() const;
        int getCurrentWeight() const;
        string getCode() const;
        string getName() const;
        string getType() const;

        // setter
        void setId(int id);
        void setWeightToHarvest(int weight);
        void setPrice(int price);
        void setCurrentWeight(int weight);
        void setCode(string code);
        void setName(string name);
        void setType(string type);

        // other operations
        virtual bool isCanEat(Produk p) const;
        void eat(Produk p);
        bool isHarvest() const;
        Produk harvest();
        friend ostream& operator<<(ostream& os, Hewan& hewan);
};

#endif