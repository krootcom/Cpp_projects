#include <iostream>
using namespace std;

class Mammal{
    public:
        void FeedBabyMilk(){
            cout << "Mammal: I love milk!" << endl;
        }
};

class Reptile{
    public:
        void SpitVenom(){
            cout << "Reptile: Spit Poison!" << endl;
        }
};

class Bird{
    public:
        void LayEggs(){
            cout << "Bird: eggs laid!" << endl;
        }
};

class Platypus: public Mammal, public Bird, public Reptile{
    public:
        void Swim(){
            cout << "Platypus: I can swim!" << endl;
        }
};

int main(){
    Platypus realFreak;
    realFreak.LayEggs();
    realFreak.FeedBabyMilk();
    realFreak.SpitVenom();
    realFreak.Swim();
}