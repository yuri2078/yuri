/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：主函数main()的一维数组a中元素为非0整数。程序将负数
      存入数组b的左侧，正数存入数组b的右侧，并将数组b左侧
      的负数按升序，右侧的正数按降序重新排列。

编写程序：
      1. 编写函数int split(int a[],int b[],int len)，将数
         组a中len个整数分别存放在数组b的左右两侧，其中负数
         存入数组b的左侧，正数存入数组b的右侧。函数返回数
         组b中最后一个负数的下标。

      2. 编写void sort(int a[],int left,int right,int order)
         函数，对数组a中下标在[left, right]范围内的元素进
         行升序或降序排序。当order=1时，进行降序排序，当
         order=0时，进行升序排序。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int split(int a[],int b[],int len){
/**********Program**********/




/**********  End  **********/
}

void sort(int a[],int left,int right,int order){
/**********Program**********/




/**********  End  **********/
}

int main(){
    int a[10]={7,-2,3,14,-5,-6,5,22,-4,8},b[10];
    int i,mid;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL){
        printf("File open error\n");
        exit(0);
    }
    mid=split(a,b,10);
    for(i=0;i<10;i++){
        printf("%d\t",b[i]);
        fprintf(fp,"%d\t",b[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    sort(b,0,mid,0);
    sort(b,mid+1,9,1);
    for(i=0;i<10;i++){
        printf("%d\t",b[i]);
        fprintf(fp,"%d\t",b[i]);
    }
    printf("\n");
    fprintf(fp,"\n");
    fclose(fp);
    getch();
    return 0;
}