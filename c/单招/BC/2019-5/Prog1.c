/*-------------------------------------------------------------------------
��������ơ�
---------------------------------------------------------------------------
��Ŀ��������x�е�����ȡ�������ά����s�У���ɾ�������ظ���������

1.��д int tt(char x[],char s[][M])������������x�д���һЩ��������Щ������
  ��д��ĸ��ͷ������Сд��ĸ�������������ַ�ȡ���γ��ַ����������ά����s�С�
  �������������ĸ����� 

2.��д int del_name(char s[][M],int n)��������s�������ظ�������ɾ����ֻ��
  ��һ������������ʣ�������ĸ����� 

������x��ȡ���������У�     Ann Belle David Ann Mary Belle Ken Ann Mark Mary
ɾ���ظ����������������У�Ann Belle David Mary Ken Mark

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 10
#define N 20  
int tt(char x[],char s[][M]) 
{
/**********Program**********/
    



/**********  End  **********/
} 

int del_name(char s[][M],int n)
{
/**********Program**********/
    



/**********  End  **********/  
}
int main()
{
    char name[N][M];
    char x[]="13Ann14BelleDavid&&AnnMaryBelleKenAnnMarkMary234";
    int k,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=tt(x,name);
    for(k=0;k<n;k++)
    {
        printf("%s ",name[k]);
        fprintf(fp,"%s ",name[k]);
    }
    printf("\n");
    fprintf(fp,"\n");
    n=del_name(name,n);
    for(k=0;k<n;k++)
    {
        printf("%s ",name[k]);
        fprintf(fp,"%s ",name[k]);
    }
    fclose(fp);
    return 0;
}