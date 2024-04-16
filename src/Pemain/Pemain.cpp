#include "./Pemain.hpp"
#include "./Petani.hpp"
#include "../Matrix/Grid.hpp"
#include "../Config/Config.hpp"
#include "../Toko/Toko.hpp"
#include "../Exception/PemainException.hpp"
#include "../Config/Simpan.hpp"
#include "../Item/Item.hpp"

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
    {"STATUS", 14},
    {"SIMPAN",15},
    {"TAMBAH_PEMAIN",16}
};

Pemain::Pemain(string& username, int kekayaan, int beratBadan) : username(username), kekayaan(kekayaan), beratBadan(beratBadan), inventory() {
    auto itr = listPemain.begin();
    if(itr == listPemain.end()){
        listPemain.insert(itr, this);
        numPemain++;
    }else{
        while (username.compare((*itr)->getUsername()) > 0 && itr != listPemain.end()-1) {
            itr++;
        }
        if(username.compare((*itr)->getUsername()) > 0){
            itr++;
        }
        listPemain.insert(itr, this);
        numPemain++;
    }
    
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
    auto pemain = listPemain.begin();
    while (pemain != listPemain.end()) {
        if ((*pemain)->getRole() == "Petani") {
            Petani* petani = dynamic_cast<Petani*>(*pemain);
            if (petani) {
                petani->getLadang().addDurationTanaman();
            }
        }
        pemain++;
    }
}

void Pemain::simpan() {
    string buf;
    getline(cin,buf);
    Simpan::simpan();
}

bool Pemain::namaValid(string nama){
    if (nama.length() == 0) {
        return false;
    }
    for (int i = 0; i < listPemain.size(); i++) {
        if (nama.compare(listPemain[i]->username) == 0) {
            return false;
        }
    }
    return true;
}

bool Pemain::checkWinCondition() {
    if (kekayaan >= Config::getJumlahUangWin() && beratBadan >= Config::getBeratBadanWin()) {
        return true;
    } else {
        return false;
    }
}

void Pemain::cetakPenyimpanan() {
    inventory.cetakInfo();
}

void Pemain::makan() {
    // Cek apakah ada makanan di inventory (penyimpanan)
    int width = Config::getBesarPenyimpanan().first;
    int height = Config::getBesarPenyimpanan().second;
    bool adaMakanan = false;
    int i = 0, j = 0;
    Item* currentItem;
    while (i < width && !adaMakanan) {
        while (j < height && !adaMakanan) {
            currentItem = inventory.getCell(i, j);
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
        Item* item = inventory.ambilItem(koordinat.first + 1, koordinat.second);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        beratBadan += Config::getAddedWeight(item->getName());
        cout << "Alhasil, berat badan kamu naik menjadi " << beratBadan << endl;
    }
}

void Pemain::printStatus() {
    cout << "Nama: " << username << endl;
    cout << "Kekayaan: " << kekayaan << endl;
    cout << "Berat Badan: " << beratBadan << endl;
    cout << "Role: " << getRole() << endl;
    cetakPenyimpanan();
}