#include <iostream>
using namespace std;

class Fish{
    public:
        virtual Fish* Clone() = 0;
        virtual void Swim() = 0;
        virtual ~Fish() {};
};

class Tuna: public Fish{
    public:
        Fish* Clone() override{
            return new Tuna(*this);
        }

        void Swim() override final{
            cout << "Tune swim fast in sea" << endl;
        }
};

class BluefinTuna final:public Tuna{
    public:
        Fish* Clone() override{
            return new BluefinTuna(*this);
        }
        // Нельзя перекрыть final Tuna::Swim
};

class Carp final: public Fish{
    Fish* Clone() override{
        return new Carp(*this);
    }
    void Swim() override final{
        cout << "Carp swim slow in lake" << endl;
    }
};

int main(){
    const int ARRAY_SIZE = 4;

    Fish* myFishes[ARRAY_SIZE] = {nullptr};
    myFishes[0] = new Tuna();
    myFishes[1] = new Carp();
    myFishes[2] = new BluefinTuna();
    myFishes[3] = new Carp();

    Fish* myNewFishes[ARRAY_SIZE];
    for(int index = 0; index < ARRAY_SIZE; ++index)
        myNewFishes[index] = myFishes[index]->Clone();
    
    //Вызов виртуального метода для проверки
    for(int index = 0; index < ARRAY_SIZE; ++index)
        myNewFishes[index]->Swim();

    //освобождение памяти
    for(int index = 0; index < ARRAY_SIZE; ++index){
        delete myFishes[index];
        delete myNewFishes[index];
    }


    return 0;
}