#include "./Walikota.hpp"
#include "./Petani.hpp"
#include "./Peternak.hpp"

// subclass functions
Walikota::Walikota(string& username, int kekayaan) : Pemain(username, kekayaan){}

void Walikota::pungutPajak(){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;;
    vector<tuple<Pemain*, int>> pajak;
    int totalPajak = 0;
    int currentPajak;

    for (int i = 0; i < listPemain.size(); i++) {
        currentPajak = listPemain[i]->calculateTax();
        // NANTI PUSH PRIOQUEUE
        pajak.push_back(tuple<Pemain*, int>(listPemain[i], currentPajak));
        totalPajak += currentPajak;
    }
    // Print hasil pemungutan;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < listPemain.size(); i++) {
        cout << "  " << i+1;
        get<0>(pajak[i])->bayarPajak();
    }

    cout << "Negara mendapatkan pemasukan sebesar" << totalPajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!";
}

void Walikota::bangun(){

}
void Walikota::tambahPemain(){
    string jenis, nama;
    if (kekayaan < 50) {
        cout << "Uang tidak cukup!" << endl;
    } else {
        cout << "Masukkan jenis pemain: ";
        cin >> jenis;
        while (jenis.compare("walikota") != 0 && jenis.compare("petani") != 0 && jenis.compare("peternak") != 0) {
            cout << "Masukkan jenis pemain: ";
            cin >> jenis;
        }
        cout << "Masukkan nama pemain: ";
        cin >> nama;
        while (!namaValid(nama)) {
            cout << "Masukkan nama pemain: ";
            cin >> nama;
        }
        Pemain* pemainBaru;
        // nanti ganti config
        if (jenis.compare("walikota") == 0){
            pemainBaru = new Walikota(nama, 50);
        } else if (jenis.compare("petani") == 0) {
            pemainBaru = new Petani(nama, 50);
        } else if (jenis.compare("peternak")) {
            pemainBaru = new Peternak(nama, 50);
        }

        cout << "Pemain baru ditambahkan!" << endl;
        cout << "Selamat datang " << '"' << pemainBaru->getUsername() << "' di kota ini!" << endl;
    }
}

// Inherited functions (virtual)
void Walikota::doCommand(string command){

}

int Walikota::calculateTax(){
    return -1;
}

void Walikota::buyItem(){

}

void Walikota::sellItem(){

}

void Walikota::eat(){

}