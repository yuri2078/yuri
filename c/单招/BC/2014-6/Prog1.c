/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中字符串s为测试数据，字符串s由若干形如
      "$1,234"的货币格式的子串组成，首先将s中所有的货币格
      式的子串转换成整数，存入数组a中，然后将数组a中每个
      整数转换成八进制数字字符串存入二维字符数组oct中。

例如：字符串s为
          "$1,234$21,456$3,968$11,759"，
      转换后存入数组a中的整数为
          1234 21456 3968 11759 ，
      每个整数转换成八进制数字字符串，存入数组oct的各行字
      符串为
          "2322"  "51720"  "7600"  "26757"。

编写程序：
      1、编写int abstract(char s[],int a[])函数，按上述规
         则将字符串s中的子串转换成整数，存入数组a中，函数
         返回整数个数。
      2、编写void convert(int a[],char oct[][N],int m)函
         数, 将数组a中每个整数转换成八进制数字字符串形式，
         并存入二维字符数组oct中。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#define M 50
#define N 50
int abstract(char s[],int a[])
{
/**********Program**********/



 
/**********  End  **********/
}

void convert(int a[],char oct[][N],int m)
{
/**********Program**********/



 
/**********  End  **********/
}

void main(){
    char  s[M]="$1,234$21,456$3,968$11,759";
    int  a[M];
    char oct[M][N];
    int i,n;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,a);
    fprintf(fp,"Following are integers:\n");
    printf("Following are integers:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t",a[i]);
        printf("%d\t",a[i]);
    }
    fprintf(fp,"\n");
    printf("\n");
    convert(a,oct,n);
    fprintf(fp,"Octal form:\n");
    printf("Octal form:\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s\t",oct[i]);
        printf("%s\t",oct[i]);
    }
    fclose(fp);
}

