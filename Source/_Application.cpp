#include<iostream>
using namespace std;


#include"Gender.h"
#include"BookingClasses.h"
#include"Exceptions.h"
#include"Railways.h"
#include"Priority.h"
#include"Divyaang.h"
#include"General.h"
#include"SeniorCitizens.h"
#include"Ladies.h"
#include"Passenger.h"
#include"Booking.h"
#include"Statics.h"

int main(){
    	const Passenger *x1=Passenger::CreatePassenger("29/02/2000",Gender::Male::Type(),
                                "123456789012","1234567890","Bishal","Bag","","Cancer Type");
        cout<<*x1<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Kolkata"),*Station::CreateStation("Delhi"),"31/12/2021",
                                BookingClasses::ACFirstClass::Type(),Divyaang::Cancer::Type(),x1);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }

	const Passenger *x2=Passenger::CreatePassenger("28/02/2000",Gender::Female::Type(),
                                "123456789024","1234567890","Somlagna","","Bag","");
        cout<<*x2<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Kolkata"),*Station::CreateStation("Delhi"),"31/10/2021",
                                BookingClasses::ExecutiveChairCar::Type(),Ladies::Type(),x2);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x3=Passenger::CreatePassenger("01/05/2001",Gender::Male::Type(),
                                "123456789234","1234567890","Bishal","Bag","","Cancer Type");
        cout<<*x3<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Chennai"),"12/12/2021",
                                BookingClasses::ACFirstClass::Type(),Divyaang::Cancer::Type(),x3);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x4=Passenger::CreatePassenger("02/05/1950",Gender::Male::Type(),
                                "123456789342","1234567890","Sukesh","","","");
        cout<<*x4<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Kolkata"),"12/09/2021",
                                BookingClasses::FirstClass::Type(),Tatkal::Type(),x4);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x5=Passenger::CreatePassenger("01/05/2001",Gender::Male::Type(),
                                "123456789340","1234567890","Ramen","Bag","","Blind Type");
        cout<<*x5<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Kolkata"),"12/09/2021",
                                BookingClasses::FirstClass::Type(),Divyaang::Cancer::Type(),x5);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x6=Passenger::CreatePassenger("01/05/2010",Gender::Male::Type(),
                                "123456789340","1234567890","","Kumar","Saha","");
        cout<<*x6<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Mumbai"),"12/09/2021",
                                BookingClasses::FirstClass::Type(),General::Type(),x6);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x7=Passenger::CreatePassenger("01/05/2010",Gender::Male::Type(),
                                "123456789340","1234567890","","Kumar","Saha","");
        cout<<*x7<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Bangalore"),"12/09/2023",
                                BookingClasses::FirstClass::Type(),General::Type(),x7);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
const Passenger *x8=Passenger::CreatePassenger("01/05/1960",Gender::Male::Type(),
                                "123456789340","1234567890","","Kumar","Saha","");
        cout<<*x8<<endl;
        try{
                const Booking* p=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Chennai"),"12/09/2021",
                                BookingClasses::AC2Tier::Type(),General::Type(),x8);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }

        cout<<"++++Testing Compute Fare\n\n";
        cout<<"\tExpected Fare: 1849\n";
        const Booking* q=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Delhi"),"12/09/2021",
                                BookingClasses::AC3Tier::Type(),General::Type(),x8);
                cout<<*q<<endl;

        cout<<"\n\n\tExpected Fare: 1125\n";
        const Passenger *x9=Passenger::CreatePassenger("01/05/1950",Gender::Male::Type(),
                                "123456789340","1234567890","","Kumar","Saha","");
        const Booking* r=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Delhi"),"12/09/2021",
                                BookingClasses::AC3Tier::Type(),SeniorCitizens::Male::Type(),x9);
                cout<<*r<<endl;

        cout<<"\n\n\tExpected Fare: 2411\n";
        const Passenger *x10=Passenger::CreatePassenger("01/05/1950",Gender::Male::Type(),
                                "123456789340","1234567890","","Kumar","Saha","Cancer Type");
        const Booking* s=Booking::createNewBooking(*Station::CreateStation("Mumbai"),*Station::CreateStation("Delhi"),"12/09/2021",
                                BookingClasses::ACFirstClass::Type(),Divyaang::Cancer::Type(),x10);
                cout<<*s<<endl;

}
