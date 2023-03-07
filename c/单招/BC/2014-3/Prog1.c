/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中字符串s为测试数据，字符串s由空格和若
      干二进制形式的数字字符子串组成，首先删除字符串s中的
      多余空格，即字符串开头和结尾不能有空格，数字字符子
      串间只能有一个空格，再将字符串s中二进制形式的数字字
      符子串转换成十进制整数，存入数组a中。

例如：字符串s为"   1100  1011  0100  101    ",
      删除多余空格后字符串s为"1100 1011 0100 101"，转换后
      存入数组a有4个十进制整数12，11，4，5。

编写程序：
     1、编写 int del(char s[])函数，按上述规则删除字符串s
        中的多余空格，函数返回删除空格后字符串s的长度。不
        允许使用C库函数。
     2、编写 int convert(char s[],int a[])函数，将字符串s
        中二进制形式的数字字符子串，转换成十进制整数，存入
        数组a中，函数返回a中整数个数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
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

