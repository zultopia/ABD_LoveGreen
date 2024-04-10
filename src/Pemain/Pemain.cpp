#include "Pemain.hpp"

Pemain::Pemain(string& username, int kekayaan, int beratBadan) : username(username), kekayaan(kekayaan), beratBadan(beratBadan), inventory() {
    auto itr = listPemain.begin();
    while (username.compare((*itr)->getUsername()) < 0 && itr != listPemain.end()) {
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

int Pemain::getBeratBadan() {
    return beratBadan;
}

Penyimpanan& Pemain::getInventory() {
    return inventory;
}
vector<string> Pemain::getDaftarInventory(){
    return inventory.getListPenyimpanan();
}
void Pemain::next() {
    currentPemain = (currentPemain + 1) % numPemain;
}
void Pemain::simpan() {

}

void Pemain::muat() {
    
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

void Pemain::cetakPenyimpanan() {
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

void Pemain::makan() {
    //makan
}

