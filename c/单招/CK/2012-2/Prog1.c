/*-------------------------------------------------------
��������ա�
---------------------------------------------------------

��Ŀ���������Ƚ����������12��ˮ�ɻ��������һ��3��4�е�
      ����array�У�Ȼ���ҳ����е���������ڵ��к����кţ�
      �����к����к��������Ļ�ϡ�

˵������νˮ�ɻ�����ָ���λ���������͵��ڸ������������

---------------------------------------------------------
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������ݡ�
      �Ҳ���ʹ��C���ԵĿ⺯��
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int narcissus()
{
    int M,N,t,sum,find=0;
        
    while(!find)
    {
        sum=0;
        N=rand()%900+100;
        M=N;
        while(M)
        {
            t=M%10;
/***********SPACE***********/
            ��?��;
            M=M/10;
        }
        if(N==sum) find=1;
    }
    return N;
}

int max_value(int array[][4],int rw[])
{
    int i,j,max;
    max=array[0][0];
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            if(max<array[i][j])
            {
                max=array[i][j];
                rw[0]=i;
                rw[1]=j;
            }
    return max;
}

void main()
{
    int array[3][4];        //���ڴ��ˮ�ɻ���
    int row_col_num[2];        //���ڴ�����ˮ���������к�
    int i,j;

    srand((unsigned)time(NULL));
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            array[i][j]=narcissus();
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
/***********SPACE***********/
    printf("Max=%d\n",��?��);
    printf("Col number of Max is:%5d\n",row_col_num[0]);
    printf("Row number of Max is:%5d\n",row_col_num[1]);
}