# 软件安装方面

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

## 文件操作命令

### 目录结构

1. Bin 全称inary 存储一些二进制文件

2. Dev 存放外接设备如光盘之类的

3. Etc 存储一些配置文件

4. Home 用户主要文件

5. Proc 全称porcess 表示进程，存储linux运行时候的进程

6. Root root用户的家目录

7. Sbin super Binary 二进制文件

8. usr 存放用户安装应用的目录

9. var 存放程序/系统的日志

## linux指令

+ 指令格式

    `ls -l -a -h ./home` 等价于 `ls -lah ./home`

+ 常用指令

    1. ls [路径] 查看当前目录下的文件
        + ls -l 以详细列表形式展示
        + ls -a 显示所有文件 包括隐藏文件
        + ls -h 表示可读性较高的形式显示
        + ls ./ 显示本级目录
        + ls ../ 显示上一级目录
    2. pwd 查看当前目录
    3. cd 切换目录
        + cd ~ 进入home目录
        + cd .. 进入上一级目录
    4. mkdir 创建文件夹
        + mkdir -p a/b/c 一次性创建多个不存在的目录
        + mkdir a b c 一次性创建多个目录
    5. touch 创建文件
    6. rm 删除文件
        + rm -rf hhh 删除当前文件下 hhh文件夹里的内容
    7. cp 复制文件
        + cp -r hello 复制文件夹
    8. mv 移动文件
    9. man ls 查看ls手册
    10. reboot 重启
    11. poweroff 关机
    12 shutdown -h now 关机

## 补充指令

1. time ./a 找到执行时间
