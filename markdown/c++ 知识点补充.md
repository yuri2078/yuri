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
  + auto
  + register
  + thread_local
  + mutable 使用这个可以修改常量函数里的变量

## 知识点补充

### 类和对象

+ explicit 一般用于构造函数/拷贝构造函数 加上之后就不能发生隐式类型转换，必须指明

    ```cpp
        class Person
        {
            Person(int x = 0, int y =1)
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
