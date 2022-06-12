#include <iostream>
class Student
{
protected:
    int num, age;
    std::string name;
public:
    Student(int num,std::string name,int age);
    void display(void);
};

Student::Student(int num,std::string name,int age)
{
    this->num = num;
    this->name = name;
    this->age = age;
}

void Student::display(void)
{
    std::cout << "ѧ��:" << num << ",����:" << name << ",����:" << age;
}

class StudentGE : public Student
{
private:
    double score;
public:
    StudentGE(int num,std::string name,int age, double score);
    void display(void);
};
StudentGE::StudentGE(int num,std::string name,int age, double score) : Student(num,name,age)
{
    this->score = score;
}

void StudentGE::display(void)
{
    Student::display();
    std::cout << "��¼ȡ����:" << score;
}

class StudentSP : public StudentGE
{
private:
    std::string pecialty;

public:
    StudentSP(int num,std::string name,int age, double score, std::string pecialty);
    void display(void);
};
StudentSP::StudentSP(int num,std::string name,int age, double score, std::string pecialty) : StudentGE(num,name,age,score)
{
    this->pecialty = pecialty;
}

void StudentSP::display(void)
{
    StudentGE::display();
    std::cout << "��רҵ�س�:" << pecialty;
}

int main()
{
    StudentGE stud(10010,"������",22,89);
    stud.display();
    std::cout << '\n';
    StudentSP stud2(10014,"������",18,65,"�赸");
    stud2.display();
    return 0;
}