#include "Penyimpanan.hpp"

using namespace std;

// CETAK_PENYIMPANAN
Penyimpanan::Penyimpanan() : rows(8), cols(8), grid(rows, vector<string>(cols, "")) {}

Penyimpanan::Penyimpanan(int numRows, int numCols) : rows(numRows), cols(numCols), grid(rows, vector<string>(cols, "")) {}

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
            cout << setw(5) << grid[i][j] << "|";
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

void Penyimpanan::updateCell(int row, int col, const string& value) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid[row - 1][col] = value;
    }
}

int Penyimpanan::hitungSlotKosong() {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j].empty()) {
                ++count;
            }
        }
    }
    return count;
}

string Penyimpanan::ambilItem(int row, int col) {
    string item = "";
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        item = grid[row - 1][col];
        grid[row - 1][col] = ""; 
    }
    return item;
}

// Function Overloading
void Penyimpanan::tambahItem(const string& jenisItem) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j].empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        grid[emptyRow][emptyCol] = jenisItem;
        cout << "Bangunan " << jenisItem << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan bangunan baru." << endl;
    }
}

// Operator Overloading
void Penyimpanan::operator+(const string& item) {
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
        siapPanen = true;
        for (int j = 0; j < cols; ++j) {
            string cellValue = grid[i][j];
            if (cellValue == " BNT " || cellValue == " ALT " || cellValue == " SDT ") {
                if ((cellValue == " ALT " || cellValue == " SDT ") && siapPanen) {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << cellValue << RESET << "|";
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

void Ladang::tanamTanaman(int row, int col, const string& jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid[row - 1][col] = jenis;
    }
}

string Ladang::ambilItem(int row, int col) {
    string item = "";
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        item = grid[row - 1][col];
        grid[row - 1][col] = ""; 
    }
    return item;
}

// Function Overloading
void Ladang::tambahTanaman(const string& jenisTanaman) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j].empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        grid[emptyRow][emptyCol] = jenisTanaman;
        cout << "Bangunan " << jenisTanaman << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan bangunan baru." << endl;
    }
}

// Operator Overloading
void Ladang::operator+(const string& tanaman) {
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
        siapPanen = true;
        for (int j = 0; j < cols; ++j) {
            string cellValue = grid[i][j];
            if (cellValue == " COW " || cellValue == " SNK ") {
                if (cellValue == " COW " && siapPanen) {
                    cout << GREEN;
                } else {
                    cout << RED;
                }
            }
            cout << setw(5) << cellValue << RESET << "|";
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
            string cellValue = grid[i][j];
            if (cellValue == " COW ") {
                cout << "- " << static_cast<char>('A' + j)  << setw(2) << setfill('0') << i+1 << ": Cow" << endl;
            } else if (cellValue == " SNK ") {
                cout << "- " << static_cast<char>('A' + j)  << setw(2) << setfill('0') << i+1 << ": Snake" << endl;
            }
        }
    }
}

void Peternakan::ternakHewan(int row, int col, const string& jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid[row - 1][col] = jenis;
    }
}

string Peternakan::ambilItem(int row, int col) {
    string item = "";
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        item = grid[row - 1][col];
        grid[row - 1][col] = ""; 
    }
    return item;
}

// Function Overloading
void Peternakan::tambahTernak(const string& jenisTernak) {
    int emptyRow = -1;
    int emptyCol = -1;
    // Cari slot kosong pertama
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j].empty()) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
        if (emptyRow != -1) break;
    }
    if (emptyRow != -1 && emptyCol != -1) {
        grid[emptyRow][emptyCol] = jenisTernak;
        cout << "Bangunan " << jenisTernak << " berhasil ditambahkan ke penyimpanan." << endl;
    } else {
        cout << "Penyimpanan penuh, tidak dapat menambahkan bangunan baru." << endl;
    }
}

// Operator 
void Peternakan::operator+(const string& ternak) {
    tambahTernak(ternak);
}