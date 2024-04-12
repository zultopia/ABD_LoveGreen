#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <map> 
#include <string>
#include "Item.hpp"
#include "../Config/Config.hpp"

using namespace std;

class Bangunan : public Item {
    private:
        int idBangunan;
        map<string, int> materials; 
    
    public:
        // Constructor
        Bangunan();
        Bangunan(string nama);
        // Destructor
        ~Bangunan();

        // Getter
        int getIdBangunan() const;
        map<string, int> getMaterials();

        // Setter
        void setIdBangunan(int idBangunan);
        void setMaterials(const map<string, int>& materials); 

        // Operator overloading untuk ostream
        friend ostream& operator<<(ostream& os, Bangunan& bangunan);
};

#endif