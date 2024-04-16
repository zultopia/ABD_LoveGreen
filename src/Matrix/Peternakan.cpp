#include "Peternakan.hpp"
#include <climits>

// CETAK_PETERNAKAN
Peternakan::Peternakan() : Grid<Hewan>(Config::getBesarPeternakan().first, Config::getBesarPeternakan().second) {}

Peternakan::Peternakan(int numRows, int numCols) : Grid<Hewan>(numRows, numCols) {}

void Peternakan::cetakInfo() {
    cout << "   ===================[ Peternakan ]================" << endl;
    cout << setw(5) << " ";
    for (char c = 'A'; c <= 'A' + cols - 1; ++c) {
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
            Hewan* cellValue = getCell(i, j);
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
    cetakLokasiHewan();
}

void Peternakan::cetakLokasiHewan() {
    cout << "\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Hewan* cellValue = getCell(i, j);
            if (cellValue != nullptr) {
                cout << "- " << static_cast<char>('A' + j)  << "0" << i+1 << ": " << cellValue->getName() << endl;
            }
        }
    }
}

void Peternakan::tambahHewan(int row, int col, Hewan* jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        updateCell(row - 1, col, jenis); 
    }
}

Hewan* Peternakan::ambilTernak(int row, int col) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        Hewan* item = getCell(row - 1, col);
        removeItem(row - 1, col);
        return item;
    } else {
        return nullptr;
    }
}

// Function Overloading
void Peternakan::tambahHewan(Hewan* jenisTernak) {
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
        updateCell(emptyRow, emptyCol, jenisTernak);
        cout << "Ternak " << jenisTernak->getCode() << " berhasil ditambahkan ke peternakan.\n" << endl;
    } else {
        cout << "Peternakan penuh, tidak dapat menambahkan ternak baru.\n" << endl;
    }
}

void Peternakan::menanamTernak(Item* item) {
    string nama = item->getName();
    bool ternakBerhasil = false;
    while (!ternakBerhasil) {
        cout << endl << "Pilih petak tanah yang akan ditinggali\n" << endl;
        cetakInfo();

        string petak;
        cout << endl << "Petak tanah: "; cin >> petak; cout << endl; 

        pair<int, int> koordinatPetak = konversiKoordinat(petak);
        if (isCellValid(koordinatPetak.first, koordinatPetak.second)) {
            if (getCell(koordinatPetak.first, koordinatPetak.second) != nullptr) {
                cout << "Petak tanah tersebut sudah ditempati. Pilih petak lain." << endl;
            } else {
                Hewan* hewan;
                string type = get<2>(Config::getAnimalMap()[nama]);
                if (type.compare("CARNIVORE") == 0) { hewan = new Karnivora(nama); } 
                else if (type.compare("HERBIVORE") == 0) { hewan = new Herbivora(nama); } 
                else { hewan = new Omnivora(nama); }
                tambahHewan(koordinatPetak.first + 1, koordinatPetak.second, hewan);
                cout << "Dengan hati-hati, kamu meletakkan seekor "<< hewan->getName() << " di kandang." << endl;
                cout << hewan->getName() << " telah menjadi peliharaanmu sekarang!\n" << endl;
                ternakBerhasil = true;
            }
        } else {
            cout << "Petak kandang tidak valid!\n" << endl;
        }
    }
}

map<string, int> Peternakan::hitungJumlahHewanPanen() {
    map<string, int> jumlahHarvest;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Hewan* cellValue = getCell(i, j);
            if (cellValue != nullptr && cellValue->isHarvest()) {
                string kodeHewan = cellValue->getCode();
                if (jumlahHarvest.find(kodeHewan) == jumlahHarvest.end()) {
                    jumlahHarvest[kodeHewan] = 1;
                } else {
                    jumlahHarvest[kodeHewan] += 1;
                }
            }
        }
    }
    return jumlahHarvest;
}

// Operator Overloading
void Peternakan::operator+(Hewan* ternak) {
    tambahHewan(ternak);
}

vector<tuple<string,string,int>> Peternakan::getDaftarIsi(){
    vector<tuple<string,string,int>> tempvector;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (getCell(i,j) != nullptr) {
                char lokasitemp = 'A' + j;
                string temp = string() + lokasitemp;
                string lokasi = temp + "0" + to_string(i+1);
                tempvector.push_back(make_tuple(lokasi,getCell(i,j)->getName(),getCell(i,j)->getCurrentWeight()));
            }
        }
    }
    return tempvector;

}

void Peternakan::wabah() {
    int minBeratBadan = INT_MAX;
    int minRow = -1, minCol = -1;

    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            Hewan* hewan = getCell(i, j);
            if (hewan != nullptr && hewan->getCurrentWeight() < minBeratBadan) {
                minBeratBadan = hewan->getCurrentWeight();
                minRow = i;
                minCol = j;
            }
        }
    }
    // Menghapus hewan dengan berat terendah
    if (minRow != -1 && minCol != -1) {
        Hewan* hewan = getCell(minRow, minCol);
        removeItem(minRow, minCol); 
        delete hewan; 
        cout << "Sebuah hewan telah mati akibat wabah di peternakan." << endl;
    }
}