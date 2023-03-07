/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：将字符串s中的所有数字字符顺序前移，其他字符顺序后移。
      例如，s为asd123fgh456，则处理后的新字符串应为
      123456asdfgh。

---------------------------------------------------------
注意：请勿改动主函数main()中的其他内容。
-------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
    void fun(char s[]);
    char s[80];
    printf("Please input the string:");
    scanf("%s",s);
    fun(s);
    printf("The result is %s\n",s);
}
void fun(char s[])
{
    int i,j,k;
    char p[80],t[80];
    j=k=0;
    for(i=0;s[i]!='\0';i++)
    {
/***********SPACE***********/
        if(【?】)  p[j++]=s[i];
        else t[k++]=s[i];
    }
    for(i=0;i<j;i++)
        s[i]=p[i];
    for(i=0; i<k;i++)
/***********SPACE***********/
        s[【?】]=t[i];
    s[j+k]=0;        
}
