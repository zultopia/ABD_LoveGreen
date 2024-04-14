#ifndef __PEMAIN_HPP__
#define __PEMAIN_HPP__

#include <iostream>
#include <string>
#include <cctype>
#include <tuple>
#include <vector>
#include "../matrix/Grid.hpp"
#include "../Matrix/Penyimpanan.hpp"
#include "../config/Config.hpp"
#include "../Toko/Toko.hpp"
#include "PemainException.hpp"

using namespace std;

class Pemain {
    protected:
        string username;
		int kekayaan;
		int beratBadan;
		Penyimpanan inventory;
		static map<string,int> commandTable;
    public:
        Pemain(string& username, int kekayaan, int beratBadan);

        static vector<Pemain*> listPemain;
		static int currentPemain;
		static int numPemain;
		
		string getUsername();
		int getKekayaan();
		int getBeratBadan();
		virtual string getRole() = 0;
		Penyimpanan& getInventory();
        vector<string> getDaftarInventory();
        static bool namaValid(string nama);

        virtual void doCommand(string command) = 0;
        void next();
        void simpan();
		void muat();
        virtual int bayarPajak();

		virtual int calculateTax() = 0;
		virtual void beli() = 0;
		virtual void jual() = 0;
		virtual void makan();
		void cetakPenyimpanan();
};

// Declare listPemain
vector<Pemain*> Pemain::listPemain;
int Pemain::currentPemain = 0;
int Pemain::numPemain = 0;
map<string,int> Pemain::commandTable = {
    {"NEXT",1},
    {"CETAK_PENYIMPANAN",2},
    {"PUNGUT_PAJAK",3},
    {"CETAK_LADANG",4},
    {"CETAK_PETERNAKAN",5},
    {"TANAM",6},
    {"TERNAK",7},
    {"BANGUN",8},
    {"MAKAN",9},
    {"KASIH_MAKAN",10},
    {"BELI",11},
    {"JUAL",12},
    {"PANEN",13},
    {"MUAT",14},
    {"SIMPAN",15},
    {"TAMBAH_PEMAIN",16}
};

#endif