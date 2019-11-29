#ifndef PICKUP_H_INCLUDED
#define PICKUP_H_INCLUDED

#include "Vehicle.h"
#include "ServiceHistory.h"
#include <iostream>
#include <vector>

using namespace std;

struct Dimension
{
    int _width;
    int _length;
    int _height;
    Dimension(){}
    Dimension(int width, int length, int height):_width(width), _length(length), _height(height){}
};

class PickUp: public Vehicle
{
    Dimension dim;
    vector<ServiceHistory*> record;
public:
    PickUp(){}
    PickUp(string ID, string brand, int cost, int width, int length, int height):Vehicle(ID, brand, cost)
    {
        dim._width = width;
        dim._length = length;
        dim._height = height;
    }
    void printDetail();
    void serviceEngine();
    void serviceTransmission();
    void serviceTires();
    ~PickUp(){}
};

#endif // PICKUP_H_INCLUDED
