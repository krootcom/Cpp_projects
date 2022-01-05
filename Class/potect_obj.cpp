#include <iostream>
using namespace std;

class Fish {
    protected:
        bool isFreshWaterFish;

    public:
        void Swim(){
            if(isFreshWaterFish)
                cout << " Fresh fish " << endl;
            else 
                cout << " Sea fish " << endl;
        }
};

class Tuna: public Fish{
    public:
        Tuna(){
            isFreshWaterFish = false;
        }
};

class Carp: public Fish{
    public:
        Carp(){
            isFreshWaterFish = true;
        }
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