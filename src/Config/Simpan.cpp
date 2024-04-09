#include "Simpan.hpp"

using namespace std;

void Simpan::simpan(string path) {
    // Memeriksa folder sudah ada atau belum
    if(!filesystem::exists(filesystem::path(path).parent_path())) {
        ConfigException e("Lokasi berkas tidak valid");
        throw e;
    }

    ofstream outputFile(path, ios::out);

    // Memeriksa file bisa dibuka atau tidak
    if(!outputFile.is_open()) {
        ConfigException e("File tidak dapat dibuka.");
        throw e;
    }

    // Data pemain ditulis
    outputFile << getPemain().size() << endl;
    for (const auto& pemain : getPemain()) {
        outputFile << get<0>(getDataPemain()[pemain]) << " ";
        outputFile << get<1>(getDataPemain()[pemain]) << " ";
        outputFile << get<2>(getDataPemain()[pemain]) << endl;

        // Inventory ditulis
        outputFile << getInventory()[pemain].size() << endl;
        for (const auto& inventory : getInventory()[pemain]) {
            outputFile << inventory << endl;
        }

        // Ladang (petani) atau peternakan (peternak) ditulis
        if (get<0>(getDataPemain()[pemain]) != "Walikota") {
            outputFile << getLadangdanTernak()[pemain].size() << endl;
            for (const auto& ladangTernak : getLadangdanTernak()[pemain]) {
                outputFile << get<0>(ladangTernak) << " ";
                outputFile << get<1>(ladangTernak) << " ";
                outputFile << get<2>(ladangTernak) << endl;
            }
        }
    }

    // Data toko ditulis
    outputFile << getToko().size() << endl;
    for (const auto& item : getToko()) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
    cout << "State berhasil disimpan" << endl;
}