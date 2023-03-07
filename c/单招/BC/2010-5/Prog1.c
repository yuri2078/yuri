/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()将字符串a中若干个连续的数字字符串转换成整
      数（不考虑正负符号），保存在数组n中，并对数组n中元素
      进行升序排序，最后计算最小值、次小值的最大公约数。

      系统函数 int isdigit(char c) 的功能是判断参数c是否是
      数字字符。如果c是数字字符，函数返回真，否则返回假。

编写程序：
      1、编写int abstract(char a[],int n[])函数: 将字符串a
         中的连续数字字符转换为整数，保存在数组n中,函数返回
         整数个数。

      2、编写void sort(int n[],int k)函数: 对数组n中的k个元
         素进行升序排序。

      3、编写int gcd(int a,int b)函数: 求参数a,b的最大公约数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int abstract(char a[],int n[]){
/**********Program**********/



/**********  End  **********/
}

void sort(int n[],int k){
/**********Program**********/



/**********  End  **********/
}

int gcd(int a,int b){
/**********Program**********/



/**********  End  **********/
}

void main(){
        char a[100]={"kn--23,q,37.&#%%18'w94jAF%130Enter12-+55"};
        int  n[10],k,i;
        FILE *fp;
        k=abstract(a,n);
        sort(n,k);
        if((fp=fopen("data.txt","w"))==NULL){
                printf("File open error\n");
                exit(0);
        }
        for(i=0;i<k;i++){
                fprintf(fp,"%d\t",n[i]);
                printf("%d\t",n[i]);
        }
        k=gcd(n[0],n[1]);
        fprintf(fp,"\n%d, %d 's gcd=%d\n",n[0],n[1],k);
        printf("\n%d, %d 's gcd=%d\n",n[0],n[1],k);
        fclose(fp);
}