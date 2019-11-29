#ifndef SERVICEHISTORY_H_INCLUDED
#define SERVICEHISTORY_H_INCLUDED

#include "MaintenanceJob.h"
#include <iostream>
#include <vector>

using namespace std;

class ServiceHistory
{
private:
    std::vector<MaintenanceJob*> rec;
public:
    string _oilMessage;
    int _fluidLevel;
    string _fluidMessage;
    string _typeTyre;
    string _tyreMessage;
    ServiceHistory(string oilMess):_oilMessage(oilMess){}
    ServiceHistory(int fluidLevel, string fluidMess): _fluidLevel(fluidLevel), _fluidMessage(fluidMess){}
    ServiceHistory(string typeTyre, string tyreMess): _typeTyre(typeTyre), _tyreMessage(tyreMess){}
};

#endif // SERVICEHISTORY_H_INCLUDED
