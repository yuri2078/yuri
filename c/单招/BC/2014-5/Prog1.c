/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()������������ɵ�һά����aΪ�������ݣ���
      �Ƚ�����a��Ԫ�ظ��Ƶ�����b�У����ƹ���Ϊ�����Ӻ�Ϊ
      ��������������1�Σ������Ӻ�Ϊż����������������2�Ρ�
      ��������b�������������Լ��������������c�С�����
      ����ָ������������������ӡ�

���磺����a������Ϊ
          15 28 50 76 63��
      ���Ƶ�b��Ϊ
          15  28  28  50  76  76  63��
      ��������c�������������Լ��Ϊ
          1 28 2 2 76 1��

��д����
      1����дint copy(int a[],int n��int b[])������������
         ��������a�е��������Ƶ�����b�У�������������b
         ������������
      2����дvoid gcd(int b[],int n,int c[])������������b
         �������������Լ������������c�У�����nΪ����b
         ������������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define M 5
#define N 10
int copy(int a[],int n,int b[])
{
/**********Program**********/



 
/**********  End  **********/
}

void gcd(int a[],int k,int c[])
{
/**********Program**********/



 
/**********  End  **********/
}

void main(){
    int  a[M]={15,28,50,76,63};
    int  b[N],c[N];
    int  i,n;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=copy(a,M,b);
    fprintf(fp,"After copying:\n");
    printf("After copying:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d  ",b[i]);
        printf("%d  ",b[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    gcd(b,n,c);
    fprintf(fp,"Aarray c:\n");
    printf("Array c:\n");
    for(i=0;i<n-1;i++)
    {
        fprintf(fp,"%d  ",c[i]);
        printf("%d  ",c[i]);
    }
    fclose(fp);
}



