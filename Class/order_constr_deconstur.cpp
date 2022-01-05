#include <iostream>
using namespace std;

class FishDummyMember{
    public:
        FishDummyMember(){
            cout << "constr FishDummyMember" << endl;
        }

        ~FishDummyMember(){
            cout << "deconstr FishDummyMember" << endl;
        }    
};

class Fish{
    protected:
        FishDummyMember dummy;

    public:
        Fish(){
            cout << "constr Fish" << endl;
        }

        ~Fish(){
            cout << "deconstr Fish" << endl;
        }
};

class TunaDummyMember{
    public:
        TunaDummyMember(){
            cout << "constr TunaDummyMember" << endl;
        }

        ~TunaDummyMember(){
            cout << "deconstr TunaDummyMember" << endl;
        }
};

class Tuna: public Fish{
    private:
        TunaDummyMember dummy;
    public:
        Tuna(){
            cout << "constr Tuna" << endl;
        }
        ~Tuna(){
            cout << "deconstr Tuna" << endl;
        }
};

int main(){
    Tuna myDinner;
}