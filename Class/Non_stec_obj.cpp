#include <iostream>
using namespace std;

class MonsterDB{
    private:
        ~MonsterDB(){}; //Закрытый деконструктор для предотвращения
                        // создание обьектов в стеке 

    public:
        static void DestroyInstance(MonsterDB* pInstance){
            delete pInstance;//Вызов закрытого деконструктора
        }

        void DoSomething() {}//Пустой метод
};

int main(){
    MonsterDB* myBD = new MonsterDB(); // в динамической памяти
    myBD->DoSomething();

    //Раскоментируйте чтобы убедится в неработоспособности
    //delete myBD;


    MonsterDB::DestroyInstance(myBD);

    return 0;
}