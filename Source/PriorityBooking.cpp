#include<iostream>
using namespace std;
#include<cmath>
#include"PriorityBooking.h"

int maxm(int a,int b){
        if(a>b) return a;
        else return b;
}

int minm(int a,int b){
        if(a<b) return a;
        else return b;
}


PriorityBooking::PriorityBooking(const Station from, const Station to, 
        const Date date, const BookingClasses& bclass,const Priority& bcat, 
        const Passenger* pass):Booking(from,to,date,bclass,bcat,pass){

        fare_=computeFare(bcat);
}

const int PriorityBooking::computeFare(const Priority& type) const{
    int  distance=Railways::TheRailways().getDistance(fromStation_.GetName(),toStation_.GetName());
    double ans=Booking::sBaseFarePerKM*distance;
    ans=ans*type_.getLoadFactor();
    if(type_.getMinDistance()<distance)
    {
        int tcharg=maxm(type.getMinTatkalCharge(type_),ans*type.getPremiumCharge(type_));
        tcharg=minm(tcharg,type.getMaxTatkalCharge(type_));
        ans+=tcharg;
    }

    ans+=type_.getReservationCharge();

    if(abs(ceil(ans)-ans)<abs((int)ans-ans))
    return ans+1;
    else return ans;
}
