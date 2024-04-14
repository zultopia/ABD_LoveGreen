#ifndef WALIKOTA_HPP
#define WALIKTA_HPP

#include "Pemain.hpp"

class Walikota : public Pemain {
    public:
        // subclass functions
        Walikota(string& username, int kekayaan, int beratBadan);
        void pungutPajak();
        void bangun();
        void tambahPemain();

        string getRole();

        // Inherited functions (virtual)
        int bayarPajak();
        void doCommand(string command);
        int calculateTax();
        void beli();
        void jual();
};

#endif