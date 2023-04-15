#include <iostream>
#include <string>

class Sum
{
public:
    int operator() (int x, int y)
    {
        return x + y;
    }
    void clean()
    {

    }
};

class Fish
{
private:
    int cout;
public:
    Fish()
    {
        this->cout = 0;
        std::cout << "构造函数!\n";
    }

    void operator() (void)
    {
        std::cout << "鱼儿正在吃东西!\n";
        this->cout++;
    }

    int GetCout(void) {
        return this->cout;
    }
};

template <class T>
class Print
{
public:
    void operator() (const T &s)
    {
        std::cout << s << "\n";
    }
    
};

template <class T>
void ClassPrint(Print<T> &p, const T &s)
{
    std::cout << "classprint 打印 ： ";
    p(s);
    std::cout  << "\n";
}

int main(void)
{
    //函数对象可以直接用（） 调用

    Sum sum; //生成一个对象
    std::cout << "sum(10,20) == " << sum(10, 20) << "\n"; //通过对象直接访问函数
    Fish fish; //创建一条鱼
    //让他吃几次东西
    fish();
    fish();
    fish();
    fish();
    std::cout << "鱼儿一共吃了" << fish.GetCout() << "次\n"; //通过对象函数可以访问函数状态，因为他的本质是一个类

    Print<int> p; //建立一个打印整数的对象
    p(666); //直接打印
    std::cout << "\n";

    //通过传递对象打印结果
    Print<std::string> s;
    std::string ss = "卧槽 太好了";
    ClassPrint(p, 666);
    ClassPrint(s, ss);
    return 0;

    // 总结
    //仿函数可以有自己状态，可以传递对象打印
}