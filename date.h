#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

using namespace std;

class Date
{
private:
    int _day;
    int _month;
    int _year;
public:
    Date(){}
    Date(string str);
    int GetDay(){return _day;}
    int GetMonth(){return _month;}
    int GetYear(){return _year;}
    void printDate();
    void setValue(string str);

    friend bool operator>(const Date &obj1, const Date &obj2);
    friend bool operator<(const Date &obj1, const Date &obj2);
};

#endif // DATE_H_INCLUDED
