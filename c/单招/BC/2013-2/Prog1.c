/*************************************************************

��Ŀ��������main()�������ֺ���ĸ��ɵ��ַ���sΪ�������ݣ�����
      ��Ҫ��ȡ�ַ���s�����ַ�'$'�ָ��Ĳ�ͬ�˽�������ʽ���ַ�����
      ���˽�������ʽ�ַ��Ӵ�����Ӧ���ַ������µ��ַ���t��Ȼ��
      ͳ���ַ���t�����������Ӵ���Ӧ�����ĳ���Ƶ�ʡ�

���磺�ַ���sΪ"101$062$063$114$066$110$062$063$141$071"������
      ���ַ���tΪ"A23L6H23a9"������"23"��Ӧ����23����Ƶ��Ϊ2,
      "6"��"9"��Ӧ��������Ƶ��Ϊ1��

��д����
    1. ��д����void GenStr(char s[],char t[]),�����ַ���s�в�ͬ
       �˽�������ʽ���ַ��Ӵ�����ÿ���˽�������ʽ�ַ��Ӵ�����Ӧ
       ���ַ��������ַ�����t�С�

    2. ��д����int CountFreq(char t[],int b[],int Freq[])��ͳ��
       �ַ�����t�в�ͬ�����Ӵ���Ӧ��������Ƶ�ʣ���ͬ����������
       ��������b��,����Ƶ�ʱ�������������Freq�У���������������
       ����
     
**************************************************************
ע�⣺����Ķ�������main()�е��κ���䡣
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 10

void  GenStr(char s[],char t[])
{
/**********Program**********/




/**********  End  **********/
}

int CountFreq(char t[],int b[],int Freq[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="101$062$063$114$066$110$062$063$141$071";
    char t[N]="";
    int b[N]={0},Freq[N]={0};
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

    num=CountFreq(t,b,Freq);
    printf("The different integer and frequency is: ");
    fprintf(fp,"The different integer and frequency is: ");
        
    for(i=0;i<num;i++)
    {
        printf("[%d: %d] ",b[i],Freq[i]);
        fprintf(fp,"[%d: %d] ",b[i],Freq[i]);

    }
    printf("\n");
    fprintf(fp,"\n");

    fclose(fp);
    getch();
    return 0;
}