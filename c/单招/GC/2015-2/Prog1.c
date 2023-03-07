/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：函数unsigned delbits(unsigned x,unsigned p,unsigned n)
      把非负整数x从左端第p(p>1)位开始的n位删除，形成新的数
      返回。

例如：若x为12345，p为3，n为2，形成新的数为125。
      若x为12345，p为6，n为2，形成新的数为12345。
      若x为12345，p为3，n为4，形成新的数为12。

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
unsigned delbits(unsigned x,unsigned p,unsigned n)
{
    int a[10],i,j,k;
    i=0;
    while(x)
    {
/*******************FOUND*******************/        
        a[i]=x%10;
        x/=10;
    }
    k=i;
    for(i=0;i<k/2;i++)
    {
        a[i]+=a[k-i-1];
        a[k-i-1]=a[i]-a[k-i-1];
        a[i]=a[i]-a[k-i-1];
    }
    j=p-1;
/*******************FOUND*******************/        
    for(i=p+n;i<=k-1;i++)
    { 
        a[j]=a[i];
        j++;
    }
    k=j;
    for(i=0;i<k;i++) 
/*******************FOUND*******************/        
        x+=a[i]*10;
    return x;
}
int main()
{
    unsigned x,p,n;
    printf("Input x(unsigned int):\n");
    scanf("%u",&x);
    printf("Input p(unsigned int):\n");
    scanf("%u",&p);
    printf("Input n(unsigned int):\n");
    scanf("%u",&n);
    x=delbits(x,p,n);
    printf("After deleting  x=%u\n",x);
    return 0;
}