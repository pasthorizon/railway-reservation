// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __BOOKINGCLASSES_H
#define __BOOKINGCLASSES_H

#include<string>
using namespace std;

template<typename T>
class BookingClassType;

//forward defining the Divyaang class
class Divyaang;


//static subtyping the Booking class types
class BookingClasses{
    struct ACFirstClassType{};
    struct ExecutiveChairCarType{};
    struct AC2TierType{};
    struct FirstClassType{};
    struct AC3TierType{};
    struct ACChairCarType{};
    struct SleeperType{};
    struct SecondSittingType{};

    protected:
    const string name_;
    BookingClasses(const string name):name_(name){}
    
    public:
    static void UnitTestBookingClasses();

    virtual const double getLoadFactor() const=0;
    virtual const bool isBerth() const=0;
    virtual const bool isAC() const =0;
    virtual const unsigned int getTiers() const =0;
    virtual const bool isLuxury() const=0;
    virtual const double getReservationCharge() const=0;
    virtual const double getPremiumCharge()const=0;
    virtual const double getMinTatkalCharge()const=0;
    virtual const double getMaxTatkalCharge()const=0;
    virtual const double getMinDistance()const=0;
    const string getName() const;

    virtual const double getConcessionFactor(const Divyaang&) const=0;

    typedef BookingClassType<ACFirstClassType> ACFirstClass;
    typedef BookingClassType<ExecutiveChairCarType> ExecutiveChairCar;
    typedef BookingClassType<AC2TierType> AC2Tier;
    typedef BookingClassType<FirstClassType> FirstClass;
    typedef BookingClassType<AC3TierType> AC3Tier;
    typedef BookingClassType<ACChairCarType> ACChairCar;
    typedef BookingClassType<SleeperType> Sleeper;
    typedef BookingClassType<SecondSittingType> SecondSitting;


    friend ostream& operator<<(ostream& cout, const BookingClasses&);
};

template<typename T>
class BookingClassType:public BookingClasses{
    static const string sName;
    static const double sFareLoadFactor;
    static const bool sIsBerth;
    static const bool sIsAC;
    static const unsigned int sNoOfBerths;
    static const bool sIsLuxury;
    static const double sReservationCharge;
    
    static const double sTatkalRate;
    static const double sMinTatkalCharge;
    static const double sMaxTatkalCharge;
    static const unsigned int sMinTatkalDistance;

    BookingClassType<T>(const string name=BookingClassType<T>::sName):BookingClasses(name){}
    public:
    const double getLoadFactor() const;
    const bool isBerth() const;
    const bool isAC() const;
    const unsigned int getTiers() const;
    const bool isLuxury() const;
    const double getReservationCharge() const;
    const double getConcessionFactor(const Divyaang&) const;
    const double getPremiumCharge()const;
    const double getMinTatkalCharge()const;
    const double getMaxTatkalCharge()const;
    const double getMinDistance()const;

    static const BookingClassType<T>& Type(){
        static const BookingClassType<T> theObject;
        return theObject;
    }
};


//implemented in the header because of the dynamic binding nature
template<typename T>
const double BookingClassType<T>::getLoadFactor() const{
    return BookingClassType<T>::sFareLoadFactor;
}

template<typename T>
const bool BookingClassType<T>::isBerth() const{
    return BookingClassType<T>::sIsBerth;
}

template<typename T>
const bool BookingClassType<T>::isAC() const{
    return BookingClassType<T>::sIsAC;
}

template<typename T>
const unsigned int BookingClassType<T>::getTiers() const{
    return BookingClassType<T>::sNoOfBerths;
}

template<typename T>
const bool BookingClassType<T>::isLuxury() const{
    return BookingClassType<T>::sIsLuxury;
}

template<typename T>
const double BookingClassType<T>::getReservationCharge() const{
    return BookingClassType<T>::sReservationCharge;
}

template<typename T>
const double BookingClassType<T>::getPremiumCharge() const{
    return BookingClassType<T>::sTatkalRate;
}

template<typename T>
const double BookingClassType<T>::getMinTatkalCharge() const{
    return BookingClassType<T>::sMinTatkalCharge;
}

template<typename T>
const double BookingClassType<T>::getMaxTatkalCharge() const{
    return BookingClassType<T>::sMaxTatkalCharge;
}

template<typename T>
const double BookingClassType<T>::getMinDistance() const{
    return BookingClassType<T>::sMinTatkalDistance;
}



#endif