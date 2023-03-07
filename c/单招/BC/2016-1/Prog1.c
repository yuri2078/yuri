/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------
题目：按从小到大的顺序找出所有的4位Armstrong数，并把这些
      Armstrong数对应的逆序数以及该逆序数从高位到低位的数
      值依次存入二维数组ar的第一至第五列，再找到逆序数中
      十位数最小的行，该行之前数据保持不变，该行到最后一
      行数据，以行为单位循环前移一行，该行移至最后一行。 

      Armstrong数是指：一个n位数的各位数字的n次方之和等于
      该数。例如，1634=1^4+6^4+3^4+4^4。因此，1634是4位
      Armstrong数。

例如：按规则得到的二维数组:
        4361        4        3        6        1
        8028        8        0        2        8
        4749        4        7        4        9
      移动后的二维数组:
        4361        4        3        6        1
        4749        4        7        4        9
        8028        8        0        2        8


编写程序：
      1.编写函数int arms(int ar[][5])实现以下功能：按以上
      规则将4位Armstrong数的逆序数以及该逆序数的高位到低位
      数值依次存入二维数组ar的第一至第五列，函数返回4位
      Armstrong数的总个数。

      2.编写函数void mov(int ar[][5],int n)，在ar数组的前n行
      中找到逆序数的十位数最小的行，该行之前数据保持不变，
      该行到最后一行数据，以行为单位循环前移一行，该行移至
      最后一行。 

---------------------------------------------------------
注意：请勿改动主程序main()中的任何语句。
---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define N 10
#define M 5
int arms(int ar[][M])
{
/**********Program**********/




/**********  End  **********/
}
void mov(int ar[][M],int n)
{
/**********Program**********/




/**********  End  **********/
}
int main()
{ 
    int a[N][M]={0};
    int i,j,num;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    num=arms(a);
    printf("二维数组\n");
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
    mov(a,num);
    printf("移动后\n");
    fprintf(fp,"移动后\n");
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