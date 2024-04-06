#include "Peternak.hpp"

Peternak::Peternak(string& username, int kekayaan) : Pemain(username, kekayaan), peternakan() {}

void Peternak::ternak() {
    cout << endl;
    cout << "Pilih hewan dari penyimpanan:" << endl;
    cout << endl;
    inventory.cetakInfo();
    string slot;
    cout << "Slot: "; cin >> slot; cout << endl; 

    pair<int, int> koordinatItem = konversiKoordinat(slot);
    // cout << koordinatItem.first << " " << koordinatItem.second << endl;
    string item = inventory.ambilItem(koordinatItem.first + 1, koordinatItem.second);
    cout << "Kamu memilih " << item << "." << endl;

    cout << endl;
    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    cout << endl;
    peternakan.cetakInfo();
    string petak;
    cout << endl;
    cout << "Petak tanah: "; cin >> petak; cout << endl; 
    pair<int, int> koordinatPetak = konversiKoordinat(petak);
    // cout << koordinatPetak.first << " " << koordinatPetak.second << endl;

    peternakan.ternakHewan(koordinatPetak.first + 1, koordinatPetak.second, item);
    cout << "Dengan hati-hati, kamu meletakkan seekor Chicken di kandang." << endl;
    cout << item << " telah menjadi peliharaanmu sekarang!" << endl;
}

void Peternak::beri_pangan() {}

void Peternak::cetak_peternakan() {
    peternakan.cetakInfo();
}

void Peternak::harvest() {}

void Peternak::doCommand(string command) {}

void Peternak::bayarPajak() {}

int Peternak::calculateTax() {
    if(kekayaan <= 0 && peternakan.hitungSlotKosong() == 0) {
        return 0;
    } else {
        int netoKekayaan = kekayaan + inventory.hitungSlotKosong() + peternakan.hitungSlotKosong();
        int KTKP = 11;
        int KKP = netoKekayaan - KTKP;
        if(KKP <= 0) {
            return 0;
        } else {
            if(KKP <= 6) {
                return KKP * 0.05;
            } else if(KKP > 6 && KKP <= 25) {
                return KKP * 0.15;
            } else if(KKP > 25 && KKP <= 50) {
                return KKP * 0.25;
            } else if(KKP > 50 && KKP <= 500) {
                return KKP * 0.30;
            } else {
                return KKP * 0.35;
            }
        }
    }
}

void Peternak::buyItem() {}

void Peternak::sellItem() {}

void Peternak::eat() {}
