#include "Simpan.hpp"
#include "ConfigException.hpp"
#include <filesystem>

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
    outputFile << Muat::getPemain().size() << endl;
    for (const auto& pemain : Muat::getPemain()) {
        outputFile << get<0>(Muat::getDataPemain()[pemain]) << " ";
        outputFile << get<1>(Muat::getDataPemain()[pemain]) << " ";
        outputFile << get<2>(Muat::getDataPemain()[pemain]) << endl;

        // Inventory ditulis
        outputFile << Muat::getInventory()[pemain].size() << endl;
        for (const auto& inventory : Muat::getInventory()[pemain]) {
            outputFile << inventory << endl;
        }

        // Ladang (petani) atau peternakan (peternak) ditulis
        if (get<0>(Muat::getDataPemain()[pemain]) != "Walikota") {
            outputFile << Muat::getLadangdanTernak()[pemain].size() << endl;
            for (const auto& ladangTernak : Muat::getLadangdanTernak()[pemain]) {
                outputFile << get<0>(ladangTernak) << " ";
                outputFile << get<1>(ladangTernak) << " ";
                outputFile << get<2>(ladangTernak) << endl;
            }
        }
    }

    // Data toko ditulis
    outputFile << Muat::getToko().size() << endl;
    for (const auto& item : Muat::getToko()) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
    cout << "State berhasil disimpan" << endl;
}