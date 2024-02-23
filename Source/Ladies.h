// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __LADIES_H
#define __LADIES_H

#include"Concession.h"

class Passenger;
class LadiesBooking;

class Ladies:public Concession{
    Ladies():Concession("Ladies Type"){}
    public:
    static void UnitTestLadies();
    static const Ladies& Type(){
        const static Ladies theObj;
        return theObj;
    }
    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const ;
    const bool checkEligibility(const Passenger&)const;
    const double getConcessionFactor()const;
};

#endif