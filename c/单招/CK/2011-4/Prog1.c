/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：程序输出由0~3四个数字组成的符合下列条件的4位整数：
      1. 每个4位整数中，0~3四个数字只能出现一次；
      2. 百位数不能为3，十位数不能为2。

---------------------------------------------------------
注意：请勿改动主函数main()中的其他内容。
-------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>

int main(){
    int g,s,b,q;
    int num=0;
    for(b=0;b<4;b++){
        if(b==3) continue;
        for(s=0;s<4;s++){
            if((b==s)||(s==2)) continue;
/***********SPACE***********/
            for(q=【?】;q<4;q++){
                if((q==b)||(q==s)) continue;
/***********SPACE***********/
                g=【?】-q-b-s;
                printf("%d\n",q*1000+b*100+s*10+g);
                num++;
            }
        }
    }
    printf("%d\n",num);
    getch();
    return 0;
}