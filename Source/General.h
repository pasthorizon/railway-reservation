// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __GENERAL_H
#define __GENERAL_H

#include<iostream>
using namespace std;
#include"BookingCategory.h"
class GeneralBooking;

class General:public BookingCategory{
    General():BookingCategory("General Category"){}
    public:
    static const General& Type();
    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const ;
    const bool checkEligibility(const Passenger&) const;
    virtual ~General(){}
};

#endif