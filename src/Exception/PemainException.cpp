#include "PemainException.hpp"

PemainException::PemainException(const char* message){
    this->message = message;
}
const char* PemainException::what() const throw(){
    return message.c_str();
}