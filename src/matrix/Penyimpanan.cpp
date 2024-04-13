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

void Penyimpanan::tambahItem(int row, int col, Item* jenisItem) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, jenisItem); 
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
            if (grid.getCell(i, j) == nullptr || grid.getCell(i, j)->getCode().empty()) {
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
            if (grid.getCell(i,j) != nullptr) {
                temp.push_back(grid.getCell(i,j)->getName());
            }
        }
    }
    return temp;
}

bool Penyimpanan::checkMakanan(int row, int col){
    if (row <= 0 || row > rows || col < 0 || col >= cols) {
        // Index tidak valid
        return -1;
    } else {
        Item* item = grid.getCell(row-1, col);
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