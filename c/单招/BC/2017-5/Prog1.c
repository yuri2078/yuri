/*-------------------------------------------------------------------------
��������ơ�
--------------------------------------------------------------------------- 
��Ŀ���ַ���text�д洢������Ӣ�ĵ��ʡ������text��ȡ��ÿ�����ʣ������ʵ�˳
      ������

��д����
1.����int word_get(char s[],char w[][WORD_LEN])�Ĺ����ǣ����ַ���text�е�
  ����ȡ��������Ϊ�ַ������浽��ά�ַ�����w�У�ÿ�����ʱ���һ�С����ʼ���
  �ո�����         

2.����void word_sort(char w[][WORD_LEN],int n)�Ĺ����ǣ��Զ�ά�ַ�����w��
  �ĵ��ʰ��ֵ�˳��������С�

�������ݣ� c is a programming language
���н���� a c is language programming

---------------------------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
---------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define TXT_LEN 80    
#define WORD_LEN 20   
#define WORD_COUNT 10 

int word_get(char s[],char w[][WORD_LEN])
{
/**********Program**********/




/**********  End  **********/
}


void word_sort(char w[][WORD_LEN],int n)
{
/**********Program**********/
 



/**********  End  **********/
}

void main()
{
    FILE *fp;
    int i,n;
    char text[TXT_LEN]="c is a programming language";
    char word[WORD_COUNT][WORD_LEN];
    printf("ԭʼ�ַ�����\t%s\n",text);        
    n=word_get(text,word);
    word_sort(word,n);
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    printf("�������ַ�����");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s ",word[i]);
        printf("%s ",word[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
}