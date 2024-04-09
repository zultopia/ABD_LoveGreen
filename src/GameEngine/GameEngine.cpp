#include "GameEngine.hpp"

string GameEngine::command;
static map<string,int> commandTable = {
    {"NEXT",1},
    {"CETAK_PENYIMPANAN",2},
    {"PUNGUT_PAJAK",3},
    {"CETAK_LADANG",4},
    {"CETAK_PETERNAKAN",5},
    {"TANAM",6},
    {"TERNAK",7},
    {"BANGUN",8},
    {"MAKAN",9},
    {"KASIH_MAKAN",10},
    {"BELI",11},
    {"JUAL",12},
    {"PANEN",13},
    {"MUAT",14},
    {"SIMPAN",15},
    {"TAMBAH_PEMAIN",16}
};
void GameEngine::ReceiveCommand(){
    cin >> command;
    if(commandTable.find(command) == commandTable.end()){
        // throw error
    }
    switch (commandTable[command])
    {
    case 1:
        Next();
        break;
    case 2:
        CetakPenyimpanan();
        break;
    case 3:
        PungutPajak();
        break;
    case 4:
        CetakLadang();
        break;
    case 5:
        CetakPeternakan();
        break;
    case 6:
        Tanam();
        break;
    case 7:
        Ternak();
        break;
    case 8:
        BangunBangunan();
        break;
    case 9:
        Makan();
        break;
    case 10:
        KasihMakan();
        break;
    case 11:
        Membeli();
        break;
    case 12:
        Menjual();
        break;
    case 13:
        Memanen();
        break;
    case 14:
        Muat();
        break;
    case 15:
        Simpan();
        break;
    case 16:
        TambahPemain();
        break;
    default:
        break;
    }
}
void GameEngine::Next(){

}
void GameEngine::CetakPenyimpanan(){
    
}
void GameEngine::PungutPajak(){

}
void GameEngine::CetakLadang(){

}
void GameEngine::CetakPeternakan(){

}
void GameEngine::Tanam(){

}
void GameEngine::Ternak(){

}
void GameEngine::BangunBangunan(){

}
void GameEngine::Makan(){

}
void GameEngine::KasihMakan(){

}
void GameEngine::Membeli(){

}
void GameEngine::Menjual(){

}
void GameEngine::Memanen(){

}
void GameEngine::Muat(){

}
void GameEngine::Simpan(){

}
void GameEngine::TambahPemain(){

}