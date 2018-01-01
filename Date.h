using namespace std;

class Date {
public:
    Date(int day, int month, int year);

    int getDay() {return day;};
    int getMonth() {return month;};
    int getYear() {return year;};
    int getDaysInTheCurrentMonth();
    int getDaysBetween(Date otherDate); //TODO

    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    bool operator<(Date &pOther);
    bool operator<=(Date &pOther);
    bool operator==(Date &pOther);
    bool operator>(Date &pOther);
    bool operator>=(Date &pOther);

    Date newDateByOffsetInDays(int offsetInDays);

private:
    int year;
    int month;
    int day;

    bool yearIsLeap();
};
