/*************************************************************

��Ŀ��������main()������������ĸ��ɵ��ַ���sΪ�������ݣ�����
      ���Ȱѵ�1����m���ַ�ƽ�Ƶ��ַ�������󣬵�m+1��������
      ���Ƶ��ַ�����ǰ���������µ��ַ���s��Ȼ������ַ���s����
      ���������������Ӵ���Ӧ���������Լ����

���磺�ַ���sΪ"abc12efg20mf30"��m��ֵΪ3�����ƶ������ַ���s
      Ϊ"12efg20mf30abc"��

��д����
    1. ��д����void GenStr(char s[],int m)��������Ҫ�������µ�
       �ַ����������Ȼ�������ַ�����s�С�

    2. ��д����int Calculate(char s[],int b[]),�����ַ���s����
       �����������Ӵ���Ӧ���������Լ���������������������b
       �У�������������������

**************************************************************
ע�⣺����Ķ�������main()�е��κ���䡣
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],int m)
{
/**********Program**********/




/**********  End  **********/
}

int Calculate(char s[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="abc12efg20mf30";
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,3);
    printf("The string s is: %s\n",s);
    fprintf(fp,"The string s is: %s\n",s);

    num= Calculate(s,b);        
    printf("The max factor is: ");
    fprintf(fp,"The max factor is: ");
        
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
