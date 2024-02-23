// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __BOOKING_H
#define __BOOKING_H

#include<vector>
#include"Railways.h"
#include"BookingClasses.h"
#include"BookingCategory.h"
#include"Date.h"
#include"Passenger.h"

class BookingCategory;

class Booking{
    
    private:
    //blocking the copy constructor and the
    //copy assignment constructor
    Booking(const Booking&);
    const Booking& operator=(const Booking&);

    //All the changeable attributes made static
    //so that they can be changed without recompiling
    //the .cpp file of this class
    
    static const double sLuxuryTaxPercent;

    //PNR and sBookings are properties of the class, hence static
    static int sBoookingPNRSerial;
    static vector< const Booking*> sBookings;

    protected:
    static const double sBaseFarePerKM;
    const int pNRNumber_;
    const Station fromStation_;
    const Station toStation_;
    const Date date_;
    const BookingClasses& type_;
    const Passenger* passenger_;
    const BookingCategory& bookingcategory_;

    //mutable because it will need to be computed by 
    //a function which is otherwise of const type
    mutable int fare_;
   
        //private constructor because construction without
        //validation should not be allowed
    Booking(const Station, const Station, const Date, 
            const BookingClasses&,const BookingCategory&, const Passenger*);
    
    public:
    //unit test function made static to test without object creation
    static void UnitTestBookings();
    //virtual destructor
    virtual ~Booking();

    //creatNewBooking to take in and validate the data before
    //constructing a booking object
    static const Booking* createNewBooking(const Station, const Station, const string, 
            const BookingClasses&,const BookingCategory&, const Passenger*);
    
    friend ostream& operator<<(ostream& cout,const Booking&);
    //static function to print the list of bookings made so far
    static void GetList();
};

#endif