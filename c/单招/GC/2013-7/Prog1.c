/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面程序的功能是：验证是否存在两个大于2而小于n的素数
      p1与p2，使得n=p1+p2.(2012<=n<=2016)

请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int); 
int find(int,int[]);    //寻找符合条件的素数对
void main()
{
    int n,p[2];
    for(n=2012;n<=2016;n++){
        if(find(n,p))
            printf("%d=%d+%d\n",n,p[0],p[1]);
        else
            printf("Not Exist m and n make %d=m+n\n",n);
    }
}

/****************FOUND*****************/
void find(int n,int p[])
{
    int n1=3,n2,flag=0;    
    
    while(n1<=n/2 &&!flag)
    {
        if(prime(n1))    n2=n-n1;
/****************FOUND*****************/        
        if(prime(n2=1))
        {
            p[0]=n1;
            p[1]=n2;
            flag=1;
        }
        n1=n1+2;
    }
    return flag;
}


int prime(int n)    //判断一个正整数n是否为素数
{
    int i=2;
/****************FOUND*****************/    
    while(i<=sqrt(n)&&n%i==0) i++;
    
    if(i>sqrt(n))    return 1;    
    return 0;
}