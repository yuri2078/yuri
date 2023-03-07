/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：主函数main()统计字符串str中的各字母（不区分大小写）
      及其他字符出现的次数，并显示统计结果（次数为0，则不
      显示）。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(){
    char str[]={"---JiangSu Teachers University of Technology---"};
    int chnum[27]={0},i=-1;
/***********FOUND***********/
    while(str[i]){
        if(isalpha(str[i]))
/***********FOUND***********/
            chnum[toupper(str[i])-97]++;
        else
            chnum[26]++;
    }
    for(i=0;i<27;i++)
/***********FOUND***********/
        if(chnum[i]=0)
            if(i==26)
                printf("other ch=%d\n",chnum[26]);
            else
                printf("%c(%c)=%d\n",i+65,i+97,chnum[i]);
    getch();
    return 0;
}