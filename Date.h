using namespace std;

class Date {
public:
    Date(int day, int month, int year);

    void operator=(Date &pOther);

    int getDay() {return day;};
    int getMonth() {return month;};
    int getYear() {return year;};
    int getCurrentDaysInTheMonth();
    int getDaysBetween(Date otherDate); //TODO

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
