#ifndef __SENIORCITIZENS_H
#define __SENIORCITIZENS_H

#include"Concession.h"
class SCBooking;


//static subtyping the Male and Female types of SeniorCitizen
template<typename T>
class SCTypes;

class SeniorCitizens: public Concession{
    struct MaleType{};
    struct FemaleType{};
    protected:
    SeniorCitizens():Concession("Senior Citizen Type"){}
    public:
    static void UnitTestSeniorCitizens();
    virtual const double getConcessionFactor()const=0;
    typedef SCTypes<MaleType> Male;
    typedef SCTypes<FemaleType> Female;
};

template<typename T>
class SCTypes:public SeniorCitizens{

    static const double concessionFactor;
    SCTypes<T>():SeniorCitizens(){}

    //singleton implemented using Meyer's method
    public:
    static const SCTypes<T>& Type(){
        static const SCTypes theObj;
        return theObj;
    }
    const double getConcessionFactor()const;
    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const ;
    const bool checkEligibility(const Passenger&)const;
};


//implementing in the header to facilitate dynamic binding during runtime
template<typename T>
const double SCTypes<T>::getConcessionFactor()const{
    return SCTypes<T>::concessionFactor;
}

#endif