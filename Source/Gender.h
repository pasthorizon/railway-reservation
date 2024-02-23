// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __GENDER_H
#define __GENDER_H

#include<string>
using namespace std;

//static subtyping of the gender class
template<typename T>
class GenderTypes;

class Gender{
    private:
    struct MaleType{};
    struct FemaleType{};
    
    protected:
    const string name_;
    Gender(const string name):name_(name){}
    ~Gender(){}
    
    public:
    static void UnitTestGender();
    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
    virtual const string getTitle()const =0;
    const string getName()const{
        return name_;
    }
    friend ostream& operator<<(ostream& cout,const Gender&);
   
};

template<typename T>
class GenderTypes:public Gender{
    static const string sName;
    static const string sSalutation;

    GenderTypes<T>(const string name=GenderTypes<T>::sName):Gender(name){}
    public:
    ~GenderTypes<T>(){}
    static const GenderTypes<T>& Type(){
        static const GenderTypes<T> theObject;
        return theObject;
    }
    const string getTitle()const{
        return GenderTypes<T>::sSalutation;
    }
    
};

#endif