/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中由正整数组成的一维数组a为测试数据，首
      先将数组a中元素复制到数组b中，复制规则为真因子和为
      奇数的整数复制1次，真因子和为偶数的整数连续复制2次。
      再求数组b相邻两数的最大公约数，并存入数组c中。真因
      子是指不包括整数本身的因子。

例如：数组a中整数为
          15 28 50 76 63，
      复制到b中为
          15  28  28  50  76  76  63。
      存入数组c的相邻两数最大公约数为
          1 28 2 2 76 1。

编写程序：
      1、编写int copy(int a[],int n，int b[])函数，按上述
         规则将数组a中的整数复制到数组b中，函数返回数组b
         中整数个数。
      2、编写void gcd(int b[],int n,int c[])函数，求数组b
         相邻两数的最大公约数，存入数组c中，参数n为数组b
         中整数个数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define M 5
#define N 10
int copy(int a[],int n,int b[])
{
/**********Program**********/



 
/**********  End  **********/
}

void gcd(int a[],int k,int c[])
{
/**********Program**********/



 
/**********  End  **********/
}

void main(){
    int  a[M]={15,28,50,76,63};
    int  b[N],c[N];
    int  i,n;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=copy(a,M,b);
    fprintf(fp,"After copying:\n");
    printf("After copying:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d  ",b[i]);
        printf("%d  ",b[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    gcd(b,n,c);
    fprintf(fp,"Aarray c:\n");
    printf("Array c:\n");
    for(i=0;i<n-1;i++)
    {
        fprintf(fp,"%d  ",c[i]);
        printf("%d  ",c[i]);
    }
    fclose(fp);
}



