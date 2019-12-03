#include "RentalContract.h"

using namespace std;

RentalContract::RentalContract()
{
    string name, location, phone, rent_date, due_date, user_id;
    cout << "*****Please welcome*****\n";
    cout << "Enter the following information to set up contract:\n";
    cout << "Your name: ";
    cin.clear();
    cin.ignore();
    getline(cin, name);
    cout << "Your location: ";
    cin.clear();
    getline(cin, location);
    cout << "Your phone number: ";
    cin >> phone;
    cout << "Your rent date(dd/mm/yyyy): ";
    cin >> rent_date;
    cout << "Your due date(dd/mm/yyyy): ";
    cin >> due_date;
    cout << "Please enter ID you wish to use: ";
    cin >> user_id;
    customer_name_ = name;
    phone_number_ = phone;
    location_ = location;
    user_ID_ = user_id;
    rent_date_.setValue(rent_date);
    due_date_.setValue(due_date);
}

int RentalContract::GetNumCar()
{
    return arr_veh_.size();
}

Vehicle* RentalContract::AddCar()
{
    int cost,user_choice;
    string ID, brand;
    cout << "Vehicle number " << GetNumCar() + 1 <<":\n";
    cout << "Enter your ID: ";
    cin >> ID;
    cout << "Enter your brand: ";
    cin >> brand;
    cout << "Enter initial cost: ";
    cin >> cost;
    while(true)
    {
        cout << "Enter your type of vehicle(1 for Sedan, 2 for pickup, 3 for SUV): ";
        cin >> user_choice;
        if(user_choice >= 1 && user_choice <= 3)
            break;
    }
    if(user_choice == 1)
    {
        int trunkCap;
        cout << "Enter your trunk cap: ";
        cin >> trunkCap;
        cout << "\n/////////////////////////////\n\n";
        return AddVehicle(ID, brand, cost,trunkCap);
    }
    else if(user_choice == 2)
    {
        int width, length, height;
        cout << "Enter Pickup width: ";
        cin >> width;
        cout << "Enter Pickup length: ";
        cin >> length;
        cout << "Enter Pickup height: ";
        cin >> height;
        cout << "\n/////////////////////////////\n\n";
        return AddVehicle(ID, brand, cost, width, length, height);
    }
    else if(user_choice == 3)
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
        cout << "\n/////////////////////////////\n\n";
        return AddVehicle(ID, brand, cost, isFour);
    }
}

Vehicle* RentalContract::AddVehicle(string ID, string brand, int cost,int trunkCap)
{
    Vehicle* pVeh = new Sedan(ID, brand, cost, trunkCap);
    arr_veh_.push_back(pVeh);
    return pVeh;
}

Vehicle* RentalContract::AddVehicle(string ID, string brand, int cost, int width, int length, int height)
{
    Vehicle* pVeh = new PickUp(ID, brand, cost, width, length, height);
    arr_veh_.push_back(pVeh);
    return pVeh;
}

Vehicle* RentalContract::AddVehicle(string ID, string brand, int cost, bool isFour)
{
    Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
    arr_veh_.push_back(pVeh);
    return pVeh;
}

RentalContract::~RentalContract()
{
    arr_veh_.clear();
}

void RentalContract::printInfo()
{
    unsigned num_size = arr_veh_.size();
    for(unsigned i = 0; i < num_size; i++)
    {
        arr_veh_[i]->printDetail();
    }
}

string RentalContract::GetUserId()
{
    return user_ID_;
}

string RentalContract::GetUserName()
{
    return customer_name_;
}

string RentalContract::GetVehicleID(int idx)
{
    return arr_veh_[idx]->GetId();
}

void RentalContract::SetBookDate(string str_date)
{
    book_date_.setValue(str_date);
}

void RentalContract::SetIsBooked(int idx)
{
    arr_veh_[idx]->SetIfBooked();
}

bool RentalContract::GetIfBooked(int idx)
{
    return arr_veh_[idx]->GetIfBooked();
}

void RentalContract::SetNotAvailable(int idx)
{
    arr_veh_[idx]->SetNotAvailable();
}

void RentalContract::PrintBookDate()
{
    book_date_.printDate();
}

int RentalContract::GetCost(int idx)
{
    return arr_veh_[idx]->getCost();
}

bool RentalContract::GetRentStatus(int idx)
{
    return arr_veh_[idx]->getStatus();
}

void RentalContract::PrintVehicle(int idx)
{
    arr_veh_[idx]->printDetail();
}

void RentalContract::SetAvailable(int idx)
{
    arr_veh_[idx]->SetAvailable();
}

void RentalContract::PrintHistoryService(int idx)
{
    arr_veh_[idx]->printDetail();
    arr_veh_[idx]->PrintServiceHistory();
}
