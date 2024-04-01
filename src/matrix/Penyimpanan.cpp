#include "Penyimpanan.hpp"

using namespace std;

// CETAK_PENYIMPANAN
Penyimpanan::Penyimpanan() : rows(8), cols(8), grid(rows, vector<string>(cols, "")) {}

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

// CETAK_LADANG
Ladang::Ladang() : Penyimpanan() {}

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
    cout << "\n- ALT: Aloe Tree\n- BNT: Banana Tree\n- SDT: Sandalwood Tree" << endl;
}

void Ladang::tanamTanaman(int row, int col, const string& jenis) {
    if (row >= 1 && row <= rows && col >= 0 && col < cols) {
        grid[row - 1][col] = jenis;
    }
}

// CETAK_PETERNAKAN
Peternakan::Peternakan() : Penyimpanan() {}

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
