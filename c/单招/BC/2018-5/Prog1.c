/*------------------------------------------------------------------------
【程序设计】
--------------------------------------------------------------------------
题目：二维数组a[N][M]中存储了N*M个整数，找出该数组前RN行中最大数，并用
      该整数所生成的降序数将其替换。

      所谓降序数是指该数的高位数字不小于低位数字，比如整数7531是降序数。
      
编写程序：
    1.函数int findmax(int mp[],int a[][M],int n)的功能是查找二维数组a前n行
      数据中的最大数及其位置。将最大数的行列位置依次保存在mp中，函数返回
      最大值。
      
    2.函数array_change(int mp[],int a[][M],int max)的功能是用max的降序数替
      换数组a中，行列位置在mp[]中的元素。

测试样例：数组a中共有4行3列数据，数组a前3行
          数据中的最大数是1735，由1735生成的降序数是7531

程序运行前的初始数据      423    8  1602
                           32   64  1237
                         1328 1735   256
                          512 1024  2084

程序运行后的结果数据      423    8  1602
                           32   64  1237
                         1328 7531   256
                          512 1024  2084
-------------------------------------------------------------------------
注意：请勿改动主程序main()中的任何语句。
-------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#define N 4 
#define M 3 
#define RN 3

int findmax(int mp[],int a[][M],int n)
{
/**********Program**********/




/**********  End  **********/
}

void array_change(int mp[],int a[][M],int max)
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    FILE *fp;

    int max,i,j;
    int mp[2]={0}; 
    int a[N][M]={{423,8,1602},{32,64,1237},{1328,1735,256},{512,1024,2084}};

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    printf("\n");

    max=findmax(mp,a,RN);
    array_change(mp,a,max);

    if((fp=fopen("data.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            fprintf(fp,"%5d",a[i][j]);
            printf("%5d",a[i][j]);
        }
        fprintf(fp,"\n");
        printf("\n");
    } 
    fclose(fp);
    return 0;
}

