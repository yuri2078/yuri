/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：N个有序整数数列已放在一维数组a中，下列给定程序中，
      函数fun的功能是：利用折半查找算法找整数m在数组中的
      位置。若找到，则返回其下标值；反之，则返回－1。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#define N 10
int fun(int a[],int m)
{
/***********FOUND***********/
        int  left=1, right=N, mid;
        while(left<=right)
        {
                mid=(left+right)/2;
                if (m>a[mid])
/***********FOUND***********/
                        right =mid - 1;    
                else if (m<a[mid])
/***********FOUND***********/
                        left = mid -1;
                     else return (mid);
        }
        return(-1);
}

main()
{
        int  i, a[N]={-3,4,7,9,13,45,67,89,100,180}, k, m;
        printf("a数组中的数据如下：");
        for(i=0;i<N;i++) 
                printf("%d ",a[i]);
        printf("\nEnter m:");
        scanf("%d",&m);
        k=fun(a,m);
        if (k>=0) 
                printf("m=%d,index=%d\n",m,k);
        else 
                printf("Not be found!\n");
        return 0;
}