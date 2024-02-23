// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __GENERALBOOKING_H
#define __GENERALBOOKING_H

#include<iostream>
using namespace std;
#include"Booking.h"

class General;

class GeneralBooking:public Booking{
    private:
    GeneralBooking(const Station, const Station, const Date, const BookingClasses&,const BookingCategory&, const Passenger*);
    int computeFare();

    friend class General;
};

#endif
