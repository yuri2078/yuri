/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()������������ĸ��ɵ��ַ���sΪ�������ݣ�
      ������Ҫ���ַ���s���ַ����Ƶ��ַ�����t�У��±�Ϊż��
      λ���ϵ���ĸ�ַ��������Σ������ַ�����һ�Σ�Ȼ���ж�
      �ַ���t�������������Ӵ���Ӧ�������Ƿ���"ƽ��������"��

���磺�ַ���sΪ"g12bc32fA31"���������������ַ���tΪ
      "gg12bcc32fAA31"��

ƽ����������
      ������ƽ��������ķ�������ƽ����Ϊ��������
      
���磺12��ƽ������144��12�ķ�����21��ƽ������441����12����
      һ��"ƽ��������"��

��д����
      1. ��д����void  GenStr(char s[],char t[]),������Ҫ��
      �����µ��ַ���������������ַ�����t�С�

      2. ��д����int TestFanshu(char t[],int b[]),�ж���
         ����t�������������Ӵ���Ӧ�������Ƿ���ƽ����������
         ��ƽ������������������b�У���������ƽ����������
         ������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

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

int TestFanshu(char t[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="g12bc32fA31";
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

    num=TestFanshu(t,b);
    printf("The pingfangjingfanshu is: ");
    fprintf(fp,"The pingfangjingfanshu is: ");

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