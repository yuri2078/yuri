#include <iostream>

class Date
{
private:
    int year, month, day;
public:
    Date(); //默认值
    Date(int year, int month, int day); //有参构造函数
    Date(const Date &b); //拷贝构造函数
    void show(void);
};

class Student 
{
private:
    Date birth;
    std::string name;
    int id;
public:
    Student(std::string name, int id, int year, int month, int day);
    void show(void);
};

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    std::cout << "Birth类构造函数\n";
}

Date::Date()
{
    year = month = day = 0; 
}

Date::Date(const Date &b)
{
    year = b.year;
    month = b.month;
    day = b.day;
}

void Date::show(void)
{
    std::cout << year << '-' << month << '-' << day;
}

Student::Student(std::string name, int id, int year, int month, int day)
{
    this->name = name;
    this->id = id;
    Date b(year, month, day);
    birth = b;
    std::cout << "Student类构造函数\n";
}

void Student::show(void)
{
    std::cout << "姓名：" << name << "\n";
    std::cout << "学号：" << id << "\n";
    std::cout << "出生日期：";
    birth.show();
}

int main()
{
    Student stu("lili",10002,2000,1,1);
    stu.show();
    return 0;
}