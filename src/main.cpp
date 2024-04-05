#include "Config/Config/Config.cpp"
#include "Hewan/BaseHewan/Hewan.cpp"
#include "Hewan/Herbivora/Herbivora.cpp"
#include "Hewan/karnivora/karnivora.cpp"
#include "Hewan/Omnivora/Omnivora.cpp"
#include "Item/Item.cpp"
#include "Produk/BaseProduk/Produk.cpp"
#include "Tanaman/BaseTanaman/Tanaman.cpp"

int main() {
    Config config;
    config.loadFarm("Animal.txt");
    Hewan *hewan1 = new Herbivora(config, "COW");
    hewan1->print();
    config.loadFarm("Plant.txt");
    Item *tanaman1 = new Tanaman(config, "ALT");
    tanaman1->print();
    config.loadProduk("Produk.txt");
    Item *produk1 = new Produk(config, "TEAK_WOOD");
    produk1->print();
}