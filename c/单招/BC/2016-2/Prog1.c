/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------
题目：主函数main()中一维数组cs为测试数据，均为4位整数。
      首先找出其中的Armstrong数，依次存入二维数组ar的第一列，
      并把Armstrong数从低位到高位数值分别存放在同一行的第二
      至第五列，然后计算二维数组ar中Armstrong数的逆序数并
      替换该数，再根据右边数起第二列数据的大小，以行为单位
      按升序排列。

      Armstrong数是指：一个n位数的各位数字的n次方之和等于
      该数。例如，1634=1^4+6^4+3^4+4^4。因此，1634是4位
      Armstrong数。

例如：将数组cs[]={1158,8208,3945,4578,1634,7792,9474},中的
      Armstrong数存入二维数组ar中：
        8208        8        0        2        8
        1634        4        3        6        1
        9474        4        7        4        9
        替换、排序后:
        8028        8        0        2        8                        
        4749        4        7        4        9
        4361        4        3        6        1

编写程序：
      1.编写函数int arms(int cs[],int ar[][5],int m)实现
      以下功能：从cs数组的m个数中找出Armstrong数，依次存
      入二维数组ar的第一列，并把该数从低位到高位数值分别
      放在同一行的第二、第三、第四和第五列，函数返回
      Armstrong数的总个数。

      2.编写函数void sort(int ar[][5],int n),计算ar数组中
      第一列的n个Armstrong数的逆序数并替换该数，再根据ar
      数组右边数起第二列数据的大小，以行为单位按升序排列。

---------------------------------------------------------
注意：请勿改动主程序main()中的任何语句。
---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define N 10
#define M 5
int arms(int cs[],int ar[][M],int m)
{
/**********Program**********/
    
/**********  End  **********/
}
void sort(int ar[][M],int n)
{
/**********Program**********/

/**********  End  **********/
}
int main()
{ 
    int cs[]={1158,8208,3945,4578,1634,7792,9474},a[N][M]={0};
    int num;
    int i,j;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    num=arms(cs,a,7);
    printf("二维数组\n");
    fprintf(fp,"二维数组\n");
    for(i=0;i<num;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%d\t",a[i][j]);
            fprintf(fp,"%d\t",a[i][j]);
        }
        putchar('\n');
        fputc('\n',fp);
    }
    sort(a,num);
    printf("排序后\n");
    fprintf(fp,"排序后\n");
    for(i=0;i<num;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%d\t",a[i][j]);
            fprintf(fp,"%d\t",a[i][j]);
        }
        putchar('\n');
        fputc('\n',fp);
    }
    fclose(fp);
    getch();
    return 0;
}