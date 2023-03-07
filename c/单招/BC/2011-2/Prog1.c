/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()中str_b是这样的字符串：若干个长度不等的，
      连续的'0'、'1'字符组成的字符子串被长度不等的'.'字符
      间隔。将连续的'0'、'1'字符子串看成是二进制整数。要求
      将其转换为十进制整数。其中字符子串的首字符代表二进制
      数的符号位，'0'表示正数，'1'表示负数。

例如：
      "0111"表示7，"1111"表示-7。

编写程序：
      1. 编写函数int convert(char b[],int d[])，将字符数组
         b中连续二进制数字字符子串转换为十进制整数，并存入
         整型数组d中。函数返回十进制数的个数。

      2. 编写函数void sort(int d[],int n)，对数组d中n个元素
         进行升序排序。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int convert(char b[],int d[]){
/**********Program**********/




/**********  End  **********/
}

void sort(int d[],int n){
/**********Program**********/




/**********  End  **********/
}

int main(){
    char str_b[100]="...111100.01111.01100111...0111..110000.011..";
    int int_d[10];
    int i,k;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL){
        printf("File open error\n");
        exit(0);
    }
    k=convert(str_b,int_d);
    for(i=0;i<k;i++){
        printf("%d\t",int_d[i]);
        fprintf(fp,"%d\t",int_d[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    sort(int_d,k);
    for(i=0;i<k;i++){
        printf("%d\t",int_d[i]);
        fprintf(fp,"%d\t",int_d[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    getch();
    return 0;
}