#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

using namespace std;

class Item {
    private:
        int price;
        string code;
        string name;

    public:
        // ctor
        Item();
        Item(int price, string code, string name);

        // dtor
        ~Item();

        // getter
        int getPrice();
        string getCode();
        string getName();

        // getter
        void setPrice(int price);
        void setCode(string code);
        void setName(string name);

        // other operations
        virtual bool eatable() const = 0;
};

#endif