/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()���ַ���sΪ�������ݣ����Ƚ��ַ���s�е�
      �����ַ��Ӵ�ȡ����ת���ɶ�Ӧ��ʮ������������������
      ��a�У�Ȼ���ҳ�����a �е����л���������
      ����������ָ��һ������������������ֵ������������

���磺�ַ���sΪ" 17rose  t131ar  *d373monkey852y heo181c!#",
      ������������a�е�����Ϊ17,131,373,852,181��������
      ����131,373��181��

��д����
      1����дint abstract(char s[],int a[])������ȡ��s�е�
         �����ַ��Ӵ���ת����ʮ������������������a��������
         �ش���a�е�����������
      2����дint pal_prime(int a[],int n,int b[])��������
         ������a�����еĻ�����������������b������nΪ����a
         ����������������ֵΪ���������ĸ�����

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
int abstract(char s[],int a[])
{
/**********Program**********/
 



/**********  End  **********/
}

int pal_prime(int a[],int n,int b[])
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    char s[50]={" 17rose  t131ar  *d373monkey852y heo181c!#"};
    int a[50],b[50];
    int i,n;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,a);
    fprintf(fp,"Following are integers:\n");
    printf("Following are integers:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
        printf("%d ",a[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    n=pal_prime(a,n,b);
    fprintf(fp,"Following are palindrome primes:\n");
    printf("Following are palindrome primes:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",b[i]);
        printf("%d ",b[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    fclose(fp);
}
