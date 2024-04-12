#include "Bangunan.hpp"

// Constructor
Bangunan::Bangunan() : Item(), idBangunan(0) {}

// Destructor
Bangunan::~Bangunan() {}

// Getter
int Bangunan::getIdBangunan() const {
    return idBangunan;
}

vector<pair<string, int> > Bangunan::getMaterials() {
    return materials;
}

// Setter
void Bangunan::setIdBangunan(int idBangunan) {
    this->idBangunan = idBangunan;
}

void Bangunan::setMaterials(const vector<pair<string, int> >& materials) {
    this->materials = materials;
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