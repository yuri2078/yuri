/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：程序首先将随机产生的12个水仙花数存放于一个3行4列的
      数组array中，然后找出其中的最大数所在的行号与列号，
      并将行号与列号输出在屏幕上。

说明：所谓水仙花数是指其各位数字立方和等于该数本身的数。

---------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
      且不能使用C语言的库函数
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int narcissus()
{
    int M,N,t,sum,find=0;
        
    while(!find)
    {
        sum=0;
        N=rand()%900+100;
        M=N;
        while(M)
        {
            t=M%10;
/***********SPACE***********/
            【?】;
            M=M/10;
        }
        if(N==sum) find=1;
    }
    return N;
}

int max_value(int array[][4],int rw[])
{
    int i,j,max;
    max=array[0][0];
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            if(max<array[i][j])
            {
                max=array[i][j];
                rw[0]=i;
                rw[1]=j;
            }
    return max;
}

void main()
{
    int array[3][4];        //用于存放水仙花数
    int row_col_num[2];        //用于存放最大水仙数的行列号
    int i,j;

    srand((unsigned)time(NULL));
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            array[i][j]=narcissus();
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
/***********SPACE***********/
    printf("Max=%d\n",【?】);
    printf("Col number of Max is:%5d\n",row_col_num[0]);
    printf("Row number of Max is:%5d\n",row_col_num[1]);
}