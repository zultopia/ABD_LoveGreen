#include "../Config/Config.hpp"
#include "../Config/Simpan.hpp"
#include "../Config/Muat.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Produk/ProdukEatable.hpp"
#include "../Produk/ProdukUneatable.hpp"
#include "../Tanaman/Tanaman.hpp"

class GameEngine{
    private:
        string command;
        bool finish;
    public:
        GameEngine();
        void setUp();
        void defaultSetUp();
        void receiveCommand();
        void loopCommand();
        void run();
};
