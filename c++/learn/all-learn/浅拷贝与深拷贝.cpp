#include <iostream>

class People
{
private:
    std::string *name;
    int *height;
public:
    People(std::string name, int height);
    ~People();
    People(const People &p);
    void show(void);
};

People::People(std::string name, int height)
{
    this->name = new std::string(name);
    this->height = new int(height);
}

People::~People()
{
    delete name;
    delete height;
}

People::People(const People & p)
{
    name = new std::string(*p.name); //通过新建地址的是深拷贝
    height = new int(*p.height); //在有指针进行赋值的时候必须用深拷贝，不然会错误
}

    void People::show(void)
{
    std::cout << *name << "的身高是：" << *height << std::endl;
}

int main()
{
    People p1("小明", 160);
    p1.show();
    People p2(p1); //调用拷贝构造函数，但是默认的拷贝构造函数是浅拷贝，仅仅是赋值，所以在p2 delete height之后，p1在删除就被报错，非法访问
    p2.show();
    return 0;
}