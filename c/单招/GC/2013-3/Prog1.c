/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ����������У�sort�����Ĺ����ǣ���n��������ɵ���������
      ��С��������

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
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
    srand((unsigned)time(NULL));    //��ʼ�������ʱ������
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