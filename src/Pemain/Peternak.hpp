#ifndef __PETERNAK__
#define __PETERNAK__

#include "Pemain.hpp"

class Peternak : public Pemain {
	private:
		Peternakan peternakan;
	public:
		Peternak(string& username, int kekayaan);

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