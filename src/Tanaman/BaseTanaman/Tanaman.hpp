#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include <iostream>
#include "../../Item/Item.hpp"
#include "../../Produk/BaseProduk/Produk.hpp"
#include "../../Config/Config/Config.hpp"

using namespace std;

class Tanaman : public Item{
    private:
        int idTanaman;
        int durationToHarvest;
        int currentDuration;
        string typeTanaman;

    public:
        // ctor
        Tanaman();
        Tanaman(int id, int duration_to_harvest, int price, string code, string name, string typeTanaman);
        Tanaman(Config& config, string code);

        // dtor
        ~Tanaman();

        // getter
        int getIdTanaman() const;
        int getDurationToHarvest() const;
        int getCurrentDuration() const;
        string getTypeTanaman() const;

        // setter
        void setIdTanaman(int id);
        void setDurationToHarvest(int duration);
        void setCurrentDuration(int duration);
        void setTypeTanaman(string type);

        // other operations
        bool eatable() const override;
        void addDuration();
        bool isHarvest() const;
        Produk harvest(Config& config);
        void print() override;
        
};

#endif