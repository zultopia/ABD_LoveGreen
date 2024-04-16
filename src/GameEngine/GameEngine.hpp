#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

using namespace std;
#include <string>

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

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
        void printYellow(const string& text); 
        void printBlue(const string& text); 
        void welcome();
        void genie();
        void run();
};

#endif