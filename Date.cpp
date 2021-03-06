#include "Date.h"

Date::Date(int day, int month, int year)
{
    if(!setDay(day))
        this->day = 1;
    if(!setMonth(month))
        this->month = 1;
    if(!setYear(year))
        this->year = 1900;
}


int Date::getDaysInTheCurrentMonth()
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
    Date dateCounter(day, month, year);

    if(dateCounter < otherDate)
    {
        while(dateCounter.getYear() < otherDate.getYear())
        {
            daysCounted += dateCounter.getDaysInTheCurrentMonth() - dateCounter.day;
            dateCounter.day = dateCounter.getDaysInTheCurrentMonth();

            if(!dateCounter.setMonth(dateCounter.getMonth() + 1))
            {
                dateCounter.month = 1;
                dateCounter.setYear(dateCounter.year + 1);
            }

            dateCounter.day = 0;
        }

        while(dateCounter.getMonth() < otherDate.getMonth())
        {
            daysCounted += dateCounter.getDaysInTheCurrentMonth() - dateCounter.day;
            dateCounter.day = dateCounter.getDaysInTheCurrentMonth();

            if(dateCounter.getMonth() < otherDate.getMonth())
            {
                dateCounter.setMonth(dateCounter.month + 1);
            }

            dateCounter.day = 0;
        }

        while(dateCounter.getDay() < otherDate.getDay())
        {
            daysCounted += otherDate.getDay() - dateCounter.getDay();
            dateCounter.setDay(otherDate.day);
        }

    }
    else
    {
        while(dateCounter.getYear() > otherDate.getYear())
        {
            daysCounted += dateCounter.day;

            if(!dateCounter.setMonth(dateCounter.getMonth() - 1))
            {
                dateCounter.setMonth(12);
                dateCounter.setYear(dateCounter.year - 1);
            }

            dateCounter.day = dateCounter.getDaysInTheCurrentMonth();

        }

        while(dateCounter.getMonth() > otherDate.getMonth())
        {
            daysCounted += dateCounter.day;

            if(dateCounter.getMonth() > otherDate.getMonth())
            {
                dateCounter.setMonth(dateCounter.month - 1);
            }

            dateCounter.day = dateCounter.getDaysInTheCurrentMonth();
        }

        while(dateCounter.getDay() > otherDate.getDay())
        {
            daysCounted += dateCounter.getDay() - otherDate.getDay();
            dateCounter.setDay(otherDate.day);
        }
    }

    return daysCounted;
}


bool Date::setDay(int day)
{
    if(day > 0 && day <= getDaysInTheCurrentMonth())
    {
        this->day = day;
        return true;
    }

    else
        return false;
}

bool Date::setMonth(int month)
{
    if(month > 0 && month < 13)
    {
        this->month = month;
        return true;
    }

    else
        return false;
}

bool Date::setYear(int year)
{
    this->year = year;
    return true;
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


Date Date::newDateByOffsetInDays(int offsetInDays)
{
    int remainingOffset = offsetInDays;
    Date newDate(day, month, year);

    if(remainingOffset >= 0)
    {

        // Initial

        if(remainingOffset > newDate.getDaysInTheCurrentMonth() - newDate.day)
        {
            int oldDay = newDate.day;
            newDate.day = newDate.getDaysInTheCurrentMonth();
            remainingOffset =  remainingOffset - (newDate.getDaysInTheCurrentMonth() - oldDay);
        }
        else
        {
            newDate.day += remainingOffset;
            remainingOffset = 0;
        }

        // Main loop

        while(remainingOffset > 0)
        {
            if(!newDate.setMonth(newDate.month + 1))
            {
                newDate.setYear(newDate.year + 1);
                newDate.setMonth(1);
            }
            newDate.day = 0;


            if(remainingOffset > newDate.getDaysInTheCurrentMonth())
            {
                newDate.day = newDate.getDaysInTheCurrentMonth();
                remainingOffset -= newDate.getDaysInTheCurrentMonth();
            }
            else
            {
                newDate.day += remainingOffset;
                remainingOffset = 0;
            }
        }
    }
    else
    {
        // Initial
        remainingOffset = remainingOffset*(-1);

        if(remainingOffset > (newDate.day - 1))
        {
            int oldDay = newDate.day;
            newDate.day = 1;
            remainingOffset = remainingOffset - (oldDay - 1);
        }
        else
        {
            newDate.day -= remainingOffset;
            remainingOffset = 0;
        }

        // Main loop

        while(remainingOffset > 0)
        {
            if(!newDate.setMonth(newDate.month - 1))
            {
                newDate.setYear(newDate.year - 1);
                newDate.setMonth(12);
            }
            newDate.day = newDate.getDaysInTheCurrentMonth() + 1;

            if(remainingOffset > newDate.getDaysInTheCurrentMonth())
            {
                newDate.day = 1;
                remainingOffset -= newDate.getDaysInTheCurrentMonth();
            }
            else
            {
                newDate.day -= remainingOffset;
                remainingOffset = 0;
            }
        }
    }

    return newDate;
}

