/*************************************************************

题目：主函数main()中由数字与字母组成的字符串s和t为测试数据，程
      序首先将未在字符串s中出现、而在字符串t中出现的字符，生成
      一个新的字符串a；然后计算字符串a中所有数字子串对应的整数，
      找出其平方数中有连续的三位数字就是该数本身的整数。

例如：当s="AB148"，t="E250A148C259G376"时，字符串a为
      "E250C259G376"。a中数字子串"250"，其对应整数平方数为
      62500，250便是所要找的一个满足条件的整数。

编写程序：
    1. 编写函数void GenStr(char s[],char t[],char a[])，将未在
       字符串s中出现、而在字符串t中出现的字符保存在字符数组a中。

    2. 编写函数int Calculate(char a[],int b[]),计算字符串a中数
       字子串，按上述要求找出所要的整数，结果保存在整数数组b中，
       函数返回整数个数。

**************************************************************
注意：请勿改动主程序main()中的任何语句。
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],char t[],char a[])
{
/**********Program**********/




/**********  End  **********/
}

int Calculate(char a[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="AB148";
    char t[]="E250A148C259G376";
    char a[N];
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,t,a);
    printf("The string a is: %s\n",a);
    fprintf(fp,"The string is: %s\n",a);

    num=Calculate(a,b);
    printf("The integer list is: ");
    fprintf(fp,"The integer list is: ");
    for(i=0;i<num;i++)
    {
        printf("%d ",b[i]);
        fprintf(fp,"%d ",b[i]);
    }

    printf("\n");
    fprintf(fp,"\n");

    fclose(fp);
    getch();
    return 0;
}