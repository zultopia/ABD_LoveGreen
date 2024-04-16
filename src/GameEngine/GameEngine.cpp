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

void GameEngine::welcome() {
    printYellow(" _____ ______ _               __  __       _______   _____       _______       _   _  _____    _____ _____                    ");
    printYellow("/ ____|  ____| |        /\\   |  \\/  |   /\\|__   __| |  __ \\   /\\|__   __|/\\   | \\ | |/ ____|  |  __ \\_   _|                   ");
    printYellow("| (___ | |__  | |       /  \\  | \\  / |  /  \\  | |    | |  | | /  \\  | |  /  \\  |  \\| | |  __   | |  | || |                     ");
    printYellow("\\___ \\|  __| | |      / /\\ \\ | |\\/| | / /\\ \\ | |    | |  | |/ /\\ \\ | | / /\\ \\ | . ` | | |_ |  | |  | || |                     ");
    printYellow("______) | |____| |____ / ____ \\| |  | |/ ____ \\ |    | |__| / ____ \\| |/ ____ \\| |\\  | |__| |  | |__| || |_                    ");
    printYellow("|_____/|______|______/_/    \\_\\_| _|_/_/    \\_\\_|    |_____/_/____\\_\\_/_/  _\\_\\_|_\\_|\\_____|__|_____/_____|___   _____  ____  ");
    printYellow("| |/ /  ____|  __ \\     /\\       | |  /\\        /\\   | \\ | | |  _ \\ / __ \\| \\ | |  __ \\ / __ \\ \\        / / __ \\ / ____|/ __ \\ ");
    printYellow("| ' /| |__  | |__) |   /  \\      | | /  \\      /  \\  |  \\| | | |_) | |  | |  \\| | |  | | |  | \\ \\  /\\  / / |  | | (___ | |  | |");
    printYellow("|  < |  __| |  _  /   / /\\ \\ _   | |/ /\\ \\    / /\\ \\ | . ` | |  _ <| |  | | . ` | |  | | |  | |\\ \\/  \\/ /| |  | |\\___ \\| |  | |");
    printYellow("| . \\| |____| | \\ \\  / ____ \\|__| / ____ \\  / ____ \\| |\\  | | |_) | |__| | |\\  | |__| | |__| | \\  /\\  / | |__| |____) | |__| |");
    printYellow("|_|\\_\\______|_|  \\_\\/_/    \\_\\____/_/    \\_\\/_/    \\_\\_| \\_| |____/ \\____/|_| \\_|_____/ \\____/   \\/  \\/   \\____/|_____/ \\____/");
    printYellow("                                                                                                                                    ");
}

void GameEngine::genie() {
    printBlue("⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⢸⣿⠟⠋⣉⣉⠙⠻⣿⡇⠀⠀⠀⠀⠀");
    printBlue("⠀⠀⠀⠀⠀⠀⠉⢠⣾⣿⣿⣷⡄⠉⠀⠀⠀⠀⠀⠀");
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
    welcome();
    genie();
    setUp();
    loopCommand();
}