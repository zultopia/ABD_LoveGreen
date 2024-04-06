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
            cout << setw(5) << grid.getCell(i, j)->getCode() << "|"; 
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

void Penyimpanan::updateCell(int row, int col, const Item& value) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, value); 
    }
}

int Penyimpanan::hitungSlotKosong() {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid.getCell(i, j) != nullptr && grid.getCell(i, j)->getCode().empty()) {
                ++count;
            }   
        }
    }
    return count;
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
void Penyimpanan::tambahItem(const Item& jenisItem) {
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
        cout << "Item " << jenisItem.getCode() << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan item baru." << endl;
    }
}

// Operator Overloading
void Penyimpanan::operator+(const Item& item) {
    tambahItem(item);
}

// CETAK_LADANG
Ladang::Ladang() : Penyimpanan() {}

Ladang::Ladang(int numRows, int numCols) : Penyimpanan(numRows, numCols) {}

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
            if (cellValue->getCode() == " BNT " || cellValue->getCode() == " ALT " || cellValue->getCode() == " SDT ") {
                if ((cellValue->getCode() == " ALT " || cellValue->getCode() == " SDT ")) {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << cellValue->getCode() << RESET << "|";
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
    cout << "\nKeterangan Kode Tanaman:\n";
    cout << "- ALT: Aloe Tree\n";
    cout << "- BNT: Banana Tree\n";
    cout << "- SDT: Sandalwood Tree\n";
}

void Ladang::tanamTanaman(int row, int col, const Tanaman& jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, jenis);
    }
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
void Ladang::tambahTanaman(const Tanaman& jenisTanaman) {
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
        cout << "Tanaman " << jenisTanaman.getCode() << " berhasil ditambahkan ke ladang." << endl;
    } else {
        cout << "Ladang penuh, tidak dapat menambahkan tanaman baru." << endl;
    }
}

// Operator Overloading
void Ladang::operator+(const Tanaman& tanaman) {
     tambahTanaman(tanaman);
}

// CETAK_PETERNAKAN
Peternakan::Peternakan() : Penyimpanan() {}

Peternakan::Peternakan(int numRows, int numCols) : Penyimpanan(numRows, numCols) {}

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
            if (cellValue->getCode() == " COW " || cellValue->getCode() == " SNK ") {
                if (cellValue->getCode() == " COW ") {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << cellValue->getCode() << RESET << "|";
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
            if (cellValue->getCode() == " COW ") {
                cout << "- " << static_cast<char>('A' + j)  << "0" << i+1 << ": Cow" << endl;
            } else if (cellValue->getCode() == " SNK ") {
                cout << "- " << static_cast<char>('A' + j)  << "0" << i+1 << ": Snake" << endl;
            }
        }
    }
}

void Peternakan::ternakHewan(int row, int col, const Hewan& jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid.updateCell(row - 1, col, jenis); 
    }
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
void Peternakan::tambahTernak(const Hewan& jenisTernak) {
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
        cout << "Ternak " << jenisTernak.getCode() << " berhasil ditambahkan ke peternakan." << endl;
    } else {
        cout << "Peternakan penuh, tidak dapat menambahkan ternak baru." << endl;
    }
}

// Operator Overloading
void Peternakan::operator+(const Hewan& ternak) {
    tambahTernak(ternak);
}