#include "./Walikota.hpp"
#include "./Petani.hpp"
#include "./Peternak.hpp"

// subclass functions
Walikota::Walikota(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan){}

void Walikota::pungutPajak(){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;;
    vector<tuple<Pemain*, int>> pajak;
    int totalPajak = 0;
    int currentPajak;

    for (int i = 0; i < listPemain.size(); i++) {
        currentPajak = listPemain[i]->calculateTax();
        // Cek apakah walikota/bukan
        if (currentPajak >= 0) {
            auto itr = pajak.begin();
            while ((currentPajak < get<1>(*itr) ||(currentPajak == get<1>(*itr) && username.compare(get<0>(*itr)->getUsername()) == 0)) && itr != pajak.end()) {
                itr++;
            }
            pajak.insert(itr, tuple<Pemain*, int>(listPemain[i], currentPajak));
        }
    }
    // Print hasil pemungutan;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < listPemain.size(); i++) {
        cout << "  " << i+1;
        totalPajak += get<0>(pajak[i])->bayarPajak();
    }

    cout << "Negara mendapatkan pemasukan sebesar" << totalPajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!";
}

void Walikota::bangun(){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    auto itr = Config::getRecipeMap().begin();
    int i = 1;
    map<string, string> Bahan;
    while (itr != Config::getRecipeMap().end()) {
        cout << "  " << i << ". " << itr->first << " (" << Config::getPrice(itr->first);
        auto itrMaterial = Config::getMaterialInfo(itr->first).begin();
        while (itrMaterial != Config::getMaterialInfo(itr->first).end()){
            cout << ", " << itrMaterial->first << " " << itrMaterial->second;
            itrMaterial++;
        }
        cout << ")" << endl;
        Bahan.insert(pair<string,string>(itr->first, Config::getCode(itr->first)));
        i++;
        itr++;
    }
    cout << endl << "Bangunan yang ingin dibangun: ";
    string answer;
    cin >> answer;
    try {
        string kodeBangunan = Bahan[answer];
    } catch(...){
        cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
        this->bangun();
        return;
    }
    // Harus Cek Inventory ada item atau ga

    // Kalau ga ada:
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan "; // apa aja yg gapunya
    // Kalau ada:
        // tambah ke inventory : new Bangunan(...)
        cout << answer << " berhasil dibangun dan telah menjadi hak milik walikota!";


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
        if (jenis.compare("walikota") == 0){
            pemainBaru = new Walikota(nama, 50, 40);
        } else if (jenis.compare("petani") == 0) {
            pemainBaru = new Petani(nama, 50, 40);
        } else if (jenis.compare("peternak")) {
            pemainBaru = new Peternak(nama, 50, 40);
        }

        cout << "Pemain baru ditambahkan!" << endl;
        cout << "Selamat datang " << '"' << pemainBaru->getUsername() << "' di kota ini!" << endl;
    }
}

string Walikota::getRole() {
    return "walikota";
}

// Inherited functions (virtual)
void Walikota::doCommand(string command){
    if(commandTable.find(command) == commandTable.end()){
        throw "Command Tidak Valid!";
    }
    switch (commandTable[command])
    {
    case 1:
        this->next();
        break;
    case 2:
        this->cetakPenyimpanan();
        break;
    case 3:
        this->pungutPajak();
        break;
    case 8:
        this->bangun();
        break;
    case 9:
        this->makan();
        break;
    case 11:
        this->beli();
        break;
    case 12:
        this->jual();
        break;
    case 14:
        this->muat();
        break;
    case 15:
        this->simpan();
        break;
    case 16:
        this->tambahPemain();
        break;
    default:
        throw "Command Tidak Valid untuk Pemain ini";
        break;
    }
}

int Walikota::calculateTax(){
    return -1;
}

// Beli jual belom beres implementasi
void Walikota::beli(){
    Toko::CetakWalikota();
    // Toko::BeliWalikota();
}

void Walikota::jual(){
    // Toko::Jual();
}