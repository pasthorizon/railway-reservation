// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __PASSENGER_H
#define __PASSENGER_H

class Passenger;
#include"Gender.h"
#include"Date.h"
#include"BookingClasses.h"
#include"BookingCategory.h"

class Passenger
{
    const string firstName_;
    const string middleName_;
    const string lastName_;
    const Date dateOfBirth_;
    const Gender& gender_;
    const string aadhar_;
    const string phone_;
    const string disabilityID_;
    
    //Private constructor to prevent call before validation
    //Disability type/ID by default set to NONE
    Passenger(const string,const Gender&, 
        const string, const string,const string,const string, const string,const string="None");
    
    //Private methods to validate the data before construction
    static void ValidateName(const string, const string, const string);
    static void ValidateDOB(const string);
    static void ValidateAadhar(const string);
    static void ValidatePhone(const string);
    
    //blocking the copy assignment constructor
    Passenger& operator=(const Passenger&);
    public:
    static void UnitTestPassenger();

    const Date getDOB()const{
        return dateOfBirth_;
    }
    const string getDisabiltyID()const{
        return disabilityID_;
    }
    const bool isMale()const;

    //Interface to create passenger
    //Validates the data and then calls the constructor
    static const Passenger* CreatePassenger(const string,const Gender&, 
        const string, const string, const string,const string,const string, const string="None");
    
    //copy constructor
    Passenger(const Passenger&);
    
    friend ostream& operator<<(ostream& cout, const Passenger&);
};

#endif