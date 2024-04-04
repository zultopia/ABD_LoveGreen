#include <iostream>
#include <map>
using namespace std;
class A{
        
    };
class B: public A{

};
int main(){
    A a;
    B b;
    A c;
    map<string,int> tes;
    tes["A"] = '\0';

    cout << tes.at("A");

    if(typeid(a) == typeid(b)){
        cout << "same\n";
    }else{
        cout << "not\n";
    }
    return 0;
}