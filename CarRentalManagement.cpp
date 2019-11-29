#include "CarRentalManagement.h"

using namespace std;

CarRentalManagement::CarRentalManagement(Vehicle* &veh)
{
    Contract.push_back(veh);
}

void CarRentalManagement::setupContract()
{
    string user;
    cout << "Enter your name: ";
    cin >> _name;
    cout << "Your age: ";
    cin >> _age;
    cout << "Are you qualified according to law(above 18, driving license acquired...): ";
    cin >> user;
    if(user == "yes")
    {
        _isQualified = true;
    }
    else if(user == "no")
    {
        _isQualified = false;
    }
    cout << "Your phone number: ";
    cin >> _phoneNum;

    addCar();
}

int CarRentalManagement::getnumCar()
{
    return numCar;
}

void CarRentalManagement::addCar()
{
    int cost,userChoice;
    string ID, brand;
    cout << "Enter your ID: ";
    cin >> ID;
    cout << "Enter your brand: ";
    cin >> brand;
    cout << "Enter initial cost: ";
    cin >> cost;
    while(true)
    {
        cout << "Enter your type of vehicle(1 for Sedan, 2 for pickup, 3 for SUV): ";
        cin >> userChoice;
        if(userChoice >= 1 && userChoice <= 3)
            break;
    }
    if(userChoice == 1)
    {
        int trunkCap;
        cout << "Enter your trunk cap: ";
        cin >> trunkCap;
        //Vehicle* pVeh = new Sedan(ID, brand, cost,trunkCap);
        //Contract.push_back(pVeh);
        addVehicle(ID, brand, cost,trunkCap);
    }
    else if(userChoice == 2)
    {
        int width, length, height;
        cout << "Enter Pickup width: ";
        cin >> width;
        cout << "Enter Pickup length: ";
        cin >> length;
        cout << "Enter Pickup height: ";
        cin >> height;
        //Vehicle* pVeh = new PickUp(ID, brand, cost, width, length,height);
        //Contract.push_back(pVeh);
        addVehicle(ID, brand, cost, width, length,height);
    }
    else if(userChoice == 3)
    {
        string choice;
        bool isFour;
        cout << "Is your SUV fourseat(enter yes or no): ";
        cin >> choice;
        if(choice == "yes")
        {
            isFour = true;
        }
        else if(choice == "no")
        {
            isFour = false;
        }
        //Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
        //Contract.push_back(pVeh);
        addVehicle(ID, brand, cost, isFour);
    }
        //numCar++;
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost,int trunkCap)
{
    //Vehicle* pTem = new Sedan();
    Vehicle* pVeh = new Sedan(ID, brand, cost,trunkCap);
    Contract.push_back(pVeh);
    numCar++;
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost, int width, int length,int height)
{
    //Vehicle* pTem = new PickUp();
    Vehicle* pVeh = new PickUp(ID, brand, cost, width, length,height);
    Contract.push_back(pVeh);
    numCar++;
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost, bool isFour)
{
    //Vehicle* pTem = new SUV();
    Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
    Contract.push_back(pVeh);
    numCar++;
}

void CarRentalManagement::serviceFleet()
{
    size_t num = Contract.size();
    int choice;
    for(int i = 0; i < num; i++)
    {
        cout << "Enter your previous mile: ";
        cin >> preMile;
        cout << "Enter your current mile: ";
        cin >> curMile;
        if(curMile - preMile >= 3000)
        {
            cout << "Enter 1 for Engine Service, 2 for Transmission Service, 3 for Tire Service: ";
            cin >> choice;
            if(choice == 1)
            {
                Contract[i]->serviceEngine();
            }
            else if(choice == 2)
            {
                Contract[i]->serviceTransmission();
            }
            else if(choice == 3)
            {
                Contract[i]->serviceTires();
            }
            else cout << "Invalid choice.";
        }
        else cout << "Your vehicle is still functioning properly, please return next time." << endl;
    }
}

void CarRentalManagement::Booking()
{
    cout << "Welcome, please enter your taking date: ";
    cin >> bookDate;
    cout << "Enter the vehicle you want: ";
    cin >> bookVehicle;
    isDebt = true;
}

void CarRentalManagement::Taking()
{
    string temDate,temVehicle;
    while(true)
    {
        cout << "Enter the date you booked: ";
        cin >> temDate;
        cout << "Enter the vehicle you booked: ";
        cin >> temVehicle;
        if(temVehicle == bookVehicle && temDate == bookDate)
            break;
    }
}

void CarRentalManagement::Returning()
{

}

CarRentalManagement::~CarRentalManagement()
{
    Contract.clear();
}

int CarRentalManagement::numCar = 0;
