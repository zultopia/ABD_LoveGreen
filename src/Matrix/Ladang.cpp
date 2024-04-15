#include "Ladang.hpp"
#include "Grid.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Config/Config.hpp"

// CETAK_LADANG
Ladang::Ladang() : Grid<Tanaman>(Config::getBesarLahan().first, Config::getBesarLahan().second) {}

Ladang::Ladang(int numRows, int numCols) : Grid<Tanaman>(numRows, numCols) {}

void Ladang::cetakInfo() {
    cout << "   ====================[ Ladang ]===================" << endl;
    cout << setw(5) << " ";
    for (char c = 'A'; c <= 'A' + cols - 1 ; ++c) {
        cout << setw(2) << c;
        cout << "    ";
    }
    cout << endl;

    cout << setw(4) << "+";
    for (int i = 0; i < cols; ++i) {
        cout << "-----+";
    }
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        if (i < 9) {
            cout << "0" << i + 1;
        } else {
            cout << i + 1;
        }
        cout << setw(2) << "|";
        for (int j = 0; j < cols; ++j) {
            Tanaman* cellValue = getCell(i, j);
            if (cellValue != nullptr) {
                if (cellValue->isHarvest()) {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << (cellValue != nullptr ? cellValue->getCode() + " " : "") << RESET << "|";
        }
        cout << endl;
        cout << setw(4) << "+";
        for (int k = 0; k < cols; ++k) {
            cout << "-----+";
        }
        cout << endl;
    }
    cetakKeteranganTanaman();
}

void Ladang::cetakKeteranganTanaman() {
    map<string, bool> kodeTanamanDicetak;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (getCell(i, j) != nullptr) {
                string kodeTanaman = getCell(i, j)->getCode();
                if (kodeTanamanDicetak.find(kodeTanaman) == kodeTanamanDicetak.end()) {
                    cout << "- " << kodeTanaman << ": " << getCell(i, j)->getName() << endl;
                    kodeTanamanDicetak[kodeTanaman] = true;
                }
            }
        }
    }
}

void Ladang::tambahTanaman(int row, int col, Tanaman* jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        updateCell(row - 1, col, jenis);
    }
}

Tanaman* Ladang::ambilTanaman(int row, int col) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        Tanaman* item = getCell(row - 1, col);
        removeItem(row - 1, col);
        return item;
    } else {
        return nullptr;
    }
}

// Function Overloading
void Ladang::tambahTanaman(Tanaman* jenisTanaman) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (getCell(i, j)->getCode().empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        updateCell(emptyRow, emptyCol, jenisTanaman);
        cout << "Tanaman " << jenisTanaman->getCode() << " berhasil ditambahkan ke ladang." << endl;
    } else {
        cout << "Ladang penuh, tidak dapat menambahkan tanaman baru." << endl;
    }
}

void Ladang::menanamTanaman(Item* item) {
    bool tanamBerhasil = false;
    while (!tanamBerhasil) {
        cout << "Pilih petak tanah yang akan ditanami\n" << endl;
        cetakInfo();

        string petak;
        cout << endl << "Petak tanah: "; cin >> petak; cout << endl;

        pair<int, int> koordinatPetak = konversiKoordinat(petak);

        if (getCell(koordinatPetak.first, koordinatPetak.second) != nullptr) {
            cout << "Petak tanah tersebut sudah ditanami. Pilih petak lain." << endl;
        } else {
            Tanaman* tanaman = new Tanaman(item->getName());
            tambahTanaman(koordinatPetak.first + 1, koordinatPetak.second, tanaman);
            cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
            cout << item->getName() << " berhasil ditanam di petak " << petak << endl;
            tanamBerhasil = true;
        }
    }
}

map<string, int> Ladang::hitungJumlahTanamanPanen() {
    map<string, int> jumlahHarvest;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Tanaman* cellValue = getCell(i, j);
            if (cellValue != nullptr && cellValue->isHarvest()) {
                string kodeTanaman = cellValue->getCode();
                if (jumlahHarvest.find(kodeTanaman) == jumlahHarvest.end()) {
                    jumlahHarvest[kodeTanaman] = 1;
                } else {
                    jumlahHarvest[kodeTanaman] += 1;
                }
            }
        }
    }
    return jumlahHarvest;
}

// Operator Overloading
void Ladang::operator+(Tanaman* tanaman) {
    tambahTanaman(tanaman);
}

vector<tuple<string,string,int>> Ladang::getDaftarIsi(){
    vector<tuple<string,string,int>> tempvector;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (getCell(i,j) != nullptr) {
                char lokasitemp = 'A' + j;
                string temp = string() + lokasitemp;
                string lokasi = temp + "0" + to_string(i+1);
                tempvector.push_back(make_tuple(lokasi,getCell(i,j)->getName(),getCell(i,j)->getCurrentDuration()));
            }
        }
    }
    return tempvector;
}