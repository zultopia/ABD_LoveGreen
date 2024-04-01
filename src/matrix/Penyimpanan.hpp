#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// Kode warna untuk menandakan apakah siap panen atau tidak
#define RESET   "\033[0m"
#define RED     "\033[31m"  // Belum siap panen
#define GREEN   "\033[32m"  // Siap panen

class Penyimpanan {
    protected:
        const int rows;
        const int cols;
        std::vector<std::vector<std::string> > grid;

    public:
        Penyimpanan();

        virtual void cetakInfo();

        void updateCell(int row, int col, const std::string& value);

        int hitungSlotKosong();
};

class Ladang : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Ladang();

        void cetakInfo() override;

        void tanamTanaman(int row, int col, const std::string& jenis);
};

class Peternakan : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Peternakan();

        void cetakInfo() override;

        void cetakLokasiHewan();

        void ternakHewan(int row, int col, const std::string& jenis);
};