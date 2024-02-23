// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include<iostream>
using namespace std;
#include"Date.h"
#include"Exceptions.h"
#include<ctime>

//declaring the static variables which wont ever be changed
const char Date::monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

const char Date::dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday",
                        "Friday", "Saturday", "Sunday" };

const Date Date::CreateDate(const string strDate){
    try{
        checkStringValidity(strDate);
        unsigned int dd=atoi(strDate.substr(0,2).c_str());
        unsigned int mm=atoi(strDate.substr(3,2).c_str());
        unsigned int yy=atoi(strDate.substr(6,4).c_str());
        if(dd==0||mm==0||yy==0) throw invalid_format();
        checkDateValidity(dd,mm,yy);

        return Date(dd,mm,yy);
    }
    catch(const Bad_date& e){
        throw;
    }
}


void Date::checkStringValidity(const string strDate){
    if(strDate.size()!=10)
    throw invalid_format();
    if(strDate[2]!='/'||strDate[5]!='/')
    throw invalid_format();
}

void Date::checkDateValidity(unsigned int dd, unsigned int mm, unsigned int yy){
    
	if( yy <1900 ||yy>2099 )
		throw invalid_date();
		
	if( mm <= 0 || mm > 12)
		throw invalid_date();
	
	if( mm == 2)
	{	
		if ( yy % 4 == 0 )
		{
				if( dd > 29 || dd <=0) 
					throw invalid_date();
		}
		else
		{
				if( dd > 28 || dd <=0) 
					throw invalid_date();
		}
	}
	else if( mm == 1 || mm == 3 || mm  == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12 )
	{
		if( dd > 31 || dd <= 0) 
			throw invalid_date();
	}
	else
	{
		if( dd > 30 || dd <= 0) 
			throw invalid_date();
	}
}

int Date::getAge() const {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    unsigned int dd=now->tm_mday;
    unsigned int mm=now->tm_mon+1;
    unsigned int yy=now->tm_year + 1900;
    return yy-year_;
}

bool Date::inYearSpan() const{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    unsigned int dd=now->tm_mday;
    unsigned int mm=now->tm_mon+1;
    unsigned int yy=now->tm_year + 1900;
    
    if(yy==year_){
        if(mm>month_)
        return false;
        if(mm==month_){
            if(dd<=date_) return false;
        }

    }
    
    else if(yy==year_+1)
    {
        if(mm>month_) return false;
        else if(mm==month_&&dd>date_+1) return false;
    }
    else return false;
    
    return true;
}

bool Date::isPast() const{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    unsigned int dd=now->tm_mday;
    unsigned int mm=now->tm_mon+1;
    unsigned int yy=now->tm_year + 1900;
    if(year_>yy) return false;
    if(year_==yy){
        if(month_>mm) return false;
        else if(month_==mm&&date_>=dd) return false;
    }
    return true;
}

