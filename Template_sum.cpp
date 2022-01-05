#include <iostream>
using namespace std;

template <typename Res, typename ValType>
void Sum(Res& result, ValType& val){
    result = result + val;
}

template<typename Res, typename First, typename... Rest>
void Sum(Res& result, First val, Rest... valN)
{
    result = result + val;
    return Sum(result, valN ...);
}

int main(){
    double Dresult = 0;
    Sum(Dresult, 2.4, 6.5, 46.6);
    cout << "Dresult = " << Dresult << endl;

    string strResult;
    Sum(strResult, "name ", "Kirill");
    cout << "strResult = " << strResult << endl;
}