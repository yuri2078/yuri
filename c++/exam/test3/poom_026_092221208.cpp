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
        std::cout << "身份:教师  姓名: " << name << "  性别：" << sex;
        std::cout << "  年龄：" << age << "  职称:" << title << "\n";
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
        std::cout << "身份:学生  姓名: " << name << "  性别：" << sex;
        std::cout << "  年龄：" << age << "  成绩:" << score << "\n";
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
        std::cout << "身份:研究生  姓名: " << Teacher::name << "  性别：" << Teacher::sex << "  年龄：";
        std::cout << Teacher::age << "  职称:" << title << "  成绩:" << score <<  "  津贴:" << wage <<  "\n";
    }
};

int main()
{
    Teacher teacher("徐燕","女",38,"副教授");
    Student student("钱清岳","男",20,90);
    Graduate grad("王丽","女",26,"助教",89.5,1234.5);
    teacher.display();
    student.display();
    grad.display();
    return 0;
}