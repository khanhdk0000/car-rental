#include "Sedan.h"

using namespace std;

void Sedan::printDetail()
{
    cout << "ID: " << _ID << endl;
    cout << "Brand: " <<_brand << endl;
    cout << "Cost: " << _cost << endl;
    string status = (_isAvailable) ? "yes" :"no";
    cout << "Status: " << status << endl;
    cout << "Trunk Cap: " << trunk_cap << endl;
}

void Sedan::serviceEngine()
{
    string mess;
    cout << "Welcome to Engine Service of Sedan." << endl;
    cout << "Enter your request opinion: ";
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, mess);
    if(is_first_)
    {
        ServiceHistory tem(mess, 1);
        record = tem;
        is_first_ = false;
    }
    else
    {
        record.AddMainten(1, mess);
    }
}

void Sedan::serviceTransmission()
{
    int info;
    string mess;
    cout << "Welcome to Transmission Service of Sedan." << endl;
    cout << "Enter the fluid level of transmission: ";
    cin >> info;
    fluid_level_ = info;
    cout << "Enter your request about Transmission: ";
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, mess);
    if(is_first_)
    {
        ServiceHistory tem(mess, 2);
        record = tem;
        is_first_ = false;
    }
    else
    {
        record.AddMainten(2, mess);
    }
}

void Sedan::serviceTires()
{
    string type;
    string mess;
    cout << "Welcome to Tire Service of Sedan." << endl;
    cout << "Enter your type of tire: ";
    cin >> type;
    tyre_type_ = type;
    cout << "Enter your opinion about tire: ";
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, mess);
    if(is_first_)
    {
        ServiceHistory tem(mess, 3);
        record = tem;
        is_first_ = false;
    }
    else
    {
        record.AddMainten(3, mess);
    }
}
