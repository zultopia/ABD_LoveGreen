#ifndef __PETANI_HPP__
#define __PETANI_HPP__

#include "Pemain.hpp"
#include "Matrix/Ladang.hpp"

class Petani : public Pemain {
	private:
		Ladang ladang;
	public:
		Petani(string& username, int kekayaan, int beratBadan);
		~Petani();

		Ladang& getLadang();
		string getRole();

		void tanam();
		void cetakLadang();
		void harvest();

		void doCommand(string command);
		void bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		vector<tuple<string,string,int>> getDaftarIsi();
};

#endif