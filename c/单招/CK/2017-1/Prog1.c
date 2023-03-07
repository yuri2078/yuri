/*-----------------------------------------------------------------------
【程序填空】
-------------------------------------------------------------------------
题目：main函数找出二维数组m[N][N]中每行的奇数（每行仅有一个奇数），并调用
      move函数将该奇数移动到该行主对角线位置。

函数void move(int m[],int from,int to)的功能是将一维数组m的from列元素移动
到to列。程序显示结果为：

移动前:
    14   5  10   6
    37  24  12   2
    10   6  19  28
     4  17  18  24
移动后:
     5  10   6  14
     2  37  24  12
    10   6  19  28
    18  24   4  17
-------------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
-----------------------------------------------------------------------*/

#include<stdio.h>

#define N 4 
 
void move(int m[],int from,int to)
{
    int i,t;
/**************************SPACE*************************/
    for(; from【?】to ; )
    {
        t=m[0];
        for(i=1;i<N;i++)
            m[i-1]=m[i];
        m[N-1]=t;
/**************************SPACE*************************/
        from=【?】;
        if(from<0)from=N-1;
    }
}
void print(int m[][N])
{
    int i,j;
    for(i=0;i<N;i++)
    { 
        for(j=0;j<N;j++) 
            printf("%4d",m[i][j]);
        printf("\n");
    }
}
int main()
{
    int m[N][N]={{14,5,10,6},{37,24,12,2},{10,6,19,28},{4,17,18,24}};
    int row,col;
    printf("移动前:\n");
    print(m);
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(m[row][col]%2 && row!=col)
            {
                move(m[row],col,row);
                break;
            }
    printf("\n移动后:\n");
    print(m);
    return 0;
}