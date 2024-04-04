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

        Penyimpanan(int numRows, int numCols);

        virtual void cetakInfo();

        void updateCell(int row, int col, const std::string& value);

        int hitungSlotKosong();

        virtual string ambilItem(int row, int col);
};

class Ladang : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Ladang();

        Ladang(int numRows, int numCols);

        void cetakInfo() override;

        void cetakKeteranganTanaman();

        void tanamTanaman(int row, int col, const string& jenis);

        string ambilItem(int row, int col) override;
};

class Peternakan : public Penyimpanan {
    private:
        bool siapPanen;

    public:
        Peternakan();

        Peternakan(int numRows, int numCols);

        void cetakInfo() override;

        void cetakLokasiHewan();

        void ternakHewan(int row, int col, const string& jenis);

        string ambilItem(int row, int col) override;
};