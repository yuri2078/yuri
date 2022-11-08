#!/bin/bash
while 'true' ; do
    read -rp "请输入分数 : " NUM
    if [ "$NUM" == "q" ];then
       break
    fi

    if [ "$NUM" -ge "0" ] && [ "$NUM" -le "100" ]; then
        if [ "$NUM" -ge "60" ]; then
           echo "及格捏"
        else
           echo "没有及格捏"
        fi
    else 
       echo "请输入一个正确的整数"
    fi
done
