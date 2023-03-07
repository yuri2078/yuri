/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ��void sort(char number[][20],char city[][20],char key[][20])
      ������city����Ԫ�ذ���keyֵ�Զ�������beijing,shanghai,
      guangzhou��˳�����У�����keyֵ��ͬ����ЩԪ�أ�����number
      ��ֵ���������С�number�е�Ԫ�ر�ʾ���������������ı�š�
      int find(char s[],char key[][20])��������ĳ������s��key
      �����Զ��������е��±�λ�ò����ء�

���磺   ����ǰ������:          
         number    city
           2     guangzhou
           1     shanghai
           2     beijing
           3     guangzhou
           1     beijing
           1     guangzhou
         ����������:
         number    city
           1     beijing
           2     beijing
           1     shanghai
           1     guangzhou
           2     guangzhou
           3     guangzhou
      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define N 6
int find(char s[],char key[][20])
{
    int j;
    for(j=0;j<3;j++)
/***************FOUND****************/
        if(strcmp(s,key)==0)
            break;
    return j;
}


void sort(char number[][20],char city[][20],char key[][20])
{
    int i,j,p,n1,n2;
/***************FOUND****************/
    char temp[N][20];
    for(i=0;i<N-1;i++)
    {
        p=i;
        for(j=i+1;j<N;j++)
        {
            n1=find(city[p],key);
            n2=find(city[j],key);
            if(n1>n2) p=j;
/***************FOUND****************/                        
            if(n1==n2&&strcmp(number[p],number[j])) p=j;
        }
        if(p!=i)
        {
            strcpy(temp,number[i]);
            strcpy(number[i],number[p]);
            strcpy(number[p],temp); 
            strcpy(temp,city[i]);
            strcpy(city[i],city[p]);
            strcpy(city[p],temp);
        }
    }
}

int main() 
{
    char number[N][20]={"2","1","2","3","1","1"};
    char city[N][20]={"guangzhou","shanghai","beijing","guangzhou","beijing","guangzhou"};
    char key[3][20]={"beijing","shanghai","guangzhou"};       
    int i;
    printf("����ǰ������:\n");
    printf("number  city\n");
    for(i=0;i<N;i++)
        printf("%4s\t%s\n",number[i],city[i]);
    printf("\n");
    sort(number,city,key);
    printf("����������:\n");
    printf("number  city\n");
    for(i=0;i<N;i++)
        printf("%4s\t%s\n",number[i],city[i]);
    printf("\n");
    return 0;
}