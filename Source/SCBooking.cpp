#include<iostream>
using namespace std;

#include"SCBooking.h"

SCBooking::SCBooking(const Station from, const Station to, 
        const Date date, const BookingClasses& type,const SeniorCitizens& category, 
        const Passenger* pass):ConcessionalBooking(from,to,date,type,category,pass){
            fare_=computeFare(category.getConcessionFactor());
}
