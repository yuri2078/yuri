/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()���ַ���sΪ�������ݣ��ַ���s�ɿո����
      �ɶ�������ʽ�������ַ��Ӵ���ɣ�����ɾ���ַ���s�е�
      ����ո񣬼��ַ�����ͷ�ͽ�β�����пո������ַ���
      ����ֻ����һ���ո��ٽ��ַ���s�ж�������ʽ��������
      ���Ӵ�ת����ʮ������������������a�С�

���磺�ַ���sΪ"   1100  1011  0100  101    ",
      ɾ������ո���ַ���sΪ"1100 1011 0100 101"��ת����
      ��������a��4��ʮ��������12��11��4��5��

��д����
     1����д int del(char s[])����������������ɾ���ַ���s
        �еĶ���ո񣬺�������ɾ���ո���ַ���s�ĳ��ȡ���
        ����ʹ��C�⺯����
     2����д int convert(char s[],int a[])���������ַ���s
        �ж�������ʽ�������ַ��Ӵ���ת����ʮ��������������
        ����a�У���������a������������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define N 50
int del(char s[])
{
/**********Program**********/
 



/**********  End  **********/
}

int convert(char s[],int a[])
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    char s[N]={"   1100  1011  0100  101      "};
    int a[N],n,i;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=del(s);
    fprintf(fp,"The string after deleting spaces:%s\n",s);
    printf("The string after deleting spaces:%s\n",s);
    fprintf(fp,"The length is:%d\n",n);
    printf("The length is:%d\n",n);
    n=convert(s,a);
    fprintf(fp,"Following are integers:");
    printf("Following are integers:");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
        printf("%d ",a[i]);
    }
    fclose(fp);
}

