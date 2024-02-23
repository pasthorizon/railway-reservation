// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __BOOKINGCATEGORY_H
#define __BOOKINGCATEGORY_H

#include<iostream>
using namespace std;
#include"Railways.h"
#include"Date.h"

//forward declaring the classes which are to be used
class BookingClasses;
class Booking;
class Passenger;

class BookingCategory{
    const string name_;

    //blocking the copy constructor and copy assignment constructor 
    BookingCategory(const BookingCategory&);
    BookingCategory& operator=(const BookingCategory&);

    protected:
    BookingCategory(const string name): name_(name){}
    public:
    const string getName()const{
        return name_;
    };

    //virtual function createNewBooking, because each leaf class will call the 
    //constructor of the Booking leaf class corresponding to it.
    virtual const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const=0;
    //each category will have its own criteria for eligibility
    virtual const bool checkEligibility(const Passenger&)const=0; 
    
};

#endif