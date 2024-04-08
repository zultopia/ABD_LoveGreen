#ifndef __PEMAIN_HPP__
#define __PEMAIN_HPP__

#include <iostream>
#include <string>
#include <cctype>
#include <tuple>
#include <vector>
#include "../matrix/Penyimpanan.hpp"
#include "../config/Config.hpp"
#include "../toko/toko.hpp"

using namespace std;

class Pemain {
    protected:
        string username;
		int kekayaan;
		Penyimpanan inventory;
        static vector<Pemain*> listPemain;
    public:
        Pemain(string& username, int kekayaan);
		// virtual ~Pemain();

		string getUsername();
		int getKekayaan();
		Penyimpanan& getInventory();
        static bool namaValid(string nama);

        virtual void doCommand(string command) = 0;
        void next();
        void simpan();
        virtual void bayarPajak() = 0;

		virtual int calculateTax() = 0;
		virtual void buyItem() = 0;
		virtual void sellItem() = 0;
		virtual void eat() = 0;
		void cetak_penyimpanan();
		pair<int, int> konversiKoordinat(string koordinat);
};

#endif