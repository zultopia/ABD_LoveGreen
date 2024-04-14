#ifndef CONFIG_EXCEPTION_HPP
#define CONFIG_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class ConfigException : public exception {
protected:
    string message;
public:
    ConfigException(const char* message);
    const char* what() const throw();
};

class InvalidFileConfigException : public ConfigException {
public:
    InvalidFileConfigException(const char* fileType);
};

class InvalidKeyConfigException : public ConfigException {
public:
    InvalidKeyConfigException();
};

#endif