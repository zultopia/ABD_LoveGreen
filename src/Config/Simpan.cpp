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

void Simpan::update(){
    pemain.clear();
    for(auto i = Pemain::listPemain.begin(); i != Pemain::listPemain.end(); i++){
        pemain.push_back((*i)->Pemain::getUsername());
        string role;
        role = (*i)->getRole();
        dataPemain[(*i)->Pemain::getUsername()] = make_tuple(role,(*i)->getBeratBadan(), (*i)->getKekayaan());
        inventory[(*i)->Pemain::getUsername()] = (*i)->getDaftarInventory();
        if((*i)->getRole() == "petani"){
            Petani* currenPetani = (Petani*)(*i);
            LadangdanTernak[(*i)->getUsername()] = currenPetani->getDaftarIsi();
        }
        if((*i)->getRole() == "peternak"){
            Peternak* currenPetani = (Peternak*)(*i);
            LadangdanTernak[(*i)->getUsername()] = currenPetani->getDaftarIsi();
        }
        toko.clear();
        toko = Toko::getIsiToko();
    }
}