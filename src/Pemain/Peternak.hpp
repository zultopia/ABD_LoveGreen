#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include "Pemain.hpp"

class Peternak : public Pemain {
	private:
		Peternakan peternakan;
	public:
		Peternak(string& username, int kekayaan, int beratBadan);

		Peternakan& getPeternakan();

		void ternak();
		void beriPangan();
		void cetakPeternakan();
		void harvest();

		void doCommand(string command);
		int bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		void eat();
};

#endif