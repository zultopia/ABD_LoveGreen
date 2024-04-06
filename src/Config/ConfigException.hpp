#ifndef CONFIG_EXCEPTION_HPP
#define CONFIG_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

class ConfigException : public exception{
    private:
        string message;
    public:
        ConfigException(const char* message);
        const char* what() const throw();
        

};

#endif