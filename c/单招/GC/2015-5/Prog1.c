/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ��int find(char a[],char b[],int c[])ͳ���ַ���a�г�
      ���ַ���b�Ĵ����������ַ���bÿ�����ַ���a�г��ֵ���
      ʼ�±����α���������c�С�

���磺���ַ���aΪ"You are a P.R.C citizen or other P.R.C person"
      �ַ���bΪ"P.R.C" ���ַ���b��a�г���2�Σ���ʼ�±���
      ��Ϊ10��33�����ַ���aΪ"bcde aeeeq mneec",�ַ���bΪ
      "ee" ���ַ���b��a�г���3�Σ���ʼ�±�����Ϊ6��7��13��

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int find(char a[],char b[],int c[])
{
    int i,j,n=0; 
    i=0;
    while(a[i])
    {
        j=0;
        while(a[i]==b[j]&&a[i]&&b[j])
        {
            i++;j++;
        }
        if(b[j]=='\0')
        {
/*******************FOUND*******************/
            c[n]=i;
            n++;
        }
/*******************FOUND*******************/
        i=j;
    }
/*******************FOUND*******************/
    return n-1;
}

int main()
{
    char a[80]="You are a P.R.C citizen or other P.R.C person";
    char b[10]="P.R.C";
    int  c[80];
    int i,n;
    printf("String a:\n");
    puts(a);
    printf("Substring b:\n");
    puts(b);
    n=find(a,b,c);
    if(n)
    {
        printf("\nAfter counting:\n%d times\n",n);
        printf("Location:\n");
        for(i=0;i<n;i++) printf("%d\t",c[i]);
        printf("\n");
    }
    else
        printf("\nCan not find substring.\n");
    return 0;
}