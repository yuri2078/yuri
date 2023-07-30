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

## 移动

- 上下左右 -> `kjhl`
- `^` 移动到行首`$` 移动到行尾
- `w` 跳到下一个单词开头 `e` 下一个单词结尾
-  `/vim` 向下查找vim `？vim` 向上查找vim
-  `*` 向下查找光标所在单词 `#` 向上查找光标所在单词
-  `ctrl b` 向上翻页 `ctrl f` 向下翻页 
-  `gg` 文件开头 `G` 文件末尾

## 删除和修改

- `dd` -- 删除当前行
- `x` -- 删除光标所在字母
- `r+新字母` -- 修改字符
- `选中后 x | d` 删除选中内容
- `选中后 c` 删除选中内容并且将光标切换为插入模式

## 复制

- `yy` -- 复制当前行
- `选中 + y` -- 复制选中内容
- `p` -- 粘贴到当前下一行
- `P` -- 粘贴到当前上一行

## 撤销

- `u` -- 撤销
- `ctrl + r` -- 反撤销

## 其他操作

- `10p` -- 粘贴10次
- `space l c` 注释
- `space l f` 格式化代码
- `space l t` 运行代码
- 
- `c n` 打开代码导航
- 