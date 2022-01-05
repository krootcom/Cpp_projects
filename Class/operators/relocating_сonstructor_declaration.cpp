#include <iostream>
#include <string.h>
using namespace std;

class MyString{
    private:
        char* buffer;

        MyString(): buffer(nullptr) //Закрытый конструктор
        {
            cout << "constr po yd" << endl;
        }

    public:
        MyString(const char* initInput) //Конструктор
        {
            cout << "Constr: " << initInput << endl;
            if(initInput != nullptr){
                buffer = new char[strlen(initInput) + 1];
                strcpy(buffer, initInput);
            }
            else
                buffer = nullptr;
        }

        MyString(MyString&& moveSrc) //перемещающийся конструктор
        {
            cout << "Move constr: " << moveSrc.buffer << endl;
            if(moveSrc.buffer != nullptr){
                buffer = moveSrc.buffer; //Получение владения
                moveSrc.buffer = nullptr; //Освобождение перемещёного ресурса
            }
        }

        MyString& operator=(MyString&& moveSrc) //Перемещающее присваевание
        {
            cout << "Move declaration: " << moveSrc.buffer << endl;
            if((moveSrc.buffer != nullptr) && (this != &moveSrc)){
                delete[] buffer; // release own buffer

                buffer = moveSrc.buffer; //Получение владения
                moveSrc.buffer = nullptr;
            }

            return *this;
        }

        MyString(const MyString& copyScr) //Копирующий констрактор
        {
            cout << "Copy constr: " << copyScr.buffer << endl;
            if(copyScr.buffer != nullptr){
                buffer  = new char[strlen(copyScr.buffer) + 1];
                strcpy(buffer, copyScr.buffer);
            }
            else
                buffer = nullptr;
        }

        MyString& operator=(const MyString& copySrc) // Оператор копирующего присваивания
        {
            cout << "Copy declaration: " << copySrc.buffer << endl;
            if((this != &copySrc) && (copySrc.buffer != nullptr)){
                if(buffer != nullptr)
                    delete[] buffer;

                buffer = new char[strlen(copySrc.buffer) + 1];
                strcpy(buffer, copySrc.buffer);
            }

            return *this;
        }

        ~MyString() //Деконструктор
        {
            if (buffer != nullptr)
                delete[] buffer;
        }

        int GetLeigth(){
            return strlen(buffer);
        }

        operator const char*(){
            return buffer;
        }

        MyString operator+(const MyString& addThis){
            cout << "operator+: " << endl;
            MyString newStr;

            if(addThis.buffer != nullptr){
                newStr.buffer = new char[GetLeigth()+strlen(addThis.buffer)+1];
                strcpy(newStr.buffer, buffer);
                strcat(newStr.buffer, addThis.buffer);
            }

            return newStr;
        }
};

int main(){
    MyString Hello ("Hello ");
    MyString World ("Wrold");
    MyString CPP(" of C++");

    MyString sayHelloAgain("overwrite this");
    sayHelloAgain = Hello + World + CPP;

    return 0;
}