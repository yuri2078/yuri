/*-------------------------------------------------------
��������ա�
---------------------------------------------------------

��Ŀ��ʹ��ð�ݷ���10��������ɵĸ��������д�С������
      �����ź����10���������������   

---------------------------------------------------------
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������ݡ�
      �Ҳ���ʹ��C���ԵĿ⺯��������ա�
-------------------------------------------------------*/

#include <stdio.h>
#define COUNT 10
#include <time.h>
#include <math.h>
#include <stdlib.h>

void bubble_sort(float f[],int n){
    int i,j;
    int swap=1;
    float t;
    i=0;
    while(i<n-1 && swap){
        swap=0;
        for(j=0;j<n-i-1;j++)
        {
/***************SPACE***************/
            if(��?��)
            {
                t=f[j];
                f[j]=f[j+1];
                f[j+1]=t;
                swap=1;                                
            }
        }
        i++;
    }
}

void main(){
    int i;
    float f_data[COUNT];
    srand((unsigned)time(NULL));
    /*�������10��������*/
    for(i=0;i<COUNT;i++) 
        f_data[i]=(float)(rand()%900+100)/(float)10.0;
    printf("\n");
        
/***************SPACE***************/
    bubble_sort(��?��);
        
    printf("The sorted 10 numbers;\n");
        
    for(i=0;i<COUNT;i++) 
    {
        if(i%5==0) printf("\n");
        printf("%8.2f",f_data[i]);
    }
    printf("\n");
}