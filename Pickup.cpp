#include "Pickup.h"

using namespace std;

void PickUp::printDetail()
{
    cout << "ID: " << _ID << endl;
    cout << "Brand: " <<_brand << endl;
    cout << "Cost: " << _cost << endl;
    string status = (_isAvailable) ? "yes" :"no";
    cout << "Status: " << status << endl;
    cout << "Dimension: Width" << dim._width << ", Length: " << dim._length << ", Height: " << dim._height << endl;
}

void PickUp::serviceEngine()
{
    string mess;
    cout << "Welcome to Engine Service of Pickup." << endl;
    cout << "Enter your opinion: ";
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(mess);
    record.push_back(pRec);
}

void PickUp::serviceTransmission()
{
    int info;
    string mess;
    cout << "Welcome to Transmission Service of Pickup." << endl;
    cout << "Enter the fluid level of transmission: ";
    cin >> info;
    cout << "Enter your request about Transmission: ";
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(info, mess);
    record.push_back(pRec);
}

void PickUp::serviceTires()
{
    string type;
    string mess;
    cout << "Welcome to Tire Service of Pickup." << endl;
    cout << "Enter your type of tire: ";
    cin >> type;
    cout << "Enter your opinion about tire: ";
    cin.ignore();
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(type, mess);
    record.push_back(pRec);
}
