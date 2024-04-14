#include "HewanException.hpp"

InvalidEatingException::InvalidEatingException(string pemakan, string makanan) {
    this->pemakan = pemakan;
    this->makanan = makanan;
}

void InvalidEatingException::printMessage() {
    cout << pemakan << " tidak bisa memakan " << makanan << "." << endl;
}