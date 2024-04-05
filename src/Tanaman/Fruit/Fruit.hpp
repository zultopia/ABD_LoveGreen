#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "../BaseTanaman/Tanaman.hpp"

using namespace std;

class Fruit : public Tanaman {
    public:
        // ctor
        Fruit();
        // dtor
        ~Fruit();

        bool eatable() const override;
};

#endif