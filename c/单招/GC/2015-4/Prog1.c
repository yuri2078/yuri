/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ��void add(char a[],char b[],char c[])��������'0','1'
      ��ɵ��ַ���a,b�����������ӷ�������ӣ�������'0','1'
      ��ɵ��ַ�����ʽ���浽�ַ���c�С�

���磺�ַ���aΪ"1100",�ַ���bΪ"111",����add�������ַ���c
      Ϊ"10011"��

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
void reverse(char s[])
{
    int i,len;
    char t;
/*******************FOUND*******************/
    len=strlen(s-1);
    for(i=0;i<len/2;i++)
    {
        t=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=t;
    }
}
void add(char a[],char b[],char c[])
{
    int i,j,k,t,flag;
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=flag=0;
    while(i>=0||j>=0)
    {
        if(i<0)
            t=b[j]-48+flag;
        else if(j<0)
            t=a[i]-48+flag;
        else
            t=a[i]-48+b[j]-48+flag;
/*******************FOUND*******************/
        c[k]=t/2;
        k++;
        flag=0;
        if(t>1) 
            flag=1;
        i--;
        j--;
    }
/*******************FOUND*******************/
    if(flag==0) 
        c[k++]='1';
    c[k]='\0';
    reverse(c);
}
int main()
{
    char a[50],b[50],c[51];
    printf("Input a(binary):\n");
    scanf("%s",a);
    printf("Input b(binary):\n");
    scanf("%s",b);
    add(a,b,c);
    printf("After adding  a+b=%s\n",c);
    return 0;
}