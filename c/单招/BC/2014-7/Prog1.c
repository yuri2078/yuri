/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()��aΪM��N�ж�ά�������飬����M*N������
      ���ݡ����Ƚ���ά������ÿһ�����Ԫ���ƶ�����β����
      ��Ԫ�غ͸�������Ԫ�ص����λ�ñ��ֲ��䡣�ٶ�M����β
      Ԫ����������ͬһ��Ԫ������βԪ��һ�����������β
      Ԫ�ر�����ͬһ���С�

���磺����5*4������
        3     2     5     4
        7    21    11     6
        9     4     2     1
        2     8     7     6
       10    12    23    18
      ����������ÿ�����Ԫ���ƶ�����β����Ϊ
        4     3     2     5
       11     6     7    21
        4     2     1     9
        7     6     2     8
       18    10    12    23
      ����βԪ������Զ�ά�����������Ϊ
        4     3     2     5
        7     6     2     8
        4     2     1     9
       11     6     7    21
       18    10    12    23


��д����
      1����дvoid max_matrix(int a[][N],int m,int n)������
         �����������ƶ�ÿһ�е����Ԫ�ء�
      2����дvoid sort_matrix(int a[][N],int m,int n)������
         ����βԪ������Զ�ά��������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define M 5
#define N 4
void max_matrix(int a[][N],int m,int n)
{
/**********Program**********/




/**********  End  **********/
}

void sort_matrix(int a[][N],int m,int n)
{
/**********Program**********/




/**********  End  **********/
}

void main()
{
    int  a[M][N]={{3,2,5,4},{7,21,11,6},{9,4,2,1},{2,8,7,6},{10,12,23,18}};
    int i,j;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    max_matrix(a,M,N);
    fprintf(fp,"After moving:\n");
    printf("After moving:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(fp,"%4d",a[i][j]);
            printf("%4d",a[i][j]);
        }
        fprintf(fp,"\n");
        printf("\n");
    }
    fprintf(fp,"\n");
    printf("\n");
    sort_matrix(a,M,N);
    fprintf(fp,"After sorting:\n");
    printf("After sorting:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(fp,"%4d",a[i][j]);
            printf("%4d",a[i][j]);
        }
        fprintf(fp,"\n");
        printf("\n");
    }
    fclose(fp);
}
