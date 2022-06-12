#include <iostream>
#include <cstring>
class Person
{
protected:
    char name[20];
    char sex[4];
    int age;

public:
    Person(const char *name, const char *sex, int age)
    {
        strcpy(this->name, name);
        strcpy(this->sex, sex);
        this->age = age;
    }
};

class Teacher : public Person
{
protected:
    char title[20];
public:
    Teacher(const char *name, const char *sex, int age, const char *title) : Person(name,sex,age)
    {
        strcpy(this->title, title);
    }
    void display(void)
    {
        std::cout << "���:��ʦ  ����: " << name << "  �Ա�" << sex;
        std::cout << "  ���䣺" << age << "  ְ��:" << title << "\n";
    }
};

class Student : public Person
{
protected:
    double score;

public:
    Student(const char *name, const char *sex, int age, double  score) : Person(name,sex,age)
    {
        this->score = score;
    }
    void display(void)
    {
        std::cout << "���:ѧ��  ����: " << name << "  �Ա�" << sex;
        std::cout << "  ���䣺" << age << "  �ɼ�:" << score << "\n";
    }
};

class Graduate : public Teacher , public Student
{
private:
    double wage;
    
public:
    Graduate(const char *name, const char *sex, int age, const char *title, double  score, double wage) : Teacher(name,sex,age,title), Student(name,sex,age,score)
    {
        this->wage = wage;
    }
    void display(void)
    {
        std::cout << "���:�о���  ����: " << Teacher::name << "  �Ա�" << Teacher::sex << "  ���䣺";
        std::cout << Teacher::age << "  ְ��:" << title << "  �ɼ�:" << score <<  "  ����:" << wage <<  "\n";
    }
};

int main()
{
    Teacher teacher("����","Ů",38,"������");
    Student student("Ǯ����","��",20,90);
    Graduate grad("����","Ů",26,"����",89.5,1234.5);
    teacher.display();
    student.display();
    grad.display();
    return 0;
}