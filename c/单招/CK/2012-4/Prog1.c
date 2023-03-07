/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：程序实现在一个升序排列的整数数组中插入一个数，使数组
      仍保持升序排列。   

---------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
      且不能使用C语言的库函数进行填空。
-------------------------------------------------------*/

#include <stdio.h>

/*输出数组元素*/
void print_array(int a[],int n) {
    int i;
    for(i=0;i<n;i++)
        printf("%4d", a[i]);
    printf("\n");
}

/*在数组中插入一个元素，使其仍然有序，x为待插入的数，
  n为数组中原有元素的个数*/
void insert_array(int a[],int n,int x){
    int i=n-1;
    int find=0;
    while(i>=0 && !find){
        if(x<a[i])
        {
/***************SPACE***************/
            【?】
            i--;
        }
        else find=1;
        }
    a[i+1]=x;
}

void main(){
    int a[11]={1,3,5,8,11,13,17,21,26,30},x;

    printf("The array bofore insert:\n");
    print_array(a,10);
    printf("\nPlease Enter a Intger N=");
    scanf("%d",&x);
    insert_array(a,10,x);
    printf("The array after insert:\n");
    /*调用print_array输出插入元素后的数组*/
/***************SPACE***************/
    【?】
}