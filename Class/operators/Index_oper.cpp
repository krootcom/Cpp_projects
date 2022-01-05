#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class MyString{
    private: 
        char* buffer;

        //закрытый конструктор нах? а я хз
        MyString() {};

    public:
        //Конструктор
        MyString(const char* Input){
            if(Input != nullptr){
                buffer = new char[strlen(Input) + 1];
                strcpy(buffer, Input);
            }
            else
                buffer = nullptr;
        } 

        //Копирующий конструктор
        MyString(const MyString& copySource) {
			buffer = nullptr;
			cout << " copy constructor " << endl;
			if (copySource.buffer != nullptr) {
				buffer = new char[strlen(copySource.buffer) + 1];
				strcpy(buffer, copySource.buffer);
				cout << "buffer in: Ox" << hex;
				cout <<(unsigned int*)buffer << endl;
			}
		}
        
        // Крч если вы хотите чтобы он не копировалсч то засуньте копирующий конструктор в private
        // Оператор копирующего присваивания
        MyString& operator=(const MyString& copySource)
        {
            if ((this != &copySource)&&(copySource.buffer != nullptr))
            {
                if (buffer != nullptr)
                    delete[] buffer;

                // Глубокое копирование в свой буфер
                buffer = new char[strlen(copySource.buffer) + 1];

                // Копирование из исходного объекта в локальный буфер
                strcpy(buffer, copySource.buffer);
            }
            return *this;
        }

        const char& operator[](int index) const{
            if (index < GetLeigth())
                return buffer[index];
        }

        operator const char*(){
            return buffer;
        }

        ~MyString(){
            delete[] buffer;
        }

        int GetLeigth() const{
            return strlen(buffer);
        }
};

int main(){
    MyString Hello("Hello");
    MyString World(" World");

    cout << "defore = : ";
    cout << Hello << World << endl;
    World = Hello;
    cout << "after = : " ;
    cout << Hello << World << endl;

    cout << "Put sentence ";
    string strInput;
    getline(cin, strInput);

    MyString youSaid(strInput.c_str());

    cout << "Your input with operator[]: " << endl;
    for(int index = 0; index < youSaid.GetLeigth(); ++index)
        cout << youSaid[index] << " ";
    cout << endl;

    cout << "Put index 0 - " << youSaid.GetLeigth() - 1 << ": ";
    int InIndex = 0;
    cin >> InIndex;
    cout << "Search sym in posi " << InIndex;
    cout << " - " << youSaid[InIndex] << endl;

    return 0;
}