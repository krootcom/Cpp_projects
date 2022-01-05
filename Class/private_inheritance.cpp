#include <iostream>
using namespace std;

class Motor{
    public:
        void SwitchIngnition(){
            cout << "Ignition on" << endl;
        }
        void PumpFuel(){
            cout << "fuel in cylinders" << endl;
        }
        void FireCylinders(){
            cout << "P-p-p-p-p-p-p-p....." << endl;
        }
};

class Car:private Motor{
    public:
        void move(){
            SwitchIngnition();
            PumpFuel();
            FireCylinders();
        }
};

int main(){
    Car myDreamCar;
    myDreamCar.move();
    //myDreamCar.FireCylinders();
    }