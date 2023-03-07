/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ��void move(int a[],int n,int m)������n��Ԫ�ص�һά
      ����aѭ������m��λ�ã�
      void change(int a[],int n,int b[][N])����������a��
      �д����ά����b��Ȼ��b�������´�������a��

���磺����a��Ԫ��Ϊ1,2,3,4,5,6,7,8,9,10,11,12,����move��
      ����aѭ������3��λ�ú�a��Ԫ��Ϊ
      4,5,6,7,8,9,10,11,12,1,2,3,����change������a��Ԫ
      ��Ϊ4,8,12,5,9,1,6,10,2,7,11,3��

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/
#include <stdio.h>
#define M 3
#define N 4
void move(int a[],int n,int m)
{
    int i,t;
    while(m)
    {
        t=a[0];
        for(i=0;i<n-1;i++)
/*******************FOUND*******************/
            a[i]=a[i+m];
        a[n-1]=t;
        m--;
    }
}
void change(int a[],int n,int b[][N])
{
    int i,j;
    for(i=0;i<n;i++)
/*******************FOUND*******************/
        b[i/M][i-i/N]=a[i];
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
/*******************FOUND*******************/
            a[j*M+i]=b[i][j];
}
int main()
{
    int a[M*N]={1,2,3,4,5,6,7,8,9,10,11,12};
    int b[M][N],i,j,m;
    printf("Before moving\nArray a:\n");
    for(i=0;i<M*N;i++)
        printf("%d ",a[i]);
    printf("\nInput m:\n");
    scanf("%d",&m);
    move(a,M*N,m);
    printf("\nAfter moving\nArray a:\n");
    for(i=0;i<M*N;i++)
        printf("%d ",a[i]);
    change(a,M*N,b);
    printf("\n\nAfter changing\nArray b:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
    printf("Array a:\n");
        for(i=0;i<M*N;i++)
            printf("%d ",a[i]);
    printf("\n");
    return 0;
}