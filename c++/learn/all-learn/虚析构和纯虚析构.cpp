#include <iostream>
class Animal
{
public:
    int *age;
    Animal(int age)
    {
        this->age = new int(age);
        std::cout << "age = " << age << "\n";
    }
    //设置成为虚析构
    // virtual ~Animal()
    // {
    //     delete age;
    //     std::cout << "animal 析构函数调用" << "\n";
    // }
    //加上0 为纯虚析构 它不仅需要设声明，还需要有实现
    virtual ~Animal() = 0;
};

//加上之后这就是一个抽象类了。他是无法实例化对象的。 
Animal::~Animal()
{
    delete age;
    std::cout << "animal 析构函数调用" << "\n";
}

class Person : public Animal
{
public:
    std::string *name;
    Person(std::string name,int age) : Animal(age)
    {
        this->name = new std::string(name);
        std::cout << "name = " << *this->name << "\n";
    }
    ~Person()
    {
        delete name;
        std::cout << "person 析构函数调用" << "\n";
    }
};


class Student : public Person
{
public:
    Student(std::string name,int age) : Person(name,age)
    {
        std::cout << "Student = " << *this->name << "\n";
    }
    ~Student()
    {
        std::cout << "Student 析构函数调用" << "\n";
    }
};

void fun1(void)
{
    // 使用父类指针创建子类对象
    Animal *al = new Person("jack",444);
    delete al;
    // 打印结果
    // age = 444
    // name = jack
    // animal 析构函数调用

    //我们发现他并没有去调用子类的析构函数，这样会引起内存泄漏 
}


void fun2(void)
{
    Animal *wo = new Student("wocao", 666);
    //在设置虚析构之后，就可以正常析构子类了
    std::cout << *wo->Animal::age <<  "\n";
    delete wo;
}


int main()
{
    fun2();
    return 0;
}