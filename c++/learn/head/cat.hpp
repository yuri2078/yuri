#pragma once //防止头文件重复
#include <iostream>

//正常情况下，我们把 定义放在 .h 当中，然后把 具体实现放在具体的cpp 文件中，然后 在cpp 文件中引用 .h
//但是这里因为 模板函数只有在调用的时候才会调用，链接的时候会发生问题
//我们把类模板 的外部文件 的 定义和声明写到一起，后缀名为hpp head + cpp

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

class Dog : public Animal<std::string,double>
{
public:
    Dog(std::string name, double age) : Animal<std::string, double>(name,age)
    {
        this->name = "旺财";
    }
};

template <class T1, class T2>
class Cat : public Animal<T1,T2>
{
public:
    Cat(T1 name, T2 age);
    void display();
};

template <class T1, class T2>
Cat<T1,T2>::Cat(T1 name, T2 age) : Animal<T1, T2>(name,age)
{
    this->name = "咪咪";
}

template <class T1, class T2>
void Cat<T1,T2>::display(void)
{
    std::cout << "鱼儿 "<< this->name << " 的年龄是： " << this->age << "\n ";
}
