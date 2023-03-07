/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：主函数main()调用fun()函数，其中fun函数的功能是：计
      算二维数组周边元素之和，作为函数值返回。二维数组中
      的值在主函数中赋予。例如，若二维数组中的值为：
        1  3  5  7  9
        2  9  9  9  4
        6  9  9  9  8
        1  3  5  7  0
      则函数值1+3+5+7+9+4+8+0+7+5+3+1+6+2=61。

下面给定的程序存在错误，请改正。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include<stdio.h>
/***********FOUND***********/
int fun(int a[4][])
{
    int i,j,sum=0;
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
/***********FOUND***********/
            if(i==0&&j==0&&i==3&&j==4)
/***********FOUND***********/
                sum=a[i][j];
    return sum;
}

int main()
{
    int aa[4][5]={{1,3,5,7,9},{2,9,9,9,4},{6,9,9,9,8},{1,3,5,7,0}};
    int i,j,y;
    printf("The original data is:\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
            printf("%6d",aa[i][j]);
        printf("\n");
    }
    y=fun(aa);
    printf("The sum:%d\n",y);
    return 0;
}
