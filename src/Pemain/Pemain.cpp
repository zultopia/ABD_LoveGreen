#include "Pemain.hpp"

Pemain::Pemain(string& username, int kekayaan) : username(username), kekayaan(kekayaan), inventory() {}

string Pemain::getUsername() {
    return username;
}

int Pemain::getKekayaan() {
    return kekayaan;
}

Penyimpanan& Pemain::getInventory() {
    return inventory;
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