#ifndef MAINTENANCEJOB_H_INCLUDED
#define MAINTENANCEJOB_H_INCLUDED

#include "rapidjson/rapidjson.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include "date.h"
#include "Json.h"
#include <errno.h>
#include "date.h"
#include <rapidjson/ostreamwrapper.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace rapidjson;
using namespace std;

class MaintenanceJob //where when what mileage,
{
    // overload - for mileage difference: mJob1-mJob2
    // mJob1 < or > mJob2 compare the time
private:
    string type;
    string _what;
    Date _when;//(dd/mm/yyyy)
    string _where;
    int _mileage;
    int timeth;
    string oil_service_;
    string fluid_service_;
    string tyre_service_;
    //Json history;
public:
    MaintenanceJob(){}
    MaintenanceJob(string when, string what, string where, int mileage): _when(when), _what(what), _where(where), _mileage(mileage){}
    void printDetail();
    void SetValue(int kind, string mess, int time);
    void SetLocation(string location){_where = location;}
    void SetDate(string day);
    void PrintHistory(string _id, string _brand);
    friend int operator-(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
    friend bool operator>(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
    friend bool operator<(const MaintenanceJob &obj1, const MaintenanceJob &obj2);
};

#endif // MAINTENANCEJOB_H_INCLUDED
