#include <iostream>

//全局函数类外实现，需要写在前面那，告诉编译器有这个东西
template <class T1, class T2>
class Cat;

template <class T1, class T2>
void show3(Cat<T1, T2> &c)
{
    std::cout << "\nshow3 : 我的猫猫 "<< c.name << " 的年龄是： " << c.age << "\n ";
}

template <class typeName, class typeAge = int>
//声明类模板 它可以有默认的类型
class Student
{
private:
    typeName name;
    typeAge age;
public:
    //未知类型，进行赋值，初始化
    Student(typeName name, typeAge age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        std::cout << name << "  的年龄是：" << age << "\n";
    }
};

class Person1
{
public:
    void fun1()
    {
        std::cout << "这里是person-------------1\n";
    }
};

class Person2
{
public:
    void fun1()
    {
        std::cout << "这里是person-------------2\n";
    }
};

template <class T>
class Person
{
public:
    T obj;
    void fun()
    {
        //通过传入的参数，调用不同的fun1
        obj.fun1();
        //类模板的函数只有调用的时候才会生成，所以这里没有报错
    }
};


//模板对象作为函数参数
void display_Student1(Student<std::string, double> &s)
{
    s.display();
}

template <class T1, class T2>
void display_Student2(Student<T1, T2> &s) //让编译器自己猜类型
{
    s.display();
    //打印一下他猜测的类型
    std::cout << "typeid T1 = " << typeid(T1).name() << "\n";
    std::cout << "typeid T2 = " << typeid(T2).name() << "\n";
}

template <class T>
void display_Student3(T &s)
{
    s.display();
    std::cout << "typeid T = " << typeid(T).name() << "\n";
}

template <class typeName, class typeAge>
class Animal
{
protected:
    typeName name;
    typeAge age;
public:
    Animal(typeName name, typeAge age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        std::cout << "小动物 " << name << "  的年龄是：" << age << "\n";
    }
};

// class Dog : public Animal 报错想要继承，必须指定好父类的类型，这样才能给他分配内存
class Dog : public Animal<std::string,double> //正常继承
{
public:
    Dog(std::string name, double age) : Animal<std::string, double>(name,age)
    {
        this->name = "旺财";
    }
};

template <class T1, class T2>
class Cat : public Animal<T1,T2> //使用模板正常初始化
{
public:
    Cat(T1 name, T2 age);
    void display();

    //全局函数类内实现
    friend void show1(Cat<T1, T2> &c)
    {
        std::cout << "\nshow1 : 我的猫猫 "<< c.name << " 的年龄是： " << c.age << "\n ";
    }
    friend void show2(Cat<T1, T2> &c);
    friend void show3<>(Cat<T1, T2> &c); //此时告诉编译器我是个全局模板函数
};

template <class T1, class T2>
void show2(Cat<T1, T2> &c)
{
    std::cout << "\nshow2 : 我的猫猫 "<< c.name << " 的年龄是： " << c.age << "\n ";
}


//成员函数的类外实现
template <class T1, class T2>
Cat<T1,T2>::Cat(T1 name, T2 age) : Animal<T1, T2>(name,age)
{
    this->name = "咪咪";
}

template <class T1, class T2>
void Cat<T1,T2>::display(void)
{
    std::cout << "猫猫 "<< this->name << " 的年龄是： " << this->age << "\n ";
    //这里必须使用this 指针调用，不然会提示你找不到name捏
}


int main()
{
    //自己声明类型
    Student<std::string, double> s("张三", 66.6);
    //Student s2("张三", 66.6); 他没有自动类型推导
    Student<std::string> s3("李四", 555); //他有一个默认的类型，这里输入一个就行了
    s3.display();
    s.display();

    Person<Person1> p1; //指定类型为person1
    p1.fun(); 
    Person<Person2> p2;
    p2.fun(); 
    //普通类的成员函数是编译的时候就创建
    //类模板中的函数时只有调用的时候才创建

    //类模板对象作为函数参数类型的方法
    //1、指定传入类型
    display_Student1(s);
    //2、把数据类型模板化
    display_Student2(s);
    //3、把整个类模板化
    display_Student3(s);

    //类模板的继承
    Dog d("哈哈",55.6);
    d.display();
    Cat<std::string, double> c("哈哈",66.6);
    c.display();

    show1(c);
    // show2(c); 报错，类内声明的是一个普通函数，而定义的确实另一个函数
    show3(c);
    return 0;
}