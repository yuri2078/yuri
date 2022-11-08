#!/bin/bash
FILE=$(ls -a)
echo "$FILE"
for file in $FILE; do
    if [ "$file" == "phpMyAdmin.tar.gz" ];then
       read -rp "y/n : " bool
       if [ "$bool" == "y" ];then
           # 复制到根目录
           cp "$file" "/home/yuri/yuri" 
          echo '进入 http://localhost/admin 访问文件'
          
       fi
    fi
done
