#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Temperature{
    double Kelvin;
    Temperature(long double kelvin) : Kelvin(kelvin) {}
};

Temperature operator"" _C(long double celsius){
    return Temperature(celsius + 273);
}

Temperature operator"" _F(long double farengait){
    return Temperature((farengait + 459.67) * 5 / 9);
}

int main(){
    Temperature k1 = 33.6_F;
    Temperature k2 = 0.0_C;

    cout << "Temperature k1: " << k1.Kelvin << " K" << endl;
    cout << "Temperature k2: " << k2.Kelvin << " K" << endl;
}