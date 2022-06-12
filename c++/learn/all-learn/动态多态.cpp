#include <iostream>
class Animal
{
public:
    virtual void eat()
    {
        std::cout << "动物正在吃东西!\n";
    }
    // 声明成虚函数，类会创建一个虚函数表vfptr virtual funtion pointer 
    // 他会记录虚函数地址

};

class People : public Animal
{
public:
    void eat()
    {
        std::cout << "人类正在吃东西!\n";
        // 当子类继承基类时，基类的虚函数和虚函数表也会继承，但是当你重写虚函数时，他会更新虚函数指针表里的内容，让他指向新的地址
        // 但是此时基类的虚函数指针表里的内容仍然没有变
        // 当你对基类引用或者基类指针传递时，如果调用虚函数，则会从子类的虚函数指针表中寻找地址
    }
};

void doEat1(Animal &a)
{
    a.eat();
    //这里直接调用animal的eat 
    //只有当传入子类指针或者引用的时候，他会找虚函数指针表，但是直接创建实例就不会
}

void doEat2(Animal &a)
{
    a.eat();
    //这里调用的是people的eat
    //当基类的函数定义为虚函数时，基类的指针会指向 重写后的函数 
    //没有定义为虚函数这里会调用animal的eat，当定义之后则会调用重写eat
}


int main()
{
    People p1;
    doEat1(p1); //输入出动物在吃东西
    doEat2(p1); //输入人类在吃东西
    // std::cout << "p1 -> age = " << p1.age;
    return 0;
}