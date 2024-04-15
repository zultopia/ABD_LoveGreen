#include "Bangunan.hpp"
#include "Item.hpp"
#include "../Config/Config.hpp"

// Constructor
Bangunan::Bangunan() : Item(), idBangunan(0) {}
Bangunan::Bangunan(string nama) : Item(){
    idBangunan = Config::getId(nama);
    setPrice(Config::getPrice(nama));
    setCode(Config::getCode(nama));
    setName(nama);
    materials = Config::getMaterialInfo(nama);
}
// Destructor
Bangunan::~Bangunan() {}

// Getter
int Bangunan::getIdBangunan() const {
    return idBangunan;
}

map<string, int> Bangunan::getMaterials() {
    return materials;
}

// Setter
void Bangunan::setIdBangunan(int idBangunan) {
    this->idBangunan = idBangunan;
}

void Bangunan::setMaterials(const map<string, int>& materials) {
    this->materials = materials;
}
bool Bangunan::eatable() const {
    return false;
}
// Operator overloading 
ostream& operator<<(ostream& os, Bangunan& bangunan) {
    os << "=+=+= INFO BANGUNAN =+=+=" << endl;
    os << "idBangunan           : " << bangunan.getIdBangunan() << endl;
    os << "code                 : " << bangunan.getCode() << endl;
    os << "name                 : " << bangunan.getName() << endl;
    os << "price                : " << bangunan.getPrice() << endl;
    os << "materials            : " << endl;
    for (const auto& material : bangunan.getMaterials()) {
        os << material.first << " - " << material.second << endl;
    } 
    return os;
}