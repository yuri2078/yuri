/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：将字符串中最前面和最后面的*号去掉，并将字符串中间1
      个或多个连续的*号替换为1个空格。

例如：初始字符串为"*****this*is****C****program****"，
      结果为"this is C program"

---------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
-------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
void rep(char str1[],char str3[])
{
    char str2[80];
    int front,back,i,j;
    for(front=0;str1[front]=='*';front++)
        ;
    back=strlen(str1);
    for(;str1[back-1]=='*';back--)
        ;
    for(i=front;i<back;++i)
/**************************SPACE*************************/
        str2[【?】]=str1[i];
    str2[back-front]=0;
    for(i=j=0;str2[i];i++)
        if(str2[i]!='*') 
            str3[j++]=str2[i];
/**************************SPACE*************************/
        else if(str2[【?】]!='*') 
            str3[j++]=' ';
    str3[j]=0;
}
int main()
{
    char str1[]="*****this*is****C****program****",str3[80];
    rep(str1,str3);
    puts(str1);
    puts(str3);
    return 0;
}