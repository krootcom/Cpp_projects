#include <iostream>
using namespace std;

class Fish {
    protected:
        bool isFreshWaterFish;

    public:
        Fish(bool IsFreshWater) : isFreshWaterFish(IsFreshWater){}

        void Swim(){
            if(isFreshWaterFish)
                cout << " Fresh fish " << endl;
            else 
                cout << " Sea fish " << endl;
        }
};

class Tuna: public Fish{
    public:
        Tuna() : Fish(false) {}
};

class Carp: public Fish{
    public:
        Carp() : Fish(true) {}
};

int main(){
    Carp myL;
    Tuna myD;

    cout << "My food: " << endl;
    cout << " Lunch ";
    myL.Swim();
    cout << " Dinner ";
    myD.Swim();

    //myL.isFreshWaterFish = false;
    
    return 0;
}