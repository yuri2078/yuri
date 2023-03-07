/*------------------------------------------------------------------------
【程序改错】
--------------------------------------------------------------------------

题目：函数将str字符串中的5个数字字符串转换为正、负整数，保存在二维数组m的
      最后一行，各元素为3、-4、16、18、6。并经函数move处理后，运行结果如下：

18     6     3    -4    16
16    18     6     3    -4
-4    16    18     6     3
 3    -4    16    18     6

--------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
------------------------------------------------------------------------*/
#include<stdio.h>
#include<ctype.h>
#define ROW 4
#define COL 5
void abstract(char str[],int m[])
{
    int i,j,k,sign=1;
    for(k=j=i=0;str[i];i++)
    {
        if(isdigit(str[i]))
        {
            if(str[i-1]=='-')
                sign=-1;
            k=k*10+str[i]-'0';
        }
        /***********FOUND***********/
        if(isdigit(str[i])&&str[i+1]!=0)
        {
            m[j++]=k*sign;
            sign=1;
            k=0;                
        }
    }
}
void move(int m[][COL])
{
    int i,j;
    for(i=ROW-2;i>=0;i--)
        for(j=0;j<COL;j++)
            /***********FOUND***********/
            m[i][j]=m[i+1][j+1];        
}
int main()
{
    char str[]="digit3posi-4plus16zero18six6 ";
    int m[ROW][COL];
    int i,j;
    /***********FOUND***********/
    abstract(str,m[0]);
    move(m);
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
    return 0;
}
