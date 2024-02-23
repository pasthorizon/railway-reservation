// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include<exception>
using namespace std;

class Bad_booking:public exception{
    
};

class invalid_category:public Bad_booking{  //in case of ineligbility for some category
    public:
    virtual const char* what() const throw()
    {
        return "Bad_booking exception: Invalid category\n";
    }
};

class invalid_Bdate:public Bad_booking{     //if the date of travel is before the current date
    public:                                 //or if the date is after one year of current date
    virtual const char* what() const throw()
    {
        return "Bad_booking exception: Invalid date of travel\n";
    }
};

class invalid_stations:public Bad_booking{  //if the path given does not exist
    public:
    virtual const char* what() const throw()
    {
        return "Bad_booking exception: Invalid path of travel\n";
    }
};

class Bad_passenger: public exception{

};

class Bad_aadhaar: public exception{    //aadhaar format not correct
    public:
    virtual const char* what() const throw()
    {
        return "Bad_passenger exception: Wrong format of Aadhaar card no.\n";
    }
};

class Bad_phone: public exception{      //phone format not correct
    public:
    virtual const char* what() const throw()
    {
        return "Bad_passenger exception: Wrong format of phone no.\n";
    }
};

class Bad_DOB: public exception{        //if DOB in future
    public:
    virtual const char* what() const throw()
    {
        return "Bad_passenger exception: Invalid DOB entry\n";
    }
};

class Bad_name: public exception{       //if both last name and first name empty
    public:
    virtual const char* what() const throw()
    {
        return "Bad_passenger exception: Incomplete name info\n";
    }
};

class Bad_railways:public exception{
    
};

class duplicate_stations:public Bad_railways{   //if same station name appears more the once
    public:
    virtual const char* what() const throw()
    {
        return "Bad_railways exception: Duplicate stations present in master data\n";
    }
};

class duplicate_stationpairs:public Bad_railways{   //if two distances between same station pairs
    public:
    virtual const char* what() const throw()
    {
        return "Bad_railways exception: Ambiguos distances between two pairs\n";
    }
};

class Bad_date:public exception{

};

class invalid_format:public Bad_date{   //incorrect format DD/MM/YYYY
    public:
    virtual const char* what() const throw()
    {
        return "Bad_date exception: Incorrect format of date entry\n";
    }
};

class invalid_date:public Bad_date{     //invalid date like 31st Sept, 29th Feb 2021
    public:
    virtual const char* what() const throw()
    {
        return "Bad_date exception: Invalid date\n";
    }
};

class Bad_stations:public exception{
    public:
    virtual const char* what() const throw()    //empty station name
    {
        return "Bad_station exception: Station name cannot be empty\n";
    }
};

#endif