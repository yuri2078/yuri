/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------
��Ŀ��������main()��һά����numΪ��������,���򽫲�������
      ת��Ϊ�����ַ���������������s�У�Ȼ�������ַ���s
      ת��Ϊ���Ҹ�ʽ���浽����t�У������������t��

��д����
      1. ��д����
      void LongtoStr(long m[],int n,char s[][30])
      ������m��n������ת���������ַ���������������s�С�
    
      2. ��д����
      void Currency(char s[][30],int n,char M,char t[][30])
      ��n�������ַ���sת��Ϊ���Ҹ�ʽ���浽����t�в������
      M��ʾ���ҷ��š�

���磺
      ��������:
        12345678,45678,1689
      ���н����
        num[0]=12345678 is changed as $12,345,678
        num[1]=45678 is changed as $45,678
        num[2]=1689 is changed as $1,689

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define N 10

void LongtoStr(long m[],int n,char s[][30])
{
/**********Program**********/




/**********  End  **********/
   
}

void Currency(char s[][30],int n,char M,char t[][30])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    FILE *fp;
    long int num[N]={12345678,45678,1689};
    char s[N][30],t[N][30];
    int i,n;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("FILE open error.\n");
        exit(0);
    }

    n=3;
    LongtoStr(num,n,s);
    Currency(s,n,'$',t);

    for(i=0;i<n;i++)
    {
        printf("num[%d]=%ld is changed as %s\n",i,num[i],t[i]);
        fprintf(fp,"num[%d]=%ld is changed as %s\n",i,num[i],t[i]);
    }
    fclose(fp);
    getch();
    return 0;
}