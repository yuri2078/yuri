/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------

��Ŀ��������main()��һά����a��Ԫ��Ϊ��0���������򽫸���
      ��������b����࣬������������b���Ҳ࣬��������b���
      �ĸ����������Ҳ�������������������С�

��д����
      1. ��д����int split(int a[],int b[],int len)������
         ��a��len�������ֱ���������b���������࣬���и���
         ��������b����࣬������������b���Ҳࡣ����������
         ��b�����һ���������±ꡣ

      2. ��дvoid sort(int a[],int left,int right,int order)
         ������������a���±���[left, right]��Χ�ڵ�Ԫ�ؽ�
         ������������򡣵�order=1ʱ�����н������򣬵�
         order=0ʱ��������������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
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