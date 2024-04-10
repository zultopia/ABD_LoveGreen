#include "Petani.hpp"

Petani::Petani(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan), ladang() {}

Ladang& Petani::getLadang() {
    return ladang;
}

string Petani::getRole() {
    return "petani";
}

void Petani::tanam() {
    // Menampilkan daftar tanaman yang tersedia di penyimpanan
    cout << endl;
    cout << "Pilih tanaman dari penyimpanan:" << endl;
    cout << endl;
    inventory.cetakInfo();

    // Meminta input slot item yang akan ditanam
    string slot;
    cout << "Slot: "; cin >> slot; cout << endl; 

    // Mengambil item dari penyimpanan
    pair<int, int> koordinatItem = konversiKoordinat(slot);
    Item* item = inventory.ambilItem(koordinatItem.first + 1, koordinatItem.second);
    if (item != nullptr) {
        string code = item->getCode();
        auto it = Config::getPlantMap().find(code);
        if (it == Config::getPlantMap().end()) {
            cout << "Item yang dipilih bukan tanaman." << endl;
            return;
        }
        
        cout << "Kamu memilih " << item->getName() << "." << endl;
        cout << endl;

        // Memeriksa apakah ladang sudah penuh
        if (ladang.hitungSlotKosong() == 0) {
            cout << "Ladang sudah penuh. Tidak dapat menanam lebih banyak tanaman." << endl;
            return;
        }

        bool tanamBerhasil = false;
        while (!tanamBerhasil) {
            // Meminta input petak tanah yang akan ditanami
            cout << "Pilih petak tanah yang akan ditanami" << endl;
            cout << endl;
            ladang.cetakInfo();

            // Meminta input slot petak tanah
            string petak;
            cout << endl;
            cout << "Petak tanah: ";
            cin >> petak;
            cout << endl;

            // Menanam tanaman pada petak tanah yang dipilih
            pair<int, int> koordinatPetak = konversiKoordinat(petak);

            // Memeriksa apakah petak tanah sudah ditanami
            if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) != nullptr) {
                cout << "Petak tanah tersebut sudah ditanami. Pilih petak lain." << endl;
            } else {
                // Menanam tanaman pada petak tanah yang dipilih
                Tanaman* tanaman = new Tanaman(item->getCode());
                ladang.tanamTanaman(koordinatPetak.first + 1, koordinatPetak.second, tanaman);
                cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
                cout << item->getName() << " berhasil ditanam di petak " << petak << endl;
                ladang.cetakInfo();
                inventory.cetakInfo();
                tanamBerhasil = true;
            }
        }
    } else {
        cout << "Tidak ada Item pada posisi tersebut." << endl;
    }
}

void Petani::cetakLadang() {
    ladang.cetakInfo();
}

void Petani::harvest() {
    ladang.cetakInfo();

    cout << endl;
    map<string, int> harvest = ladang.hitungJumlahTanamanPanen();

    if (harvest.empty()) {
        cout << "Tidak ada tanaman siap panen." << endl;
    } else {
        cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
        int counter = 1;
        map<int, string> tanamanByNumber;
        for (auto it = harvest.begin(); it != harvest.end(); it++) {
            cout << counter << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            tanamanByNumber[counter] = it->first;
            counter++;
        }

        cout << endl;
        int nomor;
        cout << "Nomor tanaman yang ingin dipanen: "; cin >> nomor; cout << endl;

        if (nomor < 1 || nomor > harvest.size()) {
            cout << "Nomor tanaman tidak valid." << endl;
        } else {
            int jumlahPetak;
            string kodeTanaman = tanamanByNumber[nomor];
            cout << "Berapa petak yang ingin dipanen: "; cin >> jumlahPetak; cout << endl;

            if (jumlahPetak < 1 || jumlahPetak > harvest[kodeTanaman]) {
                cout << "Jumlah petak yang ingin dipanen melebihi/kurang dari jumlah petak yang tersedia." << endl;
            } else {
                if (inventory.hitungSlotKosong() < jumlahPetak) {
                    cout << "Slot penyimpanan tidak cukup." << endl;
                    return;
                } 

                string petak;
                vector<string> petakDipanen;
                cout << "Pilih petak yang ingin dipanen: " << endl;
                for (int i = 0; i < jumlahPetak; i++) {
                    cout << "Petak ke-" << i + 1 << ": "; cin >> petak;
                    pair<int, int> koordinatPetak = konversiKoordinat(petak);
                    if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) == nullptr) {
                        cout << "Petak tersebut tidak memiliki tanaman." << endl;
                        return;
                    } else if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->getCode() != kodeTanaman) {
                        cout << "Petak tersebut memiliki tanaman yang berbeda." << endl;
                        return;
                    } else if (!ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->isHarvest()) {
                        cout << "Tanaman pada petak tersebut belum siap dipanen." << endl;
                        return;
                    } else {
                        petakDipanen.push_back(petak);
                        Tanaman* tanamanPanen = ladang.ambilTanaman(koordinatPetak.first + 1, koordinatPetak.second);
                    }
                }
                cout << petakDipanen.size() << " petak tanaman " << kodeTanaman << " pada petak ";
                for (int i = 0; i < petakDipanen.size(); i++) {
                    cout << petakDipanen[i];
                    if (i != petakDipanen.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " telah dipanen." << endl;
            }
        }
    }
}

void Petani::doCommand(string command) {
    if(commandTable.find(command) == commandTable.end()){
        // throw error
    }
    switch (commandTable[command])
    {
    case 1:
        this->next();
        break;
    case 2:
        this->cetakPenyimpanan();
        break;
    case 4:
        this->cetakLadang();
        break;
    case 6:
        this->tanam();
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
    case 13:
        this->harvest();
        break;
    case 14:
        this->muat();
        break;
    case 15:
        this->simpan();
        break;
    default:
        throw "Command Tidak Valid untuk Pemain ini";
        break;
    }
}

int Petani::bayarPajak() { return 0; }

int Petani::calculateTax() { return 0; }

void Petani::beli() {}

void Petani::jual() {}
