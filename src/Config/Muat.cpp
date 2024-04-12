#include "Muat.hpp"

string Muat::readPath(){
    char answer;
    cout << "Apakah Anda ingin memuat state? (y/n) ";
    cin >> answer;
    answer = (char)tolower(answer);
    while(answer != 'y' && answer != 'n'){
        cout << "Apakah Anda ingin memuat state? (y/n) ";
        cin >> answer;
        answer = (char)tolower(answer);
    }
    string path;
    if(answer == 'y'){
        cout << "Masukkan lokasi berkas state : ";
        cin >> path;
    }
    return path;

}

void Muat::muat(){
    string path = readPath();
    if(path.length() == 0){

    }else{
        // Memeriksa folder sudah ada atau belum
        // if(!filesystem::exists(filesystem::path(path).parent_path())) {
        //     ConfigException e("Lokasi berkas tidak valid");
        //     throw e;
        // }
        ifstream inputFile(path);
        if(!inputFile.is_open()){
            ConfigException e("File state.txt tidak dapat dibuka.");
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

void Muat::setUp(){
    for(auto i = pemain.begin(); i != pemain.end(); i++){
        Pemain* player;
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
    }
    Toko::setUpTokoMuat();
}
void Muat::setUpPetani(Pemain* player, string nama){
    player = new Petani(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    Pemain::listPemain.push_back(player);
    Petani* currenPetani = (Petani*)(player);
    Ladang& ladang = currenPetani->getLadang();
    for(auto j = LadangdanTernak.at(nama).begin(); j != LadangdanTernak.at(nama).end(); j++){
        pair<int,int> posisi = currenPetani->konversiKoordinat(get<0>(*j));
        Tanaman* currTanaman = new Tanaman(get<1>(*j), get<2>(*j));
        // masukkin ladang
        ladang.tanamTanaman(posisi.first, posisi.second, currTanaman);
    }
}
void Muat::setUpPeternak(Pemain* player, string nama){
    player = new Peternak(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    Pemain::listPemain.push_back(player);
    Peternak* currenPeternak = (Peternak*)(player);
    Peternakan& peternakan = currenPeternak->getPeternakan();
    for(auto j = LadangdanTernak.at(nama).begin(); j != LadangdanTernak.at(nama).end(); j++){
        pair<int,int> posisi = currenPeternak->konversiKoordinat(get<0>(*j));
        if(Config::getType(get<1>(*j)) == "HERBIVORE"){
            Herbivora* animal = new Herbivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.ternakHewan(posisi.first,posisi.second, animal);
        }else if(Config::getType(get<1>(*j)) == "CARNIVORE"){
            Karnivora* animal = new Karnivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.ternakHewan(posisi.first,posisi.second, animal);
        }else if(Config::getType(get<1>(*j)) == "OMNIVORE"){
            Omnivora* animal = new Omnivora(get<1>(*j), get<2>(*j));
            // masukkin peternakan
            peternakan.ternakHewan(posisi.first,posisi.second, animal);
        }
    
    }
}
void Muat::setUpWalikota(Pemain* player, string nama){
    player = new Walikota(nama,get<2>(dataPemain.at(nama)),get<1>(dataPemain.at(nama)));
    Pemain::listPemain.push_back(player);
}
void Muat::setUpInventory(Pemain* pemain){
    Penyimpanan& inventoryPlayer = pemain->getInventory();
    for(auto j = inventory.at(pemain->getUsername()).begin(); j != inventory.at(pemain->getUsername()).end(); j++){
        if(Config::getType(*j) == "HERBIVORE"){
            Herbivora* animal = new Herbivora(*j);
            inventoryPlayer.tambahItem(animal);
        }else if(Config::getType(*j) == "CARNIVORE"){
            Karnivora* animal = new Karnivora(*j);
            inventoryPlayer.tambahItem(animal);
        }else if(Config::getType(*j) == "OMNIVORE"){
            Omnivora* animal = new Omnivora(*j);
            inventoryPlayer.tambahItem(animal);
        }else if(Config::getType(*j) == "MATERIAL_PLANT" || Config::getType(*j) == "FRUIT_PLANT"){
            Tanaman* plant = new Tanaman(*j);
            inventoryPlayer.tambahItem(plant);
        }else if(Config::getType(*j) == "PRODUCT_MATERIAL_PLANT"){
            ProdukUneatable* product = new ProdukUneatable(*j);
            inventoryPlayer.tambahItem(product);
        }else if(Config::getType(*j) == "PRODUCT_FRUIT_PLANT" || Config::getType(*j) == "PRODUCT_ANIMAL"){
            ProdukEatable* product = new ProdukEatable(*j);
            inventoryPlayer.tambahItem(product);
        }else if(Config::getCode(*j) == "SMH" || Config::getCode(*j) == "MDH" || Config::getCode(*j) == "LRH" || Config::getCode(*j) == "HTL"){
            // konstruk bangunan trus masukin inventory

        }
    }
}
