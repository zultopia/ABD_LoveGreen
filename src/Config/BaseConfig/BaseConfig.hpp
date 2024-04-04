#ifndef BASECONFIG_HPP
#define BASECONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BaseConfig {  
    public:
        BaseConfig(){};
        ~BaseConfig(){};
        virtual void load() = 0;
};

#endif