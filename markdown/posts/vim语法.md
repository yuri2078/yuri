---
title: vim语法
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 小记
comments: true
description: '我的爱宛如孤岛之花，不为人知的绽放,不为人知的凋零！'
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/21.png'
date: 2022-08-04 19:17:31
tags: vim
keywords:
---
# vim语法

## 常规用法

1. vim 文件 用vim打开文件

2. sudo vim 文件 使用su权限打开文件

## 命令行

1. wq 保存并且退出

2. q 推出不保存

3. i 切换到插入模式

4. esc 推出编辑模式，切换到命令行模式

5. h-左 j-上 k-下 l-右

6. 0 到这一行的开头

7. yy 拷贝 dd 剪切 p粘贴

8. set fileencoding 查看编码

9 :1,$s/word1/word2/g 或 :%s/word1/word2/g 用world2 替换world1