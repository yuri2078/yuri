/*-------------------------------------------------------
��������ա�
---------------------------------------------------------

��Ŀ�����³���5���ַ�����С������������ַ����ȽϵĹ�
      ��Ϊ���������ַ���������������ַ���ASCII��ֵ��С��
      �бȽϣ�ֱ�����ֲ�ͬ���ַ�������'\0'Ϊֹ��
      ���ȫ���ַ���ͬ������Ϊ��ȣ������ֲ���ͬ���ַ���
      ���Ե�һ������ͬ�ַ��ıȽϽ��Ϊ׼��

---------------------------------------------------------
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������ݡ�
      �Ҳ���ʹ��C���ԵĿ⺯��������ա�
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define N 5
#define MAXLEN 100

/*����compstr(char str1[],char str2[])ʵ���ַ���str1��
  �ַ���str2�ıȽϣ���str1����str2,�򷵻�0����str1С��
  str2,�򷵻�-1����str1����str2,�򷵻�1*/

int compstr(char str1[],char str2[]){
    int flag=0;
    int i=0;
    while (str1[i]&&str2[i]&&!flag)
    {
/***************SPACE***************/
        if (��?��) flag=1;                        
        else if (str1[i]<str2[i]) flag=-1;
        i++;
    }
        
    if(!str1[i] && str2[i]) flag=-1;
    else if(str1[i] && !str2[i]) flag=1;
    return flag;
}

void main(){     
    char ls[N][MAXLEN]={"china","beijing","guangzhou","changchun","jiangsu"};
    char t[MAXLEN];
    int i, j;        

    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-1;j++)
/***************SPACE***************/
            if(��?��>0){ 
                strcpy(t,ls[j]);
                strcpy(ls[j],ls[j+1]);
                strcpy(ls[j+1],t);
            }
    printf("\n\n");
    for(i=0; i<N; i++) printf("%s ",ls[i]);
    printf("\n\n");
}