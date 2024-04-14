#include "ConfigException.hpp"

ConfigException::ConfigException(const char* message) : message(message) {}

const char* ConfigException::what() const throw() {
    return message.c_str();
}

InvalidFileConfigException::InvalidFileConfigException(const char* fileType) : ConfigException(("File " + string(fileType) + ".txt tidak dapat dibuka.").c_str()) {}

InvalidKeyConfigException::InvalidKeyConfigException() : ConfigException("Tidak ada key tersebut pada Config") {}