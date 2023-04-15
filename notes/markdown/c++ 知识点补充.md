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

+ 尽可能的使用const 修饰代码
  + 避免无意识中修改变量导致出错
  + 使他能够接受const 和 非const 参数
  + 是4程序能够正常生成 临时变量 --- 引用的时候
+ 命名规则
  + 小驼峰 myPoint
  + 大驼峰 MyPoint
  + 匈牙利 my_point
  + `__`  和 `_`开头的命令被保留给实现，一般不用
+ 不使用using namespace std
  + 使用 using std::cout;
  + 使用 using std::cin;
+ 使用容器的时候包含头文件
  + iostream 包含了string 但 自己还是包含一下





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

## 知识点补充

### 类和对象

+ explicit 一般用于构造函数/拷贝构造函数 加上之后就不能发生隐式类型转换，必须指明

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

+ 匿名对象调用成员函数 直接生成匿名对象，调用函数

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

+ 类型转换

  + ``` QMouseEvent *mouse_1 = static_cast<QMouseEvent*> (e); ```
  
+ 数组的初始化

  + `int array[10] { 1, 2, 3, 4 }`c11可以忽略等于号
  + `int array[10] {}`c11可以直接用空括号初始化0
  + 列表禁止缩窄定义 比如long  ->  int


## 常用函数补充

- `#include <limits.h>` 保存各类型的最大值 INT_MAX
- `#include <stdlib.h>` 常用申请内存函数
  1. `int *num = (int *)malloc(8 * sizeof(int));` //分配内存但是不重置为0 失败返回NULL
  2. `int *num = (int *)calloc(8, sizeof(int)); `//分配n 个size内存 并置为0 失败返回 NULL
  3. `num = realloc(num, 9 * sizeof(int)); `重新分配内存可大可小
     - 后面空间小于 原有空间则释放多余地址
     - 后面空间大于 原有空间则查看后面连续地址是否有剩余 没有则把旧数据拷贝到新地址且返回新地址
     - 指针为NULL 且size不为0 作用和malloc类似 返回新的地址
     - 指针不为NULL 但是size为0  则空间会被释放 返回NULL
     - 空间不足 返回NULL原空间内容不变
- `atol` 将字符串转换成long类型 同理的还有`atoll` `atoi` `atof`之类的

## 常见关键字补充

### **const** **关键字**

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

### explicit 关键字

 一般用于构造函数/拷贝构造函数 加上之后就不能发生隐式类型转换，必须指明

```c++
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

**总结**

1. 有的时候我们要求不能发生隐式转换 所以要加关键字

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

### && 左值引用

```c++
int && i = 888;
std::move(i);
```

 



## 指针知识补充

### 函数指针

```c++
#include <iostream>

int max(int x, int y)
{
    return x > y ? x : y;
}

void test()
{
    std::cout << "void test \n";
}

int main(int argc, char const *argv[])
{
    int (*pf)(int, int); //定义函数指针
    pf = max;
    std::cout << "max -- " << pf(55, 66) << std::endl;
    void (*pm)() = test; //定义函数指针
    pm(); //调用函数指针
    return 0;
}

```

### 智能指针



## std命名空间应用补充

### std::move()

将类型转换为左值，默认调用移动构造函数.

### std::packaged_task

> `std::packaged_task` 是 C++ 中的一个异步任务工具，用于异步执行函数或函数对象，并返回一个可以获取异步结果的 `std::future` 对象

#### 创建 packaged_task 对象

`std::packaged_task` 对象是通过传入一个函数对象或一个函数指针来创建的。

```cpp
std::packaged_task<int(int, int)> task(&add_numbers);
```

以上代码创建了一个名为 `task` 的 `std::packaged_task` 对象，并将其初始化为调用函数 `add_numbers` 的任务。该任务接受两个整数参数，并返回一个整数结果。

#### 获取 future

要获取与 `std::packaged_task` 对象关联的 `std::future` 对象，可以调用 `get_future()` 方法。

```cpp
std::future<int> result = task.get_future();
```

调用 `get_future()` 方法将创建一个 `std::future` 对象，该对象与 `std::packaged_task` 关联，并可用于在异步任务完成后获取结果。

#### 异步执行 packaged_task

要执行 `std::packaged_task` 对象中的任务，可以使用一个线程或一个执行者将其转换为异步任务。

```cpp
std::thread t(std::move(task), 1, 2);
t.join();
```

首先创建一个新线程，并在该线程中执行任务，然后使用 `join()` 方法等待该线程完成。

#### 取得异步执行结果

要获取异步执行的结果，可以使用 `std::future` 对象的 `get()` 方法。

```cpp
int result_value = result.get();
```

调用 `get()` 方法将阻塞当前线程，直到异步任务完成并返回结果。结果返回后，将其存储在 `result_value` 变量中。

#### 异常处理

在使用 `std::packaged_task` 时，可能会抛出异常，需要进行异常处理。可以在异步任务中使用 `try...catch` 来捕获异常，并在 `std::promise` 对象上设置异常信息。

```cpp
void divide_numbers(int numerator, int denominator, std::promise<double> p) {
    try {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero exception");
        }
        double result = static_cast<double>(numerator) / denominator;
        p.set_value(result);
    } catch (...) {
        p.set_exception(std::current_exception());
    }
}

int main() {
    std::packaged_task<double(int, int)> task(divide_numbers);
    std::future<double> result = task.get_future();

    std::thread t(std::move(task), 10, 0);

    t.join();

    try {
        double result_value = result.get();
        std::cout << "Result: " << result_value << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

在这个例子中，`divide_numbers` 函数用于执行除法操作，如果除数为零，则抛出异常。`std::promise` 对象用于存储异步任务的结果，如果任务执行成功，则调用 `set_value` 方法，否则调用 `set_exception` 方法存储异常信息。在主函数中，调用 `result.get()` 方法时，如果存在异常，则会将异常传播到该线程，需要使用 `try...catch` 块来捕获它们。

### std::bind

> `std::bind` 是 C++11 中的一个函数对象适配器，常用于将一个可调用对象的某些参数进行绑定，生成一个新的可调用对象。以下是 `std::bind` 的详细用法：

#### 静态绑定函数

对于一个静态成员函数或一个全局函数，可以用以下语法来创建 `std::bind` 对象：

```cpp
void print_name(const std::string& name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

int main() {
    auto f = std::bind(&print_name, "Alice", std::placeholders::_1);
    f(30);  // 输出：Name: Alice, Age: 30
}
```

`std::bind` 通过传递函数的指针和绑定参数列表（其中第一个参数是函数指针所属的对象，对于静态成员函数和全局函数，可以传递任意值或省略该参数）来创建一个函数对象 `f`。在这个例子中，`print_name()` 是一个全局函数，`"Alice"` 是一个静态绑定参数（固定值），而使用 `std::placeholders::_1` 表示将其余的参数占位符化，以便在调用 `f()` 时动态绑定。

#### 绑定成员函数

对于非静态的成员函数，需要绑定该函数所属的对象，再绑定函数的参数。例如：

```cpp
class Person {
public:
    void print_age(int age) {
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    Person p;
    auto f = std::bind(&Person::print_age, &p, std::placeholders::_1);
    f(30);  // 输出：Age: 30
}
```

在这个例子中，`f()` 是一个可调用的对象，它绑定了成员函数 `&Person::print_age` 和对象 `&p`，并使用 `_1` 占位符表示该函数的参数。

#### 绑定并复制参数

`std::bind` 可以将可调用对象的某些参数绑定，并将其余参数原样传递。例如：

```cpp
void print_info(const std::string& name, int age, double weight) {
    std::cout << "Name: " << name << ", Age: " << age << ", Weight: " << weight << std::endl;
}

int main() {
    auto f = std::bind(print_info, std::placeholders::_2, 25, std::placeholders::_1);
    f(50.0, "Alice");  // 输出：Name: Alice, Age: 25, Weight: 50
}
```

在这个例子中，调用 `f()` 时传递两个参数，`std::placeholders::_2` 代表 `print_info()` 的第一个参数， `std::placeholders::_1` 代表 `print_info()` 的第三个参数，`25` 是一个静态绑定的参数。

#### 用于函数组合

`std::bind` 还可以用于函数组合，将多个函数组合成一个新的函数对象，例如：

```cpp
double square(double x) {
    return x * x;
}

double increment(double x) {
    return x + 1.0;
}

int main() {
    auto f = std::bind(square, std::bind(increment, std::placeholders::_1));
    std::cout << f(2.0) << std::endl;  // 输出：9
}
```

在这个例子中，`f()` 是一个组合函数，其中 `std::bind(square, std::bind(increment, std::placeholders::_1))` 将先调用 `std::bind(increment, std::placeholders::_1)`，然后将其结果传递给 `square()` 函数进行计算。

总之，std::bind 同样适用于 lambda 表达式，可以用来实现在调用时指定一些参数的效果，从而实现更加灵活的编程。

### std::future

> `std::future` 是 C++11 中的一个异步任务工具，用于管理异步任务，等待异步任务的完成并获取其结果。以下是 `std::future` 的详细用法：

#### 创建 future 对象

要创建 `std::future` 对象，需要先使用一个 `std::promise` 对象来设置异步任务的结果。例如：

```cpp
void divide_numbers(int numerator, int denominator, std::promise<double> p) {
    if (denominator == 0) {
        p.set_exception(std::make_exception_ptr(std::runtime_error("Division by zero exception")));
    } else {
        p.set_value(static_cast<double>(numerator) / denominator);
    }
}

int main() {
    std::promise<double> p;
    std::future<double> f = p.get_future();

    std::thread t(divide_numbers, 10, 2, std::move(p));

    t.join();

    double result = f.get();
    std::cout << "Result: " << result << std::endl;
}
```

在这个例子中，首先创建一个 `std::promise` 对象 `p`，并使用 `get_future()` 方法创建与其关联的 `std::future` 对象 `f`。然后创建一个新线程 `t`，并将异步任务函数 `divide_numbers()` 和 `std::move()` 等作为参数传递给该线程。线程执行并等待异步任务完成后，调用 `get()` 方法获取异步任务的结果，该方法将阻塞当前线程，直到异步任务完成并返回结果。

#### 等待异步任务完成

要等待异步任务完成，可以使用 `std::future` 对象的 `wait()` 方法或 `wait_for()` 和 `wait_until()` 方法。如果异步任务已经完成，则这些函数将立即返回，否则将阻塞当前线程。

```cpp
std::future<int> f = std::async([]() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 42;
});

// 等待异步任务完成（使用 wait 函数）
if (f.valid()) {
    std::cout << "Waiting..." << std::endl;
    f.wait();
    std::cout << "Done." << std::endl;
}

// 等待异步任务完成（使用 wait_for 函数）
if (f.valid()) {
    auto status = f.wait_for(std::chrono::seconds(5));
    if (status == std::future_status::ready) {
        std::cout << "Result: " << f.get() << std::endl;
    } else if (status == std::future_status::timeout) {
        std::cout << "Timeout." << std::endl;
    } else if (status == std::future_status::deferred) {
        std::cout << "Deferred." << std::endl;
    }
}

// 等待异步任务完成（使用 wait_until 函数）
if (f.valid()) {
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
    auto status = f.wait_until(deadline);
    if (status == std::future_status::ready) {
        std::cout << "Result: " << f.get() << std::endl;
    } else if (status == std::future_status::timeout) {
        std::cout << "Timeout." << std::endl;
    } else if (status == std::future_status::deferred) {
        std::cout << "Deferred." << std::endl;
    }
}
```

在这个例子中，使用 `std::async()` 函数创建一个异步任务，该任务等待 3 秒钟并返回 42。使用 `f.wait()` 方法等待异步任务完成，或使用 `f.wait_for()` 和 `f.wait_until()` 方法等待一段时间后检查异步任务的状态。

#### 异常处理

如果异步任务中抛出了异常，则可以使用 `std::future` 对象的 `get()` 方法捕捉异常。

```cpp
void die() {
    throw std::runtime_error("I'm dead.");
}

int main() {
    std::future<void> f = std::async(die);

    try {
        f.get();
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
```

在这个例子中，异步任务调用 `die()` 函数，并抛出一个异常。在主函数中，调用 `f.get()` 方法捕获异常并在屏幕上输出错误消息。

#### 其他操作

除了上述操作，`std::future` 还支持以下其他操作：

- `valid()`：判断 `std::future` 对象是否可用。
- `share()`：创建一个共享 `std::future` 对象，多个线程可以共享同一对象的状态。
- `get_exception_ptr()`：获取异步任务抛出的异常指针，如果异步任务未抛出异常，则返回空指针。

需要注意的是，`std::future` 对象只能获取异步任务的结果一次，如果需要多次获取结果，则可以使用 `std::shared_future` 对象。
