#ifndef PEMAIN_EXCEPTION_HPP
#define PEMAIN_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class PemainException : public exception{
    private:
        string message;
    public:
        PemainException(const char* message);
        const char* what() const throw();
};

#endif