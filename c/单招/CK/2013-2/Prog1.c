/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：对二维数组a中存储的N*N矩阵做如下操作：先将每一行中值
      最大的元素与该行位于主对角线处的元素交换，然后对主对
      角线上所有元素排序使其自左上角到右下角升序排列，最后
      输出排序后主对角线上各元素的值。

---------------------------------------------------------
注意：请勿改动主函数main()中的其他内容。
-------------------------------------------------------*/

#include<stdio.h>
#define N 5
void fun(int x[][N],int n)
{
    int i,j,t,arr,col;
    for(i=0;i<n;i++)
    {
        arr=x[i][0];col=0;
        for(i=0;i<n;i++)
        {
            arr=x[i][0];col=0;
/***********SPACE***********/
            for(j=0;j<n;j++) if(x[i][j]>=arr) {arr=x[i][j]; 【?】}
            t=x[i][i]; x[i][i]=x[i][col];x[i][col]=t;
        }
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++) 
/***********SPACE***********/
                if(【?】)
                { t=x[i][i]; x[i][i]=x[j][j]; x[j][j]=t;}
    }
}
void main()
{
    int a[N][N]={{10,25,24,13,23},{11,22,12,21,14},{20,15,19,16,18},
                {17,9,4,5,3},{2,1,6,7,8}};
    int i;
    fun(a,N);
    for(i=0;i<N;i++) printf("%4d",a[i][i]);
    printf("\n");
}
