/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()��Ҫ�Խ�����������ĸ��ɵ��ַ������ַ�
      �����й����������У���ĸ���������������ַ�����ߣ�
      ���ִ��ַ������ұ߿�ʼ�������У����жϸ��ַ�������
      ���ַ����Ƿ��ǻ����ַ��������ǻ����ַ������������
      ���������ַ��������Ӧ��ԭʼ�ַ�����

      �����ַ�����ָһ���ַ����͸��ַ�����������ͬ���ַ�����

���磺
      ���ַ���Ϊ��g1bc3d3cbg1�����������к���ַ���Ϊ��gbcdcbg1331����
      ��1331��Ϊ�����ַ����������
      ���ַ���Ϊ��ab156ba�����������к���ַ���Ϊ��abba651����
      ��651�����ǻ����ַ������������


��д����
       1. ��д����
          void adjust(char s[][20],int n,char t[][20])��
          ��n��������ĸ��ϵ��ַ�������������������У���
          ���浽����t�У����øı�ԭʼ�ַ���s���ݡ�
    
       2. ��д����
          int JudgeHuiwen(char t[][20],int n,int loc[],char huiwen[][20]),
          ��Ҫ�ж�����t��n���ַ����������������ַ����Ƿ�
          �ǻ����ַ����������������ַ������浽����huiwen
          �У����Ӧ��ԭʼ�ַ����������е�λ�ñ��浽����
          loc�С�

      �������ݣ�"g1bc3d3cbg2","abc4abc","g1bc3d3cbg1","ab156ba","ab122ba1"
      ���н����
                The number string 4 in abc4abc is huiwen string!
                The number string 1331 in g1bc3d3cbg1 is huiwen string!
                The number string 1221 in ab122ba1 is huiwen string!

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 10

void adjust(char s[][20],int n,char t[][20])
{
/**********Program**********/




/**********  End  **********/
}

int JudgeHuiwen(char t[][20],int n,int loc[],char huiwen[][20])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N][20]={"g1bc3d3cbg2","abc4abc","g1bc3d3cbg1","ab156ba","ab122ba1"};
    char t[N][20],huiwen[N][20];
    int loc[N]={0};
    int num=0,n,i;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    n=5;
    adjust(s,n,t);
    num=JudgeHuiwen(t,n,loc,huiwen);
    for(i=0;i<num;i++)
    {
        printf("The number string %s in %s is huiwen string!\n",huiwen[i],s[loc[i]]);
        fprintf(fp,"The number string %s in %s is huiwen string!\n",huiwen[i],s[loc[i]]);
    }          
    fclose(fp);
    getch();
    return 0;
}