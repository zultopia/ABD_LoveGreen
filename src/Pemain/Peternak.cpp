#include "Peternak.hpp"
#include "../Hewan/BaseHewan/Hewan.hpp"
#include "../Hewan/karnivora/karnivora.hpp"

Peternak::Peternak(string& username, int kekayaan) : Pemain(username, kekayaan), peternakan() {}

Peternakan& Peternak::getPeternakan() {
    return peternakan;
}

void Peternak::ternak() {
    // Menampilkan daftar hewan yang tersedia di penyimpanan
    cout << endl;
    cout << "Pilih hewan dari penyimpanan:" << endl;
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
        auto it = Config::getAnimalMap().find(code);
        if (it == Config::getAnimalMap().end()) {
            cout << "Item yang dipilih bukan hewan." << endl;
            return;
        }

        // Memeriksa apakah peternakan sudah penuh
        if (peternakan.hitungSlotKosong() == 0) {
            cout << "Peternakan sudah penuh. Tidak dapat menambahkan lebih banyak hewan." << endl;
            return;
        }

        bool ternakBerhasil = false;
        while (!ternakBerhasil) {
            // Meminta input petak tanah yang akan ditinggali
            cout << endl;
            cout << "Pilih petak tanah yang akan ditinggali" << endl;
            cout << endl;
            peternakan.cetakInfo();

            // Meminta input slot petak tanah
            string petak;
            cout << endl;
            cout << "Petak tanah: "; 
            cin >> petak; 
            cout << endl; 

            // Menanam hewan pada petak kandang yang dipilih
            pair<int, int> koordinatPetak = konversiKoordinat(petak);

            // Memeriksa apakah petak kandang sudah ditempati
            if (peternakan.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) != nullptr) {
                cout << "Petak tanah tersebut sudah ditempati. Pilih petak lain." << endl;
            } else {
                // Menanam hewan pada petak kandang yang dipilih
                Hewan* hewan = new Karnivora(item->getCode());
                peternakan.ternakHewan(koordinatPetak.first + 1, koordinatPetak.second, hewan);
                cout << "Dengan hati-hati, kamu meletakkan seekor Chicken di kandang." << endl;
                cout << item->getName() << " telah menjadi peliharaanmu sekarang!" << endl;
                peternakan.cetakInfo();
                inventory.cetakInfo();
                ternakBerhasil = true;
            }
        }
    } else {
        cout << "Tidak ada Item pada posisi tersebut." << endl;
    }
}

void Peternak::beri_pangan() {}

void Peternak::cetak_peternakan() {
    peternakan.cetakInfo();
}

void Peternak::harvest() {
    peternakan.cetakInfo();

    cout << endl;
    map<string, int> harvest = peternakan.hitungJumlahHewanPanen();

    if (harvest.empty()) {
        cout << "Tidak ada hewan siap panen." << endl;
    } else {
        cout << "Pilih hewan siap panen yang kamu miliki" << endl;
        int counter = 1;
        map<int, string> hewanByNumber;
        for (auto it = harvest.begin(); it != harvest.end(); it++) {
            cout << counter << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            hewanByNumber[counter] = it->first;
            counter++;
        }

        cout << endl;
        int nomor;
        cout << "Nomor hewan yang ingin dipanen: "; cin >> nomor; cout << endl;

        if (nomor < 1 || nomor > harvest.size()) {
            cout << "Nomor hewan tidak valid." << endl;
        } else {
            int jumlahPetak;
            string kodeHewan = hewanByNumber[nomor];
            cout << "Berapa petak yang ingin dipanen: "; cin >> jumlahPetak; cout << endl;

            if (jumlahPetak < 1 || jumlahPetak > harvest[kodeHewan]) {
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
                    if (peternakan.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) == nullptr) {
                        cout << "Petak tersebut tidak memiliki hewan." << endl;
                        return;
                    } else if (peternakan.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->getCode() != kodeHewan) {
                        cout << "Petak tersebut memiliki hewan yang berbeda." << endl;
                        return;
                    } else if (!peternakan.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->isHarvest()){
                        cout << "Hewan belum siap dipanen." << endl;
                        return;
                    } else {
                        petakDipanen.push_back(petak);
                        Hewan* hewanPanen = peternakan.ambilTernak(koordinatPetak.first + 1, koordinatPetak.second);
                    }
                }
                cout << petakDipanen.size() << " petak hewan " << kodeHewan << " pada petak ";
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

void Peternak::doCommand(string command) {}

int Peternak::bayarPajak() { return 0; }

int Peternak::calculateTax() { return 0; }

void Peternak::buyItem() {}

void Peternak::sellItem() {}

void Peternak::eat() {}
