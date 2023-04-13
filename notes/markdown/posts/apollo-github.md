---
title: apollo_github版本配置
author: yuri2078
avatar: https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg
authorLink: https://2078.site
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: apollo
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放,不为人知的凋零！
photos: https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/15.png
date: 2022-10-22 14:48:14
tags:
keywords:
---

****
> 来源 : apollo 官方 [github](https://github.com/ApolloAuto/apollo)
> 参考 : [apollo profile操作方法](https://zhuanlan.zhihu.com/p/543374607)

## 克隆 apollo 仓库

一般建议克隆在home目录就行

```bash
    git clone -b dv_plugin_manager_support  https://github.com/ApolloAuto/apollo.git
    #如果提示报错就终端输入，或者地址改成ssh链接
    git config --global http.postBuffer 524288000

```

## 安装插件

1. 进入apollo社区 `https://apollo.baidu.com/community`
2. 登陆控制台
3. 点击右上角 进入个人信息
4. 点击第三个选项 服务权益
5. 点击第二个仿真
6. 点击插件安装 然后生成 选择第二个github版本
7. 复制命令
8. 终端输入命令 (不是docker容器)

## 构建apollo

1. 终端依次输入以下命令

    ```bash
    #cd 进apollo目录
    cd apollo 
    rm -rf /apollo/.cache/{bazel,build,repos}
    ./apollo.sh config --noninteractive

    #我也不知道这两个命令是不是必要的，反正我输入了。
    ```

2. 新建容器 `./docker/scripts/dev_start.sh` 也可以使用`bash docker/scripts/dev_start.sh`
3. 进入docker容器 `./docker/scripts/dev_into.sh`
4. 在docker容器里面重新输入一遍刚刚生成的插件命令
5. `./apollo.sh build`开始构建系统
6. 如果不想全部构建，也可以只构建你想要的东西
7. 如果下载go套件报错,在docker输入以下命令解决

    ```bash
    sudo vim sudo vim /etc/hosts
    #在底部插入下面所有内容就行。
    #Download 下载
    203.208.41.32 dl.google.com
    203.208.41.32 dl-ssl.google.com
    
    #Groups
    203.208.41.32 groups.google.com
    
    #Google URL Shortener
    203.208.41.32 goo.gl
    
    #Google App Engine
    203.208.41.32 appengine.google.com

    ```

> 报错教程参考 ： [解决dl.google报错](https://blog.csdn.net/wangjl2416/article/details/126112157?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-126112157-blog-121098255.t5_landing_title_tags&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-126112157-blog-121098255.t5_landing_title_tags&utm_relevant_index=1)
