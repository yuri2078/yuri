/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()���ַ���a��bΪ�������ݣ��ַ���a���ַ���
      ��ASCII��ֵ�������У����ַ���b��ASCII��Ϊż�����ַ�
      ���β��뵽�ַ���a�У�ʹ�ַ���a���ַ��԰�ASCII��ֵ��
      �����С���ɾ���ַ���a�е��ظ��ַ���ʹ��ͬ�ַ�ֻ����
      һ�Ρ�

��д����
     1����дvoid insert(char a[],char b[])��������������
        ���ַ���b���ַ����뵽�ַ���a�С�
     2����д void del(char a[])������ɾ���ַ���a�е��ظ�
        �ַ���ʹ��ͬ�ַ�ֻ����һ�Ρ�

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
void insert(char a[],char b[])
{
/**********Program**********/



 
/**********  End  **********/
}

void del(char a[])
{
/**********Program**********/



 
/**********  End  **********/
}

void main(){
    char a[30]="9777532";
    char b[10]= "987645231";
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    insert(a,b);
    fprintf(fp,"After insterting:");
    printf("After insterting:");
    fprintf(fp,"%s\n",a);
    printf("%s\n",a);
    del(a);
    fprintf(fp,"After deleting:");
    printf("After deleting:");
    fprintf(fp,"%s\n",a);
    printf("%s\n",a);
    fclose(fp);
}
