#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int  isHui(int  x){
    int  k = x;
    int s = 0;
    while(k)
    {
        s = s * 10 + k % 10;
        k = k / 10;
    }
    return s == x;
}
int  findNum(int  n1,int  n2,long  a[][2])
{
    int i, k = 0,t,j;
    for (i = n1; i < n2;i++)
    {
        t = i * i + i + 17;
        for (j = 0; j < 2;j++)
        {
            if(t%10 != t/10%10)
                break;
            t = t / 10;
        }
        if(isHui(t/10)&&j==2)
        {
            a[k][0] = i;
            a[k++][1] = i * i + i + 17;
        }
    }
    return k;
}

int  main()
{
        int  n1,n2,i;
        long  a[100][2];
        scanf("%d%d",&n1,&n2);
        int  n  =  findNum(n1,n2,a);
        for(i=0;i<n;i++)
        {
                printf("%ld,%ld\n",a[i][0],a[i][1]);
        }
        return  0;
}