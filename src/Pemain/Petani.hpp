#ifndef __PETANI__
#define __PETANI__

#include "Pemain.hpp"

class Petani : public Pemain {
	private:
		Ladang ladang;
	public:
		Petani(string& username, int kekayaan);

		void tanam();
		void cetak_ladang();

		void harvest();
		int calculateTax();
		void buyItem();
		void sellItem();
		void eat();
};

#endif