#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>

using namespace std;

#include "../Produk/Produk.hpp"

class Hewan : public Item {
    private:
        int idHewan;
        int weightToHarvest;
        int currentWeight;
        string typeHewan;

    public:
        // ctor
        Hewan();
        Hewan(int currentWeight);

        // dtor
        ~Hewan();

        // getter
        int getIdHewan() const;
        int getWeightToHarvest() const;
        int getCurrentWeight() const;
        string getTypeHewan() const;

        // setter
        void setIdHewan(int id);
        void setWeightToHarvest(int weight);
        void setCurrentWeight(int weight);
        void setTypeHewan(string typeHewan);

        // other operations
        bool eatable() const override;
        virtual bool isCanEat(Produk& p) const = 0;
        void eat(Produk& p);
        bool isHarvest() const;
};

#endif