#include<iostream>
using namespace std;
#include"Passenger.h"
#include"Exceptions.h"
#include<ctime>

void Passenger::ValidateName(const string fname, const string mname, const string lname){
    if(fname==""&&lname=="")
    throw Bad_name();
}

void Passenger::ValidateDOB(const string strDate){
    try{
        const Date temp=Date::CreateDate(strDate);
        if(!temp.isPast())
        throw Bad_DOB();
    }
    catch(const Bad_date& r){
        throw Bad_DOB();
    }
}

void Passenger::ValidatePhone(const string phone){
    if(phone.size()!=10) throw Bad_phone();
    for(int i=0;i<10;i++)
    if(phone[i]>'9'||phone[i]<'0') throw Bad_phone();
}

void Passenger::ValidateAadhar(const string aadhaar){
    if(aadhaar.size()!=12) throw Bad_aadhaar();
    
}


Passenger::Passenger(const string dateofBirth,const Gender& gender, 
        const string aadhar, const string phone, const string fname, 
        const string mname, const string lname,const string disabilityID):
        firstName_(fname),middleName_(mname),lastName_(lname),gender_(gender),
        aadhar_(aadhar),phone_(phone),disabilityID_(disabilityID),dateOfBirth_(Date::CreateDate(dateofBirth)){}


const Passenger* Passenger::CreatePassenger(const string dateOfBirth,const Gender& gender, 
        const string aadhar, const string phone,const string fname,
        const string mname, const string lname,const string disabilityID)
{
    try{
        ValidateName(fname,mname,lname);
        ValidateDOB(dateOfBirth);
        ValidatePhone(phone);
        ValidateAadhar(aadhar);
    }
    catch(const Bad_passenger& e){
        throw;
    }
    return new Passenger(dateOfBirth,gender,aadhar,phone,fname,mname,lname,disabilityID);
}

Passenger::Passenger(const Passenger& P):firstName_(P.firstName_),middleName_(P.middleName_),
            lastName_(P.lastName_),gender_(P.gender_),dateOfBirth_(P.dateOfBirth_),
            phone_(P.phone_),aadhar_(P.aadhar_),disabilityID_(P.disabilityID_){}

const bool Passenger::isMale()const{
    if(&gender_==&Gender::Male::Type()) return true;
    return false;
}


ostream& operator<<(ostream&, const Passenger& obj){
    cout<<"++++Passenger Details:\n";
    cout<<"\tName: "<<obj.firstName_<<" "<<obj.middleName_<<" "<<obj.lastName_<<endl;
    cout<<"\tDate of Birth: ";
    cout<<obj.dateOfBirth_;
    cout<<"\tAadhaar No.: "<<obj.aadhar_<<endl;
    cout<<"\tPhone No. :"<<obj.phone_<<endl;
    cout<<"\tDisability: "<<obj.disabilityID_<<endl;
}
