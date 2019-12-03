#include "ServiceHistory.h"

using namespace std;

void ServiceHistory::AddMainten(int kind, string what)
{
    string location, day;
    cout << "\nWhere is your service location?: ";
    cin >> location;
    cout << "Enter the date of service: ";
    cin >> day;
    if(kind == 1)
    {
        time_oil++;
        MaintenanceJob tem;
        tem.SetLocation(location);
        tem.SetDate(day);
        tem.SetValue(1, what, time_oil);
        rec.push_back(tem);
    }
    else if(kind == 2)
    {
        time_fluid++;
        MaintenanceJob tem;
        tem.SetLocation(location);
        tem.SetDate(day);
        tem.SetValue(2,what, time_fluid);
        rec.push_back(tem);
    }
    else if(kind == 3)
    {
        time_tyre++;
        MaintenanceJob tem;
        tem.SetLocation(location);
        tem.SetDate(day);
        tem.SetValue(3,what, time_tyre);
        rec.push_back(tem);
    }
}

void ServiceHistory::PrintService(string _id, string _brand)
{
    int size_num = rec.size();
    for(int i = 0; i < size_num; i++)
    {
        rec[i].PrintHistory(_id, _brand);
    }
}
