#include "Petani.hpp"
#include "Peternak.hpp"

int main() {
    string username = "username";
    int kekayaan = 1000;
    // Petani petani(username, kekayaan);
    // petani.getInventory().updateCell(2, 1, " ATL ");
    // petani.getInventory().updateCell(3, 1, " BNT ");
    // petani.getInventory().updateCell(4, 1, " BNT ");
    // petani.getInventory().updateCell(5, 3, " ALT ");
    // petani.getInventory().updateCell(5, 4, " BNT ");
    // petani.getInventory().updateCell(6, 1, " SDT ");
    // petani.getInventory().updateCell(6, 4, " SDT ");
    // petani.getInventory().updateCell(6, 5, " ALT ");
    // petani.tanam();
    // petani.cetak_ladang();
    // petani.cetak_penyimpanan();
    Peternak peternak(username, kekayaan);
    peternak.getInventory().updateCell(2, 1, " CHK ");
    peternak.getInventory().updateCell(3, 1, " COW ");
    peternak.getInventory().updateCell(4, 1, " COW ");
    peternak.getInventory().updateCell(5, 3, " SNK ");
    peternak.getInventory().updateCell(5, 4, " COW ");
    peternak.getInventory().updateCell(6, 1, " COW ");
    peternak.getInventory().updateCell(6, 4, " SNK ");
    peternak.getInventory().updateCell(6, 5, " SNK ");
    peternak.ternak();
    peternak.cetak_peternakan();
    peternak.cetak_penyimpanan();
    return 0;
}