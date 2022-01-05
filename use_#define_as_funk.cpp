#include <iostream>
#include <string>
using namespace std;

#define SQUARE(x) ((x) * (x))
#define PI 3.1416
#define AREA_CIRCE(r) (PI*(r)*(r))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(){
    cout << "Put int number: ";
    int num = 0;
    cin >> num;

    cout << "SQUARE(" << num << ") = " << SQUARE(num) << endl;
    cout << "Space okr with radius " << num << " = " ;
    cout << AREA_CIRCE(num) << endl;

    cout << "Put another int number: ";
    int num2 = 0;
    cin >> num2;

    cout << "MIN(" << num << ", " << num2 << ") = ";
    cout << MIN(num, num2) << endl;

    cout << "MAX(" << num << ", " << num2 << ") = ";
    cout << MAX(num, num2) << endl;

    return 0;
}