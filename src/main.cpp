#include "./GameEngine/GameEngine.hpp";

int main() {
    GameEngine GE;
    try {
        GE.run();
    } catch (exception e) {
        cout << e.what() << endl;
        GE.loopCommand();
    }
    return 0;
}