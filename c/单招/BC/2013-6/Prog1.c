/*************************************************************

题目：主函数main()中由数字与字母组成的字符串s为测试数据，程序
      首先把第1到第m个字符平移到字符串的最后，第m+1到最后的字
      符移到字符串的前部，生成新的字符串s；然后计算字符串s中所
      有相邻两个数字子串对应整数的最大公约数。

例如：字符串s为"abc12efg20mf30"，m的值为3，则移动后，新字符串s
      为"12efg20mf30abc"。

编写程序：
    1. 编写函数void GenStr(char s[],int m)，按上述要求生成新的
       字符串，结果仍然保存在字符数组s中。

    2. 编写函数int Calculate(char s[],int b[]),计算字符串s中相
       邻两个数字子串对应整数的最大公约数，结果保存在整数数组b
       中，函数返回整数个数。

**************************************************************
注意：请勿改动主程序main()中的任何语句。
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 80

void  GenStr(char s[],int m)
{
/**********Program**********/




/**********  End  **********/
}

int Calculate(char s[],int b[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="abc12efg20mf30";
    int b[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,3);
    printf("The string s is: %s\n",s);
    fprintf(fp,"The string s is: %s\n",s);

    num= Calculate(s,b);        
    printf("The max factor is: ");
    fprintf(fp,"The max factor is: ");
        
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
