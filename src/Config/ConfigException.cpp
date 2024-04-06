#include "ConfigException.hpp"

ConfigException::ConfigException(const char* message){
    this->message = message;
}
const char* ConfigException::what() const throw(){
    return message.c_str();
}