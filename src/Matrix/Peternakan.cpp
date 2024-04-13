#include "Peternakan.hpp"

// CETAK_PETERNAKAN
Peternakan::Peternakan() : Penyimpanan(), grid(8,8) {}

Peternakan::Peternakan(int numRows, int numCols) : Penyimpanan(numRows, numCols), grid(numRows, numCols) {}

void Peternakan::cetakInfo() {
    cout << "   ===================[ Peternakan ]================" << endl;
    cout << setw(5) << " ";
    for (char c = 'A'; c <= 'H'; ++c) {
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
            Hewan* cellValue = grid.getCell(i, j);
            if (cellValue != nullptr) {
                if (cellValue->isHarvest()) {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << (cellValue != nullptr ? cellValue->getCode() : "") << RESET << "|";
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
            Hewan* cellValue = grid.getCell(i, j);
            if (cellValue != nullptr) {
                cout << "- " << static_cast<char>('A' + j)  << "0" << i+1 << ": " << cellValue->getName() << endl;
            }
        }
    }
}

void Peternakan::ternakHewan(int row, int col, Hewan* jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, jenis); 
    }
}

Grid<Hewan> Peternakan::getGrid() const {
    return grid;
}

Hewan* Peternakan::ambilTernak(int row, int col) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        Hewan* item = grid.getCell(row - 1, col);
        grid.removeItem(row - 1, col);
        return item;
    } else {
        return nullptr;
    }
}

// Function Overloading
void Peternakan::tambahTernak(Hewan* jenisTernak) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid.getCell(i, j)->getCode().empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        grid.updateCell(emptyRow, emptyCol, jenisTernak);
        cout << "Ternak " << jenisTernak->getCode() << " berhasil ditambahkan ke peternakan." << endl;
    } else {
        cout << "Peternakan penuh, tidak dapat menambahkan ternak baru." << endl;
    }
}

map<string, int> Peternakan::hitungJumlahHewanPanen() {
    map<string, int> jumlahHarvest;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Hewan* cellValue = grid.getCell(i, j);
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
    tambahTernak(ternak);
}

vector<tuple<string,string,int>> Peternakan::getDaftarIsi(){
    vector<tuple<string,string,int>> tempvector;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (grid.getCell(i,j) != nullptr) {
                char lokasitemp = 'A' + j;
                string temp = string() + lokasitemp;
                string lokasi = temp + "0" + to_string(i+1);
                tempvector.push_back(make_tuple(lokasi,grid.getCell(i,j)->getName(),grid.getCell(i,j)->getCurrentWeight()));
            }
        }
    }
    return tempvector;

}