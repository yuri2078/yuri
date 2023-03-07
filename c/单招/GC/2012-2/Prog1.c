/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：主函数main()中调用fun()函数，其中fun函数的功能是将
      字符串s中下标为奇数的字符或ASCII码值为偶数的字符依
      次放入字符串t中。例如，字符串s为”AABBCCDDEEFF”，
      则输出应当是”ABBCDDEFF”。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N 80
void fun(char s[],char t[])
{
    unsigned i,j=0;
    for(i=0;i<strlen(s);i++)
/***********FOUND***********/
    if(i%2&&s[i]%2==0)
        t[j++]=s[i];
/***********FOUND***********/
    t[i]='\0';
}

int main()
{
    char s[N],t[N];
    printf("Please input string s:");
/***********FOUND***********/
    scanf("%s",&s);
    fun(s,t);
    printf("The result is:%s\n",t);
    return 0;
}
