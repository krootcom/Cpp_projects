#include <iostream>
#include <string>
using namespace std;

#define ARRAY_LENGTH 25
#define PI 3.1416
#define MY_DOUBLE double
#define FAV_WHISKY "Jack Daniels"

int main(){
    int numbers[ARRAY_LENGTH] = {0};
    cout << "array length " << sizeof(numbers)/sizeof(int) << endl;

    cout << "Put radius: ";
    MY_DOUBLE rad = 0;
    cin >> rad;
    cout << "Space: " << PI * rad * rad << endl;

    string favouriteWhisky (FAV_WHISKY);
    cout << "I love: " << FAV_WHISKY << endl;

    return 0;  
}