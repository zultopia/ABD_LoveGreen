#ifndef CONFIGPRODUK_HPP
#define CONFIGPRODUK_HPP

#include <map>
#include "../BaseConfig/BaseConfig.hpp"
#include "../../Produk/Produk.hpp"

using namespace std;

class ConfigProduk : BaseConfig {
    private:
        map<string, Produk> listProduk;
    
    public:
        ConfigProduk();
        ~ConfigProduk();
        void load() override;
        Produk& findProduk(string code);
};

#endif