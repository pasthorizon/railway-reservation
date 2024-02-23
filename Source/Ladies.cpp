#include<iostream>
using namespace std;

#include"Ladies.h"
#include"LadiesBooking.h"

const Booking* Ladies::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type, const BookingCategory& category)const {
        return new LadiesBooking(from,to, date,type,Ladies::Type(),pass);
}

const double Ladies::getConcessionFactor()const{
    return 0;
}

const bool Ladies::checkEligibility(const Passenger& pass)const{
    if(pass.isMale()) return false;
    return true;
}

