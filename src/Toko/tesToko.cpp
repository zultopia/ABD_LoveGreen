// #include "Toko.cpp"
#include "Toko.hpp"

int main(){
    Config::bacaConfig();
    Toko::setUpToko();
    Toko::CetakWalikota();
    // Toko::CetakPeternakPetani();
    Toko::BeliWalikota(15,3);
    Toko::batalBeli("SMALL_HOUSE", 10);
    Toko::batalJual("SNAKE", 10);
    Toko::batalJual("SMALL_HOUSE", 10);
    Toko::CetakPeternakPetani();
}