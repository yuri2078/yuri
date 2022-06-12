#include <iostream>
class Time; 
class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day);
    friend void display(Date *d1, Time *t1);
};

Date::Date(int day, int month, int year)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

class Time
{
private:
    int hour;
    int minute;
    int sec;
public:
    friend void display(Date *d1, Time *t1);
    Time(int hour, int minute, int sec);
};

Time::Time(int hour, int minute, int sec)
{
    this->hour = hour;
    this->minute = minute;
    this->sec = sec;
}

void display(Date *d1, Time *t1)
{
    std::cout << d1->year << "Äê" << d1->month << "ÔÂ" << d1->day << "ÈÕ";
    std::cout << t1->hour << ":" << t1->minute << ":" << t1->sec << "\n";
}

int main()
{
    Date d1(4,25,2022);
    Time t1(10,13,56);
    display(&d1, &t1);
    return 0;
}