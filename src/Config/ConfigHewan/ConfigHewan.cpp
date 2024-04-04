#include "ConfigHewan.hpp"

ConfigHewan::ConfigHewan() {}

ConfigHewan::~ConfigHewan() {}

void ConfigHewan::load() {
    ifstream file("C:/Users/naufn/Documents/gitHub/ABD_LoveGreen/src/Config/ConfigHewan/Animal.txt");
    if (!file.is_open()) {
        cerr << "ex handler nih gagal membuka file Animal.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id, weight, price;
        string code, name, type;
        ss >> id >> code >> name >> type >> weight >> price;
        Hewan *hewan = nullptr;
        if (type == "HERBIVORE") {
            hewan = new Herbivora(id, weight, price, code, name); 
        } else if (type == "CARNIVORE") {
            hewan = new Karnivora(id, weight, price, code, name);
        } else if (type == "OMNIVORE") {
            hewan = new Omnivora(id, weight, price, code, name);
        }
        if (hewan) { 
            listHewan[code] = hewan;
        }
    }

    file.close();
}

Hewan* ConfigHewan::findHewan(string code) {
    if (listHewan.find(code) != listHewan.end()) {
        return listHewan[code];
    }
    return nullptr;
}
