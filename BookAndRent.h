#ifndef BOOKANDRENT_H_INCLUDED
#define BOOKANDRENT_H_INCLUDED

#include "date.h"
#include <iostream>

using namespace std;

class BookAndRent
{
public:
    virtual int Booking() = 0;
    virtual int Renting() = 0;
    virtual void Returning() = 0;
};


#endif // BOOKANDRENT_H_INCLUDED
