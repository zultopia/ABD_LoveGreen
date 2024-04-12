#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <iostream>
#include <vector> 
#include <string>
#include "Item.hpp"

using namespace std;

class Bangunan : public Item {
    private:
        int idBangunan;
        vector<pair<string, int> > materials; 

    public:
        // Constructor
        Bangunan();

        // Destructor
        ~Bangunan();

        // Getter
        int getIdBangunan() const;
        vector<pair<string, int> > getMaterials();

        // Setter
        void setIdBangunan(int idBangunan);
        void setMaterials(const vector<pair<string, int> >& materials); 

        // Operator overloading untuk ostream
        friend ostream& operator<<(ostream& os, Bangunan& bangunan);
};

#endif