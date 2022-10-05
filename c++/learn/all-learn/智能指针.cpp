#include <iostream>
#include <memory>
#include <vector>

class Person
{
private:
    
public:
    std::string name{"hello"};
    
    Person(); //默认调用函数
    Person(const std::string &name);
    void set_name(const std::string &name);
    ~Person();
    Person(const Person &&p);
};

Person::Person() 
{
    std::cout << "name : " << name << "  Person 类创建\n";
}

Person::Person(const std::string &name) : name(name)
{
    std::cout << "name : " << name << "  Person 类创建\n";
}

Person::~Person()
{
    std::cout << "name : " << name << "  Person 类析构\n";
}

void Person::set_name(const std::string &name)
{
    this->name = name;
}
Person::Person(const Person &&p)
{
    std::cout << "移动构造函数调用\n";
    this->name = p.name;
}


void test_0()
{
    Person p1; //会自己调用析构函数
    Person *p2 = new Person; //不会自己调用析构函数
    delete p2; //需要自己调用
}

//c++ 指针的类型
// 1、 普通的指针
// 2、 智能指针 （封装的普通指针，好处是自己分配内存，不用担心内存泄露）

// std::unique_ptr  指针
/*
1、在任何给定的时刻只能有一指针管理内存
2、在超出作用域后，指针将会释放内存
3、只能move 不能 copy
*/
void unique_ptr()
{
    //创建方式1 使用原始指针创建
    Person *p = new Person;
    std::unique_ptr<Person> u_p{p}; //通过原始指针创建

    //独占指针需要满足条件1 这里两个都能调用不满足，把它指向空
    p = nullptr;

    std::cout << "u_p : name --- " << u_p->name << std::endl; //正常调用，函数结束后自己会调用析构函数

    
    //创建方式2 使用new 创建
    std::unique_ptr<Person> u_p_2{new Person("yuri")};
    
    //创建方式3 使用std::make 创建

    std::unique_ptr<Person> u_p_3 =  std::make_unique<Person>("yuri is yes");

    std::cout << "u_p_2.get() : " << u_p_2.get() << std::endl; //打印地址
    //打印的是指针指向的地址，而不是& 打印指针的地址

    std::unique_ptr<Person> up = std::make_unique<Person>("yuri");
    auto hello = std::move(up); //只能通过move使用
    // auto hello = up; 报错，无法复制，只能move
}

//共享指针

/*
1、他可以copy
2、可以计数 赋值一次 计数器加一，销毁一次计数器减一
3、unique_ptr 可以传递给shard_ptr 但是shard不能传递给unique_ptr
*/


void shared_ptr()
{
    std::shared_ptr<int> int_1 = std::make_shared<int>(100);
    std::cout << "(1 cout = " << int_1.use_count() << std::endl;
    auto int_2 = int_1; //复制一次计数器加一
    std::cout << "(1 cout = " << int_1.use_count() << std::endl; //指向同一个地方，计数器都变成2
    std::cout << "(2 cout = " << int_2.use_count() << std::endl;

    int_1.reset(); //释放一次
    std::cout << "(1 cout = " << int_1.use_count() << std::endl; //已经删除了，计数器编程0
    std::cout << "(2 cout = " << int_2.use_count() << std::endl; //这里不变，因为原来的删除，所以减一变成0了
    //在函数里面调用的时候会加一，出来之后又会不变
}

void weak_ptr()
{
    //没有所有权
    //不能解引用和使用箭头函数
    //一般用于标识别的对象信息，用shard和unique会释放掉内存
    auto p = std::make_shared<Person>();
    std::weak_ptr<Person> weak_p(p);
    // p->name; 错误无法调用
    
}

int main(int argc, char const *argv[])
{
    unique_ptr(); //独占指针
    shared_ptr(); //计数指针
    return 0;
}