// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __LADIESBOOKING_H
#define __LADIESBOOKING_H

#include"ConcessionalBooking.h"
#include"Ladies.h"

//the constructor takes parameter as Ladies to 
//avoud the slicing of concession related info
class LadiesBooking:public ConcessionalBooking{
    protected:
    LadiesBooking(const Station, const Station, 
        const Date, const BookingClasses&,const Ladies&, 
        const Passenger*);
    friend class Ladies;
    
};

#endif