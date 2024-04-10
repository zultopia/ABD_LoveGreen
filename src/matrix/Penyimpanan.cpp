#include "Penyimpanan.hpp"

using namespace std;

// CETAK_PENYIMPANAN
Penyimpanan::Penyimpanan() : rows(8), cols(8), grid(8, 8) {}

Penyimpanan::Penyimpanan(int numRows, int numCols) : rows(numRows), cols(numCols), grid(numRows, numCols) {} 

void Penyimpanan::cetakInfo() {
    cout << "   =================[ Penyimpanan ]=================" << endl;
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
            cout << setw(5) << (grid.getCell(i, j) != nullptr ? grid.getCell(i, j)->getCode() : "") << "|"; 
        }
        cout << endl;
        cout << setw(4) << "+";
        for (int k = 0; k < cols; ++k) {
            cout << "-----+";
        }
        cout << endl;
    }
    cout << endl;
}

void Penyimpanan::updateCell(int row, int col, Item* value) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, value); 
    }
}

int Penyimpanan::hitungSlotKosong() {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid.getCell(i, j) == nullptr || grid.getCell(i, j)->getCode().empty()) {
                ++count;
            }   
        }
    }
    return count;
}

Grid<Item> Penyimpanan::getGrid() const {
    return grid;
}

Item* Penyimpanan::ambilItem(int row, int col) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        Item* item = grid.getCell(row - 1, col);
        grid.removeItem(row - 1, col);
        return item;
    } else {
        return nullptr;
    }
}

// Function Overloading
void Penyimpanan::tambahItem(Item* jenisItem) {
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
        grid.updateCell(emptyRow, emptyCol, jenisItem);
        cout << "Item " << jenisItem->getCode() << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan item baru." << endl;
    }
}

// Operator Overloading
void Penyimpanan::operator+(Item* item) {
    tambahItem(item);
}

vector<string> Penyimpanan::getListPenyimpanan(){
    vector<string> temp;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp.push_back(grid.getCell(i,j)->getName());
        }
    }
    return temp;
}
// CETAK_LADANG
Ladang::Ladang() : Penyimpanan(), grid(8,8) {}

Ladang::Ladang(int numRows, int numCols) : Penyimpanan(numRows, numCols), grid(numRows, numCols) {}

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
            Tanaman* cellValue = grid.getCell(i, j);
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
    cetakKeteranganTanaman();
}

void Ladang::cetakKeteranganTanaman() {
    map<string, bool> kodeTanamanDicetak;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid.getCell(i, j) != nullptr) {
                string kodeTanaman = grid.getCell(i, j)->getCode();
                if (kodeTanamanDicetak.find(kodeTanaman) == kodeTanamanDicetak.end()) {
                    cout << "- " << kodeTanaman << ": " << grid.getCell(i, j)->getName() << endl;
                    kodeTanamanDicetak[kodeTanaman] = true;
                }
            }
        }
    }
}


void Ladang::tanamTanaman(int row, int col, Tanaman* jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, jenis);
    }
}

Grid<Tanaman> Ladang::getGrid() const {
    return grid;
}

Tanaman* Ladang::ambilTanaman(int row, int col) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        Tanaman* item = grid.getCell(row - 1, col);
        grid.removeItem(row - 1, col);
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
            if (grid.getCell(i, j)->getCode().empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        grid.updateCell(emptyRow, emptyCol, jenisTanaman);
        cout << "Tanaman " << jenisTanaman->getCode() << " berhasil ditambahkan ke ladang." << endl;
    } else {
        cout << "Ladang penuh, tidak dapat menambahkan tanaman baru." << endl;
    }
}

map<string, int> Ladang::hitungJumlahTanamanPanen() {
    map<string, int> jumlahHarvest;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Tanaman* cellValue = grid.getCell(i, j);
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
            char lokasitemp = 'A' + j;
            string temp = string() + lokasitemp;
            string lokasi = temp + "0" + to_string(i+1);
            tempvector.push_back(make_tuple(lokasi,grid.getCell(i,j)->getName(),grid.getCell(i,j)->getCurrentDuration()));
        }
    }
    return tempvector;
}

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
            char lokasitemp = 'A' + cols;
            string lokasi = lokasitemp + "0" + to_string(i+1);
            tempvector.push_back(make_tuple(lokasi,grid.getCell(i,j)->getName(),grid.getCell(i,j)->getCurrentWeight()));
        }
    }
    return tempvector;

}
