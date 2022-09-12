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



