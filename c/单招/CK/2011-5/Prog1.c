/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：在一维数组a中找出最大，最小元素，并将最大元素和数组
      最后一个元素交换，最小元素和数组首元素交换。

---------------------------------------------------------
注意：请勿改动主函数main()中的其他内容。
-------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>

int main(){
    int a[10]={15,8,12,6,10,1,4,5,9,-3};
    int i,t,max_index,min_index;
    max_index=min_index=0;
    for(i=1;i<10;i++){
        if(a[i]>a[max_index])
            max_index=i;
        if(a[i]<a[min_index])
            min_index=i;
    }
    t=a[0];a[0]=a[min_index];a[min_index]=t;
/***********SPACE***********/
    if(max_index==【?】){
        t=a[min_index];a[min_index]=a[9];a[9]=t;
    }
    else{
/***********SPACE***********/
        【?】;
    }
    for(i=0;i<10;i++)
        printf("%d\t",a[i]);
    printf("\n");
    getch();
    return 0;
}