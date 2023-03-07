/*************************************************************

题目：主函数main()中由数字与字母组成的字符串s为测试数据，程序
      首先删除字符串s中下标为奇数位置上指定字符ch，生成新的字
      符串s；然后计算字符串s中各个数字子串对应整数的反序数。

例如：字符串s为："abc12efg24mf36"，指定字符ch为'f'，删除下标为
      奇数位置上字符'f'后，生成的新的字符串s为"abc12efg24m36",
      数字子串"12"对应整数12的反序数为21。

编写程序：
    1. 编写函数void GenStr(char s[],char ch)，按上述要求删除指
       定字符ch，结果仍然保存在字符数组s中。

    2. 编写函数int Calculate(char s[],int b[]),计算字符串s中数
       字子串对应整数的反序数，结果保存在整数数组b中，函数返回
       整数个数。

**************************************************************
注意：请勿改动主程序main()中的任何语句。
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],char ch)
{
/***************************Program*************************/



/***************************End*****************************/
}

int Calculate(char s[],int b[])
{
/***************************Program*************************/



/***************************End*****************************/
}

int main()
{
    char s[]="abc12efg24mf36";
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,'f');
    printf("The string s is: %s\n",s);
    fprintf(fp,"The string s is: %s\n",s);

    num= Calculate(s,b);        
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