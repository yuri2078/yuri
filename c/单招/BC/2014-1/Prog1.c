/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中字符串s为测试数据，首先将字符串s中的
      数字字符子串取出，转换成对应的十进制整数，并存入数
      组a中，然后找出数组a 中的所有回文素数。
      回文素数是指，一个整数与其逆序数等值，且是素数。

例如：字符串s为" 17rose  t131ar  *d373monkey852y heo181c!#",
      处理后存入数组a中的整数为17,131,373,852,181。回文素
      数有131,373和181。

编写程序：
      1、编写int abstract(char s[],int a[])函数，取出s中的
         数字字符子串，转换成十进制整数，存入数组a，函数返
         回存入a中的整数个数。
      2、编写int pal_prime(int a[],int n,int b[])函数，找
         出数组a中所有的回文素数，存入数组b，参数n为数组a
         中整数个数，函数值为回文素数的个数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
int abstract(char s[],int a[])
{
/**********Program**********/
 



/**********  End  **********/
}

int pal_prime(int a[],int n,int b[])
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    char s[50]={" 17rose  t131ar  *d373monkey852y heo181c!#"};
    int a[50],b[50];
    int i,n;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,a);
    fprintf(fp,"Following are integers:\n");
    printf("Following are integers:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
        printf("%d ",a[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    n=pal_prime(a,n,b);
    fprintf(fp,"Following are palindrome primes:\n");
    printf("Following are palindrome primes:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",b[i]);
        printf("%d ",b[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    fclose(fp);
}
