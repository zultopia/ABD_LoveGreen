#include <string>
#include "GameEngine.hpp"
#include "../Config/Config.hpp"
#include "../Config/Simpan.hpp"
#include "../Config/Muat.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Toko/toko.hpp"
#include "../Pemain/Pemain.hpp"

GameEngine::GameEngine() {
    finish = false;
}

void GameEngine::setUp() {
    Config::bacaConfig();
    // Config::cekConfig();
    char answer;
    cout << "Apakah Anda ingin memuat state? (y/n) ";
    cin >> answer;
    answer = (char)tolower(answer);
    while(answer != 'y' && answer != 'n'){
        cout << "Apakah Anda ingin memuat state? (y/n) ";
        cin >> answer;
        answer = (char)tolower(answer);
    }
    if (answer == 'y') {
        try{
            Muat::muat();
            // Muat::cekMuat();
            Muat::setUp();
            Toko::displayIsiToko();
        } catch (ConfigException& e){
            cout << e.what() << endl << endl;
            cout << "Default Start" << endl;
            cout << endl;
            defaultSetUp();
        }
    } else {
        defaultSetUp();
    }
}

void GameEngine::defaultSetUp() {
    Toko::setUpToko();
    string nama = "Petani1";
    new Petani(nama, 50, 40);
    nama = "Peternak1";
    new Peternak(nama, 50, 40);
    nama = "Walikota";
    new Walikota(nama, 50, 40);
}

void GameEngine::receiveCommand(){
    cout << "Sekarang giliran " << Pemain::listPemain[Pemain::currentPemain]->getUsername() << ", seorang " << Pemain::listPemain[Pemain::currentPemain]->getRole() << endl;
    cout << "Masukkan perintah: ";
    cin >> command;
    Pemain::listPemain[Pemain::currentPemain]->doCommand(command);
}

void GameEngine::loopCommand() {
    try{
        while (!finish) {
            Pemain* currentPemain = Pemain::listPemain[Pemain::currentPemain];
            receiveCommand();
            if (currentPemain->checkWinCondition()) {
                finish = true;
                cout << "Pemain " << currentPemain->getUsername() << " menang dengan kekayaan " << currentPemain->getUsername() << " gulden dan berat badan " << currentPemain->getBeratBadan() << " kg!" << endl;
                cout << "Game Finished." << endl;
            }
        }
    } catch (exception& e){
        cout << e.what() << endl;
        loopCommand();
    }
    
}

void GameEngine::run() {
    setUp();
    loopCommand();
}