#include <iostream>
#include "Simpan.cpp"

int main() {
    Simpan simpan;
    try {
        simpan.simpan();
    } catch(const ConfigException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}