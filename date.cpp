#include "date.h"

using namespace std;

bool operator>(const Date &obj1,const Date &obj2)
{
    if(obj1._year > obj2._year) return true;
    if(obj1._year < obj2._year) return false;
    if(obj1._year == obj2._year)
    {
        if(obj1._month > obj2._month) return true;
        if(obj1._month < obj2._month) return false;
        if(obj1._month == obj2._month)
        {
            if(obj1._day > obj2._day) return true;
            if(obj1._day < obj2._day) return false;
            if(obj1._day == obj2._day) return false;
        }
    }
    return false;
}

 bool operator<(const Date &obj1, const Date &obj2)
{
    if(obj1._year < obj2._year) return true;
    if(obj1._year > obj2._year) return false;
    if(obj1._year == obj2._year)
    {
        if(obj1._month < obj2._month) return true;
        if(obj1._month > obj2._month) return false;
        if(obj1._month == obj2._month)
        {
            if(obj1._day < obj2._day) return true;
            if(obj1._day > obj2._day) return false;
            if(obj1._day == obj2._day) return false;
        }
    }
    return false;
}

Date::Date(string str)
{
    size_t pos = str.find("/");
    size_t pos2 = str.find("/", pos + 1);
    _day = stoi(str.substr(0,2));
    _month = stoi(str.substr(pos + 1, 2));
    _year = stoi(str.substr(pos2 + 1));
}

void Date::printDate()
{
    cout << _day << "/" << _month << "/" << _year << endl;
}

void Date::setValue(string str)
{
    size_t pos = str.find("/");
    size_t pos2 = str.find("/", pos + 1);
    _day = stoi(str.substr(0,2));
    _month = stoi(str.substr(pos + 1, 2));
    _year = stoi(str.substr(pos2 + 1));
}
