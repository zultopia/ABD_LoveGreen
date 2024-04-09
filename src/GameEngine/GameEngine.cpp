#include "GameEngine.hpp"

string GameEngine::command;

void GameEngine::ReceiveCommand(){
    cin >> command;
    Pemain::listPemain[Pemain::currentPemain]->doCommand(command);
}