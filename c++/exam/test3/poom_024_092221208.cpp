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
    posts = "免费劳动力";
    money = 0;
}

void Employee::display(void)
{
    std::cout << posts << "编号:" << no << " 姓名:" << name << " 本月工资" << money << "\n";
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
    posts = "兼职人员";
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
    posts = "销售人员";
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
    posts = "销售经理";
    money = 6000 + sales * 0.01;
}

class  Manager : public Employee
{

public:
    Manager(int no, std::string name);
};

Manager::Manager(int no, std::string name) : Employee(no,name)
{
    posts = "公司经理";
    money = 10000;
}

int main()
{
    Technician t1(1001, "张技术", 6);
    t1.display();
    Salesman s1(1002, "销售王", 100000);
    s1.display();
    Manager m1(1003, "经理赵");
    m1.display();
    Salesmanager sale1(1004, "经理杨", 200000);
    sale1.display();
    return 0;
}