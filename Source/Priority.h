// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __PRIORITY_H
#define __PRIORITY_H

#include<iostream>
using namespace std;

#include"BookingCategory.h"

//forward definition used instead of including the
//headers to avoid cyclic inclusions
class BookingClasses;
class Booking;
class PriorityBooking;

//ad-hoc polymorphism used as only two classes were present
class Priority:public BookingCategory{
    protected:
    Priority(const string name):BookingCategory(name){}
    public:
    static void UnitTestPriority();

    virtual const double getPremiumCharge(const BookingClasses&)const=0;
    virtual const double getMinTatkalCharge(const BookingClasses&)const=0;
    virtual const double getMaxTatkalCharge(const BookingClasses&)const=0;
    virtual const double getMinDistance(const BookingClasses&)const=0;
};

class Tatkal:public Priority{
    Tatkal():Priority("Tatkal Type"){}
    public:
    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const ;
    const double getPremiumCharge(const BookingClasses&)const;
    const double getMinTatkalCharge(const BookingClasses&)const;
    const double getMaxTatkalCharge(const BookingClasses&)const;
    const double getMinDistance(const BookingClasses&)const;
    const bool checkEligibility(const Passenger&) const;

    //singleton using Meyer's method
    static const Tatkal& Type(){
        static const Tatkal theObj;
        return theObj;
    }
};

class PremiumTatkal:public Priority{
    PremiumTatkal():Priority("Premium Tatkal Type"){}
    public:
    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const ;
    const double getPremiumCharge(const BookingClasses&)const;
    const double getMinTatkalCharge(const BookingClasses&)const;
    const double getMaxTatkalCharge(const BookingClasses&)const;
    const double getMinDistance(const BookingClasses&)const;
    const bool checkEligibility(const Passenger&) const;

    static const PremiumTatkal& Type(){
        static const PremiumTatkal theObj;
        return theObj;
    }
};

#endif