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
    if (peternakan.hitungSlotKosong() == 0) {
        throw PemainException("Peternakan sudah penuh. Tidak dapat menambahkan lebih banyak hewan.");
    }
    cout << endl << "Pilih hewan dari penyimpanan:\n" << endl;
    inventory.cetakInfo();

    string slot;
    cout << "Slot: "; cin >> slot; cout << endl; 

    Item* item = inventory.ambilJenisItem(slot, "Hewan");
    if (item != nullptr) {
        cout << "Kamu memilih " << item->getName() << ".\n" << endl;
        peternakan.menanamTernak(item);
    } else {
        throw PemainException("Item yang dipilih tidak sesuai/Tidak ada Item pada posisi tersebut.");
    }
}

void Peternak::beriPangan() {
    if (peternakan.hitungSlotKosong() == peternakan.getRows() * peternakan.getCols()) {
        throw PemainException("Peternakan kosong. Tidak ada hewan yang bisa diberi makan.");
    }
    cout << endl << "Pilih petak kandang yang akan ditinggali\n" << endl;
    peternakan.cetakInfo();

    string petak;
    cout << endl; cout << "Petak kandang: "; cin >> petak; cout << endl;

    pair<int, int> koordinatPetak = Penyimpanan::konversiKoordinat(petak);
    Hewan* hewan = peternakan.getCell(koordinatPetak.first, koordinatPetak.second);

    if (hewan != nullptr) {
        cout << "Kamu memilih " << hewan->getName() << " untuk diberi makan.\n" << endl;
        cout << "Pilih pangan yang akan diberikan:\n" << endl;
        inventory.cetakInfo();

        string slot;
        cout << "Slot: "; cin >> slot; cout << endl;

        Item* item = inventory.ambilJenisItem(slot, "Produk");
        if (item != nullptr) {
            string typePangan = get<2>(Config::getProductMap()[item->getName()]);
            Produk* produkPangan;
            if (typePangan == "PRODUCT_MATERIAL_PLANT") { produkPangan = new ProdukUneatable(item->getName());} 
            else { produkPangan = new ProdukEatable(item->getName()); }

            try {
                hewan->eat(*produkPangan);
                delete produkPangan;
            } catch(InvalidEatingException& e) {
                e.printMessage();
            }

        } else {
            throw PemainException("Item yang dipilih tidak sesuai/Tidak ada Item pada posisi tersebut.");
        }
    } else {
        throw PemainException("Petak kandang tersebut kosong.");
    }
}

void Peternak::cetakPeternakan() {
    peternakan.cetakInfo();
}

void Peternak::harvest() {
    peternakan.cetakInfo();

    cout << endl;
    map<string, int> harvest = peternakan.hitungJumlahHewanPanen();

    if (harvest.empty()) {
        throw PemainException("Tidak ada hewan siap panen.");
    } else {
        cout << "Pilih hewan siap panen yang kamu miliki\n" << endl;
        int counter = 1;
        map<int, string> hewanByNumber;
        for (auto it = harvest.begin(); it != harvest.end(); it++) {
            cout << counter << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            hewanByNumber[counter] = it->first;
            counter++;
        }

        int nomor;
        cout << "Nomor hewan yang ingin dipanen: "; cin >> nomor; cout << endl;

        if (nomor < 1 || nomor > harvest.size()) {
            throw PemainException("Nomor hewan tidak valid.");
        } else {
            int jumlahPetak;
            string kodeHewan = hewanByNumber[nomor];
            cout << "Berapa petak yang ingin dipanen: "; cin >> jumlahPetak; cout << endl;

            if (jumlahPetak < 1 || jumlahPetak > harvest[kodeHewan]) {
                throw PemainException("Jumlah petak yang ingin dipanen melebihi/kurang dari jumlah petak yang tersedia.");
            } else {
                if (inventory.hitungSlotKosong() < jumlahPetak) {
                    throw PemainException("Slot penyimpanan tidak cukup.");
                } 

                string petak;
                vector<string> petakDipanen;
                cout << "Pilih petak yang ingin dipanen: " << endl;
                for (int i = 0; i < jumlahPetak; i++) {
                    cout << "Petak ke-" << i + 1 << ": "; cin >> petak;
                    pair<int, int> koordinatPetak = Penyimpanan::konversiKoordinat(petak);
                    if (peternakan.getCell(koordinatPetak.first, koordinatPetak.second) == nullptr) {
                        cout << "Petak tersebut tidak memiliki hewan." << endl;
                        return;
                    } else if (peternakan.getCell(koordinatPetak.first, koordinatPetak.second)->getCode() != kodeHewan) {
                        cout << "Petak tersebut memiliki hewan yang berbeda." << endl;
                        return;
                    } else if (!peternakan.getCell(koordinatPetak.first, koordinatPetak.second)->isHarvest()){
                        cout << "Hewan belum siap dipanen." << endl;
                        return;
                    } else {
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
                }
                cout << petakDipanen.size() << " petak hewan " << kodeHewan << " pada petak ";
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
        case 13:
            harvest();
            break;
        case 15:
            this->simpan();
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
    cout << username << " - Peternak: " << pajak << " gulden" << endl;
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
    } catch (invalid_argument& e) {
        valid = false;
    }

    while (!valid) {
        cout << "Pilihan harus berupa integer!" << endl;

        cout << "Barang ingin dibeli : ";
        valid = true;
        cin >> pilihan;
        try {
            pilihanInt = stoi(pilihan);
        } catch (invalid_argument& e) {
            valid = false;
        }
    }

    cout << "Kuantitas : ";
    string kuantitas;
    cin >> kuantitas;
    int kuantitasInt;

    try {
        kuantitasInt = stoi(kuantitas);
    } catch (invalid_argument& e) {
        valid = false;
    }

    while (!valid) {
        cout << "Kuantitas harus berupa integer!" << endl;

        cout << "Kuantitas : ";
        valid = true;
        cin >> kuantitas;
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
    cout << "Selamat Anda berhasil membeli " << kuantitas << " " << namaBarang << ". Uang Anda tersisa " << kekayaan << " gulden." << endl;
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    cetakPenyimpanan();

    // Pilih slot penyimpanan
    bool slotsValid = false;
    string slots;
    vector<tuple<int, int>> slotIntList;

    while (!slotsValid) {
        cout << "Petak Slot: ";
        string buf;
        getline(cin, buf);
        getline(cin, slots);
        slotIntList = Penyimpanan::parserListKoordinat(slots);
        if (slotIntList.size() == kuantitasInt) {
            slotsValid = true;
        } else {
            cout << "Pilihan slot tidak valid! silahkan input kembali!" << endl;
        }
    }

    // Add item ke penyimpanan
    for (auto i = slotIntList.begin(); i != slotIntList.end(); i++) {
        if (Config::isExistPlant(namaBarang)) {
            inventory.tambahItem(get<0>(*i), get<1>(*i), new Tanaman(namaBarang));
        } else if (Config::isExistAnimal(namaBarang)) {
            if (Config::getType(namaBarang).compare("HERBIVORE") == 0) {
                inventory.tambahItem(get<0>(*i), get<1>(*i), new Herbivora(namaBarang));
            } else if (Config::getType(namaBarang).compare("CARNIVORE") == 0) {
                inventory.tambahItem(get<0>(*i), get<1>(*i), new Karnivora(namaBarang));
            } else {
                inventory.tambahItem(get<0>(*i), get<1>(*i), new Omnivora(namaBarang));
            }
        } else if (Config::isExistProduct(namaBarang)) {
            if (Config::getType(namaBarang).compare("PRODUCT_MATERIAL_PLANT") == 0) {
                inventory.tambahItem(get<0>(*i), get<1>(*i), new ProdukUneatable(namaBarang));
            } else {
                inventory.tambahItem(get<0>(*i), get<1>(*i), new ProdukEatable(namaBarang));
            }
        } else {
            inventory.tambahItem(get<0>(*i), get<1>(*i), new Bangunan(namaBarang));
        }
    }
}

void Peternak::jual() {
    if (inventory.hitungSlotKosong() == Config::getBesarPenyimpanan().first * Config::getBesarPenyimpanan().second) {
        PemainException e("Inventory kosong, tidak ada barang yang bisa dijual");
        throw e;
    }

    cout << "Berikut merupakan penyimpanan Anda." << endl;
    cetakPenyimpanan();
    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;

    // Pilih slot penyimpanan
    bool slotsValid = false;
    string slots;
    vector<tuple<int, int>> slotIntList;

    while (!slotsValid) {
        slotsValid = true;
        cout << "Petak: ";
        cin >> slots;
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
                cout << "Pilihan petak tidak valid! silahkan input kembali!" << endl << endl;
            }
        } else {
            cout << "Pilihan petak tidak valid! silahkan input kembali!" << endl << endl;
        }
    }

    // Jika slot valid, maka jual
    Item* item;
    int totalJual = 0;
    for (auto i = slotIntList.begin(); i != slotIntList.end(); i++) {
        item = getInventory().ambilItem(get<0>(*i)+1, get<1>(*i));
        totalJual += Config::getPrice((item->getName()));
        Toko::Jual(item->getName(), 1);
    }
    kekayaan += totalJual;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalJual << " gulden!" << endl;
}

vector<tuple<string,string,int>> Peternak::getDaftarIsi(){
    return peternakan.getDaftarIsi();
}