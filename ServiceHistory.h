#ifndef SERVICEHISTORY_H_INCLUDED
#define SERVICEHISTORY_H_INCLUDED

#include "MaintenanceJob.h"
#include <iostream>
#include <vector>

using namespace std;

class ServiceHistory
{
private:
    vector<MaintenanceJob> rec;
    string _oilMessage;
    int _fluidLevel;
    string _fluidMessage;
    string _typeTyre;
    string _tyreMessage;
    int time_oil;
    int time_fluid;
    int time_tyre;

public:
    ServiceHistory(){}
    ServiceHistory(string oilMess, int kind):_oilMessage(oilMess),time_oil(0){AddMainten(kind, oilMess);}
    ServiceHistory(int fluidLevel, string fluidMess): _fluidLevel(fluidLevel), _fluidMessage(fluidMess), time_fluid(0){AddMainten(2, fluidMess);}
    ServiceHistory(string typeTyre, string tyreMess): _typeTyre(typeTyre), _tyreMessage(tyreMess), time_tyre(0){AddMainten(3, tyreMess);}
    void AddMainten(int kind, string what);
    void PrintService(string _id, string _brand);
};

#endif // SERVICEHISTORY_H_INCLUDED
