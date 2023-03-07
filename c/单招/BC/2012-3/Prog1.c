/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中字符数组s为测试数据，程序将测试数据按
      以下规则复制到数组t中，再将数组t中的字符串逆置。规
      则如下：已知n为数组元素下标值，对于n为奇数位置的字
      符复制n次，对于n为偶数位置的字符只复制一次。

编写程序：
      1. 编写函数 void CopyStr(char s[][30],int n, char t[][100]),
         将n个字符串s按上述规则进行复制，结果保存在数组t中。
    
      2. 编写void Reserve(char t[][100],int n)，将数组t中
         n个字符串逆置。

      测试数据：“ABCDEF”,“1234”
      运行结果：
          Stirng ABCDEF is changed as FFFFFEDDDCBA
          String 1234 is changed as 444321

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 30

void CopyStr(char s[][30],int n,char t[][100])
{
/**********Program**********/




/**********  End  **********/
}

void Reserve(char t[][100],int n)
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N][30]={"ABCDEF","1234"};
    char t[N][100];
    int i,n=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
            
    n=2;
    CopyStr(s,n,t);
    Reserve(t,n);
    for(i=0;i<n;i++)
    {
        printf("String %s is changed as %s\n",s[i],t[i]);
        fprintf(fp,"String %s is changed as %s\n",s[i],t[i]);
    }

    fclose(fp);
    getch();
    return 0;
}