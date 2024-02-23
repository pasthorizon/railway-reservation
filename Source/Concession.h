// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __CONCESSION_H
#define __CONCESSION_H

#include"BookingCategory.h"

class BookingClasses;
class Booking;
class ConcessionalBooking;

//abstraction for completeness of the hierarchy
class Concession: public BookingCategory{
    protected:
    Concession(const string name):BookingCategory(name){}
};

#endif