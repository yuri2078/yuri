/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中一维数组a为测试数据,程序将测试数据进
      行加密，加密后的数据存入数组b中，判断数组b中是否存
      在素数，将所有素数存入数组c中，并输出。

编写程序：
      1. 编写函数void encode(int x[],int n,int y[]),将数
         组x中n个不超过3位的正整数逐个做加密处理，
         并将加密后的数据存入数组y中。加密方法如下：将正
         整数的每一位用该位数字加该位序号的值替换（序号
         规定：个位为3，十位为2，百位为1），若结果大于9，
         则用该数除以10的余数替换。

      2. 编写函数int CheckPrime(int y[],int n,int c[])，
         判断数组y中n个整数是否是素数，并将所有素数存入数
         组c中，函数返回素数个数。

例如：
    测试数据:
        25,90,89,24,125
    运行结果:
        c[0]=13 is prime
        c[1]=2 is prime
        c[2]=47 is prime

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void encode(int x[],int n,int y[])
{
/**********Program**********/




/**********  End  **********/
}

int CheckPrime(int y[],int n,int c[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    int i,a[10]={25,90,89,24,125},b[10]={0},c[10]={0};
    int num=0,n;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    
    n=5;
    encode(a,n,b);
    num=CheckPrime(b,n,c);
   
    for(i=0;i<num;i++)
    {
        printf("c[%d]=%d is prime\n",i,c[i]);
        fprintf(fp,"c[%d]=%d is prime\n",i,c[i]);
    }
    fclose(fp);
    getch();
    return 0;
}