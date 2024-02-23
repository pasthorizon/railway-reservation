// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#include"Railways.h"
#include"Booking.h"



//initialising the static variables of the class
vector<const Booking*> Booking::sBookings;
int Booking::sBoookingPNRSerial=1;
const double Booking::sBaseFarePerKM=0.5;

//constructor with an initialiser list and calling the
//compute fare function and pushing the new Booking 
//into the sBookings vector
Booking::Booking(const Station fromStation, 
    const Station toStation, const Date date, 
    const BookingClasses& type,const BookingCategory& category,const Passenger*):
    fromStation_(fromStation),toStation_(toStation),
    date_(date), type_(type),bookingcategory_(category),pNRNumber_(sBoookingPNRSerial++)
{
    Booking::sBookings.push_back(this);        // delete iter;
}

const Booking* Booking::createNewBooking(const Station from, const Station to, const string strDate, 
            const BookingClasses& type,const BookingCategory& category, const Passenger* pass){

    try{
        const Date temp=Date::CreateDate(strDate);
        if(!temp.inYearSpan()) throw invalid_Bdate();
    }
    catch(const Bad_date& e){
        throw;
    }
    catch(const invalid_Bdate& e ){
        throw;
    }
    try{
        Railways::TheRailways().ValidatePath(from,to);
    }
    catch(const invalid_stations& e){
        throw;
    }
    if(!category.checkEligibility(*pass)) throw invalid_category();

    
    return category.createNewBooking(from,to,pass,Date::CreateDate(strDate),type,category);
}


//implementation of static function GetList()
//prints the list of all bookings made so far
void Booking::GetList(){
    vector<const Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
}

//Implementation of the output streaming 
//operator overload
ostream& operator<<(ostream& cout,const Booking& obj){
    cout<<"++++Booking ";
    cout<<"PNR number: "<<obj.pNRNumber_<<endl;
    cout<<"\tFrom station: "<<obj.fromStation_.GetName()<<endl;
    cout<<"\tTo station: "<<obj.toStation_.GetName()<<endl;
    cout<<"\tTravel Date: ";
    cout<<obj.date_;
    cout<<"\tTravel Class: "<<obj.type_.getName()<<endl;
    cout<<"\tTravel Category: "<<obj.bookingcategory_.getName()<<endl;
    cout<<"\tFare: "<<obj.fare_<<endl;

    return cout;
}

Booking::~Booking()
{
    // No dynamic allocation, so nothing in the destructor
}