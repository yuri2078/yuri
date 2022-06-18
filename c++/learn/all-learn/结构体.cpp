#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct Person
{
    string name; 
    int age;
    //给默认参数
    Person()
    {
        name = "卧槽，太好了！";
        age = 18;
    }
    //当有参数的时候，需要自己赋值
    Person(string name, int age)
   {
       this->name = name;
       this->age = age;
   }
};

//总结 和 类差不多

int main()
{
    Person p1; //可以直接创建
    cout << p1.name << "  " << p1.age << endl;
    Person p2("小狗狗", 5666); //可以像类一样直接赋值
    cout << p2.name << "  " << p2.age << endl;
    return 0;
}