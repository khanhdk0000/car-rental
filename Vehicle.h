#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <vector>
#include "ServiceHistory.h"

using namespace std;
class Vehicle
{
protected:
    string _ID;
    string _brand;
    int _cost;
    bool _isAvailable;
    bool is_booked;
    ServiceHistory record;
    bool is_first_;
    int fluid_level_;
    string tyre_type_;
public:
    Vehicle(){}
    Vehicle(string ID, string brand, int cost):_ID(ID),_brand(brand),_cost(cost), _isAvailable(true), is_booked(false), is_first_(true){}
    void setID(string ID){_ID = ID;}
    string getID(){return _ID;}
    void setBrand(string brand){_brand = brand;}
    string getBrand(){return _brand;}
    void setCost(int cost){_cost = cost;}
    int getCost(){return _cost;}
    void setStatus(bool isAvailable){_isAvailable = isAvailable;}
    bool getStatus(){return _isAvailable;}
    string GetId(){return _ID;}
    void SetIfBooked(){is_booked = true;}
    void SetNotAvailable(){_isAvailable = false;}
    void SetAvailable(){_isAvailable = true;}
    bool GetIfBooked(){return is_booked;}
    void PrintServiceHistory(){record.PrintService(_ID, _brand);}
    virtual void printDetail() = 0;
    virtual void serviceEngine() = 0;
    virtual void serviceTransmission() = 0;
    virtual void serviceTires() = 0;
    ~Vehicle(){}
};


#endif // VEHICLE_H_INCLUDED
