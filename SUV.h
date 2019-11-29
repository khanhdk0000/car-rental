#ifndef SUV_H_INCLUDED
#define SUV_H_INCLUDED

#include "Vehicle.h"
#include "ServiceHistory.h"
#include <iostream>
#include <vector>

using namespace std;

class SUV: public Vehicle
{
    bool fourSeat;
    vector<ServiceHistory*> record;
public:
    SUV(){}
    SUV(string ID, string brand, int cost,bool isFour):Vehicle(ID, brand, cost), fourSeat(isFour){}
    void printDetail();
    void serviceEngine();
    void serviceTransmission();
    void serviceTires();
    ~SUV(){}
};


#endif // SUV_H_INCLUDED
