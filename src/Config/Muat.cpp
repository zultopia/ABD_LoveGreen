#include "Muat.hpp"
#include "SimpanMuat.hpp"
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Item/Bangunan.hpp"
#include "Config.hpp"
#include "../Exception/ConfigException.hpp"
#include "../Toko/Toko.hpp"

string Muat::readPath(){
    string path;
    cout << "Masukkan lokasi berkas state : ";
    cin >> path;
    return path;
}

void Muat::muat(){
    string path = readPath();
    ifstream inputFile(path);
    if(!inputFile.is_open()){
        ConfigException e("File tidak dapat dibuka.");
        throw e;
    }
    string line;
    getline(inputFile, line);
    stringstream s(line);
    string loop;
    s >> loop;
    for(int i = 0; i < stoi(loop); i++){
        read(inputFile);
    }
    // bagian toko
    getline(inputFile,line);
    string jumlah;
    stringstream s2(line);
    s2 >> jumlah;
    for(int i = 0; i < stoi(jumlah); i++){
        getline(inputFile,line);
        stringstream s(line);
        string namaItem, jumlahItem;
        s >> namaItem >> jumlahItem;
        toko.insert({namaItem,stoi(jumlahItem)});
    }
}

void Muat::read(ifstream& inputFile){
    string line;
    getline(inputFile, line);
    stringstream s(line);
    string username, role, weightPlayer, uang;
    s >> username >> role >> weightPlayer >> uang;
    pemain.push_back(username);
    dataPemain.insert({username, make_tuple(role,stoi(weightPlayer),stoi(uang))});
    getline(inputFile, line);
    stringstream s1(line);
    string jumlah;
    s1 >> jumlah;
    // bagian inventory
    vector<string> vectorInventorytemp;
    for(int i = 0; i < stoi(jumlah); i++){
        getline(inputFile,line);
        stringstream s(line);
        string inventoryTemp;
        s >> inventoryTemp;
        vectorInventorytemp.push_back(inventoryTemp);
    }
    inventory.insert({username,vectorInventorytemp});
    vectorInventorytemp.clear();
    // bagian ladang atau ternak
    if (role != "Walikota"){
        getline(inputFile,line);
        string jumlah;
        stringstream s(line);
        s >> jumlah;
        vector<tuple<string,string,int>> ladangTernaktTmp;
        for(int i = 0; i < stoi(jumlah); i++){
            getline(inputFile,line);
            stringstream s(line);
            string lokasi, namaT, umurBerat;
            s >> lokasi >> namaT >> umurBerat;
            ladangTernaktTmp.push_back(make_tuple(lokasi,namaT,stoi(umurBerat)));
        }
        LadangdanTernak.insert({username, ladangTernaktTmp});
        ladangTernaktTmp.clear();
    }

}
void Muat::cekMuat(){
    for(auto i = pemain.begin(); i != pemain.end(); i++){
        cout << *i << endl;
        cout << get<0>(dataPemain.at(*i)) << " " << get<1>(dataPemain.at(*i)) << " " << get<2>(dataPemain.at(*i)) << endl;
        for(auto j = inventory.at(*i).begin(); j != inventory.at(*i).end(); j++){
            cout << *j << endl;
        }
        if( get<0>(dataPemain.at(*i)) != "Walikota" ){
            for(auto j = LadangdanTernak.at(*i).begin(); j != LadangdanTernak.at(*i).end(); j++){
                cout << get<0>(*j) << " " << get<1>(*j) << " " << get<2>(*j) << endl;
            }
        }
        cout << endl;
    }
    for(auto j = toko.begin(); j != toko.end(); j++){
        cout << j->first << " " << j->second << endl;
    }
}
void Muat::setUp(){
    for(auto i = pemain.begin(); i != pemain.end(); i++){
        Pemain* player = nullptr;
        if(get<0>(dataPemain.at(*i)) == "Petani"){
            setUpPetani(player, *i);
        }
        if(get<0>(dataPemain.at(*i)) == "Peternak"){
            setUpPeternak(player, *i);
        }
        if(get<0>(dataPemain.at(*i)) == "Walikota"){
            setUpWalikota(player, *i);
        }
        setUpInventory(player);
        cout << endl;
    }
    Toko::setUpTokoMuat();
}
void Muat::setUpPetani(Pemain*& player, string nama){
    player = (Pemain*) new Petani(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    Petani* currenPetani = (Petani*)(player);
    Ladang& ladang = currenPetani->getLadang();
    for(auto j = LadangdanTernak.at(nama).begin(); j != LadangdanTernak.at(nama).end(); j++){
        pair<int,int> posisi = Penyimpanan::konversiKoordinat(get<0>(*j));
        Tanaman* currTanaman = new Tanaman(get<1>(*j), get<2>(*j));
        // masukkin ladang
        ladang.tambahTanaman(posisi.first+1, posisi.second, currTanaman);
    }
}
void Muat::setUpPeternak(Pemain*& player, string nama){
    player = (Pemain*) new Peternak(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    Peternak* currenPeternak = (Peternak*)(player);
    Peternakan& peternakan = currenPeternak->getPeternakan();
    // peternakan.cetakInfo();
    for(auto j = LadangdanTernak.at(nama).begin(); j != LadangdanTernak.at(nama).end(); j++){
        pair<int,int> posisi = Penyimpanan::konversiKoordinat(get<0>(*j));
        if(Config::getType(get<1>(*j)) == "HERBIVORE"){
            Herbivora* animal = new Herbivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.tambahHewan(posisi.first+1,posisi.second, animal);
        }else if(Config::getType(get<1>(*j)) == "CARNIVORE"){
            Karnivora* animal = new Karnivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.tambahHewan(posisi.first+1,posisi.second, animal);
        }else if(Config::getType(get<1>(*j)) == "OMNIVORE"){
            Omnivora* animal = new Omnivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.tambahHewan(posisi.first+1,posisi.second, animal);
        }
    
    }
}
void Muat::setUpWalikota(Pemain*& player, string nama){
    player = (Pemain*) new Walikota(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    
}
void Muat::setUpInventory(Pemain*& pemain){
    Penyimpanan& inventoryPlayer = pemain->getInventory();
    cout << pemain->getUsername() << endl;
    for(auto j = inventory.at(pemain->getUsername()).begin(); j != inventory.at(pemain->getUsername()).end(); j++){
        // if (Config::isExistAnimal(*j)){
        //     if(Config::getType(*j) == "HERBIVORE"){
        //         Herbivora* animal = new Herbivora(*j);
        //         // inventoryPlayer.tambahItem(animal);
        //         inventoryPlayer + animal;
        //     }else if(Config::getType(*j) == "CARNIVORE"){
        //         Karnivora* animal = new Karnivora(*j);
        //         // inventoryPlayer.tambahItem(animal);
        //         inventoryPlayer + animal;
        //     }else if(Config::getType(*j) == "OMNIVORE"){
        //         Omnivora* animal = new Omnivora(*j);
        //         // inventoryPlayer.tambahItem(animal);
        //         inventoryPlayer + animal;
        //     }
        // } else if (Config::isExistPlant(*j)){
        //     // if(Config::getType(*j) == "MATERIAL_PLANT" || Config::getType(*j) == "FRUIT_PLANT"){
        //     //     Tanaman* plant = new Tanaman(*j);
        //     //     inventoryPlayer.tambahItem(plant);
        //     // }
        //     Tanaman* plant = new Tanaman(*j);
        //     // inventoryPlayer.tambahItem(plant);
        //     inventoryPlayer + plant;
        // } else if (Config::isExistProduct(*j)){
        //     if(Config::getType(*j) == "PRODUCT_MATERIAL_PLANT"){
        //         ProdukUneatable* product = new ProdukUneatable(*j);
        //         // inventoryPlayer.tambahItem(product);
        //         inventoryPlayer + product;
        //     }else if(Config::getType(*j) == "PRODUCT_FRUIT_PLANT" || Config::getType(*j) == "PRODUCT_ANIMAL"){
        //         ProdukEatable* product = new ProdukEatable(*j);
        //         // inventoryPlayer.tambahItem(product);
        //         inventoryPlayer + product;
        //     }
        // } else if (Config::isExistRecipe(*j)){
        //     Bangunan* bangunan = new Bangunan(*j);
        //     // inventoryPlayer.tambahItem(bangunan);
        //     inventoryPlayer + bangunan;
        // }
        inventoryPlayer + universalConstructor(*j);
    }
}

Item* Muat::universalConstructor(string nama){
    if (Config::isExistAnimal(nama)){
        if(Config::getType(nama) == "HERBIVORE"){
            Herbivora* animal = new Herbivora(nama);
            // inventoryPlayer.tambahItem(animal);
            return animal;
        }else if(Config::getType(nama) == "CARNIVORE"){
            Karnivora* animal = new Karnivora(nama);
            // inventoryPlayer.tambahItem(animal);
            return animal;
        }else if(Config::getType(nama) == "OMNIVORE"){
            Omnivora* animal = new Omnivora(nama);
            // inventoryPlayer.tambahItem(animal);
            return animal;
        }
        } else if (Config::isExistPlant(nama)){
            // if(Config::getType(*j) == "MATERIAL_PLANT" || Config::getType(*j) == "FRUIT_PLANT"){
            //     Tanaman* plant = new Tanaman(*j);
            //     inventoryPlayer.tambahItem(plant);
            // }
            Tanaman* plant = new Tanaman(nama);
            // inventoryPlayer.tambahItem(plant);
            return plant;
        } else if (Config::isExistProduct(nama)){
            if(Config::getType(nama) == "PRODUCT_MATERIAL_PLANT"){
                ProdukUneatable* product = new ProdukUneatable(nama);
                // inventoryPlayer.tambahItem(product);
                return product;
            }else if(Config::getType(nama) == "PRODUCT_FRUIT_PLANT" || Config::getType(nama) == "PRODUCT_ANIMAL"){
                ProdukEatable* product = new ProdukEatable(nama);
                // inventoryPlayer.tambahItem(product);
                return product;
            }
        } else if (Config::isExistRecipe(nama)){
            Bangunan* bangunan = new Bangunan(nama);
            // inventoryPlayer.tambahItem(bangunan);
            return bangunan;
        }
}
