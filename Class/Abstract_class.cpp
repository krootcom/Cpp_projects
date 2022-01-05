#include <iostream>
using namespace std;

class Fish{
    public:
        //определение чисто виртуальной функции
        virtual void Swim() = 0;
};

class Tuna:public Fish{
    public:
        void Swim(){
            cout << "Tuna swim fast" << endl;
        }
};

class Carp:public Fish{
    public:
        void Swim(){
            cout << "Carp swim slow" << endl;
        }
};

void MakeFishSwim(Fish& inputFish){
    inputFish.Swim();
}

int main(){
    // Fish maFish; // раскоментируй абстрактный класс и нюхни бебру!
    Carp myLunch;
    Tuna myDinner;

    MakeFishSwim(myLunch);
    MakeFishSwim(myDinner);

    return 0;
}