#include <iostream>
#include <vector>
using namespace std;

template <typename T1>
    void Display (vector<T1> inVec, int index){
        if(index <= inVec.cend()){
            cout << "value[" << index - 1 << "] = " << inVec[index - 1] << endl;
        }
    }
    
template <typename T1>
    T1 Output(vector<T1> inVec, int index){
        if(index <= inVec.cend()){
            return inVec[index - 1];
        }
        return 0
    }

template <typename T1>
    void Input (vector<T1>& inVec, T1 value){
        inVec.push_back(value);
    }

int main(){
    vector<int> TestVectorInt;
    Input(TestVectorInt, 666);
    cout << TestVectorInt[0];
    cout << Output(TestVectorInt, 1);
}