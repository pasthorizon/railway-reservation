// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None


//forward declaring the minmax  function implemented in the Railways Class
pair<string,string> minmax(string a,string b);

//Static constants related to BookingClass Types
//these constants can be easily chaged from here without
///having to compile the entire code base again
//*********************************************************************************************
template<>
const string BookingClasses::ExecutiveChairCar::sName="Executive Chair Car";
template<>
const double BookingClasses::ExecutiveChairCar::sFareLoadFactor=5;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsBerth=false;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsAC=true;
template<>
const unsigned int BookingClasses::ExecutiveChairCar::sNoOfBerths=0;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsLuxury=true;
template<>
const double BookingClasses::ExecutiveChairCar::sReservationCharge=60;

template<>
const double BookingClasses::ExecutiveChairCar::sTatkalRate=0.3;
template<>
const double BookingClasses::ExecutiveChairCar::sMinTatkalCharge=400;
template<>
const double BookingClasses::ExecutiveChairCar::sMaxTatkalCharge=500;
template<>
const unsigned int BookingClasses::ExecutiveChairCar::sMinTatkalDistance=250;


template<>
const string BookingClasses::FirstClass::sName="First Class";
template<>
const double BookingClasses::FirstClass::sFareLoadFactor=3;
template<>
const bool BookingClasses::FirstClass::sIsBerth=true;
template<>
const bool BookingClasses::FirstClass::sIsAC=false;
template<>
const unsigned int BookingClasses::FirstClass::sNoOfBerths=2;
template<>
const bool BookingClasses::FirstClass::sIsLuxury=true;
template<>
const double BookingClasses::FirstClass::sReservationCharge=50;

template<>
const double BookingClasses::FirstClass::sTatkalRate=0.3;
template<>
const double BookingClasses::FirstClass::sMinTatkalCharge=400;
template<>
const double BookingClasses::FirstClass::sMaxTatkalCharge=500;
template<>
const unsigned int BookingClasses::FirstClass::sMinTatkalDistance=500;


template<>
const string BookingClasses::AC2Tier::sName="AC 2 Tier";
template<>
const double BookingClasses::AC2Tier::sFareLoadFactor=4;
template<>
const bool BookingClasses::AC2Tier::sIsBerth=true;
template<>
const bool BookingClasses::AC2Tier::sIsAC=true;
template<>
const unsigned int BookingClasses::AC2Tier::sNoOfBerths=2;
template<>
const bool BookingClasses::AC2Tier::sIsLuxury=false;
template<>
const double BookingClasses::AC2Tier::sReservationCharge=50;

template<>
const double BookingClasses::AC2Tier::sTatkalRate=0.3;
template<>
const double BookingClasses::AC2Tier::sMinTatkalCharge=400;
template<>
const double BookingClasses::AC2Tier::sMaxTatkalCharge=500;
template<>
const unsigned int BookingClasses::AC2Tier::sMinTatkalDistance=500;


template<>
const string BookingClasses::AC3Tier::sName="AC 3 Tier";
template<>
const double BookingClasses::AC3Tier::sFareLoadFactor=2.5;
template<>
const bool BookingClasses::AC3Tier::sIsBerth=true;
template<>
const bool BookingClasses::AC3Tier::sIsAC=true;
template<>
const unsigned int BookingClasses::AC3Tier::sNoOfBerths=3;
template<>
const bool BookingClasses::AC3Tier::sIsLuxury=false;
template<>
const double BookingClasses::AC3Tier::sReservationCharge=40;

template<>
const double BookingClasses::AC3Tier::sTatkalRate=0.3;
template<>
const double BookingClasses::AC3Tier::sMinTatkalCharge=300;
template<>
const double BookingClasses::AC3Tier::sMaxTatkalCharge=400;
template<>
const unsigned int BookingClasses::AC3Tier::sMinTatkalDistance=500;


template<>
const string BookingClasses::ACFirstClass::sName="AC First Class";
template<>
const double BookingClasses::ACFirstClass::sFareLoadFactor=6.5;
template<>
const bool BookingClasses::ACFirstClass::sIsBerth=true;
template<>
const bool BookingClasses::ACFirstClass::sIsAC=true;
template<>
const unsigned int BookingClasses::ACFirstClass::sNoOfBerths=2;
template<>
const bool BookingClasses::ACFirstClass::sIsLuxury=true;
template<>
const double BookingClasses::ACFirstClass::sReservationCharge=60;

template<>
const double BookingClasses::ACFirstClass::sTatkalRate=0.3;
template<>
const double BookingClasses::ACFirstClass::sMinTatkalCharge=400;
template<>
const double BookingClasses::ACFirstClass::sMaxTatkalCharge=500;
template<>
const unsigned int BookingClasses::ACFirstClass::sMinTatkalDistance=500;



template<>
const string BookingClasses::Sleeper::sName="Sleeper";
template<>
const double BookingClasses::Sleeper::sFareLoadFactor=1;
template<>
const bool BookingClasses::Sleeper::sIsBerth=true;
template<>
const bool BookingClasses::Sleeper::sIsAC=false;
template<>
const unsigned int BookingClasses::Sleeper::sNoOfBerths=3;
template<>
const bool BookingClasses::Sleeper::sIsLuxury=false;
template<>
const double BookingClasses::Sleeper::sReservationCharge=20;

template<>
const double BookingClasses::Sleeper::sTatkalRate=0.3;
template<>
const double BookingClasses::Sleeper::sMinTatkalCharge=100;
template<>
const double BookingClasses::Sleeper::sMaxTatkalCharge=200;
template<>
const unsigned int BookingClasses::Sleeper::sMinTatkalDistance=500;

template<>
const string BookingClasses::SecondSitting::sName="Second Sitting";
template<>
const double BookingClasses::SecondSitting::sFareLoadFactor=0.6;
template<>
const bool BookingClasses::SecondSitting::sIsBerth=false;
template<>
const bool BookingClasses::SecondSitting::sIsAC=false;
template<>
const unsigned int BookingClasses::SecondSitting::sNoOfBerths=0;
template<>
const bool BookingClasses::SecondSitting::sIsLuxury=false;
template<>
const double BookingClasses::SecondSitting::sReservationCharge=15;

template<>
const double BookingClasses::SecondSitting::sTatkalRate=0.1;
template<>
const double BookingClasses::SecondSitting::sMinTatkalCharge=10;
template<>
const double BookingClasses::SecondSitting::sMaxTatkalCharge=15;
template<>
const unsigned int BookingClasses::SecondSitting::sMinTatkalDistance=100;

template<>
const string BookingClasses::ACChairCar::sName="AC Chair Car";
template<>
const double BookingClasses::ACChairCar::sFareLoadFactor=2;
template<>
const bool BookingClasses::ACChairCar::sIsBerth=false;
template<>
const bool BookingClasses::ACChairCar::sIsAC=true;
template<>
const unsigned int BookingClasses::ACChairCar::sNoOfBerths=0;
template<>
const bool BookingClasses::ACChairCar::sIsLuxury=false;
template<>
const double BookingClasses::ACChairCar::sReservationCharge=40;

template<>
const double BookingClasses::ACChairCar::sTatkalRate=0.3;
template<>
const double BookingClasses::ACChairCar::sMinTatkalCharge=125;
template<>
const double BookingClasses::ACChairCar::sMaxTatkalCharge=225;
template<>
const unsigned int BookingClasses::ACChairCar::sMinTatkalDistance=500;

//*****************************************************************************************************************


//static constants related to the Divyaang Types
//*******************************************************************************************************************

template<> const string Divyaang::None::sName="None";
template<> const double Divyaang::None::sAC2TierConcessionFactor=0;
template<> const double Divyaang::None::sAC3TierConcessionFactor=0;
template<> const double Divyaang::None::sACChairCarConcessionFactor=0;
template<> const double Divyaang::None::sACFirstClassConcessionFactor=0;
template<> const double Divyaang::None::sFirstClassConcessionFactor=0;
template<> const double Divyaang::None::sExecutiveChairCarConcessionFactor=0;
template<> const double Divyaang::None::sSleeperConcessionFactor=0;
template<> const double Divyaang::None::sSecondSittingConcessionFactor=0;


template<> const string Divyaang::TB::sName="Tuberculosis Type";
template<> const double Divyaang::TB::sAC2TierConcessionFactor=0;
template<> const double Divyaang::TB::sAC3TierConcessionFactor=0;
template<> const double Divyaang::TB::sACChairCarConcessionFactor=0;
template<> const double Divyaang::TB::sACFirstClassConcessionFactor=0.75;
template<> const double Divyaang::TB::sFirstClassConcessionFactor=0;
template<> const double Divyaang::TB::sExecutiveChairCarConcessionFactor=0;
template<> const double Divyaang::TB::sSleeperConcessionFactor=0.75;
template<> const double Divyaang::TB::sSecondSittingConcessionFactor=0.75;


template<> const string Divyaang::OH::sName="Orthopaedic Handicap Type";
template<> const double Divyaang::OH::sAC2TierConcessionFactor=0.5;
template<> const double Divyaang::OH::sAC3TierConcessionFactor=0.75;
template<> const double Divyaang::OH::sACChairCarConcessionFactor=0.75;
template<> const double Divyaang::OH::sACFirstClassConcessionFactor=0.5;
template<> const double Divyaang::OH::sFirstClassConcessionFactor=0.75;
template<> const double Divyaang::OH::sExecutiveChairCarConcessionFactor=0.75;
template<> const double Divyaang::OH::sSleeperConcessionFactor=0.75;
template<> const double Divyaang::OH::sSecondSittingConcessionFactor=0.75;


template<> const string Divyaang::Cancer::sName="Cancer Type";
template<> const double Divyaang::Cancer::sAC2TierConcessionFactor=0.5;
template<> const double Divyaang::Cancer::sAC3TierConcessionFactor=1;
template<> const double Divyaang::Cancer::sACChairCarConcessionFactor=1;
template<> const double Divyaang::Cancer::sACFirstClassConcessionFactor=0.5;
template<> const double Divyaang::Cancer::sFirstClassConcessionFactor=0.75;
template<> const double Divyaang::Cancer::sExecutiveChairCarConcessionFactor=0.75;
template<> const double Divyaang::Cancer::sSleeperConcessionFactor=1;
template<> const double Divyaang::Cancer::sSecondSittingConcessionFactor=1;


template<> const string Divyaang::Blind::sName="Blind Type";
template<> const double Divyaang::Blind::sAC2TierConcessionFactor=0.5;
template<> const double Divyaang::Blind::sAC3TierConcessionFactor=0.75;
template<> const double Divyaang::Blind::sACChairCarConcessionFactor=0.75;
template<> const double Divyaang::Blind::sACFirstClassConcessionFactor=0.5;
template<> const double Divyaang::Blind::sFirstClassConcessionFactor=0.75;
template<> const double Divyaang::Blind::sExecutiveChairCarConcessionFactor=0.75;
template<> const double Divyaang::Blind::sSleeperConcessionFactor=0.75;
template<> const double Divyaang::Blind::sSecondSittingConcessionFactor=0.75;


//***********************************************************************************************************


//Railways master data
//********************************************************************************************************************
map<const string, const Station*> Railways::sMasterStations={make_pair("Chennai",Station::CreateStation("Chennai")),
                                                     make_pair("Delhi",Station::CreateStation("Delhi")),
                                                     make_pair("Mumbai",Station::CreateStation("Mumbai")),                                          
                                                     make_pair("Banglore",Station::CreateStation("Banglore")),
                                                     make_pair("Kolkata",Station::CreateStation("Kolkata"))
                                                     };

const map<pair<const Station*,const Station*>,int> Railways::sMasterDistances={
    make_pair(make_pair(Railways::sMasterStations[minmax("Delhi","Mumbai").first],Railways::sMasterStations[minmax("Delhi","Mumbai").second]),1447),
    make_pair(make_pair(Railways::sMasterStations[minmax("Banglore","Mumbai").first],Railways::sMasterStations[minmax("Banglore","Mumbai").second]),981),
    make_pair(make_pair(Railways::sMasterStations[minmax("Kolkata","Mumbai").first],Railways::sMasterStations[minmax("Kolkata","Mumbai").second]),2014),
    make_pair(make_pair(Railways::sMasterStations[minmax("Chennai","Mumbai").first],Railways::sMasterStations[minmax("Chennai","Mumbai").second]),1338),
    make_pair(make_pair(Railways::sMasterStations[minmax("Delhi","Banglore").first],Railways::sMasterStations[minmax("Delhi","Banglore").second]),2150),
    make_pair(make_pair(Railways::sMasterStations[minmax("Delhi","Kolkata").first],Railways::sMasterStations[minmax("Delhi","Kolkata").second]),1472),
    make_pair(make_pair(Railways::sMasterStations[minmax("Delhi","Chennai").first],Railways::sMasterStations[minmax("Delhi","Chennai").second]),2180),
    make_pair(make_pair(Railways::sMasterStations[minmax("Kolkata","Banglore").first],Railways::sMasterStations[minmax("Kolkata","Banglore").second]),1871),
    make_pair(make_pair(Railways::sMasterStations[minmax("Chennai","Banglore").first],Railways::sMasterStations[minmax("Chennai","Banglore").second]),350),
    make_pair(make_pair(Railways::sMasterStations[minmax("Chennai","Kolkata").first],Railways::sMasterStations[minmax("Chennai","Kolkata").second]),1659)
};
//*****************************************************************************************************************************************************************