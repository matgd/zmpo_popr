#include <iostream>
#include "Date.h"

int main()
{
    Date d(11, 5, 2018);
    // d - d1  259
    Date d1(25, 1, 2019);
    Date d2(23, 1, 2019);
    Date dx(30, 5, 2018);
    cout<<d.getDay()<<"."<<d.getMonth()<<"."<<d.getYear()<<"\n";
   // d = d.newDateByOffsetInDays(259);
    cout<<d.getDay()<<"."<<d.getMonth()<<"."<<d.getYear()<<"\n";
    cout<<d.getDaysBetween(d1)<<endl;
    cout<<d1.getDaysBetween(d)<<endl;

    return 0;
}
