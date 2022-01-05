#include <iostream>
using namespace std;

template <typename T>
class TestStatic{
    public:
        static int staticVal;
};

//Оьявление статической переменной
template <typename T> int TestStatic<T>::staticVal;

int main(){
    TestStatic<int> intInstanse;

    cout << "static var = 1001" << endl;
    intInstanse.staticVal = 1001;

    TestStatic<double> doubInstanse;

    cout << "static var = 2002" << endl;
    doubInstanse.staticVal = 2002;

    cout << "staticInt = " << intInstanse.staticVal << endl;
    cout << "staticDoubl = " << doubInstanse.staticVal << endl;
}