#include <iostream>
using namespace std;

union SimpleUnion{
    int num;
    char alphabet;
};

struct ComplexType{
    enum DataType
    {
        Int,
        Char 
    } Type;

    union Value{
        int num;
        char alphabet;

        Value() {}
        ~Value() {}
    }value;
};

void DisplayComplexType(const ComplexType& obj){
    switch (obj.Type)
    {
    case ComplexType::Int:
        cout << "union have number: " << obj.value.num << endl;
        break;

    case ComplexType::Char:
        cout << "union have sym: " << obj.value.alphabet << endl;
        break;
    }
}

int main(){
    SimpleUnion u1, u2;
    u1.num = 2100;
    u2.alphabet = 'C';
    u1.alphabet = 'n';
    cout << "u1 al = " << u1.alphabet << " u1 num " << u1.num << endl;
    cout << "sizeof(u1) with number: " << sizeof(u1) << endl;
    cout << "sizeof(u2) with sym" << sizeof(u2) << endl;

    ComplexType myData1, myData2;
    myData1.Type = ComplexType::Int;
    myData1.value.num = 2017;

    myData2.Type = ComplexType::Char;
    myData2.value.alphabet = 'X';

    DisplayComplexType(myData1);
    DisplayComplexType(myData2);

    return 0;
}