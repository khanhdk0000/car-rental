#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>

using namespace std;
class Vehicle
{
protected:
    string _ID;
    string _brand;
    int _cost;
    bool _isAvailable;
public:
    Vehicle(){}
    Vehicle(string ID, string brand, int cost):_ID(ID),_brand(brand),_cost(cost){}
    void setID(string ID){_ID = ID;}
    string getID(){return _ID;}
    void setBrand(string brand){_brand = brand;}
    string getBrand(){return _brand;}
    void setCost(int cost){_cost = cost;}
    int getCost(){return _cost;}
    void setStatus(bool isAvailable){_isAvailable = isAvailable;}
    bool getStatus(){return _isAvailable;}
    virtual void printDetail() = 0;
    virtual void serviceEngine() = 0;
    virtual void serviceTransmission() = 0;
    virtual void serviceTires() = 0;
    ~Vehicle(){}
};


#endif // VEHICLE_H_INCLUDED
