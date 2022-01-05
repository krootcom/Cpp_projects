#include <iostream>
#include <string>
using namespace std;

class Display{
    public:
        void operator()(string input) const{
            cout << input << endl;
        }
};

int main(){
    Display obj;

    obj("My string!");

    return 0;
}