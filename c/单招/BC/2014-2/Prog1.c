/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中由一组正整数组成的一维数组a为测试数据，
      首先找出出现次数最多的整数，若不同整数有相同的最多
      出现次数时，选择最早出现的整数。再判断此整数是否为阿
      姆斯特朗数。
      阿姆斯特朗数是指，一个正整数等于其各位数字的立方和。
编写程序：
      1、编写 int maxt(int a[],int n)函数，按上述规则找出
         数组a中出现次数最多的正整数，函数返回此数。
      2、编写 int amst(int m)函数，判断参数m是否为阿姆斯特
         朗数，是阿姆斯特朗数函数返回1，否则函数返回0。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define N 10
int maxt(int a[],int n)
{
/**********Program**********/
 



/**********  End  **********/
}

int amst(int m)
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    int a[N]={370,612,153,267,153,153,267,407,407,371};
    int m;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    m=maxt(a,N);
    if(amst(m))
    {
        fprintf(fp,"%d is an Armstrong number.\n",m);
        printf("%d is an Armstrong number.\n",m);

    }
    else
    {
        fprintf(fp,"%d is not an Armstrong number.\n",m);
        printf("%d is not an Armstrong number.\n",m);
    }
    fclose(fp);
}
