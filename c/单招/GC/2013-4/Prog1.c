/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ���������Ĺ����ǣ���һά�ַ��������Կո�Ϊ�ָ�����
      ����ת�浽��ά�ַ������У�ʹ��ά�����ÿһ�����ַ�
      ������ʽ����һ�����ʣ�Ȼ�󽫶�ά�ַ������еĵ�����
      ÿ��һ���ķ�ʽ�������Ļ�ϡ�����ȷ������ǣ�
      Microsoft
      data
      access
      technologies

      ����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define W_LEN 15    //���ʳ��ȣ��������������������ĸ��������
#define W_COUNT 20    //�ַ�����������������ʵ�������

int changeStr(char [],char [][W_LEN]);

void main()
{
    char text[]="  Microsoft data  access technologies";
    char word[W_COUNT][W_LEN];
    int wcount=0;    //ͳ���ַ������������ʵĸ���
    int i;
/*******************FOUND*******************/
    wcount=changeStr(text[0],word);
    
    for(i=0;i<wcount;i++)
    {
        puts(word[i]);        
    }    

}

int changeStr(char str[],char word[][W_LEN])
{
    int i=0,j=0,k=0,newword=1;
    do{
        if(str[k]==32)    //32Ϊ�ո��ַ���ASCII��
        {
            if(!newword)
            {
                newword=1;
/*******************FOUND*******************/                
                word[i][j]='';
                j=0;
                i++;
            }
            k++;
        }
        else
        {
            if(newword)    newword=0;
            word[i][j]=str[k];
            k++;
            j++;
        }
            
    }while(str[k]);    
/*******************FOUND*******************/    
    if(str[k]=32)
        return i;
    else
    {
        word[i][j]='\0';
        return i+1;
    }
}