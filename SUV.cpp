#include "SUV.h"

void SUV::printDetail()
{
    cout << "ID: " << _ID << endl;
    cout << "Brand: " <<_brand << endl;
    cout << "Cost: " << _cost << endl;
    string status = (_isAvailable) ? "yes" :"no";
    cout << "Status: " << status << endl;
    cout << "Four Seat";
    if(fourSeat)
        cout <<": Yes";
    else cout <<": No";
}

void SUV::serviceEngine()
{
    string mess;
    cout << "Welcome to Engine Service of SUV." << endl;
    cout << "Enter your opinion: ";
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(mess);
    record.push_back(pRec);
}

void SUV::serviceTransmission()
{
    int info;
    string mess;
    cout << "Welcome to Transmission Service of SUV." << endl;
    cout << "Enter the fluid level of transmission: ";
    cin >> info;
    cout << "Enter your request about Transmission: ";
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(info, mess);
    record.push_back(pRec);
}

void SUV::serviceTires()
{
    string type;
    string mess;
    cout << "Welcome to Tire Service of SUV." << endl;
    cout << "Enter your type of tire: ";
    cin >> type;
    cout << "Enter your opinion about tire: ";
    cin.ignore();
    getline(cin, mess);
    ServiceHistory* pRec = new ServiceHistory(type, mess);
    record.push_back(pRec);
}
