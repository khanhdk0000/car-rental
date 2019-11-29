#ifndef SEDAN_H_INCLUDED
#define SEDAN_H_INCLUDED

#include "Vehicle.h"
#include "ServiceHistory.h"
#include <iostream>
#include <vector>

using namespace std;

class Sedan: public Vehicle
{
    int trunk_cap;
    std::vector<ServiceHistory*> record;
public:
    Sedan(){};
    Sedan(string ID, string brand, int cost, int trunkCap):Vehicle(ID, brand, cost), trunk_cap(trunkCap){}
    void printDetail();
    void serviceEngine();
    void serviceTransmission();
    void serviceTires();
    ~Sedan(){}
};

#endif // SEDAN_H_INCLUDED
