#include "MaintenanceJob.h"

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

////////////////////////////////

int operator-(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    int ans;
    ans = obj1._mileage - obj2._mileage;
    return ans;
}

bool operator>(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    return obj1._when > obj2._when;
}

bool operator<(const MaintenanceJob &obj1, const MaintenanceJob &obj2)
{
    return obj1._when < obj2._when;
}

void MaintenanceJob::printDetail()
{
    cout << "What: " << _what << endl;
    cout << "Where: " << _what << endl;
    cout << "When: ";
    _when.printDate();
    cout <<"\n";
    cout << "Mileage: " << _mileage << endl;
}
