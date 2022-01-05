#include <iostream>
#include<string>
using namespace std;

int main()
{
    const char* constCStyleChar = "Hello String";
    cout << "Const string: " << constCStyleChar << endl;

    std::string strFromConst (constCStyleChar);
    cout << "str from const char: " << strFromConst << endl;

    std::string str1 ("Hello World");
    std::string str2 (str1);
    cout << "String copy: " << str2 << endl;

    std::string PartialStr(str1, 5);
    cout << "fragment copy: " << PartialStr << endl;

    std::string AAAAAstr(10, 'A');
    cout << AAAAAstr << endl; 

    //Конкатенация
    std::string halfOfstr ("Ti ");
    std::string halfOfst ("pidor");
    halfOfstr.append(halfOfst);
    cout << halfOfst;
}
