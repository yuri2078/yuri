/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------
��Ŀ��������main()�������ַ���sΪ�������ݣ�������Ҫ�ȶ���
      ���ַ���s���н������򣬽��������������b�У�Ȼ���
      ����b�����ݽ���ѹ������ͬ���ֱ���������b�У����ֳ�
      �ִ�������������times�У�����������ּ�Ȩ�ͣ�������
      ������Ը����ֳ��ִ��������������������c�С�

��д����
      1. ��д����void  SortAndChange(char s[],int n, int b[])��
         ���ַ���s��n���ַ����н�������,����n���ַ�ת��Ϊ
         ���֣�����������b�С�
    
      2. ��д����int Calculcate(int b[],int n��int times[],int c[])��
         ������b�����ֽ���ѹ������ͬ���ֱ���������b�У���
         ͬ���ֳ��ִ�����������times�У�������������ּ�Ȩ
         �ͣ������������c��,�������ز�ͬ���ֵĸ�����
  
      �������ݣ� 13334444555582298760
      ���н����b[0]=9 and times[0]=1, the weight sum is 9
                b[1]=8 and times[1]=2, the weight sum is 16
                ...
                b[9]=0 and times[9]=1, the weight sum is 0
                
---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 50

void SortAndChange(char s[],int n,int b[])
{
/**********Program**********/




/**********  End  **********/
}

int Calculcate(int b[],int n,int times[],int c[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N]="13334444555582298760";
    int b[N]={0};
    int c[10]={0};
    int times[10]={0};
    int num;
    int i,n;
            
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
        
    n=strlen(s);
    SortAndChange(s,n,b);
    num=Calculcate(b,n,times,c);

    for(i=0;i<num;i++)
    {
        printf("b[%d] = %d and times[%d] =%d, the weight sum is %d\n",i,b[i],i,times[i],c[i]);
        fprintf(fp,"b[%d]= %d and times[%d] =%d, the weight sum is %d\n",i,b[i],i,times[i],c[i]);
    }
   
    fclose(fp);
    getch();
    return 0;
}