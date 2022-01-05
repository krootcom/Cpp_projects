#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> integers(5);

    cout << "start vector prm " << endl;
    cout << "Size " << integers.size() << endl;
    cout << "Capacity " << integers.capacity() << endl << endl;

    integers.push_back(555);

    cout << "after push back prm " << endl;
    cout << "Size " << integers.size() << endl;
    cout << "Capacity " << integers.capacity() << endl << endl;

    integers.push_back(666);

    cout << "after after push back prm " << endl;
    cout << "Size " << integers.size() << endl;
    cout << "Capacity " << integers.capacity() << endl; 
}