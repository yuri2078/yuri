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
    std::cout << "ְ����:" << No << "   ������" << Name;
    std::cout  << "  �Ա�" << Sex << "  ���䣺" << Age;
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
    std::cout << "  Ӧ�����ʣ�" << SSalary;
    std::cout << "  �籣��" << Security;
    std::cout << "  ʵ�����ʣ�" << Fsalary << "\n";
}

int main()
{
    Laborage l1(1001,"������", "��", 21, 20000, 1000);
    l1.Display();
    Laborage l2(1002,"������", "Ů", 25, 20000, 2900);
    l2.Display();
    Laborage l3(1003,"ӡ����", "Ů", 28, 25000, 2200);
    l3.Display();
    return 0;
}