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

        pair<int,int> koordinat = Penyimpanan::konversiKoordinat(slot);
        int validity = inventory.checkMakanan(koordinat.first, koordinat.second);
        while (validity != 0) {
            if (validity == -1){
                cout << "Tidak ada slot dengan index seperti itu!" << endl;
            } else if (validity == 1) {
                cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            } else if (validity == 2) {
                cout << "Apa yang kamu lakukan\?\?!! Kamu mencoba untuk memakan itu\?!!" << endl;
            }
            cout << "Silahkan masukan slot yang berisi makanan." << endl << endl;
            cout << "Slot: ";
            cin >> slot;
            cout << endl;
            koordinat = Penyimpanan::konversiKoordinat(slot);
            validity = inventory.checkMakanan(koordinat.first, koordinat.second);
        }
        Item* item = inventory.ambilItem(koordinat.first, koordinat.second);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        beratBadan += Config::getAddedWeight(item->getName());
        cout << "Alhasil, berat badan kamu naik menjadi " << beratBadan << endl;
    }

}

