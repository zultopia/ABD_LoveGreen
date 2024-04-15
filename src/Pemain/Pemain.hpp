#ifndef __PEMAIN_HPP__
#define __PEMAIN_HPP__

#include <iostream>
#include <string>
#include <cctype>
#include <tuple>
#include <vector>
#include <map>
#include "../Matrix/Penyimpanan.hpp"

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
        bool checkWinCondition();
        virtual void doCommand(string command) = 0;
        void next();
        void simpan();
        virtual void bayarPajak() = 0;

		virtual int calculateTax() = 0;
		virtual void beli() = 0;
		virtual void jual() = 0;
		virtual void makan();
		void cetakPenyimpanan();
};



#endif