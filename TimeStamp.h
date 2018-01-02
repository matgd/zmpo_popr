#include "Date.h"

class TimeStamp : public Date
{
public:
    TimeStamp(int minute, int hour, int day, int month, int year);

    bool operator<(TimeStamp &pOther);
    bool operator<=(TimeStamp &pOther);
    bool operator==(TimeStamp &pOther);
    bool operator>(TimeStamp &pOther);
    bool operator>=(TimeStamp &pOther);

    long long int differenceInMinutes(TimeStamp otherTimestamp);
    long long int getMinutesBetween(TimeStamp otherTimeStamp);

    TimeStamp newTimeStampByOffsetInHours(int hours);

private:
    int hour;
    int minute;
};
