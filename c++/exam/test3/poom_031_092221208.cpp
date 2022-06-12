#include <iostream>
#include <cstring>
class Student
{
private:
    char name[20];
    int chinese;
    int math;
    int english;
    
public:
    static int allStudent;
    Student(const char *name, int chinese, int math, int english)
    {
        strcpy(this->name, name);
        this->chinese = chinese;
        this->math = math;
        this->english = english;
    }

    Student()
    {
        strcpy(name, "总分");
        chinese = math = english = 0;
    }

    void display(void)
    {
        std::cout.width(10);
        std::cout << name << "   " << chinese << "   ";
        std::cout << math << "   " << english << "\n";
    }
    Student operator+ (const Student &s2)
    {
        Student s;
        s.chinese = this->chinese + s2.chinese;
        s.math = this->math + s2.math;
        s.english =this->english + s2.english;
        return s;
    }

    void showAverage(int quantity)
    {
        std::cout << "课程平均分   " << chinese / quantity << "   ";
        std::cout << math / quantity << "   " << english / quantity << "\n";
    }
};

int main()
{
    Student s1("李海",89,88,90),s2("张震",65,78,60);
    Student s3("马梅",60,90,50),s4("徐磊",55,82,90);
    Student s = s1 + s2 + s3 + s4;
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s.showAverage(4);
    return 0;
}