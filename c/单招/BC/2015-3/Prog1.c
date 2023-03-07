/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

    主函数main()的char s[]中为测试数据，保存了形如
    "  59,63  83,85   94,74  100,80  99,95   77,81 "字符
    串。将字符串中类似"59,63"这样的子串视为一个学生的语文
    和数学成绩，将其转换为整数59和63，其中59为语文成绩，
    63为数学成绩。将这两个成绩分别保存在二维数组score的第
    一列和第二列。并根据总成绩和语文成绩的大小，对score数
    组进行降序排序。

    编写函数：
    1.编写函数int abstract(char s[],int score[][2])，将s
    字符串中类似"59,63"这样的子串转换成两个整数，分别存放
    在score数组第一列和第二列，函数返回这样的子串个数(即
    学生的人数)。
    2.编写函数void sort(int score[][2],int n)，对score数
    组中n个成绩进行降序排序，排序依据是:先按总成绩降序排
    序，如总成绩相同,则再按语文成绩降序排序。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
---------------------------------------------------------*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
int abstract(char s[],int score[][2])
{
/**********Program**********/



    
/**********  End  **********/
}
void sort(int score[][2],int n)
{
/**********Program**********/



    
/**********  End  **********/
}
int main(){
    char s[]="  59,63  83,85   94,74  100,80  99,95   77,81 ";
    int score[10][2],i,n;
    FILE *fp;

    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    n=abstract(s,score);
    sort(score,n);
    for(i=0;i<n;i++){
        printf("%5d%5d%5d\n",score[i][0],score[i][1],score[i][0]+score[i][1]);
        fprintf(fp,"%5d%5d%5d\n",score[i][0],score[i][1],score[i][0]+score[i][1]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    return 0;
}
