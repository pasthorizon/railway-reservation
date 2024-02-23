
#ifndef __SCBOOKING_H
#define __SCBOOKING_H

#include"ConcessionalBooking.h"
#include"SeniorCitizens.h"

class BookingClasses;


//the constructor takes in SeniorCitizen instead of 
//BookingCategory to avoid the loss of concession information
class SCBooking:public ConcessionalBooking{
    public:
    SCBooking(const Station, const Station, 
        const Date, const BookingClasses&,const SeniorCitizens&, 
        const Passenger*);
};

#endif