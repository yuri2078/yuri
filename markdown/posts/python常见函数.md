---
title: python常见函数
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: python
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/12.png'
date: 2021-11-25 19:47:11.052
updated: 2021-12-23 20:04:45.235
tags:
keywords:
---


经常和for循环出生入死的好兄弟函数 range()函数
range(stop)

生成从 0 到 len 为止的所有整数 不包括本身

    ```py
    for i in range(10) :
        print(i,end=" ")
    # 输出结果 
    # 0 1 2 3 4 5 6 7 8 9 
    ```

range(start,stop)

生成从 start 开始到 stop 为止的所有整数 包括start 不包括 stop

    ```py
    for i in range(3,10) :
        print(i,end=" ")
    # 输出结果 
    # 3 4 5 6 7 8 9 
    ```

range(start,stop,step)

和上一个一样，不过多了step 也就是跨度 step也可以是复数

    ```py
    for i in range(3,10,3) :
        print(i,end=" ")
    # 输出结果 
    # 3 6 9 
    ```

随机生成函数

    ```py
    import random
    daan=random.randint(1,20) #随机生成1，20的数字

    ```

提高浮点数精确度函数

    ```py
    import decimal #导入decimal 函数
    a=decimal.Decimal(0.1)
    b=decimal.Decimal(0.2)
    print(a)

    ```

math函数，使用前需要导入math模块 且引用为 math.具体模块

    ```py
    import math
    x,y=input(),input()
    x,y=int(x),int(y)
    print(math.sin(x)) #x的正弦值
    print(math.cos(x)) #x的余弦值
    print(math.asin(x)) #x的反正弦
    print(math.acos(x)) #x的反余弦
    print(math.tan(x)) #x的正切
    print(math.atan(x)) #x的余切，反正切
    print(math.hypot(x,y)) #求直角三角形的斜边长度
    print(math.fmod(x,y)) #取x/y的余数
    print(math.ceil(x)) #x取不小于x的最小整数
    print(math.floor(x)) #取不大于x的最大整数
    print(math.fabs(x)) #x的绝对值
    print(math.exp(x)) #求e的x次方
    print(math.pow(x,y)) #x的y次方
    print(math.log10(x)) #求x以10为底的对数
    print(math.sqrt(x)) #开x的根号
    print(math.pi) #求Π的值
    ```
注意：里面有的函数需要的参数值不一样，类型也不一样

string 函数 需要导入string

    ```py
    import string
    s="hello python "
    ss='hello'
    print(s.capitalize()) #将字符串的第一个字母大写
    print(s.count(ss)) #查询ss字符串在s中出现的次数
    print(s.find(ss)) #查询ss字符串在s中出现的起始位置没有则返回-1
    print(s.isalnum()) #检测字符串是不是仅包含数字字母
    print(s.isalpha()) #检测字符串是不是仅包含字母
    print(s.isdigit()) #检测字符串是不是仅包含数字
    print(s.isspace()) #检测字符串是不是仅包含空格
    print(s.istitle()) #检测字符串首字母是不是大写
    print(s.islower()) #检测字符串是不是都是小写字母
    print(s.isupper()) #检测字符串是不是都是大写字母
    print(s.join(ss)) #链接字符串
    print(s.split()) #分割字符串
    print(s.lower()) #将字符串全部变成大写
    print(s.upper()) #将字符串全部变成小写
    print(s.swapcase()) #将字符串大写变小写小写变大写
    print(s.title()) #将字符串首字母大写
    print(len(s)) #获取字符串长度

    ```

列表函数 不需要导入函数

    ```py
    a=[1,2,3,4,6]
    b=[3,3,3]
    print(a)
    a.append(666) #列表尾部添加成员 
    print(a)
    print(a.count(1)) #返回列表中参数出现的次数
    a.extend(b) #向列表追加另一个列表
    print(a)
    print(a.index(6)) #返回参数在列表中的序号，不存在就报错 
    print(a)
    a.insert(0,6) #向列表指定位置插入数据 
    print(a)
    print(a.pop()) #删除列表尾部成员并返回删除的值
    print(a)
    a.remove(1) #删除列表里指定成员（第一个），不存在则报错
    print(a)
    a.reverse() #将列表成员颠倒
    print(a)
    a.sort() #将列表中成员排序
    print(a)

    ```

insert插入函数
list.insert(0,2) 向list列表插入下标0的位置插入数据2

    ```py
    a = ["java","c","c++"]
    print(a)
    #打印结果["java","c","c++"]
    a.insert(3,"python")
    #向下标3处插入"python"
    #打印结果['java', 'c', 'c++', 'python']
    print(a)

    ```

remove 删除函数
list.remove(元素) 删除元素，不存在就报错。仅仅删除一个

    ```py
    a = ["java","c","c++","python"]
    print(a)
    a.remove("python")
    #删除"python"
    ''' 
        打印结果:
        ['java', 'c', 'c++', 'python']
        ['java', 'c', 'c++']
    '''
    print(a)

    ```

clear() 清除列表所有成员
list.clear() 清除所有lise的成员

    ```py
    a = ["java","c","c++","python"]
    print(a)
    a.clear()
    #清除成员a的所有成员
    print(a)
    '''
        打印结果：
        ['java', 'c', 'c++', 'python']
        []
    '''
    ```
