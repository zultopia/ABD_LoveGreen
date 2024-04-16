#include "Peternak.hpp"
#include "../Matrix/Peternakan.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Item/Bangunan.hpp"
#include "../Config/Config.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Matrix/Penyimpanan.hpp"
#include "../Exception/PemainException.hpp"
#include "../Exception/HewanException.hpp"
#include "../Matrix/Grid.hpp"
#include "../Toko/Toko.hpp"
#include "../Produk/Produk.hpp"
#include "../Item/Item.hpp"

Peternak::Peternak(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan), peternakan(Config::getBesarPeternakan().first, Config::getBesarPeternakan().second) {}

Peternak::~Peternak() {}

Peternakan& Peternak::getPeternakan() {
    return peternakan;
}

string Peternak::getRole() {
    return "Peternak";
}

void Peternak::ternak() {
    if (inventory.hitungSlotKosong() == Config::getBesarPenyimpanan().first * Config::getBesarPenyimpanan().second) {
        throw PemainException("Inventory kosong, tidak ada hewan yang bisa diternak");
    }
    if (peternakan.hitungSlotKosong() == 0) {
        throw PemainException("Peternakan sudah penuh. Tidak dapat menambahkan lebih banyak hewan.\n");
    }
    std::cout << endl << "Pilih hewan dari penyimpanan:\n" << endl;
    inventory.cetakInfo();

    string slot;
    std::cout << "Slot: "; std::cin >> slot; std::cout << endl; 

    // Memanggil fungsi konversi dan menyimpan hasilnya
    pair<int, int> slotCoordinate = Penyimpanan::konversiKoordinat(slot);
    int row = slotCoordinate.first;
    int col = slotCoordinate.second;

    // Memeriksa apakah koordinat dalam rentang yang valid
    if (inventory.isCellValid(row, col)) {
        Item* item = inventory.ambilJenisItem(slot, "Hewan");
        if (item != nullptr) {
            std::cout << "Kamu memilih " << item->getName() << ".\n" << endl;
            peternakan.menanamTernak(item);
        } else {
            throw PemainException("Ternak gagal...\nPastikan slot yang dipilih tidak kosong dan merupakan hewan\n");
        }
    } else {
        throw PemainException("Slot yang dipilih tidak valid.\n\n");
    }
}

void Peternak::beriPangan() {
    if (peternakan.hitungSlotKosong() == peternakan.getRows() * peternakan.getCols()) {
        throw PemainException("Peternakan kosong. Tidak ada hewan yang bisa diberi makan.\n");
    }
    if (inventory.hitungSlotKosong() == Config::getBesarPenyimpanan().first * Config::getBesarPenyimpanan().second) {
        throw PemainException("Inventory kosong. Tidak ada pangan yang bisa diberikan.\n");
    }

    std::cout << endl << "Pilih petak kandang yang akan ditinggali\n" << endl;
    peternakan.cetakInfo();
    string petak;
    std::cout << endl; std::cout << "Petak kandang: "; std::cin >> petak; std::cout << endl;
    pair<int, int> koordinatPetak = Peternakan::konversiKoordinat(petak);
    if (peternakan.isCellValid(koordinatPetak.first, koordinatPetak.second)) {
        Hewan* hewan = peternakan.getCell(koordinatPetak.first, koordinatPetak.second);
        if (hewan != nullptr) {
            std::cout << "Kamu memilih " << hewan->getName() << " untuk diberi makan.\n" << endl;
            std::cout << "Pilih pangan yang akan diberikan:\n" << endl;
            inventory.cetakInfo();

            string slot;
            std::cout << "Slot: "; std::cin >> slot; std::cout << endl;
            pair<int, int> koordinatSlot = Penyimpanan::konversiKoordinat(slot);
            if (inventory.isCellValid(koordinatSlot.first, koordinatSlot.second)) {
                Item* item = inventory.ambilJenisItem(slot, "Produk");
                if (item != nullptr) {
                    string typePangan = get<2>(Config::getProductMap()[item->getName()]);
                    Produk* produkPangan;
                    if (typePangan == "PRODUCT_MATERIAL_PLANT") { produkPangan = new ProdukUneatable(item->getName());} 
                    else { produkPangan = new ProdukEatable(item->getName()); }

                    try {
                        hewan->eat(*produkPangan); std::cout << endl;
                        delete produkPangan;
                    } catch(InvalidEatingException& e) {
                        e.printMessage();
                        std::cout << "Mengembalikan item ke penyimpanan.." << endl;
                        inventory.tambahItem(item);
                    }

                } else {
                    throw PemainException("Gagal memberi makan...\nPastikan slot yang dipilih tidak kosong dan merupakan produk\n");
                }
            } else {
                throw PemainException("Slot tidak valid!\n");
            }
        } else {
            throw PemainException("Petak kandang tersebut kosong.\n");
        }
    } else {
        throw PemainException("Petak kandang tidak valid!\n");
    }
}

void Peternak::cetakPeternakan() {
    peternakan.cetakInfo(); std::cout << endl;
}

void Peternak::harvest() {
    peternakan.cetakInfo();

    std::cout << endl;
    map<string, int> harvest = peternakan.hitungJumlahHewanPanen();

    if (harvest.empty()) {
        throw PemainException("Tidak ada hewan siap panen.\n");
    } else {
        std::cout << "Pilih hewan siap panen yang kamu miliki\n" << endl;
        int counter = 1;
        map<int, string> hewanByNumber;
        for (auto it = harvest.begin(); it != harvest.end(); it++) {
            std::cout << counter << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            hewanByNumber[counter] = it->first;
            counter++;
        }

        string nomor;
        std::cout << "Nomor hewan yang ingin dipanen: "; std::cin >> nomor; std::cout << endl;

        while (!(all_of(nomor.begin(), nomor.end(), [](char c) { return isdigit(c); }))) {
            std::cout << "Nomor hewan harus berupa angka. Silakan input kembali." << endl;
            std::cout << "Nomor hewan yang ingin dipanen: "; std::cin >> nomor; std::cout << endl;
        }

        while (hewanByNumber.find(stoi(nomor)) == hewanByNumber.end()) {
            std::cout << "Nomor hewan tidak valid. Silakan input kembali." << endl;
            std::cout << "Nomor hewan yang ingin dipanen: "; std::cin >> nomor; std::cout << endl;
        }

        string jumlahPetak;
        string kodeHewan = hewanByNumber[stoi(nomor)];
        std::cout << "Berapa petak yang ingin dipanen: "; std::cin >> jumlahPetak; std::cout << endl;
        while (!(all_of(jumlahPetak.begin(), jumlahPetak.end(), [](char c) { return isdigit(c); }))) {
            std::cout << "Jumlah petak yang ingin dipanen harus berupa angka. Silakan input kembali." << endl;
            std::cout << "Berapa petak yang ingin dipanen: "; std::cin >> jumlahPetak; std::cout << endl;
        }

        while (stoi(jumlahPetak) < 1 || stoi(jumlahPetak) > harvest[kodeHewan]) {
            std::cout << "Jumlah petak yang ingin dipanen melebihi jumlah petak yang tersedia atau kurang dari satu.\n";
            std::cout << "Berapa petak yang ingin dipanen: "; std::cin >> jumlahPetak; std::cout << endl;
        }

        if (inventory.hitungSlotKosong() < stoi(jumlahPetak)) {
            throw PemainException("Slot penyimpanan tidak cukup.\n");
        } 

        vector<string> petakDipanen;
        std::cout << "Pilih petak yang ingin dipanen: " << endl;
        for (int i = 0; i < stoi(jumlahPetak); i++) {
            string petak;
            bool isValidPetak = false;
            pair<int, int> koordinatPetak;
            while (!isValidPetak) {
                std::cout << "Petak ke-" << i + 1 << ": "; std::cin >> petak;
                koordinatPetak = Penyimpanan::konversiKoordinat(petak);
                if (peternakan.getCell(koordinatPetak.first, koordinatPetak.second) == nullptr) {
                    std::cout << "\nPetak tersebut tidak memiliki hewan.\n";
                } else if (peternakan.getCell(koordinatPetak.first, koordinatPetak.second)->getCode() != kodeHewan) {
                    std::cout << "\nPetak tersebut memiliki hewan yang berbeda.\n";
                } else if (!peternakan.getCell(koordinatPetak.first, koordinatPetak.second)->isHarvest()) {
                    std::cout << "\nHewan pada petak tersebut belum siap dipanen.\n";
                } else {
                    isValidPetak = true;
                }
            }
            petakDipanen.push_back(petak);
            Hewan* hewanPanen = peternakan.ambilTernak(koordinatPetak.first + 1, koordinatPetak.second);

            // Menambahkan item hasil panen ke penyimpanan
            vector<string> namaProduk;
            string tipeTanamanPanen = hewanPanen->getTypeHewan();
            for (const auto& entry : Config::getProductMap()) {
                const tuple productInfo = entry.second;
                string productOrigin = get<3>(productInfo); 
                if (productOrigin == hewanPanen->getName()) {
                    namaProduk.push_back(entry.first);
                }
            }

            for (int i = 0; i < namaProduk.size(); i++) {
                Produk* produk = new ProdukEatable(namaProduk[i]);
                Item* item = dynamic_cast<Item*>(produk);
                if(produk != nullptr){
                    inventory.tambahItem(item);
                }
            }
        }
        std::cout << petakDipanen.size() << " petak hewan " << kodeHewan << " pada petak ";
        for (int i = 0; i < petakDipanen.size(); i++) {
            std::cout << petakDipanen[i];
            if (i != petakDipanen.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " telah dipanen.\n" << endl;
    }
}

void Peternak::doCommand(string command) {
    try{
        switch (commandTable.at(command))
        {
        case 1:
            this->next();
            break;
        case 2:
            this->cetakPenyimpanan();
            break;
        case 5:
            this->cetakPeternakan();
            break;
        case 7:
            this->ternak();
            break;
        case 9:
            this->makan();
            break;
        case 10:
            this->beriPangan();
            break;
        case 11:
            this->beli();
            break;
        case 12:
            this->jual();
            break;
        case 14:
            this->printStatus();
            break;
        case 13:
            this->harvest();
            break;
        case 15:
            this->simpan();
            break;
        case 17:
            this->magic();
            break;
        default:
            PemainException e("Command Tidak Valid untuk Pemain ini\n");
            throw e;
            break;
        }
    } catch(std::out_of_range& err){
        PemainException e("Command Tidak Ada\n");
        throw e;
    }
}

void Peternak::bayarPajak() {
    int pajak = calculateTax();
    if (getKekayaan() < pajak) {
        pajak = getKekayaan();
        this->kekayaan = 0;
    } else {
        this->kekayaan = getKekayaan() - pajak;
    }
    std::cout << username << " - Peternak: " << pajak << " gulden" << endl;
}

int Peternak::calculateTax() {
    int netoKekayaan = getKekayaan();
    int KTKP = 11; // Peternak

    for (int i = 0; i < inventory.getRows(); i++) {
        for (int j = 0; j < inventory.getCols(); j++) {
            if (inventory.getCell(i, j) != nullptr) {
                netoKekayaan += inventory.getCell(i, j)->getPrice();
            }
        }
    }
    
    for (int i = 0; i < peternakan.getRows(); i++) {
        for (int j = 0; j < peternakan.getCols(); j++) {
            if (peternakan.getCell(i, j) != nullptr) {
                netoKekayaan += peternakan.getCell(i, j)->getPrice();
            }
        }
    }

    int KKP = netoKekayaan - KTKP;
    if (KKP <= 0) { return 0;} 
    else if (KKP <= 6) { return KKP * 0.05; } 
    else if (KKP > 6 && KKP <= 25) { return KKP * 0.15; } 
    else if (KKP > 25 && KKP <= 50) { return KKP * 0.25; } 
    else if (KKP > 50 && KKP <= 500) { return KKP * 0.3; } 
    else { return KKP * 0.35; }
}

void Peternak::beli() {
    Toko::CetakPeternakPetani();
    std::cout << "Uang anda : " << kekayaan << endl;
    int slotKosong = inventory.hitungSlotKosong();
    std::cout << "Slot penyimpanan tersedia : " << slotKosong << endl;

    string pilihan;
    std::cout << "Barang ingin dibeli : ";

    std::cin >> pilihan;
    int pilihanInt;
    bool valid = true;

    try {
        pilihanInt = stoi(pilihan);
    } catch (invalid_argument& e) {
        valid = false;
    }

    while (!valid) {
        std::cout << "Pilihan harus berupa integer!" << endl;

        std::cout << "Barang ingin dibeli : ";
        valid = true;
        std::cin >> pilihan;
        try {
            pilihanInt = stoi(pilihan);
        } catch (invalid_argument& e) {
            valid = false;
        }
    }

    std::cout << "Kuantitas : ";
    string kuantitas;
    std::cin >> kuantitas;
    int kuantitasInt;

    try {
        kuantitasInt = stoi(kuantitas);
    } catch (invalid_argument& e) {
        valid = false;
    }

    while (!valid || kuantitasInt <= 0) {
        std::cout << "Kuantitas harus berupa integer dan lebih besar dari 0!" << endl;
        std::cout << "Kuantitas : ";
        valid = true;
        std::cin >> kuantitas;
        try {
            kuantitasInt = stoi(kuantitas);
        } catch (invalid_argument& e) {
            valid = false;
        }
    }

    pair<string,int> barangHarga = Toko::BeliPeternakPetani(pilihanInt, kuantitasInt);
    int hargaTotal = barangHarga.second;
    string namaBarang = barangHarga.first;
    if (kuantitasInt > slotKosong) {
        PemainException e("Slot penyimpanan tidak cukup!");
        throw e;
    } else if (hargaTotal > kekayaan) {
        PemainException e("Jumlah gulden pemain tidak cukup!");
        throw e;
    }
    kekayaan -= hargaTotal;
    std::cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaBarang << ". Uang Anda tersisa " << kekayaan << " gulden." << endl;
    std::cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    cetakPenyimpanan();

    // Pilih slot penyimpanan
    bool slotsValid = false;
    string slots;
    vector<tuple<int, int>> slotIntList;

    string buf;
    getline(std::cin, buf);
    while (!slotsValid) {
        cout << "Petak Slot: ";
        getline(cin, slots);
        try {
            slotIntList = Penyimpanan::parserListKoordinat(slots);
        } catch (...) {
            slotsValid = false;
        }

        // Memeriksa setiap sel yang dipilih
        bool anySlotOccupied = false;
        bool anyIndexOutOfBound = false;
        for (const auto& slot : slotIntList) {
            int row = get<0>(slot);
            int col = get<1>(slot);
            if (!(row >= 0 && row < inventory.getRows() && col >= 0 && col < inventory.getCols())){
                anyIndexOutOfBound = true;
            }
            if (!inventory.isCellKosong(row, col)) {
                anySlotOccupied = true;
                break;
            }
        }

        if (slotIntList.size() == kuantitasInt && !anySlotOccupied && !anyIndexOutOfBound) {
            slotsValid = true;
        } else {
            if (anyIndexOutOfBound) {
                std::cout << "Pilihan index slot tidak valid! Silakan input kembali." << endl;
            } else if (anySlotOccupied) {
                std::cout << "Salah satu atau lebih slot sudah terisi! Silakan pilih slot yang kosong." << endl;
            } else {
                std::cout << "Pilihan slot tidak valid! Silakan input kembali." << endl;
            }
        }
    }

    // Add item ke penyimpanan
    for (auto i = slotIntList.begin(); i != slotIntList.end(); i++) {
        if (Config::isExistPlant(namaBarang)) {
            inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new Tanaman(namaBarang));
        } else if (Config::isExistAnimal(namaBarang)) {
            if (Config::getType(namaBarang).compare("HERBIVORE") == 0) {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new Herbivora(namaBarang));
            } else if (Config::getType(namaBarang).compare("CARNIVORE") == 0) {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new Karnivora(namaBarang));
            } else {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new Omnivora(namaBarang));
            }
        } else if (Config::isExistProduct(namaBarang)) {
            if (Config::getType(namaBarang).compare("PRODUCT_MATERIAL_PLANT") == 0) {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new ProdukUneatable(namaBarang));
            } else {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new ProdukEatable(namaBarang));
            }
        } else {
            inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), new Bangunan(namaBarang));
        }
    }
}

void Peternak::jual() {
    if (inventory.hitungSlotKosong() == Config::getBesarPenyimpanan().first * Config::getBesarPenyimpanan().second) {
        PemainException e("Inventory kosong, tidak ada barang yang bisa dijual");
        throw e;
    }

    std::cout << "Berikut merupakan penyimpanan Anda." << endl;
    cetakPenyimpanan();
    std::cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;

    // Pilih slot penyimpanan
    bool slotsValid = false;
    string slots;
    vector<tuple<int, int>> slotIntList;

    string buf;
    getline(std::cin,buf);

    while (!slotsValid) {
        std::cout << "Petak: ";
        getline(std::cin,slots);
        slotIntList = Penyimpanan::parserListKoordinat(slots);
        Item* item;
        if (slotIntList.size() != 0) {
            slotsValid = true;
            for (int i = 0; i < slotIntList.size(); i++) {
                item = inventory.getCell(get<0>(slotIntList[i]), get<1>(slotIntList[i]));
                if ( item == nullptr || Config::isExistRecipe(item->getName())) {
                    slotsValid = false;
                    break;
                }
            }
            if (!slotsValid) {
                std::cout << "Pilihan petak tidak valid! silahkan input kembali!" << endl << endl;
            }
        } else {
            std::cout << "Pilihan petak tidak valid! silahkan input kembali!" << endl << endl;
        }
    }

    // Jika slot valid, maka jual
    Item* item;
    int totalJual = 0;
    for (auto i = slotIntList.begin(); i != slotIntList.end(); i++) {
        item = inventory.ambilItem(get<0>(*i)+1, get<1>(*i));
        totalJual += Config::getPrice((item->getName()));
        Toko::Jual(item->getName(), 1);
    }
    kekayaan += totalJual;
    std::cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalJual << " gulden!" << endl;
}

vector<tuple<string,string,int>> Peternak::getDaftarIsi(){
    return peternakan.getDaftarIsi();
}

void Peternak::printStatus() {
    Pemain::printStatus();
    cetakPeternakan();
}

void Peternak::magic(){
    Pemain::magic();
}