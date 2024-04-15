#include "GameEngine.hpp"

GameEngine::GameEngine() {
    finish = false;
}

void GameEngine::setUp() {
    Toko::setUpToko();
    Config::bacaConfig;
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
        Muat::muat();
    } else {
        defaultSetUp();
    }
}

void GameEngine::defaultSetUp() {
    string nama = "Petani1";
    new Petani(nama, 50, 40);
    nama = "Peternak1";
    new Peternak(nama, 50, 40);
    nama = "Walikota";
    new Walikota(nama, 50, 40);
}

void GameEngine::receiveCommand(){
    cin >> command;
    Pemain::listPemain[Pemain::currentPemain]->doCommand(command);
}

void GameEngine::loopCommand() {
    while (!finish) {
        Pemain* currentPemain = Pemain::listPemain[Pemain::currentPemain];
        receiveCommand();
        if (currentPemain->checkWinCondition()) {
            finish = true;
            cout << "Pemain " << currentPemain->getUsername() << " menang dengan kekayaan " << currentPemain->getUsername() << " gulden dan berat badan " << currentPemain->getBeratBadan() << " kg!" << endl;
            cout << "Game Finished." << endl;
        }
    }
}

void GameEngine::run() {
    setUp();
    loopCommand();
}