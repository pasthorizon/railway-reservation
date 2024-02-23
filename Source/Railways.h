// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 09-Apr-2021
// ***** Version: 1.0
// ***** Known bugs: None
#ifndef __RAILWAYS_H
#define __RAILWAYS_H

#include<map>
#include"Stations.h"
#include"Exceptions.h"

class Railways{
    static const string sName;
    static map<const string, const Station*> sStations;
    static map<pair<const Station*,const Station*>,int> sDistances;
    
    //master data to be validated before the construction of the Railways
    static map<const string, const Station*> sMasterStations;
    static const map<pair<const Station*,const Station*>,int> sMasterDistances;

    //private method Create Railways to call the validate 
    //function and the constructor
    static const Railways& CreateRailways();
    static void Validate(); 

    //making the constructor private for Meyer's method implementation
    Railways();
    //blocking the copy constructor and the
    //copy assignment constructor
    Railways(const Railways&);
    Railways& operator=(const Railways&);
    public:
    ~Railways();
    //unit test function made static to test without object creation
    static void UnitTestRailways();
    //singleton class returner
    static const Railways& TheRailways(){
        try{
            return CreateRailways();
        }
        catch(const Bad_railways& e){
            throw;
        }
    }
    //returns distance between any two pairs
    int getDistance(const string a,const string b)const;
    static void ValidatePath(const Station& A, const Station& B);

    //output streaming
    friend ostream& operator<<(ostream& cout, const Railways& railways);
    
};

#endif