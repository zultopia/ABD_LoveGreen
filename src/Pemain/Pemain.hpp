#ifndef __PEMAIN_HPP__
#define __PEMAIN_HPP__

#include <iostream>
#include <string>
#include <cctype>
#include "../matrix/Penyimpanan.hpp"

using namespace std;

class Pemain {
    protected:
        string username;
		int kekayaan;
		Penyimpanan inventory;
    public:
        Pemain(string& username, int kekayaan);
		// virtual ~Pemain();

		string getUsername();
		int getKekayaan();
		Penyimpanan& getInventory();

		virtual void harvest() = 0;
		virtual int calculateTax() = 0;
		virtual void buyItem() = 0;
		virtual void sellItem() = 0;
		virtual void eat() = 0;
		void cetak_penyimpanan();
		pair<int, int> konversiKoordinat(string koordinat);
};

#endif