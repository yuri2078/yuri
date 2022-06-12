#include <iostream>

class Other;
class Girlfriend
{
protected:
    std::string name;
public:
    Girlfriend(std::string);
    friend class Other; //声明友元类，就可以访问protected保护的内容了
    friend void kiss(Girlfriend *girl, Other *jia);//声明友元函数
    //这里已经使用Other类了，但是此时还没有定义，所以需要在前面声明
};

Girlfriend::Girlfriend(std::string name)
{
    this->name = name;
}

class Other
{
    std::string name;
public:
    friend void kiss(Girlfriend *girl, Other *jia);
    Other(std::string name);
};

Other::Other(std::string name)
{
    this->name = name;
}

void kiss(Girlfriend *girl, Other *jia)
{
    std::cout << jia->name << " kiss了" << girl->name;
    //此时会提醒我们不可以访问
}
int main()
{
    Girlfriend girl("波妞");//建立一个女孩波妞
    Other jia("路人甲"); //建立路人甲
    kiss(&girl, &jia);
    return 0;
}