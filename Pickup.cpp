#include "Pickup.h"

using namespace std;

void PickUp::printDetail()
{
    cout << "ID: " << _ID << endl;
    cout << "Brand: " <<_brand << endl;
    cout << "Cost: " << _cost << endl;
    string status = (_isAvailable) ? "yes" :"no";
    cout << "Status: " << status << endl;
    cout << "Dimension: Width: " << dim._width << ", Length: " << dim._length << ", Height: " << dim._height << endl;
}

void PickUp::serviceEngine()
{
    string mess;
    cout << "Welcome to Engine Service of Pickup." << endl;
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

void PickUp::serviceTransmission()
{
    int info;
    string mess;
    cout << "Welcome to Transmission Service of Pickup." << endl;
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

void PickUp::serviceTires()
{
    string type;
    string mess;
    cout << "Welcome to Tire Service of Pickup." << endl;
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
