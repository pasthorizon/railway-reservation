// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#include<iostream>
#include<string>
#include<map>
#include<unordered_set>
#include"Exceptions.h"

using namespace std;
#include"Stations.h"
#include"Railways.h"

//to return the string pair in ascending order
pair<string,string> minmax(string a,string b){
    if(a>b) return make_pair(b,a);
    return make_pair(a,b);
}

//Initialising the static variables

const string Railways::sName="Indian Railways";
map<const string, const Station*> Railways::sStations;
map<pair<const Station*,const Station*>,int> Railways::sDistances;




//releasing all the dynamically alloted memory to the stations
Railways::~Railways(){
    for(auto iter=Railways::sStations.begin();iter!=Railways::sStations.end();iter++)
    delete (*iter).second;
}

Railways::Railways(){
    
    Railways::sStations=sMasterStations;
    Railways::sDistances=sMasterDistances;
}

const Railways& Railways::CreateRailways(){
    try{
        Validate();
        static const Railways theObject;
        return theObject;
    }
    catch(const Bad_railways& e){
        throw;
    }
}

//Returns the distance between a pair of stations
//The order of the strings is handled by using the minmax function above
int Railways::getDistance(const string a,const string b)const{
    try{
        ValidatePath(*Station::CreateStation(a),*Station::CreateStation(b));
    }
    catch(const Bad_booking&){
        throw;
    }
    return Railways::sDistances[make_pair(sStations[minmax(a,b).first],sStations[minmax(a,b).second])];
    
}

//output stream overload
ostream& operator<<(ostream& cout, const Railways& railways){
    cout<<"Name: "<<railways.sName<<endl<<endl;
    for(auto iter=railways.sStations.begin();iter!=railways.sStations.end();iter++)
    cout<<"Sation name: "<<" "<<iter->first<<endl;
    cout<<endl;
    cout<<endl<<"Distances:\n";
    for(auto iter=railways.sDistances.begin();iter!=railways.sDistances.end();iter++)
    cout<<(*iter).first.first->GetName()<<" "<<(*iter).first.second->GetName()<<" "<<(*iter).second<<endl;
    return cout;
}

void Railways::Validate(){
    unordered_set<string> stations;
    map<pair<string,string>,int> distances;
    // cout<<sMasterStations.size()<<endl;
    for(auto x=sMasterStations.begin();x!=sMasterStations.end();x++)
    {
        if(stations.find(x->first)!=stations.end())
        throw duplicate_stations();
        else stations.insert(x->first);
    }

    for(auto x=sMasterDistances.begin();x!=sMasterDistances.end();x++)
    {
        pair<string,string> pairs=make_pair(x->first.first->GetName(),x->first.second->GetName());
        if(distances.find(pairs)!=distances.end())
        throw duplicate_stationpairs();
        else distances.insert(make_pair(pairs,1));
    }

}

void Railways::ValidatePath(const Station& A, const Station& B){
    
    if(Railways::sStations.find(A.GetName())==Railways::sStations.end()||Railways::sStations.find(B.GetName())==Railways::sStations.end())
    throw invalid_stations();
    string a=minmax(A.GetName(),B.GetName()).first,b=minmax(A.GetName(),B.GetName()).second;
    
    pair<const Station*,const Station*> check=make_pair(Railways::sStations[a],Railways::sStations[b]);
    if(Railways::sDistances.find(check)==Railways::sDistances.end())
    throw invalid_stations();

}

