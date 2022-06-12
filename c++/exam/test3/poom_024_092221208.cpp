#include <iostream>
class Employee
{
protected:
    int no;
    std::string name;
    std::string posts;
    double money;
public:
    Employee(int no, std::string name);
    void display(void);
};
Employee::Employee(int no, std::string name)
{
    this->no = no;
    this->name = name;
    posts = "����Ͷ���";
    money = 0;
}

void Employee::display(void)
{
    std::cout << posts << "���:" << no << " ����:" << name << " ���¹���" << money << "\n";
}

class Technician : public Employee
{
private:
    double wordTime;

public:
    Technician(int no, std::string name, double money);
};

Technician::Technician(int no, std::string name, double wordTime) : Employee(no,name)
{
    posts = "��ְ��Ա";
    money = wordTime * 150;
}

class Salesman : public Employee
{
private:
    double sales;

public:
    Salesman(int no, std::string name, double sales);
};

Salesman::Salesman(int no, std::string name, double sales) : Employee(no,name)
{
    posts = "������Ա";
    money = sales*0.05;
}

class Salesmanager : public Employee
{
private:
    double sales;

public:
    Salesmanager(int no, std::string name, double sales);
};

Salesmanager::Salesmanager(int no, std::string name, double sales) : Employee(no,name)
{
    posts = "���۾���";
    money = 6000 + sales * 0.01;
}

class  Manager : public Employee
{

public:
    Manager(int no, std::string name);
};

Manager::Manager(int no, std::string name) : Employee(no,name)
{
    posts = "��˾����";
    money = 10000;
}

int main()
{
    Technician t1(1001, "�ż���", 6);
    t1.display();
    Salesman s1(1002, "������", 100000);
    s1.display();
    Manager m1(1003, "������");
    m1.display();
    Salesmanager sale1(1004, "������", 200000);
    sale1.display();
    return 0;
}