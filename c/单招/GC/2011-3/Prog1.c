/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：主函数main()调用函数MyStrcat()将字符串src连接到字符
      串dstStr后面。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
void MyStrcat(char dstStr[], char srcStr[]){
    int i,j;
    i=j=0;
/***********FOUND***********/
    while(dstStr[i++]) i++;
    i-=1;
    while(srcStr[j]){
        dstStr[i]=srcStr[j];
        i++;j++;
    }
/***********FOUND***********/
    srcStr[i]=0;
}

int main(){
    char dst[100]="This is ";
    char src[20]="C Test!";
/***********FOUND***********/
    MyStrcat(dst[100],src[20]);
    puts(dst);
    getch();
    return 0;
}