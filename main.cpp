#include "Vehicle.h"
#include "Sedan.h"
#include "Pickup.h"
#include "SUV.h"
#include "MaintenanceJob.h"
#include "ServiceHistory.h"
#include "BookAndRent.h"
#include "CarRentalManagement.h"
#include "RentalContract.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
//    CarRental cus;
//    cus.setupContract();
//    cus.Booking();
//    cus.Taking();
//    MaintenanceJob obj("1/1/2000", "nothing", "earth", 100);
//    MaintenanceJob obj1("1/2/2001", "nothing", "earth", 150);
//    cout << (obj < obj1) << endl;
//    cout << obj1 - obj;
//    CarRentalManagement obj;
//    obj.addCar();
////    obj.addCar();
////    obj.addCar();
//    obj.serviceFleet();
//    RentalContract *cus1 = new RentalContract();
//    CarRentalManagement mag;
//    for(unsigned i = 0; i < 3; i++)
//    {
//        Vehicle* pTem = cus1->AddCar();
//        mag.addVehicle(pTem);
//    }
//    cout << "Contract: " << cus1->GetNumCar() << endl;
//    cout << "Manage: " << mag.getnumCar() << endl;
//    cus1->printInfo();
//    mag.printInfo();

    int choice;
    while(true)
    {
        system("cls");
        cout << "**********Car Rental**********" << endl;
        cout << "1. Book and Rent" << endl;
        cout << "2. Write Json" << endl;
        cout << "3. Service Fleet" << endl;
        cout << "4. Overload operator" << endl;
        cin >> choice;
        if(choice == 1)
        {
            CarRentalManagement mag;
            int num;
            cout << "How many contract you want: ";
            cin >> num;
            for(int i = 0; i < num; i++)
            {
                mag.AddContract();
                mag.AddVehicle(i);
                mag.Booking();
                mag.Renting();
                mag.Returning();
            }
         }
         else if(choice == 3 || choice == 2)
         {
                CarRentalManagement mag;
                mag.AddContract();
                mag.AddVehicle(0);
                mag.ServiceFleet();
                mag.PrintService();
         }
         else if(choice == 4)
         {
            MaintenanceJob obj("1/1/2000", "nothing", "earth", 100);
            MaintenanceJob obj1("1/2/2001", "nothing", "earth", 150);
            cout << (obj < obj1) << endl;
            cout << obj1 - obj;
         }
         system("pause");
    }
//    CarRentalManagement mag;
//    for(int i = 0; i < 3; i++)
//    {
//        mag.AddContract();
//        mag.AddVehicle(i);
//    }
//    mag.printInfo();
//
//    CarRentalManagement mag;
//    mag.AddContract();
//    mag.AddVehicle(0);
//    mag.Booking();
//    mag.Renting();
//    mag.Returning();
//
//    CarRentalManagement mag;
//    mag.AddContract();
//    mag.AddVehicle(0);
//    mag.serviceFleet();
//    mag.PrintService();
//    return 0;
}
