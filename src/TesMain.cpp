// Nih includenya begini biar gampang dicompile
// g++ TesMain.cpp -o TesMain
#include "Config/Config.cpp"
#include "Config/ConfigException.cpp"
#include "Hewan/BaseHewan/Hewan.cpp"
#include "Hewan/HewanException/HewanException.cpp"
#include "Hewan/Herbivora/Herbivora.cpp"
#include "Hewan/karnivora/karnivora.cpp"
#include "Hewan/Omnivora/Omnivora.cpp"
#include "Item/Item.cpp"
#include "Produk/BaseProduk/Produk.cpp"
#include "Produk/ProdukEatable/ProdukEatable.cpp"
#include "Produk/ProdukUneatable/ProdukUneatable.cpp"
#include "Tanaman/Tanaman.cpp"

int main(){
    map<string,tuple<int,string,string,int,int>>& plant = Config::getPlantMap();
    map<string,tuple<int,string,string,int,int>>& animal = Config::getAnimalMap();
    map<string,tuple<int,string,string,string,int,int>>& product = Config::getProductMap();
    map<string,tuple<int,string,int,map<string,int>>>& recipe = Config::getRecipeMap();

    Config::bacaConfig();

    Hewan *h1 = new Herbivora("COW", 20);
    Hewan *h2 = new Karnivora("SNAKE", 30);
    Hewan *h3 = new Omnivora("DUCK", 1000);
    cout << *h1 << endl;
    cout << *h2 << endl;
    cout << *h3 << endl;

    Tanaman *t1 = new Tanaman("TEAK_TREE", 20);
    Tanaman *t2 = new Tanaman("APPLE_TREE");
    Tanaman *t3 = new Tanaman("ALOE_TREE");
    cout << *t1 << endl;
    cout << *t2 << endl;
    cout << *t3 << endl;

    // Tanaman *t1 = new Tanaman("TEK");
    // cout << *t1 << endl;
    Produk *p1 = new ProdukEatable("APPLE");
    Produk *p2 = new ProdukEatable("APPLE");
    Produk *p3 = new ProdukEatable("APPLE");
    Produk *p4 = new ProdukEatable("APPLE");
    Produk *p5 = new ProdukEatable("APPLE");
    Produk *p6 = new ProdukEatable("APPLE");
    Produk *p7 = new ProdukEatable("APPLE");

    try {
        h1->eat(*p1);
        delete p1;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }
    
    try {
        h1->eat(*p2);
        delete p2;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }

    try {
        h1->eat(*p3);
        delete p3;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }
    try {
        h1->eat(*p4);
        delete p4;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }
    try {
        h1->eat(*p5);
        delete p5;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }
    try {
        h1->eat(*p6);
        delete p6;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }
    try {
        h1->eat(*p7);
        delete p7;
    } catch(InvalidEatingException& e) {
        e.printMessage();
    }

    cout << *h1 << endl;
    if (h1->isHarvest()) {cout << "PANEN BROU" << endl;}

}