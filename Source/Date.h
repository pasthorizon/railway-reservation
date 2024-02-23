// ***** Author: Seemant Achari
// ***** Roll No. 19CS10055
// ***** Date: 07-Mar-2021
// ***** Version: 1.0
// ***** Known bugs: None

#ifndef __DATE_H
#define __DATE_H


class Date {
    //Enum to access array elements by names
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
    
    //array of the names of months and days
    static const char monthNames[][4];
    static const char dayNames[][10];


    typedef unsigned int UINT;
    const UINT date_; Month month_; UINT year_;
    static void checkStringValidity(const string strDate);
    static void checkDateValidity(UINT d,UINT m,UINT y);
    //constructor to assign values
    Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y){}
    public:
    static void UnitTestDate();
    Date(const Date& D) : date_(D.date_), month_(D.month_), year_(D.year_){}
    static const Date CreateDate(const string strDate);
    bool inYearSpan()const;
    int getAge() const;
    bool isPast() const;
    ~Date() {}
    
    friend ostream& operator<<(ostream& cout,const Date& obj){
        cout << obj.date_ << "/" << monthNames[obj.month_ - 1] << "/" << obj.year_ << endl; 
        return cout;
    }
    
};

#endif