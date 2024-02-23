// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __CONCESSIONALBOOKING_H
#define __CONCESSIONALBOOKING_H

#include"Booking.h"
#include<cmath>
class Concession;

class ConcessionalBooking:public Booking{
    protected:
    ConcessionalBooking(const Station from, const Station to, const Date date,
         const BookingClasses& type,const BookingCategory& category, 
         const Passenger* pass):Booking(from,to,date,type,category,pass){}
    
    //since the concessionFactor for each of the leaf classes
    //depends on various factors differently, we compute it in
    //the leaf classes itself and pass it as a parameter to compute
    //the fare
    int computeFare(const double concessionFactor){
        double ans=Booking::sBaseFarePerKM*Railways::TheRailways().getDistance(fromStation_.GetName(),toStation_.GetName());
        ans=ans*type_.getLoadFactor();
        ans=ans*(1-concessionFactor);
        ans+=type_.getReservationCharge();
        if(abs(ceil(ans)-ans)<abs((int)ans-ans))
        return ans+1;
        else return ans;      
    }
};

#endif