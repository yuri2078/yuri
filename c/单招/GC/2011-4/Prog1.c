/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：程序去除主函数main()中字符串str中的非字母字符。函数
      IsAlpha()的功能是判断字符c是否为字母。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>

int IsAlpha(char c){
/***********FOUND***********/
    return ((c>='a' && c<='z') && (c>='A' && c<='Z'));
}

int main(){
    char str[]={"/** One World,One Dream! **/"};
    int prev,next;
    prev=next=0;
    while(str[next]){
        if(IsAlpha(str[next])){
/***********FOUND***********/
            str[next]=str[prev];
            prev++;
        }
        next++;
    }
/***********FOUND***********/
    str[next]=0;
    puts(str);
    getch();
    return 0;
}