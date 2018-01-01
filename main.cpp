#include <iostream>
#include "Date.h"

int main()
{
    Date d(11, 5, 2018);
    Date d1(23, 11, 2020);
    Date d2(2, 4, 2000);
    Date d3(4, 1, 1900);
    Date d4(5, 6, 2018);
    Date d5(12, 5, 2018);
    cout<<d.getYear()<<" "<<d.getMonth()<<" "<<d.getDay()<<"\n";
 //   d = d1;
    d = d.newDateByOffsetInDays(-130);
    cout<<d.getYear()<<" "<<d.getMonth()<<" "<<d.getDay()<<"\n";
    cout<<"d < d1  "<<(d < d1)<<endl;
    cout<<"d2 < d3 "<<(d2 < d3)<<endl;
    cout<<"d3 < d3 "<<(d3 < d3)<<endl;
    cout<<"d < d4  " << (d < d4) << endl;
    cout<<"d < d5  " << (d < d5) << endl;
    cout<<"---------------------------------"<<endl;
    cout<<"d > d1  "<<(d > d1)<<endl;
    cout<<"d2 > d3 "<<(d2 > d3)<<endl;
    cout<<"d3 > d3 "<<(d3 > d3)<<endl;
    cout<<"d > d4  " << (d > d4) << endl;
    cout<<"d > d5  " << (d > d5) << endl;

    cout<<d.getDaysInTheCurrentMonth()<<endl;
    return 0;
}
