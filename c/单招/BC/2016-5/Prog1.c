/*-------------------------------------------------------
��������ơ�
---------------------------------------------------------
��Ŀ��������main()���ַ���sΪ�������ݣ��ַ���s������ʮ��
      ����ʽ�������ַ��Ӵ��������ַ���ɣ����ַ���s��ʮ��
      ����ʽ�������ַ��Ӵ�ת����ʮ���������������飬����
      �����е�������ȡ������һ���鲢���������У���������
      �����������ĸ�����

      ���磺string:$17 #304!101&113 82*76~109#67@88!
          integers(9): 17   304   101   113   82   76   109   67   88          
          sorted prime(5):17    67    101    109    113
           
��д����
      1.��д����int convert(char s[],int ar[])ʵ������
      ���ܣ����ַ���s��ʮ������ʽ�������ַ��Ӵ�ת����
      ʮ����������������ar����������ʮ���������ĸ�����

      2.��д����int getb(int ar[],int n,int br[])����
      ar�����е�n����������ȡ��������br���鲢���������У�
      �������������������ĸ�����

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��κ���䡣
---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define N 20 
int convert(char s[],int ar[])
{
/**********Program**********/

/**********  End  **********/
}
int getb(int ar[],int n,int br[])
{
/**********Program**********/

/**********  End  **********/
}
int main()
{ 
    int a[N]={0},b[N]={0};
    char s[]={"$17 #304!101&113 82*76~109#67@88! "};
    int i,num;
    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }
    printf("string:%s\n",s);
    fprintf(fp,"string:%s\n",s);
    num=convert(s,a);
    printf("integers(%d):",num);
    fprintf(fp,"integers(%d):",num);
    for(i=0;i<num;i++)
    {
        printf("%d\t",a[i]);
        fprintf(fp,"%d\t",a[i]);
    }
    num=getb(a,num,b);
    printf("sorted prime(%d):",num);
    fprintf(fp,"\nsorted prime(%d)",num);
    for(i=0;i<num;i++)
    {
        printf("%d\t",b[i]);
        fprintf(fp,"%d\t",b[i]);
    }
    fclose(fp);
    getch();
    return 0;
}