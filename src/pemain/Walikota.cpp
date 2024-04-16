#include "./Walikota.hpp"
#include "./Petani.hpp"
#include "./Peternak.hpp"
#include "./Pemain.hpp"
#include "../Item/Item.hpp"
#include "../Item/Bangunan.hpp"
#include "../Matrix/Penyimpanan.hpp"
#include "../Exception/PemainException.hpp"
#include "../Matrix/Grid.hpp"
#include "../Toko/Toko.hpp"
#include "../Config/Config.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Item/Item.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"

// subclass functions
Walikota::Walikota(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan){}

void Walikota::pungutPajak(){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;
    vector<tuple<Pemain*, int>> pajak;
    int totalPajak = 0;
    int currentPajak;

    for (int i = 0; i < listPemain.size(); i++) {
        currentPajak = listPemain[i]->calculateTax();
        if (currentPajak > listPemain[i]->getKekayaan()) {
            currentPajak = listPemain[i]->getKekayaan();
        }
        // Cek apakah walikota/bukan
        if (currentPajak >= 0) {
            auto itr = pajak.begin();
            if (itr == pajak.end()){
                pajak.push_back(tuple<Pemain*, int>(listPemain[i], currentPajak));
            } else {
                while ((currentPajak < get<1>(*itr) || (currentPajak == get<1>(*itr) && username.compare(get<0>(*itr)->getUsername()) > 0)) && itr != pajak.end()-1) {
                    itr++;
                }
                if (currentPajak < get<1>(*itr) || (currentPajak == get<1>(*itr) && username.compare(get<0>(*itr)->getUsername()) > 0)) {
                    itr++;
                }
                pajak.insert(itr, tuple<Pemain*, int>(listPemain[i], currentPajak));
            }
            totalPajak += currentPajak;
        }
    }
    // Print hasil pemungutan;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < pajak.size(); i++) {
        cout << "  " << i+1 << ". ";
        get<0>(pajak[i])->bayarPajak();
    }

    cout << endl;
    cout << "Negara mendapatkan pemasukan sebesar " << totalPajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}

void Walikota::bangun(){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    auto recipeMap = Config::getRecipeMap();
    auto itr = recipeMap.begin();
    int i = 1;
    vector<string> listBangunan;
    while (itr != recipeMap.end()) {
        cout << "  " << i << ". " << itr->first << " (";
        auto materialInfo = Config::getMaterialInfo(itr->first);
        auto itrMaterial = materialInfo.begin();
        while (itrMaterial != materialInfo.end()){
            if (itrMaterial != materialInfo.begin()) {
                cout << ", ";
            }
            cout << itrMaterial->second << " " << itrMaterial->first;
            itrMaterial++;
        }
        cout << ")" << endl;
        listBangunan.push_back(itr->first);
        i++;
        itr++;
    }
    cout << endl << "Bangunan yang ingin dibangun: ";
    string answer;
    cin >> answer;
    if (!Config::isExistRecipe(answer)) {
        PemainException e("Kamu tidak punya resep bangunan tersebut!");
        throw e;
    }

    // Cek apakah bahan memenuhi
    map<string,int> materials = Config::getMaterialInfo(answer);
    map<string,int> bahanKurang;

    // Cek material
    auto itrMaterials = materials.begin();
    while (itrMaterials != materials.end()) {
        int dimiliki = inventory.jumlahItem(itrMaterials->first);
        if (dimiliki < itrMaterials->second) { 
            bahanKurang.insert(pair<string, int>(itrMaterials->first, itrMaterials->second - dimiliki));
        }
        itrMaterials++;
    }

    if (bahanKurang.size() > 0) {
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
        auto itrBahanKurang = bahanKurang.begin();
        while (itrBahanKurang != bahanKurang.end()) {
            cout << itrBahanKurang->second << " " << itrBahanKurang->first;
            if (++itrBahanKurang != bahanKurang.end()) {
                cout << ", ";
            } else {
                cout << "!" << endl;
            }
        }
    } else {
        // Bahan memenuhi
        auto itrMaterials = materials.begin();
        while (itrMaterials != materials.end()) {
            int jumlah = 0, i = 0;
            while (jumlah != itrMaterials->second) {
                int j = 0;
                while (j < Config::getBesarPenyimpanan().second){
                    Item* item;
                    item = inventory.getCell(i, j);
                    if (item->getName().compare(itrMaterials->first)){
                        jumlah++;
                        inventory.ambilItem(i+1, j);
                    }
                    j++;
                }
                i++;
            }
        }
        
        inventory.tambahItem(new Bangunan(answer));

        cout << answer << " berhasil dibangun dan telah menjadi hak milik walikota!";
    };


}
void Walikota::tambahPemain(){
    string jenis, nama;
    if (kekayaan < 50) {
        cout << "Uang tidak cukup!" << endl;
    } else {
        getline(cin, jenis);
        cout << "Masukkan jenis pemain: ";
        getline(cin, jenis);
        while (jenis.compare("petani") != 0 && jenis.compare("peternak") != 0) {
            cout << "Masukkan jenis pemain: ";
            getline(cin, jenis);
        }
        cout << "Masukkan nama pemain: ";
        getline(cin, nama);
        while (!namaValid(nama)) {
            cout << "Masukkan nama pemain: ";
            getline(cin, nama);
        }
        
        Pemain* pemainBaru = nullptr;
        if (jenis.compare("petani") == 0) {
            pemainBaru = new Petani(nama, 50, 40);
        } else if (jenis.compare("peternak") == 0) {
            pemainBaru = new Peternak(nama, 50, 40);
        }

        if (username.compare(nama) > 0) {
            currentPemain++;
        }

        if (pemainBaru != nullptr) {
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang " << "“" << pemainBaru->getUsername() << "“ di kota ini!" << endl;
        } else {
            PemainException e("Gagal membuat pemain baru!\n");
            throw e;
        }
    }
}

string Walikota::getRole() {
    return "Walikota";
}

// Inherited functions (virtual)
void Walikota::doCommand(string command){
    try{
        switch (commandTable.at(command))
        {
        case 1:
            this->next();
            break;
        case 2:
            this->cetakPenyimpanan();
            break;
        case 3:
            this->pungutPajak();
            break;
        case 8:
            this->bangun();
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
        case 15:
            this->simpan();
            break;
        case 16:
            this->tambahPemain();
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

int Walikota::calculateTax(){
    return -1;
}

void Walikota::beli(){
    Toko::CetakWalikota();
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

    while (!valid || kuantitasInt <= 0) {
        cout << "Kuantitas harus berupa integer dan lebih besar dari 0!" << endl;
        cout << "Kuantitas : ";
        valid = true;
        cin >> kuantitas;
        try {
            kuantitasInt = stoi(kuantitas);
        } catch (invalid_argument& e) {
            valid = false;
        }
    }

    pair<string,int> barangHarga = Toko::BeliWalikota(pilihanInt, kuantitasInt);
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

    string buf;
    getline(cin, buf);
    while (!slotsValid) {
        cout << "Petak Slot: ";
        getline(cin, slots);
        slotIntList = Penyimpanan::parserListKoordinat(slots);

        // Memeriksa setiap sel yang dipilih
        bool anySlotOccupied = false;
        bool anyIndexOutOfBound = false;
        for (const auto& slot : slotIntList) {
            int row = get<0>(slot);
            int col = get<1>(slot);
            if (!(row >= 0 && row < inventory.getRows() && col >= 0 && col < inventory.getCols())){
                anyIndexOutOfBound = true;
                break;
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
                cout << "Pilihan index slot tidak valid! Silakan input kembali." << endl;
            } else if (anySlotOccupied) {
                cout << "Salah satu atau lebih slot sudah terisi! Silakan pilih slot yang kosong." << endl;
            } else {
                cout << "Pilihan slot tidak valid! Silakan input kembali." << endl;
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
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), (Item*) new ProdukUneatable(namaBarang));
            } else {
                inventory.tambahItem(get<0>(*i) + 1, get<1>(*i), (Item*) new ProdukEatable(namaBarang));
            }
        }
    }
}

void Walikota::bayarPajak() {}

void Walikota::jual(){
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

    string buf;
    getline(cin,buf);
    while (!slotsValid) {
        cout << "Petak: ";
        getline(cin,slots);
        slotIntList = Penyimpanan::parserListKoordinat(slots);
        if (slotIntList.size() != 0) {
            slotsValid = true;
            for (int i = 0; i < slotIntList.size(); i++) {
                if (inventory.getCell(get<0>(slotIntList[i]), get<1>(slotIntList[i])) == nullptr) {
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