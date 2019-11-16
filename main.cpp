#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string _ID;
    string _brand;
    int _cost;
    bool _isAvailable;
public:
    Vehicle(){}
    Vehicle(string ID, string brand, int cost):_ID(ID),_brand(brand),_cost(cost){}
    void setID(string ID){_ID = ID;}
    string getID(){return _ID;}
    void setBrand(string brand){_brand = brand;}
    string getBrand(){return _brand;}
    void setCost(int cost){_cost = cost;}
    int getCost(){return _cost;}
    void setStatus(bool isAvailable){_isAvailable = isAvailable;}
    bool getStatus(){return _isAvailable;}
    virtual void printDetail() = 0;
    virtual void serviceEngine() = 0;
    virtual void serviceTransmission() = 0;
    virtual void serviceTires() = 0;
    ~Vehicle(){}
};

class Date
{
private:
    int _day;
    int _month;
    int _year;
public:
    Date(){}
    Date(string str)
    {
        size_t pos = str.find("/");
        size_t pos2 = str.find("/", pos + 1);
        _day = stoi(str.substr(0,2));
        _month = stoi(str.substr(pos + 1, 2));
        _year = stoi(str.substr(pos2 + 1));
    }
    bool operator>(Date const &obj)
    {
        if(_year > obj._year) return true;
        if(_year < obj._year) return false;
        if(_year == obj._year)
        {
            if(_month > obj._month) return true;
            if(_month < obj._month) return false;
            if(_month == obj._month)
            {
                if(_day > obj._day) return true;
                if(_day < obj._day) return false;
                if(_day == obj._day) return false;
            }
        }
        return false;
    }
    bool operator<(Date const &obj)
    {
        if(_year < obj._year) return true;
        if(_year > obj._year) return false;
        if(_year == obj._year)
        {
            if(_month < obj._month) return true;
            if(_month > obj._month) return false;
            if(_month == obj._month)
            {
                if(_day < obj._day) return true;
                if(_day > obj._day) return false;
                if(_day == obj._day) return false;
            }
        }
        return false;
    }
    void printDate()
    {
        cout << _day << "/" << _month << "/" << _year << endl;
    }
};

class MaintenanceJob //where when what mileage,
{
    // overload - for mileage difference: mJob1-mJob2
    // mJob1 < or > mJob2 compare the time
private:
    string _what;
    Date _when;//(dd/mm/yy)
    string _where;
    int _mileage;
public:
    MaintenanceJob(){}
    MaintenanceJob(string when, string what, string where, int mileage): _when(when), _what(what), _where(where), _mileage(mileage){}
    int operator-(MaintenanceJob const &obj)
    {
        int ans;
        ans = _mileage - obj._mileage;
        return ans;
    }
    bool operator>(MaintenanceJob const &obj)
    {
        return this->_when > obj._when;
    }
    bool operator<(MaintenanceJob const &obj)
    {
        return this->_when < obj._when;
    }
    void printDetail()
    {
        cout << "What: " << _what << endl;
        cout << "Where: " << _what << endl;
        cout << "When: ";
        _when.printDate();
        cout <<"\n";
        cout << "Mileage: " << _mileage << endl;
    }
};

class ServiceHistory
{
private:
    vector<MaintenanceJob*> rec;
public:
    string _oilMessage;
    int _fluidLevel;
    string _fluidMessage;
    string _typeTyre;
    string _tyreMessage;
    ServiceHistory(string oilMess):_oilMessage(oilMess){}
    ServiceHistory(int fluidLevel, string fluidMess): _fluidLevel(fluidLevel), _fluidMessage(fluidMess){}
    ServiceHistory(string typeTyre, string tyreMess): _typeTyre(typeTyre), _tyreMessage(tyreMess){}
};

class Sedan: public Vehicle
{
    int trunk_cap;
    vector<ServiceHistory*> record;
public:
    Sedan(){};
    Sedan(string ID, string brand, int cost, int trunkCap):Vehicle(ID, brand, cost), trunk_cap(trunkCap){}
    void printDetail()
    {
        cout << "ID: " << _ID << endl;
        cout << "Brand: " <<_brand << endl;
        cout << "Cost: " << _cost << endl;
        string status = (_isAvailable) ? "yes" :"no";
        cout << "Status: " << status << endl;
        cout << "Trunk Cap: " << trunk_cap << endl;
    }
    void serviceEngine()
    {
        string mess;
        cout << "Welcome to Engine Service of Sedan." << endl;
        cout << "Enter your opinion: ";
        getline(cin, mess);
        ServiceHistory* pRec = new ServiceHistory(mess);
        record.push_back(pRec);
    }
    void serviceTransmission()
    {
        int info;
        string mess;
        cout << "Welcome to Transmission Service of Sedan." << endl;
        cout << "Enter the fluid level of transmission: ";
        cin >> info;
        cout << "Enter your request about Transmission: ";
        getline(cin, mess);
        ServiceHistory* pRec = new ServiceHistory(info, mess);
        record.push_back(pRec);
    }
    void serviceTires()
    {
        string type;
        string mess;
        cout << "Welcome to Tire Service of Sedan." << endl;
        cout << "Enter your type of tire: ";
        cin >> type;
        cout << "Enter your opinion about tire: ";
        cin.ignore();
        getline(cin, mess);
        ServiceHistory* pRec = new ServiceHistory(type, mess);
        record.push_back(pRec);
    }
    ~Sedan(){}
};

struct Dimension
{
    int _width;
    int _length;
    int _height;
};

class PickUp: public Vehicle
{
    Dimension dim;
    vector<ServiceHistory*> record;
public:
    PickUp(){}
    PickUp(string ID, string brand, int cost, int width, int length, int height):Vehicle(ID, brand, cost)
    {
        dim._height = width;
        dim._length = length;
        dim._height = height;
    }
    void printDetail()
    {
        cout << "ID: " << _ID << endl;
        cout << "Brand: " <<_brand << endl;
        cout << "Cost: " << _cost << endl;
        string status = (_isAvailable) ? "yes" :"no";
        cout << "Status: " << status << endl;
        cout << "Dimension: Width" << dim._width << ", Length: " << dim._length << ", Height: " << dim._height << endl;
    }
    void serviceEngine(){
        string mess;
        cout << "Welcome to Engine Service of Pickup." << endl;
        cout << "Enter your opinion: ";
        getline(cin, mess);
        ServiceHistory* pRec = new ServiceHistory(mess);
        record.push_back(pRec);
    }
    void serviceTransmission()
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
    void serviceTires()
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
    ~PickUp(){}
};

class SUV: public Vehicle
{
    bool fourSeat;
    vector<ServiceHistory*> record;
public:
    SUV(){}
    SUV(string ID, string brand, int cost,bool isFour):Vehicle(ID, brand, cost), fourSeat(isFour){}
    void printDetail()
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
    void serviceEngine()
    {
        string mess;
        cout << "Welcome to Engine Service of SUV." << endl;
        cout << "Enter your opinion: ";
        getline(cin, mess);
        ServiceHistory* pRec = new ServiceHistory(mess);
        record.push_back(pRec);
    }
    void serviceTransmission()
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
    void serviceTires()
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
    ~SUV(){}
};

class BookAndRent
{
private:
    string bookDate;
    string bookVehicle;
    bool isDebt;
public:
    void Booking()
    {
        cout << "Welcome, please enter your taking date: ";
        cin >> bookDate;
        cout << "Enter the vehicle you want: ";
        cin >> bookVehicle;
        isDebt = true;
    }
    void Taking()
    {
        string temDate,temVehicle;
        while(true)
        {
            cout << "Enter the date you booked: ";
            cin >> temDate;
            cout << "Enter the vehicle you booked: ";
            cin >> temVehicle;
            if(temVehicle == bookVehicle && temDate == bookDate)
                break;
        }

    }
    void Returning()
    {

    }
};

class CarRental:public BookAndRent
{
private:
    static int numCar;
    string _name;
    int _age;
    bool _isQualified;
    int _phoneNum;
    int _day;
    vector <Vehicle*> Contract;
    int preMile, curMile;
public:
    CarRental(){}
    CarRental(Vehicle* &veh)
    {
        Contract.push_back(veh);
    }
    void setupContract()
    {
        string user;
        cout << "Enter your name: ";
        cin >> _name;
        cout << "Your age: ";
        cin >> _age;
        cout << "Are you qualified according to law(above 18, driving license acquired...): ";
        cin >> user;
        if(user == "yes")
        {
            _isQualified = true;
        }
        else if(user == "no")
        {
            _isQualified = false;
        }
        cout << "Your phone number: ";
        cin >> _phoneNum;

        addCar();
    }

    int getnumCar()
    {
        return numCar;
    }
    void addCar()
    {
        int cost,userChoice;
        string ID, brand;
        cout << "Enter your ID: ";
        cin >> ID;
        cout << "Enter your brand: ";
        cin >> brand;
        cout << "Enter initial cost: ";
        cin >> cost;
        while(true)
        {
            cout << "Enter your type of vehicle(1 for Sedan, 2 for pickup, 3 for SUV): ";
            cin >> userChoice;
            if(userChoice >= 1 && userChoice <= 3)
                break;
        }
        if(userChoice == 1)
        {
            int trunkCap;
            cout << "Enter your trunk cap: ";
            cin >> trunkCap;
            //Vehicle* pVeh = new Sedan(ID, brand, cost,trunkCap);
            //Contract.push_back(pVeh);
            addVehicle(ID, brand, cost,trunkCap);
        }
        else if(userChoice == 2)
        {
            int width, length, height;
            cout << "Enter Pickup width: ";
            cin >> width;
            cout << "Enter Pickup length: ";
            cin >> length;
            cout << "Enter Pickup height: ";
            cin >> height;
            //Vehicle* pVeh = new PickUp(ID, brand, cost, width, length,height);
            //Contract.push_back(pVeh);
            addVehicle(ID, brand, cost, width, length,height);
        }
        else if(userChoice == 3)
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
            //Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
            //Contract.push_back(pVeh);
            addVehicle(ID, brand, cost, isFour);
        }
        //numCar++;
    }
    void addVehicle(string ID, string brand, int cost,int trunkCap)
    {
        //Vehicle* pTem = new Sedan();
        Vehicle* pVeh = new Sedan(ID, brand, cost,trunkCap);
        Contract.push_back(pVeh);
        numCar++;
    }
    void addVehicle(string ID, string brand, int cost, int width, int length,int height)
    {
        //Vehicle* pTem = new PickUp();
        Vehicle* pVeh = new PickUp(ID, brand, cost, width, length,height);
        Contract.push_back(pVeh);
        numCar++;
    }
    void addVehicle(string ID, string brand, int cost, bool isFour)
    {
        //Vehicle* pTem = new SUV();
        Vehicle* pVeh = new SUV(ID, brand, cost, isFour);
        Contract.push_back(pVeh);
        numCar++;
    }
    void serviceFleet()
    {
        size_t num = Contract.size();
        int choice;
        for(int i = 0; i < num; i++)
        {
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
                    Contract[i]->serviceEngine();
                }
                else if(choice == 2)
                {
                    Contract[i]->serviceTransmission();
                }
                else if(choice == 3)
                {
                    Contract[i]->serviceTires();
                }
                else cout << "Invalid choice.";
            }
            else cout << "Your vehicle is still functioning properly, please return next time." << endl;
        }
    }
    ~CarRental()
    {
        Contract.clear();
    }
};


int CarRental::numCar = 0;

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
