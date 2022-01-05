#include <iostream>
using namespace std;

// Обьект принимающий либо добл либо инт
template <typename T1=int, typename T2=double>
class HoldPair{ 
    private:
        T1 value1;
        T2 value2;

    public:
        HoldPair(const T1& val1, const T2& val2)
        : value1(val1), value2(val2) {}

        const T1 & GetFirstValue() const
        {
        return value1;
        }

        const T2 & GetSecondValue() const
        {
        return value2;
        }
};

int main(){
    HoldPair<> pairIntDbl(135, 10.90);
    HoldPair<short, const char*> pairShortStr(25, "Shablon");

    cout << "First  obj in" << endl;
    cout << pairIntDbl.GetFirstValue() << endl;
    cout << pairIntDbl.GetSecondValue() << endl ;

    cout << "Second obj in " << endl;
    cout << pairShortStr.GetFirstValue() << endl;
    cout << pairShortStr.GetSecondValue() << endl;
    return 0;
}   