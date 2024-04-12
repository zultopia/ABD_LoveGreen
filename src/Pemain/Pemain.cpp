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
    // Cek apakah ada makanan di inventory (penyimpanan)
    int width = Config::getBesarPenyimpanan().first;
    int height = Config::getBesarPenyimpanan().second;
    bool adaMakanan = false;
    int i, j = 0;
    Item* currentItem;
    while (i < width && !adaMakanan) {
        while (j < height && !adaMakanan) {
            currentItem = inventory.getGrid().getCell(i, j);
            if (currentItem != nullptr) {
                if (currentItem->eatable()) {
                    adaMakanan = true;
                }
            }
            j++;
        }
        i++;
    }

    if (!adaMakanan) {
        cout << "Tidak ada makanan dalam penyimpanan" << endl;
    } else {
        // Pilih makanan
        cout << "Pilih makanan dari penyimpanan" << endl;
        cetakPenyimpanan();
        cout << endl;
        cout << "Slot: ";
        string slot;
        cin >> slot;
        cout << endl;

        // Cek apakah input valid;
        bool valid = false;

        pair<int,int> koordinat = konversiKoordinat(slot);
        if (inventory.ambilItem(koordinat.first, koordinat.second) == nullptr) {
        }
        while (inventory.ambilItem(koordinat.first, koordinat.second) == nullptr){
            
        }


    }

}

