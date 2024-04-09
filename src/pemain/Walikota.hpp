#include "Pemain.hpp"

class Walikota : public Pemain {
    public:
        // subclass functions
        Walikota(string& username, int kekayaan);
        void pungutPajak();
        void bangun();
        void tambahPemain();

        // Inherited functions (virtual)
        int bayarPajak();
        void doCommand(string command);
        int calculateTax();
        void beli();
        void jual();
        void eat();
};