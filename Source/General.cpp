#include<iostream>
using namespace std;

#include"General.h"
#include"GeneralBooking.h"

const General& General::Type()
{
        static const General theObj;
        return theObj;
}

const bool General::checkEligibility(const Passenger& pass)const{
    return true;
}

const Booking* General::createNewBooking(const Station& from_, const Station& to_,
    const Passenger* pass_,const Date& date_, const BookingClasses& bookingclass_, 
    const BookingCategory& bookingcategory_)const{
        
    Booking *p = new GeneralBooking(from_,to_,date_,bookingclass_,bookingcategory_,pass_);
    return p;
}