// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include<string>
#include<iostream>
#include<map>
using namespace std;

#include"Stations.h"
#include"Railways.h"
#include"Exceptions.h"
//Constructor
Station::Station(const string name):name_(name){}
//Copy Constructor
Station::Station(const Station& obj):name_(obj.name_){}
const string Station::GetName() const{
    return name_;
}

//const function to return distance from another stations
//Uses info in the railways singleton class
int Station::getDistance(const string other)const{
    return Railways::TheRailways().getDistance(GetName(),other);
}

const Station* Station::CreateStation(const string name){
    if(name=="") throw Bad_stations();
    return new Station(name);
}

//output stream overload
ostream& operator<<(ostream& cout,const Station& station){
    cout<<"Station name: "<<station.name_<<endl;
    return cout;
}
