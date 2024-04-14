#include "TokoException.hpp"

TokoException::TokoException(const char* message){
    this->message = message;
}
const char* TokoException::what() const throw(){
    return message.c_str();
}

InvalidNumberTokoException::InvalidNumberTokoException() : TokoException("Nomor tidak valid\n") {}

InvalidQuantityTokoException::InvalidQuantityTokoException() : TokoException("Quantity tidak valid\n") {}