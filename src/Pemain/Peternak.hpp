#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include "Pemain.hpp"

class Peternak : public Pemain {
	private:
		Peternakan peternakan;
	public:
		Peternak(string& username, int kekayaan);

		Peternakan& getPeternakan();

		void ternak();
		void beri_pangan();
		void cetak_peternakan();
		void harvest();

		void doCommand(string command);
		int bayarPajak();
		int calculateTax();
		void buyItem();
		void sellItem();
		void eat();
};

#endif