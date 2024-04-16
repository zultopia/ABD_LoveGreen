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
#include "../Toko/Toko.hpp"
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
            try{
                Muat::muat();
            } catch(ConfigException& e){
                throw e;
            } catch (...){
                ConfigException e("File tidak valid");
                throw e;
            }
            // Muat::cekMuat();
            Muat::setUp();
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

void GameEngine::printYellow(const string& text) {
    cout << YELLOW << text << RESET << endl;
}

void GameEngine::printBlue(const string& text) {
    cout << BLUE << text << RESET << endl;
}

void GameEngine::welcomeGenie() {
    printYellow(" ___  ____  __      __    __  __    __   ____    ____    __   ____   __    _  _  ___      ____  ____               ");
    printYellow("/ __)( ___)(  )    /__\\  (  \\/  )  /__\\ (_  _)  (  _ \\  /__\\ (_  _) /__\\  ( \\( )/ __)    (  _ \\(_  _)              ");
    printYellow("\\__ \\ )__)  )(__  /(__)\\  )    (  /(__)\\  )(     )(_) )/(__)\\  )(  /(__)\\  )  (( (_-.     )(_) )_)(_               ");
    printYellow("(___/(__)  (____)(__)(__)(_/\\/\\_)(__)(__)(__)   (____/(__)(__)(__)(__)(__)(_)(_)\\___/    (____/(____)              ");
    printYellow(" _  _  ____  ____    __     ____   __      __    _  _    ____  _____  _  _  ____  _____  _    _  _____  ___  _____ ");
    printYellow("( |/ )( ___)(  _ \\  /__\\   (_  _) /__\\    /__\\  ( \\( )  (  _ \\(  _  )( \\( )(  _ \\(  _  )( \\/\\/ )(  _  )/ __)(  _  )");
    printYellow(" )  (  )__)  )   / /(__)\\ .-_)(  /(__)\\  /(__)\\  )  (    ) _ < )(_)(  )  (  )(_) ))(_)(  )    (  )(_)( \\__ \\ )(_)( ");
    printYellow("(_)\\_) (___)(_)\\_)(__)(__)\\____)(__)(__)(__)(__)(_)\\_)  (____/(_____)(_)\\_)(____/(_____)(__/\\__)(_____)(___/(_____)");
    printBlue("⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⢸⣿⠟⠋⣉⣉⠙⠻⣿⡇⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⠀⠉⢠⣾⣿⣿⣷⡄⠉⠀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⣀⣤⡄⠘⣿⣿⣿⣿⠃⢠⣤⣄⡀⠀⠀⠀");
    printBlue("⠀⢀⣴⣿⣿⣿⣿⣦⣈⠉⠉⣁⣴⣿⣿⣿⣷⣄⠀");
    printBlue("⠀⣾⣿⣿⣿⡿⠛⠛⠛⠛⠛⠛⠛⢿⣿⣿⣿⣿⣧");
    printBlue("⢸⣿⣿⣿⣿⣷⣤⣤⣤⡄⢠⣤⣤⣤⣾⣿⣿⣿⣿");
    printBlue("⠀⢻⣿⣿⣿⣿⣿⣿⡿⠁⠀⢻⣿⣿⣿⣿⣿⣿⠏");
    printBlue("⠀⠀⠙⠻⠿⠿⠟⠛⢁⣼⣷⣄⠙⠛⠿⠿⠿⠟⠀");
    printBlue("⠀⠀⠀⠀⠠⣤⣶⣾⣿⣿⣿⣿⣶⣶⠀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣄⡀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⢿⣿⣿⣿⣷⠄");
}

void GameEngine::run() {
    setUp();
    welcomeGenie();
    loopCommand();
}