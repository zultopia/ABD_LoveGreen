#include "../Config/Config.hpp"
#include "../Config/Simpan.hpp"
#include "../Config/Muat.hpp"
#include "../Hewan/Herbivora/Herbivora.hpp"
#include "../Hewan/Karnivora/Karnivora.hpp"
#include "../Hewan/Omnivora/Omnivora.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Produk/ProdukEatable/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable/ProdukUneatable.hpp"
#include "../Tanaman/Tanaman.hpp"

class GameEngine{
    private:
        static map<string,int> commandTable;
        static vector<Pemain*> listPemain;
        static string command;
    public:
        static void ReceiveCommand();
};
