/*----------------------------------------------------------------------
��������ա�
------------------------------------------------------------------------
��Ŀ������a���ж����ַ�����ÿ���ַ��������ж�����ʣ�����������һ�����
      ���ո�ָ����뽫�����ʱ�������

���磺
ԭʼ���ݣ�
 pots  pans i saw a  reed 
c si a gnimmargorp egaugnal

�������������ݣ�
 stop  snap i was a  deer 
c is a programming language

-----------------------------------------------------------------------
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������֡�
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
        a[i]=��?��;
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
            swap(a[j],i,��?��);
            i=i+n;        
        }
    }
}

int main()
{
    int i;
    char a[N][81]={" pots  pans i saw a  reed ","c si a gnimmargorp egaugnal"};
    printf("ԭʼ����:\n");
    for(i=0;i<N;i++) 
        puts(a[i]);
    printf("\n");
    reverse(a,N);
    printf("��������������:\n");    
    for(i=0;i<N;i++) 
        puts(a[i]);
    return 0;    
}
