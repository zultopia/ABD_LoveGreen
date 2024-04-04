#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Kode warna untuk menandakan apakah siap panen atau tidak
#define RESET   "\033[0m"
#define RED     "\033[31m"  // Belum siap panen
#define GREEN   "\033[32m"  // Siap panen

class Penyimpanan {
    protected:
        const int rows;
        const int cols;
        vector<vector<string> > grid;

    public:
        Penyimpanan();

        Penyimpanan(int numRows, int numCols);

        virtual void cetakInfo();

        void updateCell(int row, int col, const string& value);

        int hitungSlotKosong();

        string ambilItem(int row, int col);

        void tambahItem(const string& jenisItem);

        void operator+(const string& item);
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

        string ambilTanaman(int row, int col);

        void tambahTanaman(const string& jenisTanaman);

        void operator+(const string& tanaman);
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

        string ambilTernak(int row, int col);

        void tambahTernak(const string& jenisTernak);

        void operator+(const string& ternak);
};