#include <iostream>
#include <sstream>//заголовочный файл для ostringstream
#include <string.h>
using namespace std;

class Date{
    private:
        int day, mounth, year;
        string dateString;

    public:
        Date(int inDay, int inMouth, int inYear)
        : mounth(inMouth), day(inDay), year(inYear) {};

        Date(const Date& copyScourse){
            cout << "copy constr" << endl;
            day = int(copyScourse.day);
            mounth = int(copyScourse.mounth);
            year = int(copyScourse.year);
        }

        Date& operator ++ () //Префиксный инкремент
        {
            ++day;
            return *this;
        }

        Date& operator --() //Префексный декремент
        {
            --day;
            return *this;
        }

        Date operator +(int dayToAdd)// Сложение
        {
            Date newDate(day + dayToAdd, mounth, year);
            return newDate;
        }

        Date operator -(int dayToSub)// Сложение
        {
            Date newDate(day - dayToSub, mounth, year);
            return newDate;
        }

        void Display()
        {
            cout << day << "." << mounth << "." << year << endl;
        }

        bool operator== (const Date& compareTo){
            return((day == compareTo.day)
                   && (mounth == compareTo.mounth)
                   && (year == compareTo.year));
        }

        bool operator!= (const Date& compareTo){
            return((day != compareTo.day)
                   && (mounth != compareTo.mounth)
                   && (year != compareTo.year));
        }

        //оператор перевода обьекта в текст для того чтобы впихнут в поток std
        operator const char*(){
            ostringstream forattedDate; //Помогает создат строку
            forattedDate << day << "." << mounth << "." << year;

            dateString = forattedDate.str();
            return dateString.c_str();
        }
};

int main(){
    Date today (31, 10, 2021);
    Date notToday (22, 6, 2013);

    cout << "oper == " << (today == notToday) << endl;
    cout << "oper != " << (today != notToday) << endl;

    cout << "Data value: ";
    today.Display();

    ++today;
    cout << "increment: ";
    today.Display();

    --today;
    cout << "decrement: ";
    today.Display();

    cout << "Today is: " << today << endl;

    Date tommorow(today + 5);
    cout << "today + 5: " << tommorow << endl;

    return 0;
}