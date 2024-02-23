#include<iostream>
using namespace std;

#include"GeneralBooking.h"
#include"General.h"
#include"Passenger.h"
#include"BookingCategory.h"
#include"Booking.h"
#include<cmath>


GeneralBooking::GeneralBooking(const Station from, const Station to, 
        const Date date, const BookingClasses& bclass,const BookingCategory& bcat, 
        const Passenger* pass):Booking(from,to,date,bclass,bcat,pass){
            fare_=computeFare();
        }

int GeneralBooking::computeFare(){
    double ans=Booking::sBaseFarePerKM*Railways::TheRailways().getDistance(fromStation_.GetName(),toStation_.GetName());
    // cout<<"Distance="<<Railways::TheRailways().getDistance(fromStation_.GetName(),toStation_.GetName())<<endl;
    // cout<<type_.getLoadFactor()<<endl;
    ans=ans*type_.getLoadFactor();
    ans+=type_.getReservationCharge();
    if(abs(ceil(ans)-ans)<abs((int)ans-ans))
    return ans+1;
    else return ans;
}
