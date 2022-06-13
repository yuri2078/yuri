#include <iostream>
#include <vector>
#include <algorithm>


//返回布尔类型的一元运算的仿函数的一元谓词
class Max_7
{
public:
    bool operator() (int x)
    {
        if(x > 7)
        {
            return true;
        }
        return false;
    }
};

//返回布尔类型的二元运算的仿函数 为 二元谓词
class MyCompare
{
public:
    bool operator() (int x, int y)
    {
        return x > y;
    }
};

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10;i++)
    {
        v.push_back(i*8 % 12);
    }

    std::vector<int>::iterator choose;
    choose = std::find_if(v.begin(), v.end(), Max_7());
    if(choose == v.end())
    {
        std::cout << "没有找到捏!" << "\n";
    }
    else
    {
        std::cout << "已经找到捏！ -- " << *choose << "\n";
    }

    std::cout << "还没有排序捏！\n";
    for (int i = 0; i < 10;i++)
    {
        std::cout << "v[" << i << "] == " << v[i] << " ";
    }

    std::cout << "\n排序过后捏！\n";
    std::sort(v.begin(), v.end(), MyCompare()); //二元谓词调用
    //不想声明对象可以直接使用匿名对象
    for (int i = 0; i < 10;i++)
    {
        std::cout << "v[" << i << "] == " << v[i] << " ";
    }
    return 0;
}





