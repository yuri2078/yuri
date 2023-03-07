/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()主要对仅由数字与字母组成的字符串中字符
      按下列规则重新排列：字母从左向右排列在字符串左边，
      数字从字符串的右边开始向左排列，并判断该字符串中数
      字字符串是否是回文字符串。若是回文字符串，则输出该
      回文数字字符串及其对应的原始字符串。

      回文字符串是指一个字符串和该字符串的逆序相同的字符串。

例如：
      若字符串为“g1bc3d3cbg1”，重新排列后的字符串为“gbcdcbg1331”，
      “1331”为回文字符串，输出。
      若字符串为“ab156ba”，重新排列后的字符串为“abba651”，
      “651”不是回文字符串，不输出。


编写程序：
       1. 编写函数
          void adjust(char s[][20],int n,char t[][20])，
          将n个数字字母组合的字符串按上述规则进行排列，并
          保存到数组t中，不得改变原始字符串s内容。
    
       2. 编写函数
          int JudgeHuiwen(char t[][20],int n,int loc[],char huiwen[][20]),
          主要判断数组t中n个字符串所包含的数字字符串是否
          是回文字符串，将回文数字字符串保存到数组huiwen
          中，其对应的原始字符串在数组中的位置保存到数组
          loc中。

      测试数据："g1bc3d3cbg2","abc4abc","g1bc3d3cbg1","ab156ba","ab122ba1"
      运行结果：
                The number string 4 in abc4abc is huiwen string!
                The number string 1331 in g1bc3d3cbg1 is huiwen string!
                The number string 1221 in ab122ba1 is huiwen string!

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 10

void adjust(char s[][20],int n,char t[][20])
{
/**********Program**********/




/**********  End  **********/
}

int JudgeHuiwen(char t[][20],int n,int loc[],char huiwen[][20])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N][20]={"g1bc3d3cbg2","abc4abc","g1bc3d3cbg1","ab156ba","ab122ba1"};
    char t[N][20],huiwen[N][20];
    int loc[N]={0};
    int num=0,n,i;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    n=5;
    adjust(s,n,t);
    num=JudgeHuiwen(t,n,loc,huiwen);
    for(i=0;i<num;i++)
    {
        printf("The number string %s in %s is huiwen string!\n",huiwen[i],s[loc[i]]);
        fprintf(fp,"The number string %s in %s is huiwen string!\n",huiwen[i],s[loc[i]]);
    }          
    fclose(fp);
    getch();
    return 0;
}