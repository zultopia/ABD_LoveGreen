#include "Petani.hpp"
#include "../produk/ProdukEatable/ProdukEatable.hpp"
#include "../produk/ProdukUneatable/ProdukUneatable.hpp"

Petani::Petani(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan), ladang() {}

Ladang& Petani::getLadang() {
    return ladang;
}

string Petani::getRole() {
    return "Petani";
}

void Petani::tanam() {
    // Menampilkan daftar tanaman yang tersedia di penyimpanan
    cout << endl;
    cout << "Pilih tanaman dari penyimpanan:" << endl;
    cout << endl;
    inventory.cetakInfo();

    // Meminta input slot item yang akan ditanam
    string slot;
    cout << "Slot: "; cin >> slot; cout << endl; 

    // Mengambil item dari penyimpanan
    pair<int, int> koordinatItem = konversiKoordinat(slot);
    Item* item = inventory.ambilItem(koordinatItem.first + 1, koordinatItem.second);
    if (item != nullptr) {
        string code = item->getCode();
        auto it = Config::getPlantMap().find(code);
        if (it == Config::getPlantMap().end()) {
            cout << "Item yang dipilih bukan tanaman." << endl;
            return;
        }
        
        cout << "Kamu memilih " << item->getName() << "." << endl;
        cout << endl;

        // Memeriksa apakah ladang sudah penuh
        if (ladang.hitungSlotKosong() == 0) {
            cout << "Ladang sudah penuh. Tidak dapat menanam lebih banyak tanaman." << endl;
            return;
        }

        bool tanamBerhasil = false;
        while (!tanamBerhasil) {
            // Meminta input petak tanah yang akan ditanami
            cout << "Pilih petak tanah yang akan ditanami" << endl;
            cout << endl;
            ladang.cetakInfo();

            // Meminta input slot petak tanah
            string petak;
            cout << endl;
            cout << "Petak tanah: ";
            cin >> petak;
            cout << endl;

            // Menanam tanaman pada petak tanah yang dipilih
            pair<int, int> koordinatPetak = konversiKoordinat(petak);

            // Memeriksa apakah petak tanah sudah ditanami
            if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) != nullptr) {
                cout << "Petak tanah tersebut sudah ditanami. Pilih petak lain." << endl;
            } else {
                // Menanam tanaman pada petak tanah yang dipilih
                Tanaman* tanaman = new Tanaman(item->getCode());
                ladang.tanamTanaman(koordinatPetak.first + 1, koordinatPetak.second, tanaman);
                cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
                cout << item->getName() << " berhasil ditanam di petak " << petak << endl;
                ladang.cetakInfo();
                inventory.cetakInfo();
                tanamBerhasil = true;
            }
        }
    } else {
        cout << "Tidak ada Item pada posisi tersebut." << endl;
    }
}

void Petani::cetakLadang() {
    ladang.cetakInfo();
}

void Petani::harvest() {
    ladang.cetakInfo();

    cout << endl;
    map<string, int> harvest = ladang.hitungJumlahTanamanPanen();

    if (harvest.empty()) {
        cout << "Tidak ada tanaman siap panen." << endl;
    } else {
        cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
        int counter = 1;
        map<int, string> tanamanByNumber;
        for (auto it = harvest.begin(); it != harvest.end(); it++) {
            cout << counter << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            tanamanByNumber[counter] = it->first;
            counter++;
        }

        cout << endl;
        int nomor;
        cout << "Nomor tanaman yang ingin dipanen: "; cin >> nomor; cout << endl;

        if (nomor < 1 || nomor > harvest.size()) {
            cout << "Nomor tanaman tidak valid." << endl;
        } else {
            int jumlahPetak;
            string kodeTanaman = tanamanByNumber[nomor];
            cout << "Berapa petak yang ingin dipanen: "; cin >> jumlahPetak; cout << endl;

            if (jumlahPetak < 1 || jumlahPetak > harvest[kodeTanaman]) {
                cout << "Jumlah petak yang ingin dipanen melebihi/kurang dari jumlah petak yang tersedia." << endl;
            } else {
                if (inventory.hitungSlotKosong() < jumlahPetak) {
                    cout << "Slot penyimpanan tidak cukup." << endl;
                    return;
                } 

                string petak;
                vector<string> petakDipanen;
                cout << "Pilih petak yang ingin dipanen: " << endl;
                for (int i = 0; i < jumlahPetak; i++) {
                    cout << "Petak ke-" << i + 1 << ": "; cin >> petak;
                    pair<int, int> koordinatPetak = konversiKoordinat(petak);
                    if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second) == nullptr) {
                        cout << "Petak tersebut tidak memiliki tanaman." << endl;
                        return;
                    } else if (ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->getCode() != kodeTanaman) {
                        cout << "Petak tersebut memiliki tanaman yang berbeda." << endl;
                        return;
                    } else if (!ladang.getGrid().getCell(koordinatPetak.first, koordinatPetak.second)->isHarvest()) {
                        cout << "Tanaman pada petak tersebut belum siap dipanen." << endl;
                        return;
                    } else {
                        petakDipanen.push_back(petak);
                        Tanaman* tanamanPanen = ladang.ambilTanaman(koordinatPetak.first + 1, koordinatPetak.second);

                        // Produk hasil panen
                        vector<string> namaProduk;
                        string tipeTanamanPanen = tanamanPanen->getTypeTanaman();
                        for (const auto& entry : Config::getProductMap()) {
                            const tuple productInfo = entry.second;
                            string productOrigin = get<3>(productInfo); 
                            if (productOrigin == tanamanPanen->getName()) {
                                namaProduk.push_back(entry.first);
                            }
                        }

                        for (int i = 0; i < namaProduk.size(); i++) {
                            if (tipeTanamanPanen == "MATERIAL_PLANT") {
                                Produk* produk = new ProdukEatable(namaProduk[i]);
                                Item* item = dynamic_cast<Item*>(produk);
                                if(produk != nullptr){
                                    inventory.tambahItem(produk);
                                }
                            } else if (tipeTanamanPanen == "FRUIT_PLANT") {
                                Produk* produk = new ProdukEatable(namaProduk[i]);
                                Item* item = dynamic_cast<Item*>(produk);
                                if(produk != nullptr){
                                    inventory.tambahItem(produk);
                                }
                            }
                        }
                    }
                }
                cout << petakDipanen.size() << " petak tanaman " << kodeTanaman << " pada petak ";
                for (int i = 0; i < petakDipanen.size(); i++) {
                    cout << petakDipanen[i];
                    if (i != petakDipanen.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " telah dipanen." << endl;
            }
        }
    }
}

void Petani::doCommand(string command) {
    if(commandTable.find(command) == commandTable.end()){
        // throw error
    }
    switch (commandTable[command])
    {
    case 1:
        this->next();
        break;
    case 2:
        this->cetakPenyimpanan();
        break;
    case 4:
        this->cetakLadang();
        break;
    case 6:
        this->tanam();
        break;
    case 9:
        this->makan();
        break;
    case 11:
        this->beli();
        break;
    case 12:
        this->jual();
        break;
    case 13:
        this->harvest();
        break;
    case 14:
        this->muat();
        break;
    case 15:
        this->simpan();
        break;
    default:
        throw "Command Tidak Valid untuk Pemain ini";
        break;
    }
}

int Petani::bayarPajak() {
    int pajak = calculateTax();
    if (pajak == 0) {
        cout << "Tidak ada pajak yang harus dibayar." << endl;
    } else {
        cout << "Pajak yang harus dibayar: " << pajak << endl;
        if (getKekayaan() < pajak) {
            pajak = getKekayaan();
            this->kekayaan = 0;
            cout << "Kekayaan tidak mencukupi untuk membayar pajak." << endl;
        } else {
            this->kekayaan = getKekayaan() - pajak;
            cout << "Pajak berhasil dibayar." << endl;
        }
    }
    return pajak;
}

int Petani::calculateTax() {
    int netoKekayaan = getKekayaan();
    int KTKP = 13; // Petani getKTKP()
    
    vector<string> list = ladang.getListPenyimpanan();
    for (int i = 0; i < list.size(); i++) {
        if (Config::getPlantMap().find(list[i]) != Config::getPlantMap().end()) {
            netoKekayaan += get<4>(Config::getPlantMap()[list[i]]);
        }
        if (Config::getAnimalMap().find(list[i]) != Config::getAnimalMap().end()) {
            netoKekayaan += get<4>(Config::getAnimalMap()[list[i]]);
        }
        if (Config::getProductMap().find(list[i]) != Config::getProductMap().end()) {
            netoKekayaan += get<5>(Config::getProductMap()[list[i]]);
        }
    }

    // kekayaan bangunan belum dihitung

    int KKP = netoKekayaan - KTKP;
    if (KKP <= 0) {
        return 0;
    } else if (KKP <= 6) {
        return KKP * 0.05;
    } else if (KKP > 6 && KKP <= 25) {
        return KKP * 0.15;
    } else if (KKP > 25 && KKP <= 50) {
        return KKP * 0.25;
    } else if (KKP > 50 && KKP <= 500) {
        return KKP * 0.3;
    } else {
        return KKP * 0.35;
    }
}

void Petani::beli() {
    Toko::CetakPeternakPetani();
    cout << "Uang anda : " << kekayaan << endl;
    int slotKosong = inventory.hitungSlotKosong();
    cout << "Slot penyimpanan tersedia : " << slotKosong << endl;

    string pilihan;
    cout << "Barang ingin dibeli : ";

    cin >> pilihan;
    int pilihanInt;
    bool valid = true;

    try {
        pilihanInt = stoi(pilihan);
    } catch (invalid_argument e) {
        valid = false;
    }

    while (!valid) {
        cout << "Pilihan berupa integer!" << endl;

        cout << "Barang ingin dibeli : ";
        valid = true;

        try {
            pilihanInt = stoi(pilihan);
        } catch (invalid_argument e) {
            valid = false;
        }
    }

    cout << "Kuantitas : ";
    string kuantitas;
    cin >> kuantitas;
    int kuantitasInt;

    try {
        kuantitasInt = stoi(kuantitas);
    } catch (invalid_argument e) {
        valid = false;
    }

    while (!valid) {
        cout << "Kuantitas berupa integer!" << endl;

        cout << "Kuantitas : ";
        valid = true;

        try {
            kuantitasInt = stoi(kuantitas);
        } catch (invalid_argument e) {
            valid = false;
        }
    }

    int hargaTotal = Toko::BeliPeternakPetani(pilihanInt, kuantitasInt);

    if (kuantitasInt > slotKosong) {
        PemainException e("Slot penyimpanan tidak cukup!");
        throw e;
    } else if (hargaTotal > kekayaan) {
        PemainException e("Jumlah gulden pemain tidak cukup!");
        throw e;
    }
    string namaBarang = Toko::getBarangNoUrut(pilihanInt);
    kekayaan -= hargaTotal;
    cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaBarang << ". Uang Anda tersisa 88 gulden." << endl;
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    cetakPenyimpanan();

    // Pilih slot penyimpanan
    bool slotsValid = false;
    string slots;
    string delimiter = ",";

    while (!slotsValid) {
        slotsValid = true;
        cout << "Petak Slot: ";
        cin >> slots;
        vector<string> slotList;
        vector<tuple<int, int>> slotIntList;
        tuple<int, int> koordinatInt;
        size_t pos = 0;
        string koordinat;
        while ((pos = slots.find(delimiter)) != string::npos && slotsValid) {
            koordinat = slots.substr(0, pos);
            koordinat.erase(std::remove_if(koordinat.begin(), koordinat.end(), ::isspace),koordinat.end());
            slotList.push_back(koordinat);
            slots.erase(0, pos + delimiter.length());
            koordinatInt = konversiKoordinat(koordinat);
            if (koordinatInt->first < 0 || koordinat->second < 0) {
                slotsValid = false;
                slotList.clear();
                slotIntList.clear();
                cout << "Pilihan slot tidak valid! silahkan input kembali!" << endl;
            } else {
                slotIntList.push_back(koordinatInt);
            }
        }

        // Add item ke penyimpanan
        if (slotsValid) {
            for (auto i = slotIntList.begin(); i != slotIntList.end(); i++) {
                if (Config::isExistPlant(namaBarang)) {
                    getInventory()->tambahItem((*i)->first, (*i)->second, new Tanaman(namaBarang));
                } else if (Config::isExistAnimal(namaBarang)) {
                    if (Config::getType(namaBarang).compare("HERBIVORE") == 0) {
                        getInventory()->tambahItem((*i)->first, (*i)->second, new Herbivora(namaBarang));
                    } else if (Config::getType(namaBarang).compare("CARNIVORE") == 0) {
                        getInventory()->tambahItem((*i)->first, (*i)->second, new Karnivora(namaBarang));
                    } else {
                        getInventory()->tambahItem((*i)->first, (*i)->second, new Omnivora(namaBarang));
                    }
                } else if (Config::isExistProduct(namaBarang)) {
                    if (Config::getType(namaBarang).compare("PRODUCT_MATERIAL_PLANT") == 0) {
                        getInventory()->tambahItem((*i)->first, (*i)->second, new ProdukUneatable(namaBarang));
                    } else {
                        getInventory()->tambahItem((*i)->first, (*i)->second, new ProdukEatable(namaBarang));
                    }
                } else {
                    getInventory()->tambahItem((*i)->first, (*i)->second, new Bangunan(namaBarang));
                }
            }
        }
    }
}

void Petani::jual() {}

vector<tuple<string,string,int>> Petani::getDaftarIsi(){
    return ladang.getDaftarIsi();
}
