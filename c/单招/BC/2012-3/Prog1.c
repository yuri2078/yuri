/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()���ַ�����sΪ�������ݣ����򽫲������ݰ�
      ���¹����Ƶ�����t�У��ٽ�����t�е��ַ������á���
      �����£���֪nΪ����Ԫ���±�ֵ������nΪ����λ�õ���
      ������n�Σ�����nΪż��λ�õ��ַ�ֻ����һ�Ρ�

��д����
      1. ��д���� void CopyStr(char s[][30],int n, char t[][100]),
         ��n���ַ���s������������и��ƣ��������������t�С�
    
      2. ��дvoid Reserve(char t[][100],int n)��������t��
         n���ַ������á�

      �������ݣ���ABCDEF��,��1234��
      ���н����
          Stirng ABCDEF is changed as FFFFFEDDDCBA
          String 1234 is changed as 444321

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 30

void CopyStr(char s[][30],int n,char t[][100])
{
/**********Program**********/




/**********  End  **********/
}

void Reserve(char t[][100],int n)
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N][30]={"ABCDEF","1234"};
    char t[N][100];
    int i,n=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
            
    n=2;
    CopyStr(s,n,t);
    Reserve(t,n);
    for(i=0;i<n;i++)
    {
        printf("String %s is changed as %s\n",s[i],t[i]);
        fprintf(fp,"String %s is changed as %s\n",s[i],t[i]);
    }

    fclose(fp);
    getch();
    return 0;
}