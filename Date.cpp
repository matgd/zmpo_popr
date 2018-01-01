#include "Date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}


void Date::operator=(Date &pOther)
{
    day = pOther.getDay();
    month = pOther.getMonth();
    year = pOther.getYear();
}


int Date::getCurrentDaysInTheMonth()
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 2:
        if(yearIsLeap())
            return 29;
        else
            return 28;

    default:
        return 30;
    }
}


int Date::getDaysBetween(Date otherDate)
{
    int daysCounted = 0;
    int dayCounter = day;
    int monthCounter = month;
    int yearCounter = year;

    return 0;

    // checked when other is later


}

bool Date::operator<(Date &pOther)
{
    if(year < pOther.getYear())
        return true;

    else if(year == pOther.getYear())

        if(month < pOther.getMonth())
            return true;

        else if(month == pOther.getMonth())

            if(day < pOther.getDay())
                return true;


    return false;
}

bool Date::operator<=(Date &pOther)
{
    if(*this == pOther)
        return true;

    else return (*this < pOther);
}

bool Date::operator==(Date &pOther)
{
    return ((day == pOther.getDay()) && (month == pOther.getMonth()) && (year == pOther.getYear()));
}

bool Date::operator>(Date &pOther)
{
    return !(*this <= pOther);
}

bool Date::operator>=(Date &pOther)
{
    return !(*this < pOther);
}

bool Date::yearIsLeap()
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
            return year % 400 == 0;

        return true;
    }

    return false;
}

