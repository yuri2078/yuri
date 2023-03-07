/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：假设英文大小写字母的权值分别为：
            A-E,a-e      1;
            F-J,f-j      2;
            K-O,k-o      3;
            P-T,p-t      4;
            U-Y,u-y      5;
            Z,z          6

      计算主函数main()中数组words中的各英文单词的权重（英
      文单词的权重为该单词各字母权值之和）。

例如：
      单词"World"的权重为16(W为5;o为3;r为4;l为3;d为1,5+3+4+3+1=16)。

编写程序：
      1. 编写函数void calculate(char w[][20],int n,int p[])，
         计算数组w中n个英文单词的权重，并将权重存放在数组p中。

      2. 编写函数void sort(int p[],int n,char w[][20])，
         对数组p中n个单词的权重进行降序排序，权重所对应单
         词在数组w中的位置也要作相应调整。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void calculate(char w[][20],int n,int p[]){
/**********Program**********/




/**********  End  **********/
}

void sort(int p[],int n,char w[][20]){
/**********Program**********/




/**********  End  **********/
}

int main(){
    char words[5][20]={{"JiangSu"},{"Teachers"},{"University"},{"of"},{"Technology"}};
    int value[5]={0};
    int i;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL){
        printf("File open error\n");
        exit(0);
    }
    calculate(words,5,value);
    for(i=0;i<5;i++){
        fprintf(fp,"%-20s%4d\n",words[i],value[i]);
        printf("%-20s%4d\n",words[i],value[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    sort(value,5,words);
    for(i=0;i<5;i++){
        fprintf(fp,"%-20s%4d\n",words[i],value[i]);
        printf("%-20s%4d\n",words[i],value[i]);
    }
    fclose(fp);
    getch();
    return 0;
}