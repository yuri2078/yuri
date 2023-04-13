---
title: linux常用命令
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images@1.6/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 小记
comments: true
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/11.png'
date: 2022-08-02 22:43:33
tags:
    - 常用命令
    - linux
keywords: 
description:
---

## 安装软件

+ sudo apt-get  update
+ sudo apt-get uprdge
+ sudo apt upgrade -y 升级系统包
+ sudo apt install ..deb 安装软件
+ sudo dpkg -i ...deb 安装应用
+ mkdir hello 创建文件夹
+ touch hello.txt 创建文件
+ sudo apt purge netease-cloud-music 卸载软件
+ sudo apt list --installed 列出apt包
+ snap list列出snap包
+ dpkg --list 列出所有安装的包
+ sudo aptitude install packer 防止出现依赖不足
+ sudo apt dist-upgrade 不知道是干啥的
+ gnome-session-properties  设置程序自己启动
+ zip -r hh.zip hh 压缩文件
+ unzip hh.zip解压文件

## 软件权限相关

+ ls -l .. 查看具有的属性
+ chmod +x ... 添加属性
+ sudo chown -R $(whoami) /usr/share/code 设置管理员权限

## 环境变量PATH

+ echo $PATH 查看环境变量path的内容
+ sudo vi /etc/environment PATH 用：隔开

## 清华镜像

1. /etc/apt/sources.list  

`https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/`
