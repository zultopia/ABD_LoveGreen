#include "./Walikota.hpp"
#include "./Petani.hpp"
#include "./Peternak.hpp"

// subclass functions
Walikota::Walikota(string& username, int kekayaan, int beratBadan) : Pemain(username, kekayaan, beratBadan){}

void Walikota::pungutPajak(){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;;
    vector<tuple<Pemain*, int>> pajak;
    int totalPajak = 0;
    int currentPajak;

    for (int i = 0; i < listPemain.size(); i++) {
        currentPajak = listPemain[i]->calculateTax();
        // Cek apakah walikota/bukan
        if (currentPajak >= 0) {
            auto itr = pajak.begin();
            while ((currentPajak < get<1>(*itr) ||(currentPajak == get<1>(*itr) && username.compare(get<0>(*itr)->getUsername()) == 0)) && itr != pajak.end()) {
                itr++;
            }
            pajak.insert(itr, tuple<Pemain*, int>(listPemain[i], currentPajak));
        }
    }
    // Print hasil pemungutan;
    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < listPemain.size(); i++) {
        cout << "  " << i+1;
        totalPajak += get<0>(pajak[i])->bayarPajak();
    }

    cout << "Negara mendapatkan pemasukan sebesar" << totalPajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!";
}

void Walikota::bangun(){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    auto itr = Config::getRecipeMap().begin();
    int i = 1;
    map<string, string> Bahan;
    while (itr != Config::getRecipeMap().end()) {
        cout << "  " << i << ". " << itr->first << " (" << Config::getPrice(itr->first);
        auto itrMaterial = Config::getMaterialInfo(itr->first).begin();
        while (itrMaterial != Config::getMaterialInfo(itr->first).end()){
            cout << ", " << itrMaterial->first << " " << itrMaterial->second;
            itrMaterial++;
        }
        cout << ")" << endl;
        Bahan.insert(pair<string,string>(itr->first, Config::getCode(itr->first)));
        i++;
        itr++;
    }
    cout << endl << "Bangunan yang ingin dibangun: ";
    string answer;
    cin >> answer;
    try {
        string kodeBangunan = Bahan[answer];
    } catch(...){
        cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
        this->bangun();
        return;
    }
    // Harus Cek Inventory ada item atau ga

    // Kalau ga ada:
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan "; // apa aja yg gapunya
    // Kalau ada:
        // tambah ke inventory : new Bangunan(...)
        cout << answer << " berhasil dibangun dan telah menjadi hak milik walikota!";


}
void Walikota::tambahPemain(){
    string jenis, nama;
    if (kekayaan < 50) {
        cout << "Uang tidak cukup!" << endl;
    } else {
        cout << "Masukkan jenis pemain: ";
        cin >> jenis;
        while (jenis.compare("walikota") != 0 && jenis.compare("petani") != 0 && jenis.compare("peternak") != 0) {
            cout << "Masukkan jenis pemain: ";
            cin >> jenis;
        }
        cout << "Masukkan nama pemain: ";
        cin >> nama;
        while (!namaValid(nama)) {
            cout << "Masukkan nama pemain: ";
            cin >> nama;
        }
        Pemain* pemainBaru;
        if (jenis.compare("walikota") == 0){
            pemainBaru = new Walikota(nama, 50, 40);
        } else if (jenis.compare("petani") == 0) {
            pemainBaru = new Petani(nama, 50, 40);
        } else if (jenis.compare("peternak")) {
            pemainBaru = new Peternak(nama, 50, 40);
        }

        cout << "Pemain baru ditambahkan!" << endl;
        cout << "Selamat datang " << '"' << pemainBaru->getUsername() << "' di kota ini!" << endl;
    }
}

string Walikota::getRole() {
    return "Walikota";
}

// Inherited functions (virtual)
void Walikota::doCommand(string command){
    if(commandTable.find(command) == commandTable.end()){
        throw "Command Tidak Valid!";
    }
    switch (commandTable[command])
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
    case 14:
        this->muat();
        break;
    case 15:
        this->simpan();
        break;
    case 16:
        this->tambahPemain();
        break;
    default:
        PemainException e("Command Tidak Valid untuk Pemain ini");
        throw e;
        break;
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

    int hargaTotal = Toko::BeliWalikota(pilihanInt, kuantitasInt);

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
            if (get<0>(koordinatInt) < 0 || get<1>(koordinatInt) < 0) {
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
                    getInventory().tambahItem(get<0>(*i), get<1>(*i), new Tanaman(namaBarang));
                } else if (Config::isExistAnimal(namaBarang)) {
                    if (Config::getType(namaBarang).compare("HERBIVORE") == 0) {
                        getInventory().tambahItem(get<0>(*i), get<1>(*i), new Herbivora(namaBarang));
                    } else if (Config::getType(namaBarang).compare("CARNIVORE") == 0) {
                        getInventory().tambahItem(get<0>(*i), get<1>(*i), new Karnivora(namaBarang));
                    } else {
                        getInventory().tambahItem(get<0>(*i), get<1>(*i), new Omnivora(namaBarang));
                    }
                } else if (Config::isExistProduct(namaBarang)) {
                    if (Config::getType(namaBarang).compare("PRODUCT_MATERIAL_PLANT") == 0) {
                        getInventory().tambahItem(get<0>(*i), get<1>(*i), new ProdukUneatable(namaBarang));
                    } else {
                        getInventory().tambahItem(get<0>(*i), get<1>(*i), new ProdukEatable(namaBarang));
                    }
                } else {
                    getInventory().tambahItem(get<0>(*i), get<1>(*i), new Bangunan(namaBarang));
                }
            }
        }
    }
}

void Walikota::jual(){
    // Toko::Jual();
}