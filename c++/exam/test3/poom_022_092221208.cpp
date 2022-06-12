#include <iostream>
class Archives
{
private:
    int No, Age;
    std::string Name, Sex;

public:
    Archives(int No, std::string Name, std::string Sex, int Age);
    void show(void);
};

Archives::Archives(int No, std::string Name, std::string Sex, int Age)
{
    this->No = No;
    this->Name = Name;
    this->Sex = Sex;
    this->Age = Age;
}

void Archives::show(void)
{
    std::cout << "职工号:" << No << "   姓名：" << Name;
    std::cout  << "  性别：" << Sex << "  年龄：" << Age;
}

class Laborage : public Archives
{
private:
    int SSalary, Security, Fsalary;

public:
    Laborage(int No, std::string Name, std::string Sex, int Age, int SSalary, int Security);
    void Display(void);
};

Laborage::Laborage(int No, std::string Name, std::string Sex, int Age, int SSalary, int Security) : Archives(No, Name, Sex, Age)
{
    this->SSalary = SSalary;
    this->Security = Security;
    Fsalary = SSalary-Security;
}

void Laborage::Display(void)
{
    show();
    std::cout << "  应发工资：" << SSalary;
    std::cout << "  社保金：" << Security;
    std::cout << "  实发工资：" << Fsalary << "\n";
}

int main()
{
    Laborage l1(1001,"陈天天", "男", 21, 20000, 1000);
    l1.Display();
    Laborage l2(1002,"徐欣欣", "女", 25, 20000, 2900);
    l2.Display();
    Laborage l3(1003,"印梦清", "女", 28, 25000, 2200);
    l3.Display();
    return 0;
}