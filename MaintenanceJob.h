#ifndef MAINTENANCEJOB_H_INCLUDED
#define MAINTENANCEJOB_H_INCLUDED

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
    void printDate();
    friend bool operator>(const Date &obj1, const Date &obj2);
    friend bool operator<(const Date &obj1, const Date &obj2);
};

class MaintenanceJob //where when what mileage,
{
    // overload - for mileage difference: mJob1-mJob2
    // mJob1 < or > mJob2 compare the time
private:
    string _what;
    Date _when;//(dd/mm/yy)
    string _where;
    int _mileage;
public:
    MaintenanceJob(){}
    MaintenanceJob(string when, string what, string where, int mileage): _when(when), _what(what), _where(where), _mileage(mileage){}
    void printDetail();
    friend int operator-(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
    friend bool operator>(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
    friend bool operator<(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
};

#endif // MAINTENANCEJOB_H_INCLUDED
