/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ������unsigned delbits(unsigned x,unsigned p,unsigned n)
      �ѷǸ�����x����˵�p(p>1)λ��ʼ��nλɾ�����γ��µ���
      ���ء�

���磺��xΪ12345��pΪ3��nΪ2���γ��µ���Ϊ125��
      ��xΪ12345��pΪ6��nΪ2���γ��µ���Ϊ12345��
      ��xΪ12345��pΪ3��nΪ4���γ��µ���Ϊ12��

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/

#include <stdio.h>
unsigned delbits(unsigned x,unsigned p,unsigned n)
{
    int a[10],i,j,k;
    i=0;
    while(x)
    {
/*******************FOUND*******************/        
        a[i]=x%10;
        x/=10;
    }
    k=i;
    for(i=0;i<k/2;i++)
    {
        a[i]+=a[k-i-1];
        a[k-i-1]=a[i]-a[k-i-1];
        a[i]=a[i]-a[k-i-1];
    }
    j=p-1;
/*******************FOUND*******************/        
    for(i=p+n;i<=k-1;i++)
    { 
        a[j]=a[i];
        j++;
    }
    k=j;
    for(i=0;i<k;i++) 
/*******************FOUND*******************/        
        x+=a[i]*10;
    return x;
}
int main()
{
    unsigned x,p,n;
    printf("Input x(unsigned int):\n");
    scanf("%u",&x);
    printf("Input p(unsigned int):\n");
    scanf("%u",&p);
    printf("Input n(unsigned int):\n");
    scanf("%u",&n);
    x=delbits(x,p,n);
    printf("After deleting  x=%u\n",x);
    return 0;
}