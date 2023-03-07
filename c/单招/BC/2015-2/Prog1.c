/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

    主函数main()的char s[]中为测试数据，保存了形如
    "  9/4  6/13   56/21   8/9   13/5  7/13 "字符串。将字
    符串中类似"9/4"这样的子串视为一个分数，将其转换为整数
    9和4，其中9为分子，4为分母。将分子分母分别保存在二维
    数组frica的第一列和第二列。并根据分数值的大小，对数组
    frica进行升序排序。

    编写函数：
    1.编写函数int abstract(char s[],int frica[][2])，将字
    符串s中类似"9/4"这样的子串转换成两个整数，分别存放在
    frica数组的第一列和第二列，函数返回这样的子串个数(即
    分数个数)。
    2.编写函数void sort(int frica[][2],int n)，根据分数值
    大小，对frica数组中n个分数进行升序排序。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
---------------------------------------------------------*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
int abstract(char s[],int frica[][2])
{
/**********Program**********/



    
/**********  End  **********/
}
void sort(int frica[][2],int n)
{
/**********Program**********/



    
/**********  End  **********/
}
int main()
{
    char s[]="  9/4  6/13   56/21   8/9   13/5  7/13 ";
    int frica[10][2],i,n;
    FILE *fp;

    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    n=abstract(s,frica);
    sort(frica,n);
    for(i=0;i<n;i++){
        printf("%d/%d\t",frica[i][0],frica[i][1]);
        fprintf(fp,"%d/%d\t",frica[i][0],frica[i][1]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    getch();
    return 0;
}