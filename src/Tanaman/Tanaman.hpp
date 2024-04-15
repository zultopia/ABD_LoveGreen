#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include <iostream>
#include "../Item/Item.hpp"

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
        Tanaman(string nama);
        Tanaman(string nama, int currentDuration);

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
        friend ostream& operator<<(ostream& os, Tanaman tanaman);
};

#endif