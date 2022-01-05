/*
Впереди планеты всей не дерективы предпроцессора ,
а попизделки крч тк у меня приведение вызвало кучу
вопросов то я решил этот пример сделать с обьясняющим
коментарием 

крч есть 4 типа приведения
    static_cast
    dynamic_cast
    reinterpret_cast
    const_cast

с синтаксисом по типу
Целевой_тип результат = Приведение<Целевой_тип> (Приводимый_объект);
*/

#include <iostream>
using namespace std;

class Fish{
    public:
        virtual void Swim(){
            cout << "Fish swim in the water " << endl;
        }

        virtual ~Fish() {}
};

class Tuna:public Fish{
    public:
        void Swim(){
            cout << "Tune swim in the sea " << endl;
        }

        void BecomeDinner(){
            cout << "From tuna prepare sushi " << endl;
        }
};

class Carp: public Fish{
    public:
        void Swim(){
            cout << "Carp swim in lake " << endl;
        }

        void Talk(){
            cout << "Carp talk with carp" << endl << "ЧЕГО БЛЯТЬ КАРПЫ ВЫ КТО -_+";
        }
};

class Unrelated{};

void DetectType(Fish* objFish){
    Tuna* objTuna = dynamic_cast <Tuna*>(objFish);
    if(objTuna) //проверка успешности
    {
        cout << "Tune detected: " << endl;
        objTuna->BecomeDinner();
    }

    Carp* objCarp = dynamic_cast <Carp*>(objFish);
    if(objCarp)
    {
        cout << "Carp detected: " << endl;
        objCarp->Talk(); //Вызов виртуальной функции Swim
    }
}

int main(){
    Fish* objFish = new Tuna();
    Tuna* objDer = static_cast<Tuna*>(objFish); //Всё ровно

    //Unrelated* notRelated = static_cast<Unrelated*>(objFish); //Раскоментируй и получишь бебру
    // Приведение к несвязанному типу не разрешено

    /*
    оператор static_cast проверяет только то, что ссылочные типы связаны.
    Он не выполняет проверок времени выполнения. Таким образом, с
    оператором static_cast разработчик вполне может совершить следующую ошибку:
    
    Fish* objFish = new Fish();
    Tuna* objDer = static_cast<Tuna*>(objFish); // Bee OK
    */
////////////////////////////////////////////////////////////////////////////////////////////////////

   Carp myLunch;
   Tuna myDinner;

   DetectType(&myDinner);
   cout << endl;
   DetectType(&myLunch);

   /*
    Как показано в приведенном выше коротком примере, 
    имея указатель на объект базового класса, разработчик 
    может прибегнуть к оператору dynamic_cast, 
    чтобы проверить тип целевого объекта, 
    прежде чем перейти к использованию указателя на него
   */
///////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Оператор приведения C++ renterpret_cast ближе всех к приведению в стиле
    С. Он позволяет разработчику приводить один тип объекта к другому независимо от
    того, связаны ли их типы:
    */
    Fish* objBase = new Fish();
    Unrelated* notRelated = reinterpret_cast<Unrelated*>(objBase);
    //Код компилится но не надо так (такой хуйни на static_cast не сделаешь)

   return 0;
}