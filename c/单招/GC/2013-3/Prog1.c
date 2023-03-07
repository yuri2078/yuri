/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面程序中，sort函数的功能是：将n个随机生成的无序整数
      从小到大排序。

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 10
void getarray(int [],int n);
void printArray(int [],int n);
void sort(int [],int n);

void main()
{
    int aa[MAX];
    srand((unsigned)time(NULL));    //初始化随机数时间序列
    getarray(aa,MAX);
    printf("\n\nThe Array Before sorted:\n");
    printArray(aa,MAX);
    sort(aa,MAX);    
    printf("\n\nThe Array After sorted:\n");
    printArray(aa,MAX);
}
void getarray(int a[],int n)
{
    int i=0;
/***********FOUND***********/ 
    for(;i>n;i++)
    {
        a[i]=rand()%99+1;
    }

}
void sort(int a[],int n)
{
    int i, j, k, t;
    i=0;
    do
    {
        k=i;
/***********FOUND***********/ 
        j=0;
        while(j<n)
        {
            if(a[j]<a[k]) k=j;
            j++;
        }
/***********FOUND***********/ 
        if(k<i)
        {
            t=a[i];a[i]=a[k];a[k]=t;
        }
        i++;
    }while(i<n-1);
}

void printArray(int a[], int n)
{
    int i=0;
    for (; i<n; i++)
    {
        printf("%5d", a[i]);    
    } 
    printf("\n");
}