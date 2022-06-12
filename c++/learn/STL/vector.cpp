#include <iostream>
#include <vector>
#include <algorithm> //stl 算法需要的头文件

void forEach(int val)
{
    std::cout << "val = " << val << "\n";
    //编写函数，等会遍历要用
}


class Person
{
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        std::cout << "name  = " << name << "   age  = " << age << "\n";
    }
};

//这个必须写到类的后面，不然会报错。
void forPerson(Person &p)
{
    p.display();
}

int main()
{
//新建一个vector 容器
    std::vector<int> v;
    
    for (int i = 0; i < 5;i++)
    {
        v.push_back(i); //尾插 参数
    }

//建立vector 迭代器
    std::cout << "方法1\n";
    std::vector<int>::iterator itBegin = v.begin(); //起始迭代器，指向容器第一个元素
    std::vector<int>::iterator itEnd = v.end(); //结束迭代器，指向容器最后一个 元素的后一个元素（无意义）
    while(itBegin != itEnd)
    {
        std::cout << "&itBegin = " << &itBegin << "  *itBegin = " << *itBegin << "\n";
        itBegin++;
    }
    std::cout << "&itend = " << &itEnd;
    //迭代器不是单纯的指针，不能直接打印他存储的值，但是可以打印他存储的东西的值
    //直接打印itbegin 会报错，并且他的地址一直都打印的一样，而且他不会重新回

    std::cout << "\n方法2\n";
    //方法2
    for (std::vector<int>::iterator itBegin = v.begin(); itBegin != v.end();itBegin++)
    {
        std::cout << "&itBegin = " << &itBegin << "  *itBegin = " << *itBegin << "\n";
    }

    std::cout << "\n方法3\n";
    //通过stl 提送的for_each() 迭代便利算法
    std::for_each(v.begin(), v.end(), forEach); //即可正常遍历



    std::cout << "\n方法4\n"; //. 通过数组下标访问
    //v.size 是个长整型，并且没有符号，这里最好定义成无符号类型
    for (unsigned i = 0; i < v.size();i++)
    {
        std::cout << "v[" << i << "] = " << v[i] << "\n";
    }

//通过vector 存储类
    std::vector<Person> person;
    for (int i = 0; i < 5;i++)
    {
        Person p("张三", i);
        person.push_back(p);
    }

    std::cout << "\n方法1\n";
    //通过指针遍历
    for (std::vector<Person>::iterator itBegin = person.begin(); itBegin != person.end();itBegin++)
    {
        itBegin->display();
        //itbegin 是一个指针，不能直接访问类成员函数，需要用 ->
    }
    //通过foreach 遍历
    std::cout << "\n方法2\n";
    std::for_each(person.begin(), person.end(), forPerson);

    std::cout << "\n方法3\n"; 
    // 通过数组下标访问
    for (unsigned i = 0; i < person.size();i++)
    {
        person[i].display();
    }


//容器嵌套容器

    std::vector<std::vector<int>> score;
    for (int i = 0; i < 3;i++)
    {
        std::vector<int> v;
        score.push_back(v);
        for (int j = 0; j < 5;j++)
        {
            score[i].push_back(i);
        }
    }
    std::cout << "\nvector 容器的嵌套输出\n";
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 5;j++)
        {
            std::cout << "score[" << i << "][" << j << "] = " << score[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::vector<int> v1;
    std::cout << "判断是不是空容器 ----- " << v1.empty() << "\n";
    std::cout << "v1 的 容量是: " << v1.capacity() << "   v1 的 元素个数是 : " << v1.size() << "\n";
    std::vector<int> v2(10, 666); //用十个666填充
    
    std::cout << "判断是不是空容器 ----- " << v2.empty() << "\n";
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";

    v2.resize(20,666666); //将个数改为多少，当变大的时候会用默认元素填充，变小的话原来的元素仍然存在。
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";
    std::cout << "v2[10] = " << v2[10] << "\n"; //超出部分用666666填充

    v2.push_back(555); //向尾部插入555
    std::cout << "v2[10] = " << v2[20] << "\n"; //默认插入最后一个元素后，而不是容量的最后
    v2.pop_back(); //删除最后一个元素

    for (int i = 0; i < 20;i++)
    {
        v2[i] = i;
    }

    std::vector<int>::iterator begin = v2.begin();
    v2.insert(begin + 2, 12345); //向指定位置插入 数据
    std::cout << "v2[2] = " << *(begin + 2) << "\n";
    v2.insert(begin + 3, 10, 555555); //向指定位置插入 n 个  数据
    std::cout << "v2[12] = " << *(begin + 12) << "\n"; //原本数据0 1  然后插入10个555 第12个为5555
    std::cout << "v2[13] = " << *(begin + 13) << "\n"; //而13个则为原本 0 1  后面的2
    std::cout << "v2[7] = " << *(begin + 7) << "\n";
    v2.erase(begin + 2); //删除指定元素,后面元素往前挪
    std::cout << "v2[2] = " << *(begin + 2) << "\n";
    std::cout << "v2[12] = " << *(begin + 12) << "\n"; //删除一个元素后，原本的13往前挪动

    //在改变容器长度的时候应该重新指定迭代器的end，不然到不了尾部

    std::vector<int>::iterator end = v2.end();
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";
    v2.erase(begin , end); //删除begin 到end 所有元素
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";
    v2.clear(); //清除所有元素

    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";
    while(begin != end)
    {
        std::cout << *begin << " ";
        begin++;
    }

    std::cout << "\n";
    //容器清空，但是实际的空间仍旧能够访问
    

    std::cout << "v1 的 容量是: " << v1.capacity() << "   v1 的 元素个数是 : " << v1.size() << "\n";
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";

    v1.swap(v2); //交换容器的内容，包括，大小，容量，元素个数

    std::cout << "v1 的 容量是: " << v1.capacity() << "   v1 的 元素个数是 : " << v1.size() << "\n";
    std::cout << "v2 的 容量是: " << v2.capacity() << "   v2 的 元素个数是 : " << v2.size() << "\n";

    return 0;


//创建容器

    // vector<T> v; //采用模板实现类实现，默认构造函数
    // vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
    // vector(n, elem); //构造函数将n个elem拷贝给本身。
    // vector(const vector &vec); //拷贝构造函数。

//容量和大小
    // empty(); //判断容器是否为空
    // capacity(); //容器的容量
    // size(); //返回容器中元素的个数
    // resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
    // //如果容器变短，则末尾超出容器长度的元素被删除。
    // resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
    // //如果容器变短，则末尾超出容器长度的元素被删除


//插入，删除操作

    // push_back(ele); //尾部插入元素ele
    // pop_back(); //删除最后一个元素
    // insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
    // insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
    // erase(const_iterator pos); //删除迭代器指向的元素
    // erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
    // clear(); //删除容器中所有元素


//数据存取

    // at(int idx); //返回索引idx所指的数据
    // operator[]; //返回索引idx所指的数据
    // front(); //返回容器中第一个数据元素
    // back(); //返回容器中最后一个数据元素
    // swap(vec); // 将vec与本身的元素互换

//预留空间

    // reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。

}