#include "Vehicle.h"
#include "Sedan.h"
#include "Pickup.h"
#include "SUV.h"
#include "MaintenanceJob.h"
#include "ServiceHistory.h"
#include "BookAndRent.h"
#include "CarRentalManagement.h"
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
    MaintenanceJob obj("1/1/2000", "nothing", "earth", 100);
    MaintenanceJob obj1("1/2/2001", "nothing", "earth", 150);
    cout << (obj < obj1);
    cout << obj1 - obj;

    return 0;
}
