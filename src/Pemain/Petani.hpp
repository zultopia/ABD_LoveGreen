#ifndef __PETANI_HPP__
#define __PETANI_HPP__

#include "Pemain.hpp"

class Petani : public Pemain {
	private:
		Ladang ladang;
	public:
		Petani(string& username, int kekayaan);

		Ladang& getLadang();

		void tanam();
		void cetak_ladang();
		void harvest();

		void doCommand(string command);
		int bayarPajak();
		int calculateTax();
		void buyItem();
		void sellItem();
		void eat();
};

#endif