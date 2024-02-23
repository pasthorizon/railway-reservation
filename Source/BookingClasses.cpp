#include<iostream>
using namespace std;

#include"BookingClasses.h"
#include"Divyaang.h"

const string BookingClasses::getName() const{
    return name_;
}

template<>
const double BookingClasses::AC2Tier::getConcessionFactor(const Divyaang& Y) const{
    return Y.AC2Tier();
}

template<>
const double BookingClasses::AC3Tier::getConcessionFactor(const Divyaang& Y) const{
    return Y.AC3Tier();
}

template<>
const double BookingClasses::ACFirstClass::getConcessionFactor(const Divyaang& Y) const{
    return Y.ACFirstClass();
}

template<>
const double BookingClasses::ACChairCar::getConcessionFactor(const Divyaang& Y) const{
    return Y.ACChairCar();
}

template<>
const double BookingClasses::ExecutiveChairCar::getConcessionFactor(const Divyaang& Y) const{
    return Y.ExecutiveChairCar();
}

template<>
const double BookingClasses::Sleeper::getConcessionFactor(const Divyaang& Y) const{
    return Y.Sleeper();
}

template<>
const double BookingClasses::SecondSitting::getConcessionFactor(const Divyaang& Y) const{
    return Y.SecondSitting();
}

template<>
const double BookingClasses::FirstClass::getConcessionFactor(const Divyaang& Y) const{
    return Y.FirstClass();
}

ostream& operator<<(ostream& cout, const BookingClasses& other){
    cout<<"+++Booking Class\n";
        cout<<"\tBooking Class Name: "<<other.getName()<<endl;
        cout<<"\tBooking Class Fare Load: "<<other.getLoadFactor()<<endl;
        cout<<"\tBooking Class Berth: "<<other.isBerth()<<endl;
        cout<<"\tBooking Class No. of Tiers: "<<other.getTiers()<<endl;
        cout<<"\tBooking Class Luxury Statue: "<<other.isLuxury()<<endl;
        cout<<"\tBooking Class Reservation Charge: "<<other.getReservationCharge()<<endl;
        

        return cout;
}

