#include <iostream>

class Student
{
private:
    int num;
    std::string name;
    std::string sex;
    std::string type;
    double score;
public:
    Student(int num,std::string name,std::string sex,double score);
    int Get_num(void) { return num; }
    std::string Get_name(void) { return name; }
    std::string Get_sex(void) { return sex; }
    void display(void);
};

Student::Student(int num,std::string name,std::string sex,double score)
{
    this->num = num;
    this->name = name;
    this->sex = sex;
    this->score = score;
    type = "ѧ��";
}

void Student::display(void)
{
    std::cout << type << "��\n";
    std::cout << "ѧ��:" << num << ",����:" << name << ",�Ա�:" << sex << ",����:" << score << "\n\n";
}

class Teacher
{
private:
    int num;
    std::string name;
    std::string sex;
    std::string type;
    double pay;
public:
    Teacher() {}
    Teacher(Student *student);
    Teacher(int num,std::string name,std::string sex,double pay);
    int Get_num(void) { return num; }
    std::string Get_name(void) { return name; }
    std::string Get_sex(void) { return sex; }
    void display(void);
};

Teacher::Teacher(Student *student)
{
    num = student->Get_num();
    name = student->Get_name();
    sex = student->Get_sex();
    pay = 2500;
    type = "��ҵ��У";
}

Teacher::Teacher(int num,std::string name,std::string sex,double pay)
{
    this->num = num;
    this->name = name;
    this->sex = sex;
    this->pay = pay;
    type = "��ʦ";
}

void Teacher::display(void)
{
    std::cout << type << "��\n";
    std::cout << "����:" << num << ",����:" << name << ",�Ա�:" << sex << ",нˮ:" << pay << "\n\n";
}

int main()
{
    Student student1(20010,"����","Ů",89.5);
    student1.display();
    Teacher teacher1(10001, "����", "��", 8765.4);
    teacher1.display();
    Teacher teacher2(&student1);
    teacher2.display();
    return 0;
}