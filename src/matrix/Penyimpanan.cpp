#include "Penyimpanan.hpp"
#include "../Config/Config.hpp"
#include "../Item/Item.hpp"

using namespace std;

// CETAK_PENYIMPANAN
Penyimpanan::Penyimpanan() : Grid<Item>(Config::getBesarPenyimpanan().first, Config::getBesarPenyimpanan().second) {}

Penyimpanan::Penyimpanan(int numRows, int numCols) : Grid<Item>(numRows, numCols) {}

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
            cout << setw(5) << (getCell(i, j) != nullptr ? getCell(i, j)->getCode() + " " : "") << "|"; 
        }
        cout << endl;
        cout << setw(4) << "+";
        for (int k = 0; k < cols; ++k) {
            cout << "-----+";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Total slot kosong: " << hitungSlotKosong() << endl;
    cout << endl;
}

void Penyimpanan::tambahItem(int row, int col, Item* jenisItem) {
    if (row >= 1 && row <= getRows() && col >= 0 && col < getCols()) {
        updateCell(row - 1, col, jenisItem); 
    }
}

Item* Penyimpanan::ambilItem(int row, int col) {
    if (row >= 1 && row <= getRows() && col >= 0 && col < getCols()) {
        Item* item = getCell(row - 1, col);
        removeItem(row - 1, col);
        return item;
    } else {
        return nullptr;
    }
}

Item* Penyimpanan::ambilItem(string slot) {
    pair<int, int> koordinatItem = Penyimpanan::konversiKoordinat(slot);
    return ambilItem(koordinatItem.first + 1, koordinatItem.second);
}

// Function Overloading
void Penyimpanan::tambahItem(Item* jenisItem) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            if (getCell(i, j) == nullptr || getCell(i, j)->getCode().empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        updateCell(emptyRow, emptyCol, jenisItem);
        cout << "Item " << jenisItem->getName() << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan item baru." << endl;
    }
}

// Operator Overloading
void Penyimpanan::operator+(Item* item) {
    tambahItem(item);
}

int Penyimpanan::jumlahItem(string nama) {
    int jumlah = 0;
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (getCell(i, j)->getName().compare(nama) == 0) {
                jumlah++;
            }
        }
    }
    return jumlah;
}

bool Penyimpanan::checkMakanan(int row, int col){
    if (row <= 0 || row > rows || col < 0 || col >= cols) {
        // Index tidak valid
        return -1;
    } else {
        Item* item = getCell(row-1, col);
        if (item == nullptr) {
            // Penyimpanan di index tersebut kosong
            return 1;
        } else if (!(item->eatable())) {
            // Penyimpanan di index tersebut bukan makanan
            return 2;
        } else {
            // Item bisa dimakan
            return 0;
        }
    }
}