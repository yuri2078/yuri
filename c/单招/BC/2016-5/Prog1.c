/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------
题目：主函数main()中字符串s为测试数据，字符串s由若干十进
      制形式的数字字符子串和其他字符组成，将字符串s中十进
      制形式的数字字符子串转换成十进制整数存入数组，并把
      数组中的素数提取放入另一数组并按升序排列，函数返回
      数组中素数的个数。

      例如：string:$17 #304!101&113 82*76~109#67@88!
          integers(9): 17   304   101   113   82   76   109   67   88          
          sorted prime(5):17    67    101    109    113
           
编写程序：
      1.编写函数int convert(char s[],int ar[])实现以下
      功能：将字符串s中十进制形式的数字字符子串转换成
      十进制整数存入数组ar，函数返回十进制整数的个数。

      2.编写函数int getb(int ar[],int n,int br[])，从
      ar数组中的n个整数中提取素数放入br数组并按升序排列，
      函数返回数组中素数的个数。

---------------------------------------------------------
注意：请勿改动主程序main()中的任何语句。
---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define N 20 
int convert(char s[],int ar[])
{
/**********Program**********/

/**********  End  **********/
}
int getb(int ar[],int n,int br[])
{
/**********Program**********/

/**********  End  **********/
}
int main()
{ 
    int a[N]={0},b[N]={0};
    char s[]={"$17 #304!101&113 82*76~109#67@88! "};
    int i,num;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    printf("string:%s\n",s);
    fprintf(fp,"string:%s\n",s);
    num=convert(s,a);
    printf("integers(%d):",num);
    fprintf(fp,"integers(%d):",num);
    for(i=0;i<num;i++)
    {
        printf("%d\t",a[i]);
        fprintf(fp,"%d\t",a[i]);
    }
    num=getb(a,num,b);
    printf("sorted prime(%d):",num);
    fprintf(fp,"\nsorted prime(%d)",num);
    for(i=0;i<num;i++)
    {
        printf("%d\t",b[i]);
        fprintf(fp,"%d\t",b[i]);
    }
    fclose(fp);
    getch();
    return 0;
}