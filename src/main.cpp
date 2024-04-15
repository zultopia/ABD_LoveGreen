#include <iostream>
#include <exception>
#include "./GameEngine/GameEngine.hpp"

using namespace std;

int main() {
    GameEngine GE;
    try {
        GE.run();
    } catch (exception& e) {
        cout << e.what() << endl;
        // ????
        // GE.loopCommand();
    }
    return 0;
}