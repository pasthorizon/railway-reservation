// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __DIVYAANG_H
#define __DIVYAANG_H

#include"Concession.h"
#include"BookingClasses.h"

class DivyaangBooking;

template<typename T>
class DivyaangTypes;

class Divyaang:public Concession{
    struct BlindType{};
    struct TBType{};
    struct OHType{};
    struct CancerType{};
    struct NoneType{};
    protected:
    Divyaang(const string name):Concession(name){}
    public:
    static void UnitTestDivyaangClass();

    const bool checkEligibility(const Passenger&)const;
    virtual const double  getConcessionFactor(const BookingClasses&)const=0;
    
    virtual const double AC2Tier()const=0;
    virtual const double AC3Tier()const=0;
    virtual const double ACFirstClass()const=0;
    virtual const double FirstClass()const=0;
    virtual const double ExecutiveChairCar()const=0;
    virtual const double ACChairCar()const=0;
    virtual const double Sleeper()const=0;
    virtual const double SecondSitting()const=0;

    typedef DivyaangTypes<BlindType> Blind;
    typedef DivyaangTypes<TBType> TB;
    typedef DivyaangTypes<OHType> OH;
    typedef DivyaangTypes<CancerType> Cancer;
    typedef DivyaangTypes<NoneType> None;

};

template<typename T>
class DivyaangTypes:public Divyaang
{
    static const string sName;
    static const double sAC2TierConcessionFactor;
    static const double sAC3TierConcessionFactor;
    static const double sACFirstClassConcessionFactor;
    static const double sFirstClassConcessionFactor;
    static const double sExecutiveChairCarConcessionFactor;
    static const double sACChairCarConcessionFactor;
    static const double sSleeperConcessionFactor;
    static const double sSecondSittingConcessionFactor;
    
    DivyaangTypes<T>(const string name=sName):Divyaang(name){}

    public:
    const double AC2Tier()const;
    const double AC3Tier()const;
    const double ACFirstClass()const;
    const double FirstClass()const;
    const double ExecutiveChairCar()const;
    const double ACChairCar()const;
    const double Sleeper()const;
    const double SecondSitting()const;

    const Booking* createNewBooking(const Station&, const Station&,
            const Passenger*,const Date&, const BookingClasses&, const BookingCategory&)const;

    static const DivyaangTypes<T>& Type(){
        static const DivyaangTypes<T> theObj;
        return theObj;
    }

    const double  getConcessionFactor(const BookingClasses&)  const;

    friend const double BookingClasses::AC2Tier::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::AC3Tier::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::ACFirstClass::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::FirstClass::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::ExecutiveChairCar::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::ACChairCar::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::Sleeper::getConcessionFactor(const Divyaang&) const;
    friend const double BookingClasses::SecondSitting::getConcessionFactor(const Divyaang&) const;
};

template<typename T>
const double DivyaangTypes<T>::Sleeper()const{
    return DivyaangTypes<T>::sSleeperConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::ACFirstClass()const{
    return DivyaangTypes<T>::sACFirstClassConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::AC3Tier()const{
    return DivyaangTypes<T>::sAC3TierConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::AC2Tier()const{
    return DivyaangTypes<T>::sAC2TierConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::FirstClass()const{
    return DivyaangTypes<T>::sFirstClassConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::SecondSitting()const{
    return DivyaangTypes<T>::sSecondSittingConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::ExecutiveChairCar()const{
    return DivyaangTypes<T>::sExecutiveChairCarConcessionFactor;
}

template<typename T>
const double DivyaangTypes<T>::ACChairCar()const{
    return DivyaangTypes<T>::sACChairCarConcessionFactor;
}



#endif