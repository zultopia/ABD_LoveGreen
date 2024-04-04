#ifndef HEWANCONFIG_HPP
#define HEWANCONFIG_HPP

#include <map>
#include "../BaseConfig/BaseConfig.hpp"
#include "../../Hewan/BaseHewan/Hewan.hpp"
#include "../../Hewan/Herbivora/Herbivora.hpp"
#include "../../Hewan/Karnivora/Karnivora.hpp"
#include "../../Hewan/Omnivora/Omnivora.hpp"

using namespace std;

class ConfigHewan : BaseConfig {
    private:
        map<string, Hewan*> listHewan;
    
    public:
        ConfigHewan();
        ~ConfigHewan();
        void load();
        Hewan* findHewan(string code);
};

#endif