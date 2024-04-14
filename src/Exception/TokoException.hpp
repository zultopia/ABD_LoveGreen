#ifndef TOKO_EXCEPTION_HPP
#define TOKO_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class TokoException : public exception {
protected:
    string message;
public:
    TokoException(const char* message);
    const char* what() const throw();
};

class InvalidNumberTokoException : public TokoException {
public:
    InvalidNumberTokoException();
};

class InvalidQuantityTokoException : public TokoException {
public:
    InvalidQuantityTokoException();
};

#endif