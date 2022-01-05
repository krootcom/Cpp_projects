#include <iostream>
using namespace std;

class Fish{
    public:
        void Swim(){
            cout << "Fish swim" << endl;
        }

        /*виртуальная функция которая вызывает метод дочерних классов если такие есть
         перекрытых версий метода Tuna::Swim(),
        которые получили преимущество при вызове над методом Fish::Swim(), пjскольку последний был объявлен как виртуальная функция. 
        Это очень важный момент!
        Он свидетельствует о том, что, даже не зная точный тип обрабатываемого объекта,
        класс которого происходит от класса Fish , реализация метода Make Fish Swim f) способна привести к вызову разных реализаций метода Swim ()
        , определенного в различных производных классах.
        Это и есть полиморфизм: обработка различных рыб как общего типа Fish при
        гарантии выполнения правильной реализации метода Swim (), предоставляемого производными типами.*/
        virtual void Name(){
            cout << "Something" << endl;
        }
};

class Tuna: public Fish{
    public:
        void Swim(){
            cout << "Tune swim" << endl;
        }

        void Name(){
            cout << "Tune" << endl;
        }
};

//функция вызывающая метод базового класса
void FishSwim (Fish& InputFish){
    InputFish.Swim();
}

int main(){
    Tuna MyDinner;
    MyDinner.Swim();
    FishSwim(MyDinner);
    MyDinner.Name();
}