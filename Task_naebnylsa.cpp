#include <iostream>
#include <vector>
using namespace std;

class CuvshinList{
    private:
        vector <float[2]> CuvVe;
    public:
        void AddCuvshin(float S, float L){
            float mass[2];
            mass[0] = S;
            mass[1] = L;
            CuvVe.push_back(mass);
        }
        
        void DelayCuvshin(){
            CuvVe.pop_back();
        }

        void Display(){
            for(size_t count = 0; count < CuvVe.size(); count++){
                cout << "Cuvshin[" << count << "] = " << CuvVe[count][0] << " " << CuvVe[count][1] << endl;
            }
        }
};

int main(){
    CuvshinList Cuvsh_list_one;
    Cuvsh_list_one.AddCuvshin(9.0, 88.77);
    Cuvsh_list_one.AddCuvshin(55.6, 73.2);
    Cuvsh_list_one.Display();
}