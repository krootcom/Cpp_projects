#include <iostream>
#include <string>
using namespace std;

template <typename Type>
const Type& GetMax (const Type& val1, const Type& val2)
{
if (val1 > val2)
    return val1;
else
    return val2;
}

template <typename Type>
void Display(const Type& val1, const Type& val2){
    cout << "GetMax ( " << val1 << " , " << val2 << " ) = " << GetMax(val1, val2) << endl;
}

int main(){
    int n1 = 100, n2 = 2020;
    Display(n1, n2);

    double d1 = 3.14, d2 = 5654.6;
    Display(d1, d2);

    return 0;
}