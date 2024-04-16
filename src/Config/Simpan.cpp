#include "Simpan.hpp"
#include "SimpanMuat.hpp"
#include "../Toko/Toko.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"

using namespace std;

void Simpan::simpan() {
    cout << "Masukkan lokasi berkas state: ";
    string path;
    getline(cin, path);

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

    update();

    // Data pemain ditulis
    outputFile << pemain.size() << endl;
    for (const auto& username : pemain) {
        outputFile << username << " ";
        outputFile << get<0>(dataPemain[username]) << " ";
        outputFile << get<1>(dataPemain[username]) << " ";
        outputFile << get<2>(dataPemain[username]) << endl;

        // Inventory ditulis
    
        outputFile << inventory[username].size() << endl;
        for (const auto& i : inventory[username]) {
            outputFile << i << endl;
        }

        // Ladang (petani) atau peternakan (peternak) ditulis
        if (get<0>(dataPemain[username]) != "Walikota") {
            outputFile << getLadangdanTernak()[username].size() << endl;
            for (const auto& ladangTernak : LadangdanTernak[username]) {
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

    char choice;
    cout << "Apakah Anda ingin melanjutkan permainan? (Y/N): ";
    cin >> choice;
    if (toupper(choice) == 'N') {
        // Menutup game 
        exit(0); 
    }
}

void Simpan::update(){
    pemain.clear();
    for(auto i = Pemain::listPemain.begin(); i != Pemain::listPemain.end(); i++){
        pemain.push_back((*i)->Pemain::getUsername());
        string role;
        role = (*i)->getRole();
        dataPemain[(*i)->Pemain::getUsername()] = make_tuple(role,(*i)->getBeratBadan(), (*i)->getKekayaan());
        inventory[(*i)->Pemain::getUsername()] = (*i)->getDaftarInventory();
        
        if((*i)->getRole() == "Petani"){
            Petani* currenPetani = (Petani*)(*i);
            LadangdanTernak[(*i)->getUsername()] = currenPetani->getDaftarIsi();
        }
        if((*i)->getRole() == "Peternak"){
            Peternak* currenPeternak = (Peternak*)(*i);
            LadangdanTernak[(*i)->getUsername()] = currenPeternak->getDaftarIsi();
        }
        toko.clear();
        toko = Toko::getIsiToko();
    }
}