/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：void move(int a[],int n,int m)函数将n个元素的一维
      数组a循环左移m个位置，
      void change(int a[],int n,int b[][N])函数将数组a按
      行存入二维数组b，然后将b按列重新存入数组a。

例如：数组a的元素为1,2,3,4,5,6,7,8,9,10,11,12,调用move函
      数将a循环左移3个位置后，a的元素为
      4,5,6,7,8,9,10,11,12,1,2,3,调用change函数后，a的元
      素为4,8,12,5,9,1,6,10,2,7,11,3。

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/
#include <stdio.h>
#define M 3
#define N 4
void move(int a[],int n,int m)
{
    int i,t;
    while(m)
    {
        t=a[0];
        for(i=0;i<n-1;i++)
/*******************FOUND*******************/
            a[i]=a[i+m];
        a[n-1]=t;
        m--;
    }
}
void change(int a[],int n,int b[][N])
{
    int i,j;
    for(i=0;i<n;i++)
/*******************FOUND*******************/
        b[i/M][i-i/N]=a[i];
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
/*******************FOUND*******************/
            a[j*M+i]=b[i][j];
}
int main()
{
    int a[M*N]={1,2,3,4,5,6,7,8,9,10,11,12};
    int b[M][N],i,j,m;
    printf("Before moving\nArray a:\n");
    for(i=0;i<M*N;i++)
        printf("%d ",a[i]);
    printf("\nInput m:\n");
    scanf("%d",&m);
    move(a,M*N,m);
    printf("\nAfter moving\nArray a:\n");
    for(i=0;i<M*N;i++)
        printf("%d ",a[i]);
    change(a,M*N,b);
    printf("\n\nAfter changing\nArray b:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
    printf("Array a:\n");
        for(i=0;i<M*N;i++)
            printf("%d ",a[i]);
    printf("\n");
    return 0;
}