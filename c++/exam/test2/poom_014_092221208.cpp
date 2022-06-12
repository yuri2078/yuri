#include <iostream>

class CDate
{
private:
    int Date_year;
    int Date_month;
    int Date_day;
public:
    CDate(int Date_year, int Date_month, int Date_day);
    void display(void);
};

CDate::CDate(int Date_year, int Date_month, int Date_day)
{
    this->Date_year = Date_year;
    this->Date_month = Date_month;
    this->Date_day = Date_day;
}

void CDate::display(void)
{
    std::cout << Date_year << "年" << Date_month << "月" << Date_day << "日\n";
    std::cout << "该对象的this指针是" << this << "\n";
    std::cout << "Date_year成员的起始地址:" << &this->Date_year << "\n";
    std::cout << "Date_month成员的起始地址:" << &this->Date_month << "\n";
    std::cout << "Date_day成员的起始地址:" << &this->Date_day << "\n";
}

int main()
{
    CDate date1(2021, 10, 9), date2(2022, 3, 13);
    date1.display();
    date2.display();
    return 0;
}