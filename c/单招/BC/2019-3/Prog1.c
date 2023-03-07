/*-------------------------------------------------------------------------
【程序设计】
---------------------------------------------------------------------------
题目：主函数中str字符串由若干个英文单词组成，单词间用一个或多个空格间隔。
      程序将str字符串分解成单词保存在二维数组w中，并保留w中的升序单词，
      删除非升序单词。

编写函数：
1.函数int diss(char str[],char w[][20])将str字符串分解成单词，以字符串形式
  保存在二维数组w中，函数返回单词个数。

2.函数int check(char w[][20],int n)检查二维数组w的n个单词，保留升序单词，
  删除非升序单词，函数返回升序单词个数。

所谓升序单词是指单词所有左边字母小于等于右边字母，例如单词"ghosty"、"been"为
升序单词，而"there"、"explained"为非升序单词。

程序运行结果为：
str中共有10个单词，其中升序单词有 5个，分别为：
ghosty
begin
or
been
it

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int diss(char str[],char w[][20])
{
/**********Program**********/




/**********  End  **********/
}
int check(char w[][20],int n)
{
/**********Program**********/




/**********  End  **********/
}
int main(){
    char str[]={"there   explained ghosty begin unlike or find been  opened it "};
    char words[15][20];
    int i,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=diss(str,words);
    printf("str中共有%2d个单词，",n);
    fprintf(fp,"str中共有%2d个单词，",n);
    n=check(words,n);
    printf("其中升序单词有%2d个，分别为：\n",n);
    fprintf(fp,"其中升序单词有%2d个，分别为：\n",n);
    for(i=0;i<n;i++)
    {
        printf("%s\n",words[i]);
        fprintf(fp,"%s\n",words[i]);
    }
    fclose(fp);
    return 0;
}