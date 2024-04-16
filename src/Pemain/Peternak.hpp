#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include "Pemain.hpp"
#include "../Matrix/Peternakan.hpp"

class Peternak : public Pemain {
	private:
		Peternakan peternakan;
	public:
		Peternak(string& username, int kekayaan, int beratBadan);
		~Peternak();

		Peternakan& getPeternakan();
		string getRole();

		void ternak();
		void beriPangan();
		void cetakPeternakan();
		void harvest();

		void doCommand(string command);
		void bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		vector<tuple<string,string,int>> getDaftarIsi();
		void printStatus();
		void magic();
};

#endif