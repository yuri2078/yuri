---
title: python第三章
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: python
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/13.png'
date: 2021-11-22 19:09:30.35
updated: 2021-12-23 20:05:07.521
tags:
keywords:
---


python注释通常有两种 一种是 “ # ” 字符开始
另一种是用三个引号，或者三个双引号（都是在英文输入状态）

    ```py
        # 以#号开始的注释
        ''' 以三个单引号开始的注释 '''
        """ 以三个双引号开始的注释 """
    ```

如果一行程序写不下可以用'\' 继续

    ```
    print("这一行太长了写不下了\
    可以用\接着下一行写")
    ```

python用print打印输出不同参数默认会用空格隔开并且在最后打印一个回车
这些都是可以修改的

    ```
    a=1
    b=2
    print(a,b)
    print(a,b,sep=',') #更改默认分隔符号
    print(a,b,end=';') #更改默认结束符号
    print(a,b) # 此时我们发现并没有打印回车而是直接输出
    ```
打印结果：
1 2
1,2
1 2;1 2

python中的字符串加号和乘号有着不同的功能

    ```py
    x="hello "
    y="python"
    print(x+y)
    print(x*4)
    # 运行结果：
    # hello python
    # hello hello hello hello

    ```
由此看出加号 为 两个字符串链接而乘号就是字符串打印的个数

python中常用的运算符号

    ```py
    a=13
    b=4
    print(a**b) #打印a的b次方
    print(a//b) #打印a整除b丢弃余数的结果
    print(a%b)  #与c语言相同，取余数丢弃除数
    print(a|b)  #按位或运算 
    print(a^b)  #按位异或运算
    print(a&b)  #按位与运算
    # << 左移 >> 右移运算
    ```
格式或输出 %d这种类型与c语言相同

    ```py
    a=666
    ss="i love  python "
    print("python is %d so %s" %(a,ss))
    ```
python中 bool 类型与c语言大致相同不过比较的值的结果为 Trur  和 False
并且python中多了 is 和 is not 返回值一样是 Trur  和 False

    ```py
    print(6 > 5)
    print(6 is not 5)
    print(6 < 5)
    print(6 is 5)
    ```
结果为：
True
True
False
False
python中还有 and or not bool运算  与c语言相同or前为1则不运算后面 and前为0就不运算后面的值返回值为最终运算过的值

    ```py
    # and or not 
    print(bool(3)) #值为True
    print(bool(0)) #值为False
    print(3 or 4) # 最终返回的值为3
    print(3 and 4) # 最终返回的值为4
    print(not True) #结果为False
    print(not False) #结果为True
    ```
if 语句的五种判别方式

    ```py
    b,c,d=6,7,8
    #(1)
    if b>c :
        print("我在里面")
    print("我在外面")

    #(2)
    if b>c :
        max=b
    else   :
        max=c

    #(3)
    if b>c   :
        max=b
    elif b<d :
        max=d

    #(4)
    if b>c   :
        max=b
    elif b>d :
        max=d
    else     :
        max=c

    #(5)
    max=b if b>c else c
    ```
while循环的使用

    ```py
    i = 0
    while i<100:
        print(' i = %d ' %(i) )
        i = input("输入一个大于100的数我就停了哦 ！ ")
        i = int(i)
        if(i < 0 ) :
            print("你输入的太小了。不让你继续了 你没有出来 ")
            break
    # break 强制退出
    else :
        print("恭喜你成功的出来了")
    #当while循环完成之后就会执行else语句

    ```
while循环的嵌套使用 打印99乘法表

    ```py
    i=1
    while i <=9 :
        j=1
        while j <= i :
            print("%d * %d = %d " %(j,i,i*j),end=" ")
            j += 1
        print("\n")
        i +=1
    else :
        print("以上就是99乘法表了")
    ```
注意  ： break 和 continue 只能跳过或者跳出一条循环

for 循环
for 变量 in 可迭代对象 列如：一个字符串，或者range函数

    ```py
    for i in range(10) :
        print(i,end=" ")
    for i in "hello python ." :
        print(i,end=' ')
    ```

简单的打印一个 100以内的素数

    ```py
    for i in range(2,100) :
        for j in range(2,i) :
            if i%j == 0 :
                break
        else :
            print(i,end='  ')
    ```

### 列表

python里的列表可以是多种类型
a = [1,2,3,4,5,"python"]
我们可以通过下标访问其中的每个元素

    ```py
    a = [1,2,3,4,5,"python"]
    print(a[5])
    print(a[len(a)-1])
    print(a[-1])
    print(a[0:3]) #打印下标0-3的片段
    print(a[:3]) #打印开头到3的片段
    print(a[3:]) #打印3到尾部的片段
    print(a[0:4:2]) #间隔2个打印
    print(a[::2]) #省略头和尾间隔两个打印
    print(a[::-2]) #省略头尾从尾部间隔两个打印
    ```
上面前三个结果是一样的,同理我们打印a[-2]就是打印的倒数第二个元素。
注意 所有的区间都是左开右闭。包含起始位置但是不包含尾部位置

通过切片的方式我们也可以方便的添加数据

    ```py
    a = ["java","c","c++"]
    print(a)
    #打印结果是 ['java', 'c', 'c++']
    a[len(a):]=["python"]
    # 通过切片的方式添加数据
    print(a)
    #打印结果是 ['java', 'c', 'c++', 'python']

    ```

## python 的数据精度问题

c语言中因为各种数据都存在类型，而python一开始便可以直接定义，但他们为什么类型呢？

    ```py
    x=input("请随机输入一个你想要输入的数： ")
    print(type(x)) 
    #请随机输入一个你想要输入的数： 1 <class 'str'>
    ```
我们发现他是 str 也就是字符型，从此我们知道，python是默认输入的东西为字符型，但是我们可以直接转换为别的类型
需要注意的是自己直接定义的数是相对应的数值类型比如 x=0.2  x就是float型

    ```py
    x=int(x)
    print(type(x))
    #此时的打印的数据类型就是int型了
    ```
在python中不同类型的值是不可以直接比较的

    ```py
    # x输入为6
    print(x == 6) # 结果为False
    x=int(x)
    print(x == 6) # 结果就是true了
    ```
另外python中小数的精度是有问题的，比如下面这段

    ```py
    x=0.1
    y=0.2
    print(x+y)
    print(x+y == 0.3)
    ```
我们会神奇的发现结果为0.30000000000000004 和 False
这是因为计算机存储数的原理导致的，所以小数做不到完全精确，不过我们可以借助与函数来实现精确的小数

    ```py
    import decimal #导入decimal 函数
    x=decimal.Decimal('0.1')
    y=decimal.Decimal('0.2')
    print(x+y)
    ```
此时我们发现我们输出的数就是0.3了
