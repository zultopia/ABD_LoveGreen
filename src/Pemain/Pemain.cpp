#include "Pemain.hpp"

// Declare listPemain
vector<Pemain*> Pemain::listPemain;
int Pemain::currentPemain = 0;
int Pemain::numPemain = 0;

Pemain::Pemain(string& username, int kekayaan) : username(username), kekayaan(kekayaan), inventory() {
    // NANTI PUSH PRIOQUEUE
    auto itr = listPemain.begin();
    while (username.compare((*itr)->getUsername()) < 0) {
        itr++;
    }
    listPemain.insert(itr, this);
    numPemain++;
}

string Pemain::getUsername() {
    return username;
}

int Pemain::getKekayaan() {
    return kekayaan;
}

Penyimpanan& Pemain::getInventory() {
    return inventory;
}

void Pemain::next() {
    currentPemain = (currentPemain + 1) % numPemain;
}
void Pemain::simpan() {

}

int Pemain::bayarPajak() {
    int pajak = this->calculateTax();
    if (this->kekayaan >= pajak) {
        kekayaan -= pajak;
        return pajak;
    } else {
        int tempKekayaan = kekayaan;
        kekayaan -= pajak;
        return tempKekayaan;
    }

}

bool Pemain::namaValid(string nama){
    for (int i = 0; i < listPemain.size(); i++) {
        if (nama.compare(listPemain[i]->username) == 0) {
            return false;
        }
    }
    return true;
}

void Pemain::cetak_penyimpanan() {
    inventory.cetakInfo();
}

pair<int, int> Pemain::konversiKoordinat(string koordinat) {
    if (koordinat.length() < 3) {
        cout << "Format koordinat tidak valid\n";
        return {-1, -1};
    }

    char huruf = toupper(koordinat[0]); 
    int y = huruf - 'A';

    string angkaStr = koordinat.substr(1); 
    int x = stoi(angkaStr) - 1; 

    if (x < 0 || x > 7) {
        cout << "Indeks kolom tidak valid\n";
        return {-1, -1}; 
    }

    return {x, y};
}

