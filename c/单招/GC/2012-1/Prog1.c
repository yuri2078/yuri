/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ��������main()�е���count()����ͳ���Ӵ�substr���ַ���
      str�г��ֵĴ����������ַ���strΪ��abdrgabdd�����Ӵ�
      substrΪ��ab�������Ӵ��ڸ��ַ������ֵĴ���Ϊ2��

��������ĳ�����ڴ����������

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/

#include<stdio.h>
int count(char str[],char substr[])
{
/***********FOUND***********/
    int i,j,k,num;
    for(i=0;str[i]!='\0';i++)
    {
/***********FOUND***********/
        for(j=0,k=0;substr[k]==str[j];k++,j++)
            if(substr[k+1]=='\0') 
            { num++;break; }
    }
    return(num);
}

int main()
{ 
    char str[80],substr[80];
    int num=0;
    printf("Please input string:");
    gets(str);
    printf("Please input substring:");
    gets(substr);
/***********FOUND***********/
    num=count(str[80],substr[80]);
    if(num)
        printf("Substing :%d\n",num);
    else
        printf("%s is not substring!\n",substr);
    return 0;
}