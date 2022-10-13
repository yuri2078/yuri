---
title: apollo学习路径
author: yuri2078
avatar: https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg
authorLink: https://2078.site
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: apollo
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放,不为人知的凋零！
photos: https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/15.png
date: 2022-10-01 13:37:54
tags:
keywords:
---

# apollo 学习路径

## 必要知识点掌握

### c++ 学习

**前言：** 因为Cyber使用的c++ 封装的api 并且在组件部分就已经没有Python实现了，所以学习c++ 还有有必要的，但是又不用全部学习下去。 后面的stl容器，用的也比较少。 以我目前的学习状况来看， 对模板的使用，只要知道怎么用就行了

目前为止我们需要掌握基础的东西就行。了解c++ 基本的结构，以及类的相关要求就行

#### 视频教程

0基础我推荐黑马的c++ 教程 老师将的很详细，而且每隔一段时间就有案例。能够很好的总结自己目前阶段学习的成果

哔哩哔哩 黑马官方教程 ： [黑马c++教程](https://www.bilibili.com/video/BV1et411b73Z/?spm_id_from=333.337.search-card.all.click&vd_source=b7e1ff814885b361e6eabd7f6aece347)  



> 前言： 
>
> 划分的时间不是固定的，学的快的可以多练习以下，学的慢的也可以放慢速度。遇到不会的东西都可以来问我。但是需要注意可以慢，但是不能慢太多不然后面的进度你跟不上。



第一部分： [c++ 基础入门](https://yuri2078.github.io/2022/09/25/C++%E5%9F%BA%E7%A1%80%E5%85%A5%E9%97%A8/)  (学习时间 建议 3周 ) 

1. **第一周**：第一节 -> c++ 初识    - ---  第四节 -> 程序流程结构 （前面都比较简单，一周熟悉基本结构）
2. **第二周**：第五节 -> 数组           ----- 第六节 -> 函数 （数组和函数是基本的东西，在后续的学习中经常使用）
3. **第三周**：第七节 -> 指针           ----- 第八节 -> 结构体 (指针很重要，不用学习的特别花哨，但是需要掌握 )
4. **总结** ： 三周时间，掌握基础的结构，理解c++ 的基本数据类型 前面也基本都是c语言的内容，有基础学习起来也特别快。 这三周要做的事情是熟练掌握基本结构，能够使用c++ 解决一些基本的问题。
5. **课程对应** 哔哩哔哩视频 1 - 72节
6. **学习要求**： 能够独立完成 视频 73 节的通讯录管理系统项目

第二部分:   [c++ 核心编程](https://yuri2078.github.io/2022/09/25/C++%E6%A0%B8%E5%BF%83%E7%BC%96%E7%A8%8B/)  （学习时间 建议 5 周 ）

1. **前言：**这里是 c++ 的核心编程是非常重要的部分。也是c++ 的核心以及灵魂所在。是必须要重点掌握的地方
2. **第四周**：第一节 -> 内存分区模型 ---- 第三节 -> 函数提高 (看着多，其实需要掌握的地方不多)
3. **第五周** :  第四节 : 4.1 封装  ----  4.2 对象的初始化和清理 （第一周先要熟练掌握对象的基本结构、构造、析构）
4. **第六周** :  第四节:  4.3 c++对象模型和this指针 ---- 4.5 运算符重载 （这里看着多需要掌握的不多更多是理解）
5. **第七周**： 第四节: 4.6 继承 （需要重点掌握，花一周时间好好理解。 不要跟着敲出来就觉得会了。多自己写写）
6. **第八周** :  第四节 :  4.7多态  （需要重点掌握，花一周时间好好理解。 不要跟着敲出来就觉得会了。多自己写写）
7. **总结**： 这一部分面向对象核心编程，是属于c++ 核心的地方。一定要好好学习。 其中 第四周 更多是了解，不要看到源代码不知道是什么意思。第五周封装 和实例化对象则是以后开发绕不开的东西。 对一个类的基本了解和基本使用是必须要掌握的。 后面第六周的运算符重载不用每个都看。重点掌握怎么重载，以及重载 << 这种符号时需要传入的是引用。别的大概理解就行。
8. **对应哔哩哔哩视频**的 84 -184节
9. **学习要求** : 熟练掌握类的 创建 析构 拷贝 继承 多态



**总结 ：** **总结**：这个视频看到 184 节 模板-类模板案例-封装 这一节就行了，后面的stl容器，可以先不用看。中途提到的对于文件的操作也可以选择不看。 学完这两个部分，对于c++ 的基础核心语法，已经算是掌握了。

#### 书籍教程

1.  c++ prime plus 中文版第六版 电子版 链接: https://pan.baidu.com/s/1WXc_hfJhJKL4c8InAVXHMg  提取密码: cg2f

2. GitHub 学习 大佬写的c++ prime plus 原书代码和解答 [GitHub](https://github.com/ShujiaHuang/Cpp-Primer-Plus-6th) 可能需要梯子

   

**提前了解：** 因为apollo 是构建在docker容器当中，所以需要了解基础的linux命令。 打开Ubuntu 然后按住 Ctrl +  Alt + t

就能打开终端。 终端就是输入linux命令的地方。后续提到的指令都是在这里面输入。 

打开终端输入 pwd 查看当前目录 一般是 /home/ {你的用户名} linux是多用户多任务的。 home 目录用来存放各个用户的数据， 每个用户都有自己的目录文件夹，互不干扰。但是他们共享 基本的linux文件 也就是除了home目录以外的东西

比如 存放可执行文件的bin 目录 /usr/bin/ 

### 熟悉linux 常用/基础 的指令

#### 常用指令掌握

- **pwd**（英文全拼：print work directory） 命令用于显示工作目录。

  ```bash
  #用法 pwd 就行
  
  > pwd #查看目前所在目录
  /home/yuri
  ```

- **ls**  --- list directory contents 命令用于显示指定工作目录下之内容（列出目前工作目录所含之文件及子目录)。

  ```shell
  #用法 ls 【目录名】 不加参数则默认当前目录 
  # ls 查看当前目录
  # ls /home 查看/home 目录
  
  > ls #输入ls 查看当前目录下所有（非隐藏）文件 展示出来的东西就是当前目录下所有东西了
  Desktop    Downloads  Pictures  Templates  apollo  images  myPacket      vimrc
  Documents  Music      Public    Videos     blog    miku    packettracer  yuri
  
  ```

- **cd**  （英文全拼：change directory）命令用于切换当前工作目录。 

  ```bash
  #用法 cd [目录名] cd .. linux中 用 . 表示当前目录 用.. 表示上级目录
  # cd /home/yuri 进入/home/yuri目录
  # cd .. 进入上级目录
  
  > pwd #输入pwd查看当前目录 是 /home/yuri
  /home/yuri
  
  > ls #输入ls 查看目录下有哪些文件 我们以进入Musi文件为例
  Desktop    Downloads  Pictures  Templates  apollo  images  myPacket      vimrc
  Documents  Music      Public    Videos     blog    miku    packettracer  yuri
  
  > cd Music #cd music 进入music文件夹       
  
  > pwd #输入 pwd 查看当前是不是在 /home/yuri 下的 Music 文件夹里
  /home/yuri/Music
  
  ```

- **cp**（英文全拼：copy file）命令主要用于复制文件或目录 加上 -rf 复制一整个文件夹

  ```bash
  # 用法 cp  [文件1] [复制新文件的名字] (不加目录默认当前目录) 以下操作仅仅对文件，文件夹需要加参数 -rf
  # cp file file2 复制当前目录下的file文件到当前目录下，并且命名为file2
  # cp file /home/yuri/file2 复制当前目录下的file文件到/home/yuri目录下，并且命名为file2
  
  > ls            #输入ls查看当前目录下有什么 发现有一个文件 一个文件夹
  
  CloudMusic  神话.flac
  > ls CloudMusic  #查看这个文件夹里有什么？  发现什么都没有     
            
  > cp 神话.flac CloudMusic  #将当前目录下的神话.flac 复制到 CloudMusic 
               
  > ls CloudMusic  #查看文件夹下面是不是已经有文件了  发现已经有了
  
  神话.flac
  
  # cp -rf [文件夹名字] [新文件夹名字]
  
  > cp -rf CloudMusic CloudMusic_cp #复制cloudmusic 文件夹 并命名成cloudmusic_cp
  
  > ls #
  CloudMusic  CloudMusic_cp  神话.flac
  
  ```

- **mv** 和上面 cp 命令使用情况基本一样 在对文件夹使用时 可以不用加 -rf 参数

- **./**  执行可执行文件 输入 ./可执行文件名字 即可执行一个可执行文件

  ```bash
  > ls
  hello  hello.cpp 
  # 使用g++ 将hello.cpp 编译为一个可执行文件 hello （linux 可执行文件一般没有后缀，不像win 的 .exe）
  
  > ./hello    #执行可执行文件      
  hello world
  ```

- **mkdir** make directories 的缩写，用于创建新目录

  ```bash
  > ls  #查看文件下文件
  hello  #只有一个hello文件夹
  > mkdir hhh #新建hhh 目录
  >ls
  hello hhh #再次查看发现有了
  
  # 注意： 新建的目录必要存在 比如mkdir hhh/test_1/test_2 如果中间 test_1 不存在就会报错
  
  mkdir -p hhh/test_1/test_2 递归创建目录 即使test_1 不存在
  ```

- **clear** 清空终端的命令 

- **sudo** 暂时获取root权限命令

- 待补充

### bazel 的使用



### 参考 以及后续学习

[菜鸟教程： linux命令](https://www.runoob.com/linux/linux-command-manual.html)



# 正式开始学习









​	

