/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：主函数main()中调用count()函数统计子串substr在字符串
      str中出现的次数。例如字符串str为”abdrgabdd”，子串
      substr为”ab”，则子串在该字符串出现的次数为2。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include<stdio.h>
int count(char str[],char substr[])
{
/***********FOUND***********/
    int i,j,k,num;
    for(i=0;str[i]!='\0';i++)
    {
/***********FOUND***********/
        for(j=0,k=0;substr[k]==str[j];k++,j++)
            if(substr[k+1]=='\0') 
            { num++;break; }
    }
    return(num);
}

int main()
{ 
    char str[80],substr[80];
    int num=0;
    printf("Please input string:");
    gets(str);
    printf("Please input substring:");
    gets(substr);
/***********FOUND***********/
    num=count(str[80],substr[80]);
    if(num)
        printf("Substing :%d\n",num);
    else
        printf("%s is not substring!\n",substr);
    return 0;
}