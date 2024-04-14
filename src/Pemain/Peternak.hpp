#ifndef __PETERNAK_HPP__
#define __PETERNAK_HPP__

#include "Pemain.hpp"
#include "../Matrix/Peternakan.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Item/Bangunan.hpp"
#include "../Config/Config.hpp"

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
		int bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		vector<tuple<string,string,int>> getDaftarIsi();
};

#endif