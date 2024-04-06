#include "Pemain.hpp"

class Walikota : public Pemain {
    public:
        // subclass functions
        Walikota(string& username, int kekayaan);
        void pungutPajak();
        void bangun();
        void tambahPemain();

        // Inherited functions (virtual)
        void bayarPajak();
        void doCommand(string command);
        int calculateTax();
        void buyItem();
        void sellItem();
        void eat();
};