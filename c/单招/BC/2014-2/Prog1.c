/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()����һ����������ɵ�һά����aΪ�������ݣ�
      �����ҳ����ִ�����������������ͬ��������ͬ�����
      ���ִ���ʱ��ѡ��������ֵ����������жϴ������Ƿ�Ϊ��
      ķ˹��������
      ��ķ˹��������ָ��һ���������������λ���ֵ������͡�
��д����
      1����д int maxt(int a[],int n)�����������������ҳ�
         ����a�г��ִ����������������������ش�����
      2����д int amst(int m)�������жϲ���m�Ƿ�Ϊ��ķ˹��
         �������ǰ�ķ˹��������������1������������0��

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define N 10
int maxt(int a[],int n)
{
/**********Program**********/
 



/**********  End  **********/
}

int amst(int m)
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    int a[N]={370,612,153,267,153,153,267,407,407,371};
    int m;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    m=maxt(a,N);
    if(amst(m))
    {
        fprintf(fp,"%d is an Armstrong number.\n",m);
        printf("%d is an Armstrong number.\n",m);

    }
    else
    {
        fprintf(fp,"%d is not an Armstrong number.\n",m);
        printf("%d is not an Armstrong number.\n",m);
    }
    fclose(fp);
}
