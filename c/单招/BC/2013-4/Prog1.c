/*************************************************************

��Ŀ��������main()������������ĸ��ɵ��ַ���s��tΪ�������ݣ���
      �����Ƚ�δ���ַ���s�г��֡������ַ���t�г��ֵ��ַ�������
      һ���µ��ַ���a��Ȼ������ַ���a�����������Ӵ���Ӧ��������
      �ҳ���ƽ����������������λ���־��Ǹ��������������

���磺��s="AB148"��t="E250A148C259G376"ʱ���ַ���aΪ
      "E250C259G376"��a�������Ӵ�"250"�����Ӧ����ƽ����Ϊ
      62500��250������Ҫ�ҵ�һ������������������

��д����
    1. ��д����void GenStr(char s[],char t[],char a[])����δ��
       �ַ���s�г��֡������ַ���t�г��ֵ��ַ��������ַ�����a�С�

    2. ��д����int Calculate(char a[],int b[]),�����ַ���a����
       ���Ӵ���������Ҫ���ҳ���Ҫ�������������������������b�У�
       ������������������

**************************************************************
ע�⣺����Ķ�������main()�е��κ���䡣
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],char t[],char a[])
{
/**********Program**********/




/**********  End  **********/
}

int Calculate(char a[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="AB148";
    char t[]="E250A148C259G376";
    char a[N];
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,t,a);
    printf("The string a is: %s\n",a);
    fprintf(fp,"The string is: %s\n",a);

    num=Calculate(a,b);
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