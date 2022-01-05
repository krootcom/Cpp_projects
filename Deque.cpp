#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    deque <int> intDeque;

    //присоединение данных  с конца
    intDeque.push_back(3);
    intDeque.push_back(4);
    intDeque.push_back(5);

    //Присоединение данных  с начала
    intDeque.push_front(2);
    intDeque.push_front(1);
    intDeque.push_front(0);

    cout << "Values into deque" << endl;

    //Вывод содержимого
    for (size_t count = 0;
        count < intDeque.size();
        ++count)
    {
        cout <<"intDeque[" << count << "] = " << intDeque[count] << endl; 
    }
    cout << endl;

    intDeque.pop_back();
    intDeque.pop_front();

    for (auto elements = intDeque.begin();
        elements != intDeque.end();
        ++elements)
    {
        size_t offset = distance(intDeque.begin(), elements);
        cout << "intDeque[" << offset << "]" << *elements << endl;
    }
    return 0;  
}