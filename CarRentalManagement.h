#ifndef CARRENTALMANAGEMENT_H_INCLUDED
#define CARRENTALMANAGEMENT_H_INCLUDED

#include "Vehicle.h"
#include "Sedan.h"
#include "Pickup.h"
#include "SUV.h"
#include "BookAndRent.h"
#include "RentalContract.h"
#include <iostream>
#include <vector>

using namespace std;


class CarRentalManagement:public BookAndRent
{
private:
    int _day;
    vector <Vehicle*> arrVeh;
    vector <RentalContract*> contract;
public:
    CarRentalManagement(){}
    CarRentalManagement(Vehicle* &veh);
    int getnumCar();
    void addVehicle(string ID, string brand, int cost,int trunkCap);
    void addVehicle(string ID, string brand, int cost, int width, int length,int height);
    void addVehicle(string ID, string brand, int cost, bool isFour);
    void addVehicle(Vehicle* &pVeh);
    void ServiceFleet();
    int Booking();
    int Renting();
    void Returning();
    void printInfo();
    void AddContract();
    void AddVehicle(int idx);
    void PrintService();
    ~CarRentalManagement();
};


#endif // CARRENTALMANAGEMENT_H_INCLUDED
