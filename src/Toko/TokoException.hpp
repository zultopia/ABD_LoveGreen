#ifndef TOKO_EXCEPTION_HPP
#define TOKO_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class TokoException : public exception{
    private:
        string message;
    public:
        TokoException(const char* message);
        const char* what() const throw();
};

#endif