/*----------------------------------------------------------------------
【程序填空】
------------------------------------------------------------------------
题目：数组a内有二行字符串。每个字符串包含有多个单词，各个单词用一个或多
      个空格分隔，请将各单词本身逆序。

例如：
原始数据：
 pots  pans i saw a  reed 
c si a gnimmargorp egaugnal

逆序操作后的数据：
 stop  snap i was a  deer 
c is a programming language

-----------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他部分。
---------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 2
void swap(char a[],int i,int j)
{
    while(i<j)
    {
        a[i]=a[i]-a[j];
        a[j]=a[i]+a[j];
/**************************SPACE*************************/
        a[i]=【?】;
        i++;j--;
    }
}

void reverse(char a[][81],int m)
{
    int i,j,n;
    for(j=0;j<m;j++)
    {
        i=0;
        while(a[j][i]!=0)
        {
            while(a[j][i]==' ') i++;
            if(a[j][i]==0) break;
            n=0;
            while(a[j][i+n]!=' '&&a[j][i+n]!=0)
            n++;
/**************************SPACE*************************/            
            swap(a[j],i,【?】);
            i=i+n;        
        }
    }
}

int main()
{
    int i;
    char a[N][81]={" pots  pans i saw a  reed ","c si a gnimmargorp egaugnal"};
    printf("原始数据:\n");
    for(i=0;i<N;i++) 
        puts(a[i]);
    printf("\n");
    reverse(a,N);
    printf("逆序操作后的数据:\n");    
    for(i=0;i<N;i++) 
        puts(a[i]);
    return 0;    
}
