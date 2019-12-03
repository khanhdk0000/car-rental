#include "SUV.h"

using namespace std;

void SUV::printDetail()
{
    cout << "ID: " << _ID << endl;
    cout << "Brand: " <<_brand << endl;
    cout << "Cost: " << _cost << endl;
    string status = (_isAvailable) ? "yes" :"no";
    cout << "Status: " << status << endl;
    cout << "Four Seat";
    if(fourSeat)
        cout <<": Yes" << endl;
    else cout <<": No" << endl;
}

void SUV::serviceEngine()
{
    string mess;
    cout << "Welcome to Engine Service of SUV." << endl;
    cout << "Enter your opinion: ";
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

void SUV::serviceTransmission()
{
    int info;
    string mess;
    cout << "Welcome to Transmission Service of SUV." << endl;
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

void SUV::serviceTires()
{
    string type;
    string mess;
    cout << "Welcome to Tire Service of SUV." << endl;
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
