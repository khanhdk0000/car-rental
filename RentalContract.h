#ifndef RENTALCONTRACT_H_INCLUDED
#define RENTALCONTRACT_H_INCLUDED

#include "Vehicle.h"
#include "Sedan.h"
#include "Pickup.h"
#include "SUV.h"
#include "date.h"
#include <iostream>
#include <vector>

using namespace std;

class RentalContract
{
private:
    vector<Vehicle*> arr_veh_;
    string customer_name_;
    string user_ID_;
    Date rent_date_;
    Date due_date_;
    string location_;
    string phone_number_;
    Date book_date_;
public:
    RentalContract();
    ~RentalContract();
    RentalContract(string customer_name, string location, string phone_number, string rent_date, string due_date, string user_ID)
        :customer_name_(customer_name), location_(location), phone_number_(phone_number), rent_date_(rent_date), due_date_(due_date), user_ID_(user_ID){}
    Vehicle* AddCar();
    int GetNumCar();
    Vehicle* AddVehicle(string ID, string brand, int cost,int trunkCap);
    Vehicle* AddVehicle(string ID, string brand, int cost, int width, int length,int height);
    Vehicle* AddVehicle(string ID, string brand, int cost, bool isFour);
    void printInfo();
    string GetUserId();
    string GetUserName();
    string GetVehicleID(int idx);
    void SetBookDate(string str_date);
    void SetIsBooked(int idx);
    bool GetIfBooked(int idx);
    void SetNotAvailable(int idx);
    void SetAvailable(int idx);
    void PrintBookDate();
    int GetCost(int idx);
    bool GetRentStatus(int idx);
    void PrintVehicle(int idx);
    void PrintHistoryService(int idx);
};

#endif // RENTALCONTRACT_H_INCLUDED
