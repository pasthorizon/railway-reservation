#include"Gender.h"
#include<iostream>
using namespace std;

template<>
const string Gender::Male::sName="Male";
template<>
const string Gender::Female::sName="Female";
template<>
const string Gender::Male::sSalutation="Mr.";
template<>
const string Gender::Female::sSalutation="Mrs.";


ostream& operator<<(ostream& cout,const Gender& other)
{
        cout<<"+++Gender Class\n";
        cout<<"\tGender Name: "<<other.getName()<<endl;
        cout<<"\tGender Title: "<<other.getTitle()<<endl;
        return cout;
}
