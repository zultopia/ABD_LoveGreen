#ifndef __PETANI_HPP__
#define __PETANI_HPP__

#include "./Pemain.hpp"
#include "../Matrix/Ladang.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Item/Bangunan.hpp"


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
		int bayarPajak();
		int calculateTax();
		void beli();
		void jual();
		vector<tuple<string,string,int>> getDaftarIsi();
};

#endif