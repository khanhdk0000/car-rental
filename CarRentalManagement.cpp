#include "CarRentalManagement.h"

using namespace std;

CarRentalManagement::CarRentalManagement(Vehicle* &veh)
{
    arrVeh.push_back(veh);
}

int CarRentalManagement::getnumCar()
{
    return arrVeh.size();
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost,int trunkCap)
{
    Vehicle* pVeh = new Sedan(ID, brand, cost, trunkCap);
    arrVeh.push_back(pVeh);
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost, int width, int length, int height)
{
    Vehicle* pVeh = new PickUp(ID, brand, cost, width, length, height);
    arrVeh.push_back(pVeh);
}

void CarRentalManagement::addVehicle(string ID, string brand, int cost, bool isFour)
{
    Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
    arrVeh.push_back(pVeh);
}

void CarRentalManagement::ServiceFleet()
{
    size_t num = arrVeh.size();
    int preMile, curMile;
    int choice;
    for(int i = 0; i < num; i++)
    {
        arrVeh[i]->printDetail();
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
                arrVeh[i]->serviceEngine();
            }
            else if(choice == 2)
            {
                arrVeh[i]->serviceTransmission();
            }
            else if(choice == 3)
            {
                arrVeh[i]->serviceTires();
            }
            else cout << "Invalid choice." << endl;
        }
        else cout << "This vehicle is still functioning properly, no need for prepare." << endl;
        cout << "\n/////////////////////////////\n\n";
    }
}

int CarRentalManagement::Booking()
{
    cout << "\n*****Welcome to booking service*****\n";
    string tem_id, name, vehicle_id, user_date;
    int size_num = contract.size(), size_num2;
    int idx = -1, idx_veh = -1;
    bool is_found1 = false, is_found2 = false, is_found3 = false, already_book = false;
    cout << "Please enter your name: ";
    while(true)
    {
        cin.clear();
        cin.ignore();
        getline(cin, name);
        for(unsigned i = 0; i < size_num; i++)
        {
            if(contract[i]->GetUserName() == name)
            {
                idx = i;
                is_found1 = true;
                break;
            }
        }
        if(is_found1)
        {
            break;
        }
        else
        {
            cout << "\nYour name does not exit in the database, please enter again: ";
        }

    }
    cout << "\nEnter the ID you have entered when creating contract: ";
    while(true)
    {
        cin >> tem_id;
        if(contract[idx]->GetUserId() == tem_id)
        {
            is_found2 = true;
            cout << "\n----Welcome back----\n";
        }
        if(is_found2)
            break;
        else cout << "\nPlease enter your id again: ";
    }
    int size_veh = contract[idx]->GetNumCar();
    for(int k = 0; k < size_veh;k++)
    {
        if(contract[idx]->GetIfBooked(k))
        {
            cout << "You have already booked a vehicle, please return next time.\n";
            already_book = true;
            break;
        }
    }
    if(!already_book)
    {
        cout << "Enter id of the vehicle you want to book: ";
        while(true)
        {
            size_num2 = contract[idx]->GetNumCar();
            cin >> vehicle_id;
            for(unsigned i = 0; i < size_num2; i++)
            {
                if(contract[idx]->GetVehicleID(i)== vehicle_id)
                {
                    idx_veh = i;
                    is_found3 = true;
                    break;
                }
            }
            if(is_found3)
                break;
            cout << "\nPlease enter vehicle id again: ";
        }
        cout << "Enter the date you want to book(dd/mm/yyyy): ";
        cin >> user_date;
        contract[idx]->SetBookDate(user_date);
        contract[idx]->SetIsBooked(idx_veh);
        //contract[idx]->SetNotAvailable(idx_veh);
    }
    cout << "\n----------------------------\n";
    if(already_book)
    {
        int userID
        cin >> userID;
        return userID;
    }else return -1;

}

int CarRentalManagement::Renting()
{
    cout << "\n*****Welcome to renting service*****\n";
    string tem_id, name, vehicle_id;
    int size_num = contract.size();
    int idx = -1, idx_veh = -1;
    bool is_found1 = false, is_found2 = false, is_found3 = false, already_rent = false;
    cout << "Please enter your name: ";
    while(true)
    {
        cin.clear();
        cin.ignore();
        getline(cin, name);
        for(unsigned i = 0; i < size_num; i++)
        {
            if(contract[i]->GetUserName() == name)
            {
                idx = i;
                is_found1 = true;
                break;
            }
        }
        if(is_found1)
        {
            break;
        }
        else
        {
            cout << "\nYour name does not exit in the database, please enter again: ";
        }
    }
    cout << "\nEnter the ID you have entered when creating contract: ";
    while(true)
    {
        cin >> tem_id;
        if(contract[idx]->GetUserId() == tem_id)
        {
            is_found2 = true;
            cout << "\n----Welcome back----\n";
        }
        if(is_found2)
            break;
        else cout << "\nPlease enter your id again: ";
    }
    int size_veh = contract[idx]->GetNumCar();
    for(int k = 0; k < size_veh;k++)
    {
        if(!contract[idx]->GetRentStatus(k))
        {
            cout << "You have already rented a vehicle, please return next time.\n";
            already_rent = true;
            break;
        }
    }
    if(!already_rent)
    {
        int size_num2 = contract[idx]->GetNumCar();
        for(unsigned i = 0; i < size_num2; i++)
        {
            if(contract[idx]->GetIfBooked(i))
            {
                idx_veh = i;
                is_found3 = true;
                break;
            }
        }
        if(is_found3)
        {
            bool is_agree = false, is_paid = false;
            string decision, paid;
            cout << "You have booked this vehicle on: ";
            contract[idx]->PrintBookDate();
            contract[idx]->PrintVehicle(idx_veh);
            cout << "Would you wish to take this vehicle?(Enter yes or no)";
            cin >> decision;
            if(decision == "yes")
            {
                int cost = contract[idx]->GetCost(idx_veh);
                cout << "The cost of this vehicle is: " << cost << endl;
                cout << "Would you wish to pay it?(Enter yes or no)";
                cin >> paid;
                if(paid == "yes")
                {
                    contract[idx]->SetNotAvailable(idx_veh);
                    cout << "You have successfully rented the vehicle, thank you for coming.\n";
                }
            }
         }
         else
         {
             cout << "You have not booked any vehicle, please book it first\n";
         }
    }
    cout << "\n----------------------------\n";
    if(already_rent)
    {
        int userID
        cin >> userID;
        return userID;
    }else return -1;
}

void CarRentalManagement::Returning()
{
    cout << "\n*****Welcome to returning service*****\n";
    string tem_id, name, vehicle_id, user_choice;
    int size_num = contract.size();
    int idx = -1, idx_veh = -1;
    bool is_found1 = false, is_found2 = false, is_found3 = false, is_return = false;
    cout << "Please enter your name: ";
    while(true)
    {
        cin.clear();
        cin.ignore();
        getline(cin, name);
        for(unsigned i = 0; i < size_num; i++)
        {
            if(contract[i]->GetUserName() == name)
            {
                idx = i;
                is_found1 = true;
                break;
            }
        }
        if(is_found1)
        {
            break;
        }
        else
        {
            cout << "\nYour name does not exit in the database, please enter again: ";
        }
    }
    cout << "\nEnter the ID you have entered when creating contract: ";
    while(true)
    {
        cin >> tem_id;
        if(contract[idx]->GetUserId() == tem_id)
        {
            is_found2 = true;
            cout << "\n----Welcome back----\n";
        }
        if(is_found2)
            break;
        else cout << "\nPlease enter your id again: ";
    }
    int size_veh = contract[idx]->GetNumCar();
    for(int k = 0; k < size_veh;k++)
    {
        if(!contract[idx]->GetRentStatus(k))
        {
            cout << "You have rented this vehicle:\n";
            idx_veh = k;
            contract[idx]->PrintVehicle(idx_veh);
            cout << "\nWould you want to return it?(enter yes or no):";
            cin >> user_choice;
            if(user_choice == "yes")
            {
                contract[idx]->SetAvailable(idx_veh);
                cout << "You have returned the vehicle, thank you for using our service.";
            }
            is_return = true;
            break;
        }
    }
    if(!is_return)
    {
        cout << "You have not rented any vehicle, please rent it first.";
    }
    cout << "\n----------------------------\n";
}

CarRentalManagement::~CarRentalManagement()
{
    arrVeh.clear();
}

void CarRentalManagement::addVehicle(Vehicle* &pVeh)
{
    arrVeh.push_back(pVeh);
}

void CarRentalManagement::printInfo()
{
    unsigned num_size = arrVeh.size();
    for(unsigned i = 0; i < num_size; i++)
    {
        arrVeh[i]->printDetail();
    }
}

void CarRentalManagement::AddContract()
{
    RentalContract *pTem = new RentalContract();
    contract.push_back(pTem);
}

void CarRentalManagement::AddVehicle(int idx)
{
    int count_num = 0;
    cout << "\nHow many vehicle do you wish to add? ";
    cin >> count_num;
    for(unsigned i = 0; i < count_num; i++)
    {
        Vehicle *pTem = contract[idx]->AddCar();
        arrVeh.push_back(pTem);
    }
    cin.clear();
}

void CarRentalManagement::PrintService()
{
    int num = contract.size(), num2;
    for(int i = 0; i < num; i++)
    {
        num2 = contract[i]->GetNumCar();
        for(int j = 0; j < num2; j++)
        {
            contract[i]->PrintHistoryService(j);
            cout << "\n====================\n";
        }
    }
}
