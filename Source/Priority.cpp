#include<iostream>
using namespace std;

#include"Priority.h"
#include"PriorityBooking.h"

const Booking* Tatkal::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type, const BookingCategory& category)const {
        return new PriorityBooking(from,to, date,type,Tatkal::Type(),pass);
}

const bool Tatkal::checkEligibility(const Passenger& pass)const{
    return true;
}

const double Tatkal::getPremiumCharge(const BookingClasses& type)const{
    return type.getPremiumCharge();
}
const double Tatkal::getMinTatkalCharge(const BookingClasses& type)const{
    return type.getMinTatkalCharge();
}
const double Tatkal::getMaxTatkalCharge(const BookingClasses& type)const{
    return type.getMaxTatkalCharge();
}
const double Tatkal::getMinDistance(const BookingClasses& type)const{
    return type.getMinDistance();
}



const Booking* PremiumTatkal::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type, const BookingCategory& category)const {
        return new PriorityBooking(from,to, date,type,PremiumTatkal::Type(),pass);
}

const bool PremiumTatkal::checkEligibility(const Passenger& pass)const{
    return true;
}

const double PremiumTatkal::getPremiumCharge(const BookingClasses& type )const
{
    return 2*type.getPremiumCharge();
}
const double PremiumTatkal::getMinTatkalCharge(const BookingClasses& type)const
{
    return 2*type.getMinTatkalCharge();   
}
const double PremiumTatkal::getMaxTatkalCharge(const BookingClasses& type)const{
    return 2*type.getMaxTatkalCharge();
}
const double PremiumTatkal::getMinDistance(const BookingClasses& type)const{
    return type.getMinDistance();
}
