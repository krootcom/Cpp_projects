#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //Динамический массив целых чисел
    vector <int> intArray;

    //Вставить примеры целых чисел в пример
    intArray.push_back(2020);
    intArray.push_back(4580);
    intArray.push_back(0000);
    intArray.push_back(52825);

    cout << "input values" << endl;

    //Обход вектора с помощью итератора
    vector <int>::iterator arrIterator = intArray.begin();

    while(arrIterator != intArray.end())
    {
        //Вывод содержимово
        cout << *arrIterator << endl;

       ++arrIterator;
    }

    //Поиск элемента
    vector <int>::iterator elFound =
    find(intArray.begin(), intArray.end(), 2020);

    //Проверка найдено ли значение 
    if (elFound != intArray.end())
    {
        //Значение найдено определяем место в массиве
        int elPos = distance(intArray.begin(), elFound);
        cout << "Value : " << *elFound;
        cout << " Position : " << elPos << endl;
    }
}