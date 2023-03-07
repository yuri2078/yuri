/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------
题目：主函数main()中数字字符串s为测试数据，程序主要先对数
      字字符串s进行降序排序，将结果存入在数组b中，然后对
      数组b中数据进行压缩，不同数字保存在数组b中，数字出
      现次数保存在数组times中，计算各个数字加权和（即数字
      本身乘以该数字出现次数），结果保存在数组c中。

编写程序：
      1. 编写函数void  SortAndChange(char s[],int n, int b[])，
         对字符串s中n个字符进行降序排列,并将n个字符转换为
         数字，保存在数组b中。
    
      2. 编写函数int Calculcate(int b[],int n，int times[],int c[])，
         对数组b中数字进行压缩，不同数字保存在数组b中，不
         同数字出现次数存入数组times中，并计算各个数字加权
         和，结果存入数组c中,函数返回不同数字的个数。
  
      测试数据： 13334444555582298760
      运行结果：b[0]=9 and times[0]=1, the weight sum is 9
                b[1]=8 and times[1]=2, the weight sum is 16
                ...
                b[9]=0 and times[9]=1, the weight sum is 0
                
---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 50

void SortAndChange(char s[],int n,int b[])
{
/**********Program**********/




/**********  End  **********/
}

int Calculcate(int b[],int n,int times[],int c[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[N]="13334444555582298760";
    int b[N]={0};
    int c[10]={0};
    int times[10]={0};
    int num;
    int i,n;
            
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
        
    n=strlen(s);
    SortAndChange(s,n,b);
    num=Calculcate(b,n,times,c);

    for(i=0;i<num;i++)
    {
        printf("b[%d] = %d and times[%d] =%d, the weight sum is %d\n",i,b[i],i,times[i],c[i]);
        fprintf(fp,"b[%d]= %d and times[%d] =%d, the weight sum is %d\n",i,b[i],i,times[i],c[i]);
    }
   
    fclose(fp);
    getch();
    return 0;
}