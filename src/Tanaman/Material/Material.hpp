#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "../BaseTanaman/Tanaman.hpp"

using namespace std;

class Material : public Tanaman {
    public:
        // ctor
        Material();
        // dtor
        ~Material();

        bool eatable() const override;
};

#endif