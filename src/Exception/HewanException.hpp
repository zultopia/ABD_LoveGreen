#ifndef HEWANEXCEPTION_HPP
#define HEWANEXCEPTION_HPP

#include <exception>
#include <string>
#include <iostream>
using namespace std;

class HewanException : public exception {
    public:
        // menuliskan pesan kesalahan ke stdout
        virtual void printMessage() = 0;
};

class InvalidEatingException : public HewanException {
    private:
        string pemakan;
        string makanan;
    public:
        InvalidEatingException(string pemakan, string makanan);
        void printMessage();
};

#endif