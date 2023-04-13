---
title: c++的输入输出
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: cpp
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/5.png'
date: 2022-03-04 23:00:41.516
updated: 2022-04-03 12:52:01.334
tags:
    - c/c++
keywords:
---

## cerr 和 clog 用于特定场合的输出

c++中仍然可以使用c语言的printf 和 scanf 但是c++新增了cin 和 cout

## cin 输入流

1 cin >> 变量名;   变量是什么类型接收的就是什么类型，可以接收多个变量

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        int x;
        float y;
        cin >> x >> y;//从键盘接收数据
        cout << x << endl << y; //打印x,y的值
        return 0;
    }
    ```

## 注意

(1): 列入语句 float x;char ch;cin >> x >> ch;
cin 同时读取实数和字符时 若输入 123 f时，不会读取空格给字符ch.而是把后面的f赋值给ch。回车也是同理的。会自动忽略输入的所有回车和空格。且若输入3.这种类型的，'.'也会直接忽略。
(2): 若接收字符串和字符时，不会接收回车和空格。

2 cin.get() // 从输入流中接收一个字符。并且该字符会消失。

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch;
        cin.get();
        cin >> ch;
        cout << ch << endl;
        //输入ch，打印结果为h
        return 0;
    }
    ```

3 cin.ignore(长度，字符) 忽略多少长的的输入直到遇到'字符'

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch;
        cin.ignore(10, '.');
        //忽略输入的10个字符，直到遇到'.'
        cin >> ch;
        cout << ch << endl;
        return 0;
    }
    ```

## 注意_1

（1）：当遇到符合条件的字符时，会一起忽略符合条件的字符，并不是遇到该字符就停止忽略，该字符也会被忽略。

（2）：类如语句 cin.ignore(10,'.') 如果输入11个字符，而前十个字符不是'.'，但是第11个正好是'.'，此时会连同第十一个的'.'一同忽略。第十二个则不受影响
 (3): 如果不填写参数，则忽略第一个字符等价 cin.ignore(1,EOF）；

4 cin.peek() 观测输入流的一个字符，观测完了又放回去，并不会删除它，也就是说，它只是取出来看看，并不会导致当前指向的字符变成下一个。

举例：输入一串字符串，遇到'.'结束，并将他们打印输出。

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        char ch;
        while (cin.peek() != '.')
        //读取输入流中的第一个数据，然后放回
        //这里读取的数据不会影响下面的读取
        {
            ch = cin.get();
            cout << ch;
        }
        //输入hello c. 打印结果为hello c
        return 0;
    }
    ```
5 cin.getline(str，n，ch) 从输入流接收长度为n-1的字符串，遇到字符ch停止并且存储在数组str中。ch默认为'\0'。可以不写

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        char str[80];
        char ch,x;
        cin >> x;
        //从键盘中指定停止的字符x
        cin.getline(str,80,x);
        //遇到x停止接收，并把x转为\0存储起来
        //输入流中的x会消失，并不会影响接下来的输入
        cout << str << endl;
        cin.get(ch);
        cout << "ch : " << ch;
        return 0;
    }
    ```

## 注意_2

若指定的长度过短，则会影响后续的输入。所以在指定输入长度的时候需要大于或等于第一次出现停止字符的位置。

6 cin.gcount() 返回上次读取的字符个数，包括\0。需要和get()、getline()、ignore()、peek()、read()、readsome()、putback()  unget() 等函数联用。不可以直接和cin >> 数组名，联用。

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        char str[80];
        cin.getline(str, 80);
        //读取字符
        cout << "上次读取了" << cin.gcount() << "个字符" << endl;
        return 0;
    }
    ```

## cout 输出流

    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
        cout.width(10);//设置宽度为10 等价于setw(10)
        cout.fill('*');//设置空白填充为'*'
        //设置左对齐
        cout.setf(ios_base::left); //等价于 cout << setiosflags(ios::right)
        cout << 3.1415926 << endl;
        //清除左对齐状态，默认是右对齐
        cout.unsetf(ios_base::left);//等价于 cout << resetiosflags(ios::right);
        cout.width(20);//若不重新指定宽度，后面将默认输出
        cout << 3.1415926 << endl;
        //若不指定填空字符，默认为上一次指定的字符。
        cout.setf(ios_base::showpoint);//以一般实数方式显示,默认保留五位小数
        cout.precision(6);//除小数点外保留6位有效数字
        cout << 3.1415926 << endl;
        cout.setf(ios_base::scientific);//以科学计数法显示，默认保留6位小数
        cout << 3.1415926 << endl;
        cout.precision(6);//e后面保留6位小数
        cout << 3.1415926 << endl;
        cout << hex << 123 << endl;//以十六进制输出
        cout << dec << 123 << endl;//以十进制输出
        cout << oct << 123 << endl;//以八进制输出
        return 0;
    }

    ```
