#include<iostream>
using namespace std;

#include"DivyaangBooking.h"

DivyaangBooking::DivyaangBooking(const Station from, const Station to, 
        const Date date, const BookingClasses& type,const Divyaang& category, 
        const Passenger* pass):ConcessionalBooking(from,to,date,type,category,pass){
            fare_=computeFare(category.getConcessionFactor(type_));
}
