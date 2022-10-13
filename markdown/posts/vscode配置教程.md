---
title: vscode配置教程
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 教程
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/14.png'
date: 2021-12-11 17:18:08.875
updated: 2021-12-23 20:04:15.18
tags:
keywords:
---


前言因为里面需要配置Jason文件路径，所以没有基础就按着我的路径走，等有经验了，再继续用自己的方法走

## c语言 教程

1. 下载mingw64  `https://sourceforge.net/projects/mingw-w64/files/mingw-w64/`

    选择最新的版本就行，这里用的是 gcc 810

    我们下载 x86_64-posix-seh 这个就行了
    32位系统选择32位的就行
    ![1.png](https://cdn.jsdelivr.net/gh/yuri2078/images@1.8/articlePictures/vscode配置教程/1.png)

2. 解压mingw64 到c盘根目录

    ![2.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/2.png)

3. 配置环境变量

    右击我的电脑 属性 高级系统设置 环境变量  
    进去后找到系统变量 PATH
    ![4.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/4.png)

    把刚刚解压的mingw64文件夹里的bin文件夹的目录复制进去

    ![2.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/2.png)
    ![3.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/3.png)

    ![5.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/5.png)

    弄好之后 ，win + R 组合键 然后调出cmd  使用命令 gcc -v 如果出现下面的界面表示成功
    ![6.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/6.png)

4. 下载 vscode   `https://code.visualstudio.com/`
    直接点这个 大大的蓝色的 Download for windows 下载就行了，下载完直接安装，什么都不用动直接无脑下一步。

    ![7.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/7.png)

5. 下载vsode需要的c配置文件

    下载完直接解压到你想要的地方就行了

6. 下载插件
    进vscode后直接点击左下第四个图标，下载插件  直接搜索就行了
    1 chinese 中文汉化插件 安装后需要重启
    2 code run 可以直接编写完成后 编译直接保存运行
    3 Bracket Pair Colorizer 编写代码时帮我们弄花括弧
    4 c/c++  C/C++ Extension Pack 这两个一定要安装 编写c语言需要的扩展
    5 atom 主题可用可不用

7. 编写hello c
    点击左上角第一个图标选择代打一个文件夹

    打开第五步解压的vscode 的配置文件夹
    然后选择完全信任父文件夹
    ![8.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/8.png)

    点击左上角 文件夹名字右边四个图表中的第一个然后 新建 hello.c
    ![9.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/9.png)

    然后编写代码。结束后，邮寄空白处点击run code或者点击右上角的小三角形就行了。代码会自动保存编译运行。

## python

1. 下载python `https://www.python.org/downloads/`
    直接点击那个黄色的大按钮下载就行
    ![10.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/10.png)

    然后安装，安装的时候下面有两个选项，
    把第二个  add pytho3.10 to path 勾选上，然后点击上面的 install now
    无脑下一步安装就行了

2. vscode 里搜索python扩展安装就行。
    一定要先安装完python再装扩展
    ![11.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/11.png)
    然后直接运行

## java

1. 下载Java `https://www.java.com/zh-CN/download/`

    这个无脑下一步就行了，默认安装位置就行

2. 下载jdk
    `https://www.oracle.com/java/technologies/downloads/#jdk17-windows`
![12.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/12.png)

    选择后缀是exe或者msi都可以。然后安装，这里我们不更改默认位置。直接下一步就行了。

3. 配置环境变量

    右击我的电脑 属性 高级系统设置 环境变量

    进去后我们在 系统变量下新建两个系统变量
    变量名 JAVA_HOME 值 C:\Program Files\Java\jdk-17.0.1

    这是jdk默认安装位置
    ![13.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/13.png)

    在系统变量path下，添加
    %JAVA_HOME%\jre\bin
    %JAVA_HOME%\bin
    这两个变量

4. 查看
    win + R 然后 cmd  
    输入 java -version 命令
    出现版本号就表示成功了

    ![14.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/14.png)

5. vscode扩展安装
    搜索 Java  安装  Extension Pack for Java
    这个Java包就行了

6. 点击左下角的齿轮 再点击设置
    ![15.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程15.png)

    搜索 setting 然后点第一个下面在setting.json 中设置
    ![16.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/16.png)

    进去后在最后一个花括号前加上一一句
    `"java.home": "C:\\Program Files\\Java\\jdk-17.0.1"`
    具体位置可以自己改变。
    ![17.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/17.png)

    如果出现这种报错的话!在添加的那句话的前面的语句后面加一个逗号
    ![18.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/18.png)
    如图所示没有都好就会报错

7. 打印helloJava

    ![17.png](https://cdn.jsdelivr.net/gh/yuri2078/images/articlePictures/vscode配置教程/17.png)

## vscode 常用命令

1. ctrl p 切换文件
2. ctrl  shirft L  同一改变相同值
3. f12 转到定义
4. alt f12 查看定义
5. f2 重命名符号
6. ctrl + shitf 多行选中
