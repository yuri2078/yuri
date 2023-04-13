---
title: c++知识点补充
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: cpp
comments: true
description: '我的爱宛如孤岛之花，不为人知的绽放,不为人知的凋零！'
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/15.png'
date: 2022-08-04 19:10:31
tags: c/c++
keywords:
---

# c/c++

## 写代码的要求

### 尽可能的使用const 修饰代码

+ 避免无意识中修改变量导致出错
+ 使他能够接受const 和 非const 参数
+ 是4程序能够正常生成 临时变量 --- 引用的时候

### 命名规则

+ 小驼峰 myPoint
+ 大驼峰 MyPoint
+ 匈牙利 my_point
+ `__`  和 `_`开头的命令被保留给实现，一般不用

### 不使用using namespace std

+ 使用 using std::cout;
+ 使用 using std::cin;

### 使用容器的时候包含头文件

+ iostream 包含了string 但 自己还是包含一下

### 给函数传递参数时的选择

1. 当传递类或者结构体这种数据量大的数据时一般选择 引用传递
2. 传递数组时 智能选择指针
3. 当传递普通数据类型的变量是 选择值传递

### 数组的初始化

+ `int array[10] { 1, 2, 3, 4 }`c11可以忽略等于号
+ `int array[10] {}`c11可以直接用空括号初始化0
+ 列表禁止缩窄定义 比如long  ->  int

## 未完成的事情

+ 类型关键字
  + static
  + const
  + extern
  + volatile
  + auto 自动识别类型
  + register
  + thread_local
  + mutable 使用这个可以修改常量函数里的变量

## 类和对象

### 类的基本结构

```c++
class Person : public Animal //继承自Animal 类
{
private: //访问权限
    int x; //数据成员
   
public:
    Person() = default; //默认构造函数，不写系统会自动生成
    Person(int x); //重载的构造函数
    explicit Person(int x, int y, int z = 0); //禁止发生隐式抓换构造函数
    Person(const Person &p); //拷贝构造函数 当需要拷贝的时候调用
    Person(const Person &&p); //移动构造函数 当需要移动数据完成构造的时候调用
    ~Person() = default; //析构函数，不加default默认会生成一个，他没有参数
    void printPerson(); //普通成员函数
    virtual void test(); //虚函数
    virtual void test_1() = 0; //纯虚函数，如果不重写，他的子类或者他本身无法生成对象
    int getX() const; //禁止修改数据成员，隐含 const 修饰 this指针。
};
```



### **explicit**  关键字

一般用于构造函数/拷贝构造函数 加上之后就不能发生隐式类型转换，必须指明

```cpp
    class Person
    {
        explicit Person(int x = 0, int y =1) //添加禁止隐式转换关键字
        {

        }
    };
    void test()
    {
        Person p1 = 3; //发生隐式类型转换
        //程序处理 ： Person temp(3); p1 = temp; 
        //未来避免发生不必要的错误，使用explicit关键字禁止 隐式类型转换

        //加上explicit关键字后
        // Person p1 = 3; 错误
        // Person p1 = Person(3); 正确
    }

```

### 匿名对象

调用成员函数 直接生成匿名对象，调用函数

```cpp
    class Person
    {
    public:
        void test()
        {
            cout << "hello world " << endl;
        }
    };

    int main()
    {
        Person().test();
        return 0;
    }

```

### **default** 关键字

生成一个默认的构造函数或者析构函数

```c++
class Person
{
    //生成默认构造函数，该函数不可重新定义
  	Person() = default; 
};
```



### **noexcept**  关键字

告诉编译器该函数 默认是安全的不会弹出错误

```c++
void test() noexcept;
void test() noexcept(true); //等同于上面那个
void test(); //不加关键字默认是可能弹出错误
void test() noexcept(false); //等同于上面那个

//函数 声明/定义 有一个有noexcept关键字，其他所有 声明/定义 都要有关键字
```

### override 关键字

表示对一个virtual 函数进行重写

```c++
class Animal{
    virtual void eat(){
        std::cout << "Animal is eating\n";
    }
};

class Person : public Animal{
    void eat() override{ //对虚函数进行重写
        std::cout << "Person is eating\n";
    }
};
```

### **final** 关键字

```c++
//表示该类禁止被继承
class Person final : public Animal{
    virtual void eat() final; //表示该函数禁止被子类重写
}
```




## 常用函数补充

### `#include <limits.h>` 

保存各类型的最大值 INT_MAX

### `#include <stdlib.h>` 

常用申请内存函数

1. `int *num = (int *)malloc(8 * sizeof(int));` //分配内存但是不重置为0 失败返回NULL
2. `int *num = (int *)calloc(8, sizeof(int)); `//分配n 个size内存 并置为0 失败返回 NULL
3. `num = realloc(num, 9 * sizeof(int)); `重新分配内存可大可小
   - 后面空间小于 原有空间则释放多余地址
   - 后面空间大于 原有空间则查看后面连续地址是否有剩余 没有则把旧数据拷贝到新地址且返回新地址
   - 指针为NULL 且size不为0 作用和malloc类似 返回新的地址
   - 指针不为NULL 但是size为0  则空间会被释放 返回NULL
   - 空间不足 返回NULL原空间内容不变

### `#include <limits>`

> std::numeric_limits [类模板](https://so.csdn.net/so/search?q=类模板&spm=1001.2101.3001.7020)来获取类型的最大值和最小值等

```c++
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
    std::cout << "long long max" << std::numeric_limits<long long>::max() << std::endl; // 获取long long最大值
    std::cout << "long long min" << std::numeric_limits<long long>::min() << std::endl;
    
    std::cout << "int max" << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "int min" << std::numeric_limits<long long>::min() << std::endl;
}

```



## 常见关键字补充

### const 关键字

```c++
#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 666, b = 666;
    int *p;

    const int *point = &x; //const 在左边表示他指向的值不能修改
    // *point = 666; //不能修改，报错
    point = &b; //可以修改

    int *const point_2 = &x;
    *point_2 = 666;
    // point_2 = &b; //不能修改，报错

    const int temp = 666;

    return 0;
}
```

**总结：**

1. const 加在类型的前面则表示后面的值不能修改 `const int *point = &x;`
   1. 不能通过point 修改 x 的值
   2. 可以修改point 指向的值
2. const 加在类型的后面则表示这个变量不能修改`int *const point_2 = &x;`

    1. 可以通过point_2 修改x的值
    2. 不能修改point_2 指向的值
3. 尽量加const 这样可以接受const的值，普通变量是不能接受const的值的

### auto 关键字 

自动识别数据类型

```c++
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Student
{

private:
  int age;

public:
  explicit Student()
  {
    age = 666;
  }

};

int main(int argc, char **argv)
{
    vector<int> v1;
    for(int i = 0; i < 10; i++){
      v1.push_back(i);
    }

    //自动识别迭代器类型
    for (auto begin = v1.begin(); begin != v1.end(); begin++)
    {
      cout << *begin << " ";
    }
    cout << endl;
    for (vector<int>::iterator begin = v1.begin(); begin != v1.end(); begin++)
    {
      cout << *begin << " ";
    }
    cout << endl;

    auto &hell = v1;
    cout << "hello " << hell[0] << endl;
    return 0;
}

```

### && 右值引用符号



## 宏定义知识点补充

1. `#`号 转化成字符串

   ```c++
   #define STR(s) #s //将s转化成字符串
   STR(sss) //结果 "sss"
   ```

   

2. `##` 连接前后两个 

   ```c++
   #define CAT(a,b) a##e##b //CAT(2,10) 结果2e10 也就是 2的十次方
   ```

   

3. 





## 指针知识补充

### 函数指针

### 智能指针

- **std::unique_ptr** 独占指针
    1. 在任何给定的时刻只能有一指针管理内存
    2. 在超出作用域后，指针将会释放内存
    3. 只能move 不能 copy
- **std::shard_ptr** 计数指针
    1. 他可以copy
    2. 可以计数 赋值一次 计数器加一，销毁一次计数器减一
    3. unique_ptr 可以传递给shard_ptr 但是shard不能传递给unique_ptr
    4. 拥有计数方法 .use_count() 统计指针被复制的次数。 被删除一次则加一
- **std::weak_ptr** 
    1. 没有所有权
    2. 不能解引用和使用箭头函数
    3. 一般用于标识别的对象信息，用shard和unique会释放掉内存   

详细列子

```c++
#include <iostream>
#include <memory>

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
```

