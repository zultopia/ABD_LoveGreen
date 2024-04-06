#include "Petani.hpp"

Petani::Petani(string& username, int kekayaan) : Pemain(username, kekayaan), ladang() {}

void Petani::tanam() {
    cout << endl;
    cout << "Pilih tanaman dari penyimpanan:" << endl;
    cout << endl;
    inventory.cetakInfo();
    string slot;
    cout << "Slot: "; cin >> slot; cout << endl; 

    pair<int, int> koordinatItem = konversiKoordinat(slot);
    // cout << koordinatItem.first << " " << koordinatItem.second << endl;
    string item = inventory.ambilItem(koordinatItem.first + 1, koordinatItem.second);
    cout << "Kamu memilih " << item << "." << endl;

    cout << endl;
    cout << "Pilih petak tanah yang akan ditanami" << endl;
    cout << endl;
    ladang.cetakInfo();
    string petak;
    cout << endl;
    cout << "Petak tanah: "; cin >> petak; cout << endl; 
    pair<int, int> koordinatPetak = konversiKoordinat(petak);
    // cout << koordinatPetak.first << " " << koordinatPetak.second << endl;

    ladang.tanamTanaman(koordinatPetak.first + 1, koordinatPetak.second, item);
    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << item << "berhasil ditanam!" << endl;
}

void Petani::cetak_ladang() {
    ladang.cetakInfo();
}

void Petani::harvest() {}

void Petani::doCommand(string command) {}

void Petani::bayarPajak() {}

int Petani::calculateTax() { return 0; }

void Petani::buyItem() {}

void Petani::sellItem() {}

void Petani::eat() {}

