#include <iostream>
using namespace std;

class Animal{
    public:
        Animal(){
            cout << "constr Animal" << endl;
        }

        int age;
};

class Mammal:public virtual Animal{};

class Bird:public virtual Animal{};

class Reptile:public virtual Animal{};

class Platypus:public Mammal, public Bird, public Reptile{
    public:
        Platypus(){
            cout << "constr Platypus" << endl;
        }
};

int main(){
    Platypus duckFucker;
    duckFucker.age = 25;
    //если вы уберёте virtual то в классе Platypus будет 3 атрибута age
    //Я ВСЕГДА ЗНАЛ ЧТО У УТКОНОСА 3 ЖИЗНИ
    return 0;
}