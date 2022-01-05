#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
	private:
		char* buffer;

	public:
		MyString(const char* initString) {
			buffer = nullptr;
			if (initString != nullptr) {
				buffer = new char[strlen(initString) + 1];
				strcpy(buffer, initString);
			}
		}
		
		//копирующий конструктор для использования в стороних функциях
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
		

		~MyString() {
			cout << "Deconstructor call" << endl;
			delete[] buffer;
		}

		int GetLength() {
			return strlen(buffer);
		}

		const char* GetString() {
			return buffer;
		}
};

void UseMySyring(MyString str) {
	cout << " len " << str.GetLength();
	cout << " simvol " << endl;
	cout << " value: " << str.GetString() << endl;
	return;
}

int main() {
	MyString sayHello("Hello from String Class");
	UseMySyring(sayHello);

	return 0;
}
