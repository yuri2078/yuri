/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面程序的功能是：首先随机产生N个2至3位的整数并将其
      存放于数组s中，然后从s中找出所有的互质数对(所谓的互
      质数对是指两个数最大公约数是1)， 将所找出的互质数对
      存放于二维数组t中。

请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5

int find(int[],int[][2],int); //查找互质数对
int huzhi(int,int);    //判断两个正整数是否互质
void main()
{
    int s[N],t[N*(N-1)/2][2],n=0,i=0;
    
    srand((unsigned)time(NULL));    //初始化随机数时间序列    
    for(i=0;i<N;i++)    //随机产生N个2至3位正整数
    {
        s[i]=rand()%990+10;
        printf("%6d",s[i]);
    }
    printf("\n");
    
    n=find(s,t,N);

    for(i=0;i<n;i++)
        printf("%6d,%6d\n",t[i][0],t[i][1]);
}

/****************FOUND*****************/
int find(int s[],int t[][],int n){
    int i,j,k=0;
    for(i=0;i<n-1;i++)
/****************FOUND*****************/        
        for(j=0;j<n;j++)
            if(huzhi(s[i],s[j])){
                t[k][0]=s[i];
                t[k][1]=s[j];
                k++;
            }
    return k;
}

int huzhi(int m,int n){
    int r;
    if(m<n){
        r=m;m=n;n=r;}
    r=0;    
    do{
        r=m%n;
        m=n;
        n=r;
/****************FOUND*****************/    
    }while(!r);
    
    if(m==1) 
        return 1;
    else
        return 0;
}



