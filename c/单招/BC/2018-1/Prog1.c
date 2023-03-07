/*-------------------------------------------------------------------------
【程序设计】
---------------------------------------------------------------------------
  
题目：主函数main()中的字符数组s为测试数据，程序首先取出字符数组s中的连续数
      字字符子串，构成若干个整数，保存到t数组中，然后找出数组中的所有素数，
      并将素数顺序存放到数组的后部。

编写程序：
         1.编写int abstract(char s[],int t[])函数。取出字符数组s中的连续数
           字字符子串，构成若干个整数，保存到数组t中。函数返回整数个数。

         2.编写函数void move( int t[], int n)，找到t数组中的所有素数，并将
           该数组中的所有素数顺序移到数组的后面，素数间的相对位置不变。

例如：字符数组s中的数据为"yu11asd18**6$abc3jui17t*r33t10?qwe31nm19jj21da"

      则数组t中元素为：11  18  6  3  17  33  10  31  19  21

      程序运行结果：18  6  33  10  21  11  3  17  31  19
      
--------------------------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<math.h>

int abstract(char s[],int t[])
{
/**********Program**********/





/**********  End  **********/
}
void move( int t[], int n)
{
/**********Program**********/





/**********  End  **********/
}
int main()
{
    char s[]={"yu11asd18**6$abc3jui17t*r33t10?qwe31nm19jj21da"};
    int t[20],i,n;
    FILE *fp;
    if((fp=fopen("data.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,t);
    move(t,n);
    for(i=0;i<n;i++)
    {
        printf("%d  ",t[i]);
        fprintf(fp,"%d  ",t[i]);
    }
    fclose(fp);
    return 0;
}
