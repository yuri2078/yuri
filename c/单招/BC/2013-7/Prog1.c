/*************************************************************

��Ŀ��������main()������������ĸ��ɵ��ַ���sΪ�������ݣ�����
      ����ɾ���ַ���s���±�Ϊ����λ����ָ���ַ�ch�������µ���
      ����s��Ȼ������ַ���s�и��������Ӵ���Ӧ�����ķ�������

���磺�ַ���sΪ��"abc12efg24mf36"��ָ���ַ�chΪ'f'��ɾ���±�Ϊ
      ����λ�����ַ�'f'�����ɵ��µ��ַ���sΪ"abc12efg24m36",
      �����Ӵ�"12"��Ӧ����12�ķ�����Ϊ21��

��д����
    1. ��д����void GenStr(char s[],char ch)��������Ҫ��ɾ��ָ
       ���ַ�ch�������Ȼ�������ַ�����s�С�

    2. ��д����int Calculate(char s[],int b[]),�����ַ���s����
       ���Ӵ���Ӧ�����ķ������������������������b�У���������
       ����������

**************************************************************
ע�⣺����Ķ�������main()�е��κ���䡣
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],char ch)
{
/***************************Program*************************/



/***************************End*****************************/
}

int Calculate(char s[],int b[])
{
/***************************Program*************************/



/***************************End*****************************/
}

int main()
{
    char s[]="abc12efg24mf36";
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,'f');
    printf("The string s is: %s\n",s);
    fprintf(fp,"The string s is: %s\n",s);

    num= Calculate(s,b);        
    printf("The integer list is: ");
    fprintf(fp,"The integer list is: ");
        
    for(i=0;i<num;i++)
    {
        printf("%d ",b[i]);
        fprintf(fp,"%d ",b[i]);
    }

    printf("\n");
    fprintf(fp,"\n");

    fclose(fp);
    getch();
    return 0;
}