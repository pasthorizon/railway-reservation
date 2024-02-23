// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __STATION_H
#define __STATION_H

class Station{
    const string name_;
    //blocking the copy assignment constructor
    Station& operator=(const Station&);
    //constructor to build object with given name
    Station(const string name);
    public:
    //unit test function made static to test without object creation
    static void UnitTestStation();
    
    //copy constructor
    Station(const Station&);
    //const function returning name
    const string GetName()const;
    //const function returning distance from another station
    int getDistance(const string other)const;
    friend ostream& operator<<(ostream& cout,const Station& station);
    static const Station* CreateStation(const string name);
};

#endif