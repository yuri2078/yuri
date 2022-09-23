#include <iostream>
class Pat
{
private:
    std::string name;
public:
    static int count;
    Pat(std::string name);
    static int Getcount(void); //声明静态方法，注意。使用静态方法尽量用class::方法名，调用不要用对象调用
    ~Pat();
};

Pat::Pat(std::string name)
{
    this->name = name;
    count++;
}

Pat::~Pat()
{
    count--;
}

int Pat::Getcount(void)
{
    return count;
}

int Pat::count = 0; //给count分配内容空间并初始化为0 必须在外面声明，否则会报错

int main()
{
    Pat dog("dog");
    //dog.count = 1; 不可以声明类之后初始化，。要分配内存
    std::cout << "产生了dog，当前有" << Pat::Getcount() << "只动物\n";
    Pat mao("mao");
    std::cout << "产生了dog，mao当前有" << Pat::Getcount() << "只动物\n";
    Pat shu("shu");
    std::cout << "产生了dog，mao,shu当前有" << Pat::Getcount() << "只动物\n";
    return 0;
}