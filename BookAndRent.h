#ifndef BOOKANDRENT_H_INCLUDED
#define BOOKANDRENT_H_INCLUDED

#include <iostream>

using namespace std;

class BookAndRent
{
protected:
    string bookDate;
    string bookVehicle;
    bool isDebt;
public:
    virtual void Booking() = 0;
    virtual void Taking() = 0;
    virtual void Returning() = 0;
};


#endif // BOOKANDRENT_H_INCLUDED
