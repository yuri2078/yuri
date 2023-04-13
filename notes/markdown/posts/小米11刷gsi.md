---
title: 小米11刷gsi
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 教程
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/3.png'
date: 2021-11-20 16:00:21.615
updated: 2021-11-20 16:46:58.036
tags:
keywords:
---

分享一下大佬 @和奥奥学Py 的vab分区机型刷gsi教程 
不要在问我别的有没有了，我不是大佬，我只是一个搬运工而已，教程放在这里，自己动手丰衣足食
理论上小米11p 11u [流汗滑稽]也可以

前言：
	本教程原帖链接 https://fiime.cn/thread/463

因为各种人各种不同的情况，我就不一一解释里面的情况了，懂得自己看着原来的教程自己省略一些步骤，不懂得老老实实跟着我的教程走，虽然可能不用这么麻烦，不过总归没有错



请提前备份数据！
请提前备份数据！
请提前备份数据！
请提前备份数据！
请提前备份数据！
大佬的原教程：
小米11刷入GSI/SGSI镜像步骤
1.解密动态分区文件
fastboot --disable-verification flash vbmeta
2.刷入MIUI recovery(如果你是线刷完稳定版MIUI的话就不用刷这个了，跳过就是)命令：
fastboot flash recovery 加实际地址
3.进入到fastbooted模式必须在fastboot模式下才能进入fastbootd模式
使用命令(回车)fastboot reboot fastboot兔子界面蓝色文字变成黄色文字 仔细观察OK，刷完了H。刷入GSI ROM使用命令
fastboot flash system 加实际地址
6.执行双清DATA使用命令(回车)
fastboot -w
请提前备份数据！
请提前备份数据！

小白专用教程：

1 下载所需的东西
miflash （我用的是2018.5版本）
miui12 线刷包 
想要刷的gsi （dot os） 
gsi链接 ：https://github.com/phhusson/treble_experimentations/wiki/Generic-System-Image-(GSI)-list 下载ab的 用魔法下载会变得快点[受虐滑稽]

所需工具链接 https://wwi.lanzoui.com/b016j5bcf 密码:3pd5

2 全部下载好了，手机链接电脑把文件全部拖入电脑
解压miflash压缩包 
解压miui线刷包（第一次解压出来是一个tar后缀的压缩包，要再解压一次，知道解压出来的是一个文件夹）

3 准备阶段
解压miflash 双击里面的 XiaoMiflash.exe 第一用这需要点击左上角 Driver 安装驱动

然后点击选择，选择刚刚解压出来的线刷包

如果出现 couldnt find flash script 那就是文件夹选在错了，一定要选择有bat命令文件的外层文件夹

4 重置阶段
点击 加载设备 加载出来后，看下下面对应的命令有没有选择好
别点全部删除并上锁就行，其他两个看你自己
刷完等它重启，你可以等它进系统再进fast boot 也可以直接强制关机直接进fastboot

5 推送命令阶段 
文件夹目录可以自己改，对应的命令的目录和名字也要改，懂得自己改，不明白怎么改的就按我说的来
在c盘根目录建立名为venus的文件夹把解压出来的线刷包里image目录下的 vbmeta.img 和 gsi镜像放进文件夹
解压FiimeROM工具箱 打开 Fiime命令行工具箱.exe 在弹出的界面输入按顺序输入命令

1 fastboot --disable-verification flash vbmeta C:\venus\vbmeta.img 
2 fastboot reboot fastboot （刷完这个命令会重启到fastbootd 看到字体变成黄色的就成功了） 
3 fastboot flash system C:\venus\dotos.img （名字为镜像的名字） 
4 fastboot -w （格式化 ）
5 fastboot reboot （ 重启）

