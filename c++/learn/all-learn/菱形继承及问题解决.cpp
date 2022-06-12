#include <iostream>
class a
{
    public:
        int age;
};

class Animal1 : public a
{
public:

};

class People1 : public a
{
public:
};

class Student1 : public Animal1 , public People1
{
    //这里我们不设置虚继承
};



class Animal2 : virtual public a
{
public:
};

class People2 : virtual public a
{
public:
};

class Student2 : public Animal2 , public People2
{
    //当我们设置为虚继承时，继承的基类又叫虚基类
    //此时继承的相同数据将会变成同一个
    //我们继承虚基类的 vbptr virtual  base pointer  虚基类指针表，里面存放相同数据的偏移量，最终指向同一个数据
    //列如 Animal vbptr 记录偏移量 4 People 的 vbptr 中记录的偏移量为8 他们都指向一个新的地址，也就是student 中新的age
};
    
int main()
{
    Student1 s;
    
    //我们打印一下三个类的空间占用
    std::cout << "Animal1 的占用" << sizeof(Animal1) << "\n"; //结果为4
    std::cout << "People1 的占用" << sizeof(People1) << "\n"; //结果为4
    std::cout << "Student1 的占用" << sizeof(Student1) << "\n";  //结果为8  4+4
    //当我想打印s.age的时候会报错，因为我们不知道访问哪个age。但我我们可以通过作用域进行访问
    //菱形继承导致资源有两份而且数据值不同

    Student2 s2; // 当我们创建虚继承的对象时
    //我们打印看看占用
    std::cout << "Animal2 的占用" << sizeof(Animal2) << "\n"; //结果为16
    std::cout << "People2 的占用" << sizeof(People2) << "\n"; //结果为16
    std::cout << "Student2 的占用" << sizeof(Student2) << "\n";  //结果为24 
    //我们对anima1进行赋值并输出
    s.Animal1::age = 18;
    s.People1::age = 118;
    std::cout << "Animal = " << s.Animal1::age << "\n"; //输出结果18
    std::cout << "People1 = " << s.People1::age << "\n"; //输出结果118
    // std::cout << "Student = " << s.age << "\n"; 报错，不能直接s.age 输出，意义不明

    //我们只对anima2进行赋值并输出
    s2.Animal2::age = 18; 
    std::cout << "Animal2 = " << s2.Animal2::age << "\n";
    std::cout << "People2 = " << s2.People2::age << "\n";
    std::cout << "Student2 = " << s2.age << "\n";
    //我们发现结果都是18

    // 只更改子类
    s2.age = 666; 
    std::cout << "Animal2 = " << s2.Animal2::age << "\n";
    std::cout << "People2 = " << s2.People2::age << "\n";
    std::cout << "Student2 = " << s2.age << "\n";
    //结果也是一样都是666
    return 0;
}