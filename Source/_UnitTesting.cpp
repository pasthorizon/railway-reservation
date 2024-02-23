#include<iostream>
using namespace std;
#include<string>
#include<string.h>
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

void Station::UnitTestStation()
{
    cout<<"\n\n+++Unit Testing Station Class+++\n";

    //Constructors
    Station first=*(Station::CreateStation("First"));
    if(first.GetName()!="First")
        cout<<"    "<<"Constructor taking string argument not working\n";
    else 
        cout<<"    "<<"Constructor taking string argument works\n";
    if(Station(first).GetName()!=first.GetName())
        cout<<"    "<<"Copy constructor not working\n";
    else 
        cout<<"    "<<"Copy constructor working\n";

    if(first.GetName()!="First")
        cout<<"    "<<"GetName() not working\n";
    else 
        cout<<"    "<<"GetName() works\n";

    Station mumbai=*(Station::CreateStation("Mumbai"));
    if(mumbai.getDistance("Delhi")!=1447)
        cout<<"    "<<"GetDistance() not working\n";
    else 
        cout<<"    "<<"GetDistance() works\n";
    
}

void Railways::UnitTestRailways()
{
    cout<<"\n\n+++Unit Testing Railways Class+++\n";
    cout<<"    Name: "<<Railways::sName<<endl;
    if(&Railways::TheRailways()!=&Railways::TheRailways())
        cout<<"    Singleton class not returned\n";
    else cout<<"    Singleton class returned\n";
    
    bool distances=true;
    if(Railways::TheRailways().getDistance("Delhi","Mumbai")!=1447)
    {
        distances=false;
        cout<<"    Distance between Delhi and Mumbai returned wrong\n";
    }    
    if(Railways::TheRailways().getDistance("Delhi","Kolkata")!=1472)
    {
        distances=false;
        cout<<"    Distance between Delhi and Kolkata returned wrong\n";
    }  
    
    if(Railways::TheRailways().getDistance("Delhi","Chennai")!=2180)
    {
        distances=false;
        cout<<"    Distance between Delhi and Chennai returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Delhi","Banglore")!=2150)
    {
        distances=false;
        cout<<"    Distance between Delhi and Banglore returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Mumbai","Kolkata")!=2014)
    {
        distances=false;
        cout<<"    Distance between Mumbai and Kolkata returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Banglore","Kolkata")!=1871)
    {
        distances=false;
        cout<<"    Distance between Banglore and Kolkata returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Chennai","Kolkata")!=1659)
    {
        distances=false;
        cout<<"    Distance between Chennai and Kolkata returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Banglore","Mumbai")!=981)
    {
        distances=false;
        cout<<"    Distance between Banglore and Mumbai returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Mumbai","Chennai")!=1338)
    {
        distances=false;
        cout<<"    Distance between Mumbai and Chennai returned wrong\n";
    }  
    if(Railways::TheRailways().getDistance("Chennai","Banglore")!=350)
    {
        distances=false;
        cout<<"    Distance between Banglore and Chennai returned wrong\n";
    }  
    if(distances)    cout <<"    All distances returned right\n";
    bool excep = false;
    try
    {
        Railways::ValidatePath(*Station::CreateStation("Mumbai"),*Station::CreateStation("Delhi"));
    }
    catch(Bad_booking& e)
    {
        cout<<e.what();
        excep = false;
    }
    if(!excep)
        cout<<"    ValidatePath() works right\n";
    else
        cout<<"    ValidatePath() works wrong\n";
    try
    {
        int wrong_distance = Railways::TheRailways().getDistance("Mumbai","Jaipur");//Jaipur does not exist as a station in the master data
    }
    catch(Bad_booking& e)
    {
        if (strcmp(e.what(),"Bad_booking exception: Invalid path of travel\n"))
            cout<<"    Bad staion name(station name repeated) exception handled wrong\n";
        else
            cout<<"    Bad station name(station name repeated) exception handled right\n";
    }
    try
    {
        int wrong_distance = Railways::TheRailways().getDistance("Mumbai","Mumbai");//Same station name cannot appear twice in a booking 
    }
    catch(Bad_booking& e)
    {
        if (strcmp(e.what(),"Bad_booking exception: Invalid path of travel\n"))
            cout<<"    Bad staion name(station name repeated) exception handled wrong\n";
        else
            cout<<"    Bad station name(station name repeated) exception handled right\n";
    }
    bool excep1 = false;
    try
    {
        Railways::ValidatePath(*Station::CreateStation("Mumbai"),*Station::CreateStation("Coimbatore")); //Error handling
    }
    catch(Bad_booking& e)
    {
        excep1 = true;
    }
    if(excep1)
        cout<<"    ValidatePath() handles exceptions right\n";
    else
        cout<<"    ValidatePath() handles exceptions wrong\n";
    

}

void Date::UnitTestDate()
{
    cout<<"\n\n+++Unit Testing Date Class+++\n";
    Date d1(1,1,2000);
    if( d1.date_==1 && d1.month_ == 1 && d1.year_ == 2000)
        cout<<"    Constructor with integer arguments working\n";
    else
        cout<<"    Constructor with integer arguments not working\n";
    Date d2(d1);
    if( d2.date_==1 && d2.month_ == 1 && d2.year_ == 2000)
        cout<<"    Copy Constructor working\n";
    else
        cout<<"    Copy Constructor not working\n";
    Date d3 = Date::CreateDate("12/12/2021");
    if( d3.date_==12 && d3.month_ == 12 && d3.year_ == 2021)
        cout<<"    CreateDate() with string working\n";
    else
        cout<<"    CreateDate() with string not working\n";
    if (d3.inYearSpan() == true and d1.inYearSpan() == false)
        cout<<"    inYearSpan() working right\n";
    else
        cout<<"    inYearSpan() working wrong\n";
    if(d1.getAge()==21)
        cout<<"    getAge() working right\n";
    else
        cout<<"    getAge() working wrong\n";
    if (d3.isPast() == false and d1.isPast() == true)
        cout<<"    isPast() working right\n";
    else
        cout<<"    isPast() working wrong\n";
    

    try
    {
        Date d4 = Date::CreateDate("1//4/3434/");//Wrong date format
    }
    catch(Bad_date& e)
    {
        if (strcmp(e.what(),"Bad_date exception: Incorrect format of date entry\n"))
            cout<<"    Bad date(incorrect date format) exception handled wrong\n";
        else
            cout<<"    Bad date(incorrect date format) exception handled right\n";
    }
    try
    {
        Date d5 = Date::CreateDate("30/02/2025");//Invalid date
    }
    catch(Bad_date& e)
    {
        if (strcmp(e.what(),"Bad_date exception: Invalid date\n"))
            cout<<"    Bad date(invalid date) exception handled wrong\n";
        else
            cout<<"    Bad date(invalid date) exception handled right\n";
    }
}
void Gender::UnitTestGender()
{
    cout<<"\n\n+++Unit Testing Gender Class+++\n";
    if(Gender::Male::Type().getTitle()=="Mr." && Gender::Female::Type().getTitle()=="Mrs.")
        cout<<" Gender Class works right\n";
    else
        cout<<"  Gender Class works wrong\n";

}
void Passenger::UnitTestPassenger()
{
    cout<<"\n\n+++Unit Testing Passenger Class+++\n";
    const Passenger *x=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Cancer Type");
    if(x->isMale()==true&&x->firstName_=="Dhananjay"&&x->middleName_==""&&x->lastName_==""&&x->aadhar_=="123412341234"&&x->phone_=="9091223399"&&x->getDisabiltyID()=="Cancer Type")
        cout<<"    CreatePassenger() working right\n";
    else
        cout<<"    CreatePassenger() working wrong\n";
    Passenger y(*x);
     if(y.isMale()==true&&y.firstName_=="Dhananjay"&&y.middleName_==""&&y.lastName_==""&&y.aadhar_=="123412341234"&&y.phone_=="9091223399"&&y.getDisabiltyID()=="Cancer Type")
        cout<<"    Copy Constructor working right\n";
    else
        cout<<"    Copy Constructor working wrong\n";    

    try
    {
        const Passenger *x1=Passenger::CreatePassenger("01/45/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Cancer Type");
    }
    catch(const std::exception& e)
    {
        if(strcmp(e.what(),"Bad_passenger exception: Invalid DOB entry\n"))
            cout<<"    Bad DOB exception handled wrong\n";
        else
            cout<<"    Bad DOB exception handled right\n";
    }
    try
    {
        const Passenger *x1=Passenger::CreatePassenger("01/05/1922",Gender::Male::Type(),
                                "1234121234","9091223399","Dhananjay","","","Cancer Type");
    }
    catch(const std::exception& e)
    {
        
        if(strcmp(e.what(),"Bad_passenger exception: Wrong format of Aadhaar card no.\n"))
            cout<<"    Bad Aadhaar Card No. exception handled wrong\n";
        else
            cout<<"    Bad Aadhaar Card No. exception handled right\n";
    }
    try
    {
        const Passenger *x1=Passenger::CreatePassenger("01/05/1922",Gender::Male::Type(),
                                "1234121234","909223399","Dhananjay","","","Cancer Type");
    }
    catch(const std::exception& e)
    {
        if(strcmp(e.what(),"Bad_passenger exception: Wrong format of phone no.\n"))
            cout<<"    Bad Phone No. exception handled wrong\n";
        else
            cout<<"    Bad Phone No. exception handled right\n";
    }
    try
    {
        const Passenger *x1=Passenger::CreatePassenger("01/05/1922",Gender::Male::Type(),
                                "1234121234","9109223399","","","","Cancer Type");
    }
    catch(const std::exception& e)
    {
        if(strcmp(e.what(),"Bad_passenger exception: Incomplete name info\n"))
            cout<<"    Bad Passenger Name exception handled wrong\n";
        else
            cout<<"    Bad passenger Name exception handled right\n";
    }
    
}
void BookingClasses::UnitTestBookingClasses()
{
    cout<<"\n\n+++Unit Testing BookingClasses Class+++\n";
    int count = 0;
    if(BookingClasses::ExecutiveChairCar::Type().name_=="Executive Chair Car")
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getLoadFactor()==5)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().isBerth()==false)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().isAC()==true)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getTiers()==0)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().isLuxury()==true)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getReservationCharge()==60)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getMinTatkalCharge()==400)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getMaxTatkalCharge()==500)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getMinDistance()==250.0)
        count++;
    if(BookingClasses::ExecutiveChairCar::Type().getPremiumCharge()==0.3)
        count++;
    if(count == 11)
        cout<<"    Execitive Chair Car is working right\n";
    else
        cout<<"    Execitive Chair Car is working wrong\n";


    count = 0;
    if(BookingClasses::FirstClass::Type().name_=="First Class")
        count++;
    if(BookingClasses::FirstClass::Type().getLoadFactor()==3)
        count++;
    if(BookingClasses::FirstClass::Type().isBerth()==true)
        count++;
    if(BookingClasses::FirstClass::Type().isAC()==false)
        count++;
    if(BookingClasses::FirstClass::Type().getTiers()==2)
        count++;
    if(BookingClasses::FirstClass::Type().isLuxury()==true)
        count++;
    if(BookingClasses::FirstClass::Type().getReservationCharge()==50)
        count++;
    if(BookingClasses::FirstClass::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::FirstClass::Type().getMinTatkalCharge()==400)
        count++;
    if(BookingClasses::FirstClass::Type().getMaxTatkalCharge()==500)
        count++;
    if(BookingClasses::FirstClass::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    First Class is working right\n";
    else
        cout<<"    First Class is working wrong\n";

    count = 0;
    if(BookingClasses::AC2Tier::Type().name_=="AC 2 Tier")
        count++;
    if(BookingClasses::AC2Tier::Type().getLoadFactor()==4)
        count++;
    if(BookingClasses::AC2Tier::Type().isBerth()==true)
        count++;
    if(BookingClasses::AC2Tier::Type().isAC()==true)
        count++;
    if(BookingClasses::AC2Tier::Type().getTiers()==2)
        count++;
    if(BookingClasses::AC2Tier::Type().isLuxury()==false)
        count++;
    if(BookingClasses::AC2Tier::Type().getReservationCharge()==50)
        count++;
    if(BookingClasses::AC2Tier::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::AC2Tier::Type().getMinTatkalCharge()==400)
        count++;
    if(BookingClasses::AC2Tier::Type().getMaxTatkalCharge()==500)
        count++;
    if(BookingClasses::AC2Tier::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    AC 2 Tier is working right\n";
    else
        cout<<"    AC 2 Tier is working wrong\n";
    
    count = 0;
    if(BookingClasses::AC3Tier::Type().name_=="AC 3 Tier")
        count++;
    if(BookingClasses::AC3Tier::Type().getLoadFactor()==2.5)
        count++;
    if(BookingClasses::AC3Tier::Type().isBerth()==true)
        count++;
    if(BookingClasses::AC3Tier::Type().isAC()==true)
        count++;
    if(BookingClasses::AC3Tier::Type().getTiers()==3)
        count++;
    if(BookingClasses::AC3Tier::Type().isLuxury()==false)
        count++;
    if(BookingClasses::AC3Tier::Type().getReservationCharge()==40)
        count++;
    if(BookingClasses::AC3Tier::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::AC3Tier::Type().getMinTatkalCharge()==300)
        count++;
    if(BookingClasses::AC3Tier::Type().getMaxTatkalCharge()==400)
        count++;
    if(BookingClasses::AC3Tier::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    AC 3 Tier is working right\n";
    else
        cout<<"    AC 3 Tier is working wrong\n";
    

    count = 0;
    if(BookingClasses::ACFirstClass::Type().name_=="AC First Class")
        count++;
    if(BookingClasses::ACFirstClass::Type().getLoadFactor()==6.5)
        count++;
    if(BookingClasses::ACFirstClass::Type().isBerth()==true)
        count++;
    if(BookingClasses::ACFirstClass::Type().isAC()==true)
        count++;
    if(BookingClasses::ACFirstClass::Type().getTiers()==2)
        count++;
    if(BookingClasses::ACFirstClass::Type().isLuxury()==true)
        count++;
    if(BookingClasses::ACFirstClass::Type().getReservationCharge()==60)
        count++;
    if(BookingClasses::ACFirstClass::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::ACFirstClass::Type().getMinTatkalCharge()==400)
        count++;
    if(BookingClasses::ACFirstClass::Type().getMaxTatkalCharge()==500)
        count++;
    if(BookingClasses::ACFirstClass::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    AC First Class is working right\n";
    else
        cout<<"    AC First Class is working wrong\n";

    count = 0;
    if(BookingClasses::Sleeper::Type().name_=="Sleeper")
        count++;
    if(BookingClasses::Sleeper::Type().getLoadFactor()==1)
        count++;
    if(BookingClasses::Sleeper::Type().isBerth()==true)
        count++;
    if(BookingClasses::Sleeper::Type().isAC()==false)
        count++;
    if(BookingClasses::Sleeper::Type().getTiers()==3)
        count++;
    if(BookingClasses::Sleeper::Type().isLuxury()==false)
        count++;
    if(BookingClasses::Sleeper::Type().getReservationCharge()==20)
        count++;
    if(BookingClasses::Sleeper::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::Sleeper::Type().getMinTatkalCharge()==100)
        count++;
    if(BookingClasses::Sleeper::Type().getMaxTatkalCharge()==200)
        count++;
    if(BookingClasses::Sleeper::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    Sleeper is working right\n";
    else
        cout<<"    Sleeper is working wrong\n";

    count = 0;
    if(BookingClasses::SecondSitting::Type().name_=="Second Sitting")
        count++;
    if(BookingClasses::SecondSitting::Type().getLoadFactor()==0.6)
        count++;
    if(BookingClasses::SecondSitting::Type().isBerth()==false)
        count++;
    if(BookingClasses::SecondSitting::Type().isAC()==false)
        count++;
    if(BookingClasses::SecondSitting::Type().getTiers()==0)
        count++;
    if(BookingClasses::SecondSitting::Type().isLuxury()==false)
        count++;
    if(BookingClasses::SecondSitting::Type().getReservationCharge()==15)
        count++;
    if(BookingClasses::SecondSitting::Type().getPremiumCharge()==0.1)
        count++;
    if(BookingClasses::SecondSitting::Type().getMinTatkalCharge()==10)
        count++;
    if(BookingClasses::SecondSitting::Type().getMaxTatkalCharge()==15)
        count++;
    if(BookingClasses::SecondSitting::Type().getMinDistance()==100)
        count++;
    if(count == 11)
        cout<<"    Second Sitting is working right\n";
    else
        cout<<"    Second Sitting is working wrong\n";
    
    count = 0;
    if(BookingClasses::ACChairCar::Type().name_=="AC Chair Car")
        count++;
    if(BookingClasses::ACChairCar::Type().getLoadFactor()==2)
        count++;
    if(BookingClasses::ACChairCar::Type().isBerth()==false)
        count++;
    if(BookingClasses::ACChairCar::Type().isAC()==true)
        count++;
    if(BookingClasses::ACChairCar::Type().getTiers()==0)
        count++;
    if(BookingClasses::ACChairCar::Type().isLuxury()==false)
        count++;
    if(BookingClasses::ACChairCar::Type().getReservationCharge()==40)
        count++;
    if(BookingClasses::ACChairCar::Type().getPremiumCharge()==0.3)
        count++;
    if(BookingClasses::ACChairCar::Type().getMinTatkalCharge()==125)
        count++;
    if(BookingClasses::ACChairCar::Type().getMaxTatkalCharge()==225)
        count++;
    if(BookingClasses::ACChairCar::Type().getMinDistance()==500)
        count++;
    if(count == 11)
        cout<<"    AC Chair Car is working right\n";
    else
        cout<<"    AC Chair Car is working wrong\n";

}

void Divyaang::UnitTestDivyaangClass()
{
    cout<<"\n\n+++Unit Testing Divyaang Class+++\n";
    int count = 0;
    if(Divyaang::None::Type().getName()=="None")
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::AC2Tier::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::AC3Tier::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::ACChairCar::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::ACFirstClass::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::FirstClass::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::ExecutiveChairCar::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::Sleeper::Type())==0)
        count++;
    if(Divyaang::None::Type().getConcessionFactor(BookingClasses::SecondSitting::Type())==0)
        count++;
    if(count == 9)
        cout<<"    None type works right\n";
    else
        cout<<"     None type works wrong\n";
    

    count = 0;
    if(Divyaang::TB::Type().getName()=="Tuberculosis Type")
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::AC2Tier::Type())==0)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::AC3Tier::Type())==0)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::ACChairCar::Type())==0)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::ACFirstClass::Type())==0.75)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::FirstClass::Type())==0)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::ExecutiveChairCar::Type())==0)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::Sleeper::Type())==0.75)
        count++;
    if(Divyaang::TB::Type().getConcessionFactor(BookingClasses::SecondSitting::Type())==0.75)
        count++;
    if(count == 9)
        cout<<"    Tuberculosis type works right\n";
    else
        cout<<"    Tuberculosis type works wrong\n";
    
    count = 0;
    if(Divyaang::OH::Type().getName()=="Orthopaedic Handicap Type")
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::AC2Tier::Type())==0.5)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::AC3Tier::Type())==0.75)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::ACChairCar::Type())==0.75)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::ACFirstClass::Type())==0.5)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::FirstClass::Type())==0.75)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::ExecutiveChairCar::Type())==0.75)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::Sleeper::Type())==0.75)
        count++;
    if(Divyaang::OH::Type().getConcessionFactor(BookingClasses::SecondSitting::Type())==0.75)
        count++;
    if(count == 9)
        cout<<"    Orthopaedic Handicap Type works right\n";
    else
        cout<<"    Orthopaedic Handicap Type works wrong\n";
    
     count = 0;
    if(Divyaang::Cancer::Type().getName()=="Cancer Type")
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::AC2Tier::Type())==0.5)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::AC3Tier::Type())==1)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::ACChairCar::Type())==1)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::ACFirstClass::Type())==0.5)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::FirstClass::Type())==0.75)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::ExecutiveChairCar::Type())==0.75)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::Sleeper::Type())==1)
        count++;
    if(Divyaang::Cancer::Type().getConcessionFactor(BookingClasses::SecondSitting::Type())==1)
        count++;
    if(count == 9)
        cout<<"    Cancer Type works right\n";
    else
        cout<<"    Cancer Type works wrong\n";
    
     count = 0;
    if(Divyaang::Blind::Type().getName()=="Blind Type")
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::AC2Tier::Type())==0.5)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::AC3Tier::Type())==0.75)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::ACChairCar::Type())==0.75)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::ACFirstClass::Type())==0.5)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::FirstClass::Type())==0.75)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::ExecutiveChairCar::Type())==0.75)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::Sleeper::Type())==0.75)
        count++;
    if(Divyaang::Blind::Type().getConcessionFactor(BookingClasses::SecondSitting::Type())==0.75)
        count++;
    if(count == 9)
        cout<<"    Blind Type works right\n";
    else
        cout<<"    Blind Type works wrong\n";
    const Passenger *x=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Cancer Type");
    const Passenger *y=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No cancer Type");
    if(Divyaang::Cancer::Type().checkEligibility(*x)&&!Divyaang::Cancer::Type().checkEligibility(*y))
        cout<<"    Cancer Eligibility in Divyaang working right\n";
    else
        cout<<"    Cancer Eligibility in Divyaang working wrong\n";
    const Passenger *x1=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Blind Type");
    const Passenger *y1=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No blind Type");
    if(Divyaang::Blind::Type().checkEligibility(*x1)&&!Divyaang::Blind::Type().checkEligibility(*y1))
        cout<<"    Blind Eligibility in Divyaang working right\n";
    else
        cout<<"    Blind Eligibility in Divyaang working wrong\n";
    
    const Passenger *x2=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Tuberculosis Type");
    const Passenger *y2=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No Tuberculosis Type");
    if(Divyaang::TB::Type().checkEligibility(*x2)&&!Divyaang::TB::Type().checkEligibility(*y2))
        cout<<"    Tuberculosis Eligibility in Divyaang working right\n";
    else
        cout<<"    Tuberculosis Eligibility in Divyaang working wrong\n";
    
    const Passenger *x3=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Orthopaedic Handicap Type");
    const Passenger *y3=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No OH Type");
    if(Divyaang::OH::Type().checkEligibility(*x3)&&!Divyaang::OH::Type().checkEligibility(*y3))
        cout<<"    Orthopaedic Handicap Eligibility in Divyaang working right\n";
    else
        cout<<"    Orthopaedic Handicap Eligibility in Divyaang working wrong\n";
    
}
void Priority::UnitTestPriority()
{
    cout<<"\n\n+++Unit Testing Priority Class+++\n";
    int count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::AC2Tier::Type())==500)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::AC2Tier::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::AC2Tier::Type())==400)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::AC2Tier::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for AC 2 Tier is working correct\n";
    else
        cout<<"    Tatkal for AC 2 Tier is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::AC3Tier::Type())==400)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::AC3Tier::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::AC3Tier::Type())==300)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::AC3Tier::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for AC 3 Tier is working correct\n";
    else
        cout<<"    Tatkal for AC 3 Tier is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::ACFirstClass::Type())==500)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::ACFirstClass::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::ACFirstClass::Type())==400)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::ACFirstClass::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for AC First Class is working correct\n";
    else
        cout<<"    Tatkal for AC First Class is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::Sleeper::Type())==200)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::Sleeper::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::Sleeper::Type())==100)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::Sleeper::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for Sleeper is working correct\n";
    else
        cout<<"    Tatkal for Sleeper is working wrong\n";

    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::ACChairCar::Type())==225)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::ACChairCar::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::ACChairCar::Type())==125)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::ACChairCar::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for AC Chair Car is working correct\n";
    else
        cout<<"    Tatkal for AC Chair Car is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::SecondSitting::Type())==15)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::SecondSitting::Type())==100)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::SecondSitting::Type())==10)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::SecondSitting::Type())==0.1)
        count++;
    if(count == 4)
        cout<<"    Tatkal for Second Sittingis working correct\n";
    else
        cout<<"    Tatkal for Second Sitting is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::ExecutiveChairCar::Type())==500)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::ExecutiveChairCar::Type())==250)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::ExecutiveChairCar::Type())==400)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::ExecutiveChairCar::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for Executive Chair Car is working correct\n";
    else
        cout<<"    Tatkal for Executive Chair Car is working wrong\n";
    
    count = 0;
    if(Tatkal::Type().getMaxTatkalCharge(BookingClasses::FirstClass::Type())==500)
        count++;
    if(Tatkal::Type().getMinDistance(BookingClasses::FirstClass::Type())==500)
        count++;
    if(Tatkal::Type().getMinTatkalCharge(BookingClasses::FirstClass::Type())==400)
        count++;
    if(Tatkal::Type().getPremiumCharge(BookingClasses::FirstClass::Type())==0.3)
        count++;
    if(count == 4)
        cout<<"    Tatkal for First Class is working correct\n";
    else
        cout<<"    Tatkal for First Class is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::AC2Tier::Type())==1000)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::AC2Tier::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::AC2Tier::Type())==800)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::AC2Tier::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for AC 2 Tier is working correct\n";
    else
        cout<<"    Premium Tatkal for AC 2 Tier is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::AC3Tier::Type())==800)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::AC3Tier::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::AC3Tier::Type())==600)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::AC3Tier::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for AC 3 Tier is working correct\n";
    else
        cout<<"    Premium Tatkal for AC 3 Tier is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::ACFirstClass::Type())==1000)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::ACFirstClass::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::ACFirstClass::Type())==800)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::ACFirstClass::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for AC First Class is working correct\n";
    else
        cout<<"    Premium Tatkal for AC First Class is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::Sleeper::Type())==400)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::Sleeper::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::Sleeper::Type())==200)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::Sleeper::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for Sleeper is working correct\n";
    else
        cout<<"    Premium Tatkal for Sleeper is working wrong\n";

    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::ACChairCar::Type())==450)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::ACChairCar::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::ACChairCar::Type())==250)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::ACChairCar::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for AC Chair Car is working correct\n";
    else
        cout<<"    Premium Tatkal for AC Chair Car is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::SecondSitting::Type())==30)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::SecondSitting::Type())==100)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::SecondSitting::Type())==20)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::SecondSitting::Type())==0.2)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for Second Sittingis working correct\n";
    else
        cout<<"    Premium Tatkal for Second Sitting is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::ExecutiveChairCar::Type())==1000)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::ExecutiveChairCar::Type())==250)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::ExecutiveChairCar::Type())==800)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::ExecutiveChairCar::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for Executive Chair Car is working correct\n";
    else
        cout<<"    Premium Tatkal for Executive Chair Car is working wrong\n";
    
    count = 0;
    if(PremiumTatkal::Type().getMaxTatkalCharge(BookingClasses::FirstClass::Type())==1000)
        count++;
    if(PremiumTatkal::Type().getMinDistance(BookingClasses::FirstClass::Type())==500)
        count++;
    if(PremiumTatkal::Type().getMinTatkalCharge(BookingClasses::FirstClass::Type())==800)
        count++;
    if(PremiumTatkal::Type().getPremiumCharge(BookingClasses::FirstClass::Type())==0.6)
        count++;
    if(count == 4)
        cout<<"    Premium Tatkal for First Class is working correct\n";
    else
        cout<<"    Premium Tatkal for First Class is working wrong\n";
    

}

void Ladies::UnitTestLadies(){
    cout<<"\n\n+++Unit Testing Ladies Class+++\n";
    const Passenger *x1=Passenger::CreatePassenger("01/03/1922",Gender::Female::Type(),
                                "123412341234","9091223399","Dhananjay","","","Blind Type");
    const Passenger *y1=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No blind Type");

    int count=0;
    if(Ladies::Type().checkEligibility(*x1)) count++;
    if(!Ladies::Type().checkEligibility(*y1)) count++;
    if(Ladies::Type().getConcessionFactor()==0) count++;

    if(count==3) cout<<"    Ladies type works right\n";
    else cout<<"    Ladies type works wrong\n";
}

void SeniorCitizens::UnitTestSeniorCitizens(){
    cout<<"\n\n+++Unit Testing SeniorCitizen Class+++\n";
    int count=0;
    if(SeniorCitizens::Male::Type().getConcessionFactor()==0.4) count++;
    if(SeniorCitizens::Female::Type().getConcessionFactor()==0.5) count++;
    const Passenger *x1=Passenger::CreatePassenger("01/03/1922",Gender::Female::Type(),
                                "123412341234","9091223399","Dhananjay","","","Blind Type");
    const Passenger *y1=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No blind Type");
    const Passenger *x2=Passenger::CreatePassenger("01/03/2001",Gender::Female::Type(),
                                "123412341234","9091223399","Dhananjay","","","Blind Type");
    const Passenger *y2=Passenger::CreatePassenger("01/03/1980",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","No blind Type");
    
    if(!SeniorCitizens::Male::Type().checkEligibility(*x1)) count++;
    if(!SeniorCitizens::Male::Type().checkEligibility(*y2)) count++;
    if(SeniorCitizens::Male::Type().checkEligibility(*y1)) count++;

    if(!SeniorCitizens::Female::Type().checkEligibility(*y1)) count++;
    if(!SeniorCitizens::Female::Type().checkEligibility(*x2)) count++;
    if(SeniorCitizens::Female::Type().checkEligibility(*x1)) count++;

    if(count==8) cout<<"    SeniorCitizens works correctly\n";
    else cout<<"    SeniorCitizens works wrongly\n";

}



int main(){
    /*
    const Passenger *x=Passenger::CreatePassenger("01/03/1922",Gender::Male::Type(),
                                "123412341234","9091223399","Dhananjay","","","Cancer Type");
        cout<<*x<<endl;
        try{
                const Booking* p=Booking::createNewBooking(Station("Delhi"),Station("Mumbai"),"04/05/2021",
                                BookingClasses::ACFirstClass::Type(),Divyaang::Cancer::Type(),x);
                cout<<*p<<endl;
        }
        catch(const Bad_booking& e){
                cout<<e.what();
        }
        */
       Station::UnitTestStation();
       Railways::UnitTestRailways();
       Date::UnitTestDate();
       Gender::UnitTestGender();
       Passenger::UnitTestPassenger();
       BookingClasses::UnitTestBookingClasses();
       Divyaang::UnitTestDivyaangClass();
       Priority::UnitTestPriority();
       Ladies::UnitTestLadies();
       SeniorCitizens::UnitTestSeniorCitizens();
}