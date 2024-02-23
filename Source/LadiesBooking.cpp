#include<iostream>
using namespace std;

#include"LadiesBooking.h"

LadiesBooking::LadiesBooking(const Station from, const Station to, 
        const Date date, const BookingClasses& type,const Ladies& category, 
        const Passenger* pass):ConcessionalBooking(from,to,date,type,category,pass){
            fare_=computeFare(category.getConcessionFactor());
}
