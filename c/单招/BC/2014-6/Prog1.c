/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()���ַ���sΪ�������ݣ��ַ���s����������
      "$1,234"�Ļ��Ҹ�ʽ���Ӵ���ɣ����Ƚ�s�����еĻ��Ҹ�
      ʽ���Ӵ�ת������������������a�У�Ȼ������a��ÿ��
      ����ת���ɰ˽��������ַ��������ά�ַ�����oct�С�

���磺�ַ���sΪ
          "$1,234$21,456$3,968$11,759"��
      ת�����������a�е�����Ϊ
          1234 21456 3968 11759 ��
      ÿ������ת���ɰ˽��������ַ�������������oct�ĸ�����
      ����Ϊ
          "2322"  "51720"  "7600"  "26757"��

��д����
      1����дint abstract(char s[],int a[])��������������
         ���ַ���s�е��Ӵ�ת������������������a�У�����
         ��������������
      2����дvoid convert(int a[],char oct[][N],int m)��
         ��, ������a��ÿ������ת���ɰ˽��������ַ�����ʽ��
         �������ά�ַ�����oct�С�

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define M 50
#define N 50
int abstract(char s[],int a[])
{
/**********Program**********/



 
/**********  End  **********/
}

void convert(int a[],char oct[][N],int m)
{
/**********Program**********/



 
/**********  End  **********/
}

void main(){
    char  s[M]="$1,234$21,456$3,968$11,759";
    int  a[M];
    char oct[M][N];
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
        fprintf(fp,"%d\t",a[i]);
        printf("%d\t",a[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    convert(a,oct,n);
    fprintf(fp,"Octal form:\n");
    printf("Octal form:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s\t",oct[i]);
        printf("%s\t",oct[i]);
    }
    fclose(fp);
}

