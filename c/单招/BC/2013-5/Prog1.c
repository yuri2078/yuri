/*************************************************************

��Ŀ��������main()������������ĸ��ɵ��ַ���sΪ�������ݣ�����
      ���ȴ��ַ���sβ����ʼ,������������г��ֵ�ÿ���ڵ�������
      ������������ظ�����һ�Σ����ַ���s��ͷ����ʣ��ĵ�����
      ��Ҳ�ظ��������µ��ַ���t��Ȼ������ַ���t�������Ӵ���Ӧ
      �����ĸ�λ����֮�͡�

����: ��s="A48CD06"�����ַ���tΪ"6060DCDC8484AA"���������Ӵ���
      Ӧ�����ĸ�λ����֮��Ϊ12��24��

��д����
    1. ��д����void GenStr(char s[],char t[])����������������
       �ַ���������������ַ�����t�С�

    2. ��д����int Calculate(char t[],int b[]),�����ַ���t�и�
       �������Ӵ���Ӧ�����ĸ�λ����֮�ͣ������������������b�У�
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

void  GenStr(char s[],char t[])
{
/**********Program**********/




/**********  End  **********/
}

int Calculate(char t[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="A48CD06";
    char t[N];
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,t);
    printf("The string t is: %s\n",t);
    fprintf(fp,"The string t is: %s\n",t);

    num= Calculate(t,b);        
    printf("Sum of the digits of each integer is: ");
    fprintf(fp,"Sum of the digits of each integer is: ");
        
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