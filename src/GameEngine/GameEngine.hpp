#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

using namespace std;
#include <string>
class GameEngine{
    private:
        string command;
        bool finish;
    public:
        GameEngine();
        void setUp();
        void defaultSetUp();
        void receiveCommand();
        void loopCommand();
        void run();
};

#endif