// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __PRIORITYBOOKING_H
#define __PRIORITYBOOKING_H

#include<iostream>
using namespace std;

#include"Booking.h"
class BookingClasses;
#include"Priority.h"

//the constructor takes in priority as parameter and not 
//bookingcategory to avoid the slicing of information about the
//premium charges levied
class PriorityBooking:public Booking{
    //constructor is protexted and can be called only 
    //the Tatkal and Premium Tatkal in the Priority hierarchy
    protected:
    PriorityBooking(const Station, const Station, 
        const Date, const BookingClasses&,const Priority&, 
        const Passenger*);

    //since a lot of info about the tatkal charges is stored
    //in the Priority class, we pass the class type itself 
    //as the parameter to compute fare
    const int computeFare(const Priority& type)const;
    friend class Tatkal;
    friend class PremiumTatkal;
};

#endif