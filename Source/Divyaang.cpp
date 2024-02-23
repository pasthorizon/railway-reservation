#include<iostream>
using namespace std;

#include"Divyaang.h"
#include"DivyaangBooking.h"

template<>
const Booking* Divyaang::None::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type,
             const BookingCategory& category)const{
                return new DivyaangBooking(from,to,date,type,Divyaang::None::Type(),pass);
            }

template<>
const Booking* Divyaang::TB::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type,
             const BookingCategory& category)const{
                return new DivyaangBooking(from,to,date,type,Divyaang::TB::Type(),pass);
            }

template<>
const Booking* Divyaang::Blind::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type,
             const BookingCategory& category)const{
                return new DivyaangBooking(from,to,date,type,Divyaang::Blind::Type(),pass);
            }

template<>
const Booking* Divyaang::Cancer::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type,
             const BookingCategory& category)const{
                return new DivyaangBooking(from,to,date,type,Divyaang::Cancer::Type(),pass);
            }

template<>
const Booking* Divyaang::OH::createNewBooking(const Station& from, const Station& to,
            const Passenger* pass,const Date& date, const BookingClasses& type,
             const BookingCategory& category)const{
                return new DivyaangBooking(from,to,date,type,Divyaang::OH::Type(),pass);
            }


const bool Divyaang::checkEligibility(const Passenger& pass)const{
    if(pass.getDisabiltyID()!=getName())
    return false;
    return true;
}

template<>
const double Divyaang::None::getConcessionFactor(const BookingClasses& type)const{
    return 0;
}

template<>
const double Divyaang::TB::getConcessionFactor(const BookingClasses& type)const{
    return type.getConcessionFactor(Divyaang::TB::Type());
}

template<>
const double Divyaang::OH::getConcessionFactor(const BookingClasses& type)const{
    return type.getConcessionFactor(Divyaang::OH::Type());
}


template<>
const double Divyaang::Blind::getConcessionFactor(const BookingClasses& type)const{
    return type.getConcessionFactor(Divyaang::Blind::Type());
}


template<>
const double Divyaang::Cancer::getConcessionFactor(const BookingClasses& type)const{
    return type.getConcessionFactor(Divyaang::Cancer::Type());
}
