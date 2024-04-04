#include "../../Config/ConfigProduk/ConfigProduk.cpp"
#include "../Produk.cpp"

int main() {
    ConfigProduk c;
    c.load();
    Produk p = c.findProduk("HRM");
    cout << p << endl;
}