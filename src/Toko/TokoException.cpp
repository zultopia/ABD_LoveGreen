#include "TokoException.hpp"

TokoException::TokoException(const char* message){
    this->message = message;
}
const char* TokoException::what() const throw(){
    return message.c_str();
}