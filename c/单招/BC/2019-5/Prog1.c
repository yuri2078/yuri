/*-------------------------------------------------------------------------
【程序设计】
---------------------------------------------------------------------------
题目：将数组x中的姓名取出放入二维数组s中，并删除其中重复的姓名。

1.编写 int tt(char x[],char s[][M])函数，在数组x中存有一些姓名，这些姓名以
  大写字母开头，并以小写字母结束。将姓名字符取出形成字符串，放入二维数组s中。
  函数返回姓名的个数。 

2.编写 int del_name(char s[][M],int n)函数，将s数组中重复的姓名删除，只保
  留一个。函数返回剩余姓名的个数。 

从数组x中取出的姓名有：     Ann Belle David Ann Mary Belle Ken Ann Mark Mary
删除重复姓名后保留的姓名有：Ann Belle David Mary Ken Mark

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 10
#define N 20  
int tt(char x[],char s[][M]) 
{
/**********Program**********/
    



/**********  End  **********/
} 

int del_name(char s[][M],int n)
{
/**********Program**********/
    



/**********  End  **********/  
}
int main()
{
    char name[N][M];
    char x[]="13Ann14BelleDavid&&AnnMaryBelleKenAnnMarkMary234";
    int k,n;
    FILE *fp;
    if((fp=fopen("DATA.dat","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=tt(x,name);
    for(k=0;k<n;k++)
    {
        printf("%s ",name[k]);
        fprintf(fp,"%s ",name[k]);
    }
    printf("\n");
    fprintf(fp,"\n");
    n=del_name(name,n);
    for(k=0;k<n;k++)
    {
        printf("%s ",name[k]);
        fprintf(fp,"%s ",name[k]);
    }
    fclose(fp);
    return 0;
}