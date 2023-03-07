/*-------------------------------------------------------------------------
【程序设计】
--------------------------------------------------------------------------- 
题目：字符串text中存储了若干英文单词。程序从text中取出每个单词，并按词典顺
      序排序。

编写程序：
1.函数int word_get(char s[],char w[][WORD_LEN])的功能是：将字符串text中的
  单词取出来，作为字符串保存到二维字符数组w中，每个单词保存一行。单词间由
  空格间隔。         

2.函数void word_sort(char w[][WORD_LEN],int n)的功能是：对二维字符数组w中
  的单词按字典顺序进行排列。

测试数据： c is a programming language
运行结果： a c is language programming

---------------------------------------------------------------------------
注意：请勿改动主程序main()中的任何语句。
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
    printf("原始字符串：\t%s\n",text);        
    n=word_get(text,word);
    word_sort(word,n);
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    printf("排序后的字符串：");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s ",word[i]);
        printf("%s ",word[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
}