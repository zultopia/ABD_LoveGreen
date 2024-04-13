// Nih includenya begini biar gampang dicompile
// g++ TesMain.cpp -o TesMain
#include "Config/Config.cpp"
#include "Config/ConfigException.cpp"
#include "Pemain/Pemain.cpp"
#include "Pemain/Petani.cpp"
#include "Pemain/Peternak.cpp"
#include "matrix/Penyimpanan.cpp"
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

    try {
        string username = "username";
        int kekayaan = 1000;
        int beratBadan = 50;
        Petani petani(username, kekayaan, beratBadan);
        // cout << petani.getUsername() << endl;
        // cout << petani.getKekayaan() << endl;
        // cout << petani.getBeratBadan() << endl;

        // for(auto i = plant.cbegin(); i != plant.cend(); i++){
        //     cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
        // }

        for(auto i = product.cbegin(); i != product.cend(); i++){
            cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << " " << get<5>(i->second) << endl;
        }

        string key = "BANANA_TREE";
        if(plant.find(key) != plant.end()){
            cout << get<1>(plant.at(key));
        } else {
            cout << "Tidak ada key" << endl;
        }

        // Produk* basePtr = new ProdukEatable("APPLE");
        // Item* derivedPtr = dynamic_cast<Item*>(basePtr);
        // // Item* derivedPtr2 = petani.getInventory().getGrid().getCell(1, 1);
        // if (derivedPtr) {
        //     // Konversi berhasil
        //     cout << "berhasil\n" << derivedPtr->getName() << derivedPtr->getCode() << endl;
        //     petani.getInventory().updateCell(1, 1, derivedPtr);
        //     petani.getInventory().tambahItem(derivedPtr);
        //     // petani.getInventory().updateCell(1, 1, derivedPtr2);
        //     petani.cetakPenyimpanan();
        //     // Gunakan derivedPtr untuk operasi yang spesifik pada kelas turunan
        // } else {
        //     // Konversi gagal
        //     cout << "gagal\n";
        // }

        // cout << get<1>(plant.cbegin()->second) << "tes" << endl;
        // cout << get<1>(plant.at("ALT")) << "tese" << endl;
        // cout << get<1>(plant.at("ALOE_TREE")) << "teset" << endl;
        Tanaman* i1 = new Tanaman("ALOE_TREE");
        cout << *i1 << endl;
        Tanaman* i2 = new Tanaman("BANANA_TREE");
        Tanaman* i3 = new Tanaman("BANANA_TREE");
        Tanaman* i4 = new Tanaman("ALOE_TREE");
        Tanaman* i5 = new Tanaman("BANANA_TREE");
        Tanaman* i6 = new Tanaman("SANDALWOOD_TREE");
        Tanaman* i7 = new Tanaman("BANANA_TREE");
        Tanaman* i8 = new Tanaman("ALOE_TREE");

        Hewan* h1 = new Omnivora("CHICKEN");
        // cout << *i1 << endl;
        Hewan* h2 = new Karnivora("SNAKE");
        Hewan* h3 = new Karnivora("SNAKE");
        Hewan* h4 = new Herbivora("COW");
        Hewan* h5 = new Karnivora("SNAKE");
        Hewan* h6 = new Omnivora("CHICKEN");
        Hewan* h7 = new Karnivora("SNAKE");
        Hewan* h8 = new Herbivora("COW");


        petani.getInventory().updateCell(2, 1, i1);
        petani.getInventory().updateCell(3, 1, i2);
        petani.getInventory().updateCell(4, 1, i3);
        petani.getInventory().updateCell(5, 3, i4);
        petani.getInventory().updateCell(6, 3, i5);
        petani.getInventory().updateCell(7, 3, i6);
        petani.getInventory().updateCell(8, 3, i7);
        petani.getInventory().updateCell(9, 3, i8);

        petani.getInventory().updateCell(3, 2, h1);
        petani.getInventory().updateCell(4, 2, h2);
        petani.getInventory().updateCell(5, 2, h3);
        petani.getInventory().updateCell(6, 4, h4);
        petani.getInventory().updateCell(7, 4, h5);
        petani.getInventory().updateCell(2, 4, h6);
        petani.getInventory().updateCell(9, 4, h7);
        petani.getInventory().updateCell(9, 5, h8);

        // Item* item = petani.getInventory().getGrid().getCell(2, 1);
        // if (item != nullptr) {
        //     string code = item->getCode();
        //     cout << "Kode Item: " << code << endl;
        // } else {
        //     cout << "Tidak ada Item pada posisi tersebut." << endl;
        // }

        // cout << "tes" << endl;
        // petani.getLadang().tanamTanaman(2, 1, i1);
        // cout << "tes1" << endl;
        // Tanaman* tanaman = petani.getLadang().getGrid().getCell(1, 1);
        // cout << "tes2" << endl;
        // if (tanaman != nullptr) {
        //     string code = tanaman->getCode();
        //     cout << "Kode Tanaman: " << code << endl;
        // } else {
        //     cout << "Tidak ada Tanaman pada posisi tersebut." << endl;
        // }

        // petani.cetak_ladang();
        // petani.cetak_penyimpanan();

        i1->setCurrentDuration(i1->getDurationToHarvest());
        i2->setCurrentDuration(i2->getDurationToHarvest());
        i3->setCurrentDuration(i3->getDurationToHarvest());
        i4->setCurrentDuration(i4->getDurationToHarvest());
        petani.getLadang().tanamTanaman(1, 1, i1);
        petani.getLadang().tanamTanaman(1, 2, i2);
        petani.getLadang().tanamTanaman(1, 3, i3);
        petani.getLadang().tanamTanaman(1, 4, i4);
        petani.getLadang().tanamTanaman(1, 5, i5);
        petani.getLadang().tanamTanaman(1, 6, i6);
        petani.getLadang().tanamTanaman(1, 7, i7);
        petani.getLadang().tanamTanaman(1, 8, i8);
        petani.cetakLadang();
        petani.cetakPenyimpanan();
        // petani.harvest();
        // petani.cetakLadang();
        // petani.cetakPenyimpanan();

        cout << "tes" << endl;
        vector<string> list = petani.getInventory().getListPenyimpanan();
        cout << "tes1" << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << endl;
        }

        // petani.tanam();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Kesalahan. " << e.what() << '\n';
    }
    
    return 0;
}