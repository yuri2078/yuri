/*-------------------------------------------------------------------------
��������ơ�
---------------------------------------------------------------------------
��Ŀ����������str�ַ��������ɸ�Ӣ�ĵ�����ɣ����ʼ���һ�������ո�����
      ����str�ַ����ֽ�ɵ��ʱ����ڶ�ά����w�У�������w�е����򵥴ʣ�
      ɾ�������򵥴ʡ�

��д������
1.����int diss(char str[],char w[][20])��str�ַ����ֽ�ɵ��ʣ����ַ�����ʽ
  �����ڶ�ά����w�У��������ص��ʸ�����

2.����int check(char w[][20],int n)����ά����w��n�����ʣ��������򵥴ʣ�
  ɾ�������򵥴ʣ������������򵥴ʸ�����

��ν���򵥴���ָ�������������ĸС�ڵ����ұ���ĸ�����絥��"ghosty"��"been"Ϊ
���򵥴ʣ���"there"��"explained"Ϊ�����򵥴ʡ�

�������н��Ϊ��
str�й���10�����ʣ��������򵥴��� 5�����ֱ�Ϊ��
ghosty
begin
or
been
it

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int diss(char str[],char w[][20])
{
/**********Program**********/




/**********  End  **********/
}
int check(char w[][20],int n)
{
/**********Program**********/




/**********  End  **********/
}
int main(){
    char str[]={"there   explained ghosty begin unlike or find been  opened it "};
    char words[15][20];
    int i,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=diss(str,words);
    printf("str�й���%2d�����ʣ�",n);
    fprintf(fp,"str�й���%2d�����ʣ�",n);
    n=check(words,n);
    printf("�������򵥴���%2d�����ֱ�Ϊ��\n",n);
    fprintf(fp,"�������򵥴���%2d�����ֱ�Ϊ��\n",n);
    for(i=0;i<n;i++)
    {
        printf("%s\n",words[i]);
        fprintf(fp,"%s\n",words[i]);
    }
    fclose(fp);
    return 0;
}