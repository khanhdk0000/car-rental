#ifndef CARRENTALMANAGEMENT_H_INCLUDED
#define CARRENTALMANAGEMENT_H_INCLUDED

#include "Vehicle.h"
#include "Sedan.h"
#include "Pickup.h"
#include "SUV.h"
#include "BookAndRent.h"
#include <iostream>
#include <vector>

using namespace std;


class CarRentalManagement:public BookAndRent
{
private:
    static int numCar;
    string _name;
    int _age;
    bool _isQualified;
    int _phoneNum;
    int _day;
    vector <Vehicle*> Contract;
    int preMile, curMile;
public:
    CarRentalManagement(){}
    CarRentalManagement(Vehicle* &veh);
    void setupContract();
    int getnumCar();
    void addCar();
    void addVehicle(string ID, string brand, int cost,int trunkCap);
    void addVehicle(string ID, string brand, int cost, int width, int length,int height);
    void addVehicle(string ID, string brand, int cost, bool isFour);
    void serviceFleet();
    void Booking();
    void Taking();
    void Returning();
    ~CarRentalManagement();
};


#endif // CARRENTALMANAGEMENT_H_INCLUDED
