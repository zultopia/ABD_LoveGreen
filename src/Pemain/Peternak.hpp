#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include "Pemain.hpp"
#include "../Peternakan.hpp"

class Peternak : public Pemain {
	private:
		Peternakan peternakan;
	public:
		Peternak(string& username, int kekayaan, int beratBadan);

		Peternakan& getPeternakan();
		string getRole();

		void ternak();
		void beriPangan();
		void cetakPeternakan();
		void harvest();

		void doCommand(string command);
		int bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		vector<tuple<string,string,int>> getDaftarIsi();
};

#endif