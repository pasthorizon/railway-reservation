#include<iostream>
using namespace std;

#include"SeniorCitizens.h"
#include"SCBooking.h"

template<>
const bool SeniorCitizens::Male::checkEligibility(const Passenger& pass)const{
    if(pass.isMale())
    {
        if(pass.getDOB().getAge()<=60) return false;
        else return true;
    }
    return false;
}

template<>
const bool SeniorCitizens::Female::checkEligibility(const Passenger& pass)const{
    if(!pass.isMale())
    {
        if(pass.getDOB().getAge()<=58) return false;
        else return true;
    }
    return false;
}

//calling constructor for the booking type 
//corresponding to the SeniorCitizen class in the booking 
//hierarchy. Passing the SeniorCitizen type itself to avoid 
//slicing of information(concession info will be lost in BookingCategory)
template<>
const Booking* SeniorCitizens::Male::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type, 
            const BookingCategory& category)const {

    return new SCBooking(from,to,date,type,SeniorCitizens::Male::Type(),pass);
}

template<>
const Booking* SeniorCitizens::Female::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type, 
            const BookingCategory& category)const {

    return new SCBooking(from,to,date,type,SeniorCitizens::Female::Type(),pass);
}


template<> const double SeniorCitizens::Female::concessionFactor=0.5;
template<> const double SeniorCitizens::Male::concessionFactor=0.4;
