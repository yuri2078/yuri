#include <iostream>
#include <map>
#include <unordered_map>

class Mycomply
{
public:
    bool operator()(int x, int y) const
    {
        return x > y;
    }
};


int printMap(const std::map<int,int> &m)
{
    int k = 0;
    for (std::map<int, int>::const_iterator start = m.begin(); start != m.end();start++)
    {
        std::cout << "key : " << start->first << "  value : " << start->second << std::endl;
        k++;
    }
    return k;
}


int main(int argc, char *argv[])
{
    //会按照key 值进行排序 
    //不能有重复的key 除非用muitable 
    std::map<int, int> map_1;
    map_1.insert(std::pair<int,int>(4,6)); //同通过pair 插入序对
    map_1.insert(std::make_pair(1, 666)); //直接插入不用写类型
    map_1.insert(std::map<int, int>::value_type(55, 6)); //通过valude type 插入
    map_1[3] = 233; //重载【】 运算符 直接赋值
    printMap(map_1);

    //直接用at 打印
    std::cout << "用at 打印 --- " << map_1.at(4) << std::endl;
    std::cout << "查找  key 4 --- " << map_1.find(4)->second << std::endl; //找不到返回end
    std::cout << "统计  key 4 --- " << map_1.count(4) << std::endl; //无非 0 / 1

    //通过自定义排序规则排序
    std::map<int, int, Mycomply> map_2;
    for (int i = 0; i < 10;i++)
    {
        map_2.insert(std::make_pair(i, 333));
    }

    std::cout << "打印map——2 -- \n";
    //这里指定不指定仿函数都可以
    for (std::map<int, int, Mycomply>::const_iterator start = map_2.begin(); start != map_2.end();start++)
    {
        std::cout << "key : " << start->first << "  value : " << start->second << std::endl;
    }

    std::multimap<int, int>  map_3; //定义可重复的容器
    for (int i = 0; i < 10;i++)
    {
        map_3.insert(std::make_pair(i, 333));
        map_3.insert(std::make_pair(i, 666));
    }

    std::cout << "查找可重复容器 --- " << map_3.find(1)->second << std::endl;
    std::cout << "统计 cout 1 --- " << map_3.count(1) << std::endl;
	//可重复的容器没有at函数
    return 0;
}