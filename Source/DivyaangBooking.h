// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __DIVYAANGBOOKING_H
#define __DIVYAANGBOOKING_H

#include<iostream>
using namespace std;

#include"ConcessionalBooking.h"
#include"Divyaang.h"

class BookingClasses;


class DivyaangBooking:public ConcessionalBooking{
    public:
    DivyaangBooking(const Station, const Station, 
        const Date, const BookingClasses&,const Divyaang&, 
        const Passenger*);
};

#endif