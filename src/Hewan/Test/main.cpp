#include "../Config/ConfigHewan/ConfigHewan.cpp"
#include "BaseHewan/Hewan.cpp"
#include "Herbivora/Herbivora.cpp"
#include "Karnivora/Karnivora.cpp"
#include "Omnivora/Omnivora.cpp"
#include "../Produk/Produk.cpp"
#include "../Config/ConfigProduk/ConfigProduk.cpp"

int main() {
    ConfigHewan ch;
    ch.load();
    Hewan *h = ch.findHewan("COW");
    cout << *h << endl;
}