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
        Peternak peternak(username, kekayaan, beratBadan);

        for(auto i = animal.cbegin(); i != animal.cend(); i++){
            cout << get<0>(i->second) << " " << i->first << " " << get<1>(i->second) << " " << get<2>(i->second) << " "<< get<3>(i->second)<< " " << get<4>(i->second) << endl;
        }

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

        peternak.getInventory().updateCell(2, 1, i1);
        peternak.getInventory().updateCell(3, 1, i2);
        peternak.getInventory().updateCell(4, 1, i3);
        peternak.getInventory().updateCell(5, 3, i4);
        peternak.getInventory().updateCell(6, 3, i5);
        peternak.getInventory().updateCell(7, 3, i6);
        peternak.getInventory().updateCell(8, 3, i7);
        peternak.getInventory().updateCell(9, 3, i8);

        peternak.getInventory().updateCell(3, 2, h1);
        peternak.getInventory().updateCell(4, 2, h2);
        peternak.getInventory().updateCell(5, 2, h3);
        peternak.getInventory().updateCell(6, 4, h4);
        peternak.getInventory().updateCell(7, 4, h5);
        peternak.getInventory().updateCell(2, 4, h6);
        peternak.getInventory().updateCell(9, 4, h7);
        peternak.getInventory().updateCell(9, 5, h8);

        // Item* item = peternak.getInventory().getGrid().getCell(2, 1);
        // if (item != nullptr) {
        //     string code = item->getCode();
        //     cout << "Kode Item: " << code << endl;
        // } else {
        //     cout << "Tidak ada Item pada posisi tersebut." << endl;
        // }

        // cout << "tes" << endl;
        // peternak.getPeternakan().ternakHewan(2, 1, i1);
        // cout << "tes1" << endl;
        // Hewan* hewan = peternak.getPeternakan().getGrid().getCell(1, 1);
        // cout << "tes2" << endl;
        // if (hewan != nullptr) {
        //     string code = hewan->getCode();
        //     cout << "Kode Tanaman: " << code << endl;
        // } else {
        //     cout << "Tidak ada Tanaman pada posisi tersebut." << endl;
        // }

        // peternak.cetak_peternakan();
        // peternak.cetak_penyimpanan();

        // cout << peternak.getUsername() << endl;
        // cout << peternak.getKekayaan() << endl;
        h1->setCurrentWeight(h1->getWeightToHarvest());
        h2->setCurrentWeight(h2->getWeightToHarvest());
        h3->setCurrentWeight(h3->getWeightToHarvest());
        h4->setCurrentWeight(h4->getWeightToHarvest());
        h5->setCurrentWeight(h5->getWeightToHarvest() - 3);
        peternak.getPeternakan().ternakHewan(1, 1, h1);
        peternak.getPeternakan().ternakHewan(1, 2, h2);
        peternak.getPeternakan().ternakHewan(1, 3, h3);
        peternak.getPeternakan().ternakHewan(1, 4, h4);
        peternak.getPeternakan().ternakHewan(1, 5, h5);
        peternak.getPeternakan().ternakHewan(1, 6, h6);
        peternak.getPeternakan().ternakHewan(1, 7, h7);
        peternak.getPeternakan().ternakHewan(1, 8, h8);
        peternak.cetakPeternakan();
        peternak.cetakPenyimpanan();
        vector<tuple<string,string,int>> v = peternak.getPeternakan().getDaftarIsi();
        for(auto i = v.begin(); i != v.end(); i++){
            cout << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << endl;
        }
        peternak.ternak();
        peternak.harvest();
        peternak.beriPangan();
        peternak.cetakPeternakan();
        peternak.cetakPenyimpanan();

        vector<tuple<string,string,int>> v1 = peternak.getPeternakan().getDaftarIsi();
        for(auto i = v1.begin(); i != v1.end(); i++){
            cout << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << endl;
        }

        // peternak.ternak();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}