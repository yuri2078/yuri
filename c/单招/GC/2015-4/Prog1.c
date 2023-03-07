/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：void add(char a[],char b[],char c[])函数将由'0','1'
      组成的字符串a,b按二进制数加法规则相加，和仍以'0','1'
      组成的字符串形式保存到字符串c中。

例如：字符串a为"1100",字符串b为"111",调用add函数后字符串c
      为"10011"。

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
void reverse(char s[])
{
    int i,len;
    char t;
/*******************FOUND*******************/
    len=strlen(s-1);
    for(i=0;i<len/2;i++)
    {
        t=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=t;
    }
}
void add(char a[],char b[],char c[])
{
    int i,j,k,t,flag;
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=flag=0;
    while(i>=0||j>=0)
    {
        if(i<0)
            t=b[j]-48+flag;
        else if(j<0)
            t=a[i]-48+flag;
        else
            t=a[i]-48+b[j]-48+flag;
/*******************FOUND*******************/
        c[k]=t/2;
        k++;
        flag=0;
        if(t>1) 
            flag=1;
        i--;
        j--;
    }
/*******************FOUND*******************/
    if(flag==0) 
        c[k++]='1';
    c[k]='\0';
    reverse(c);
}
int main()
{
    char a[50],b[50],c[51];
    printf("Input a(binary):\n");
    scanf("%s",a);
    printf("Input b(binary):\n");
    scanf("%s",b);
    add(a,b,c);
    printf("After adding  a+b=%s\n",c);
    return 0;
}