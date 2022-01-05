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

        void Swim(){ cout << "тунец быстрый" << endl; }
};

class Carp: public Fish{
    public:
        Carp() : Fish(true) {}

        void Swim(){ cout << "карп медленный" << endl; }
};

int main(){
    setlocale(LC_ALL,"Rus");

    Carp myL;
    Tuna myD;

    cout << "My food: " << endl;
    cout << " Lunch ";
    myL.Swim();
    cout << " Dinner ";
    myD.Swim();

    cout << " Вызов основного метода  ща немного магии )" << endl;
    myL.Fish::Swim(); 

    //myL.isFreshWaterFish = false;
    
    return 0;
}