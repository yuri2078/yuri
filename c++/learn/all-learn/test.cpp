#include <iostream>
class a
{
    public:
        int age;
};

class Animal1 : virtual public a
{
public:

};

class People1 : virtual public a
{
public:
};

class Student1 :public Animal1 , public People1
{
    //这里我们不设置虚继承
};

    
int main()
{
    Student1 s;
    s.Animal1::age = 18;
    s.People1::age = 8;
    //我们打印一下三个类的空间占用
    std::cout << "Animal1 的占用" << sizeof(Animal1) << "\n"; //结果为4
    std::cout << "People1 的占用" << sizeof(People1) << "\n"; //结果为4
    std::cout << "Student1 的占用" << sizeof(Student1) << "\n";  //结果为8  4+4
    std::cout << s.age;

    return 0;
}