/*-------------------------------------------------------
��������ա�
---------------------------------------------------------

��Ŀ������reverse()���ַ���str��������

---------------------------------------------------------
ע�⣺����Ķ�������main()�е��������ݡ�
-------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<conio.h>

void reverse(char str[]){
    int len, j;
    char c;
/***********SPACE***********/
    len = ��?��(str);
/***********SPACE***********/
    for (j=len-1; ��?��; j--){
        c=str[j];
        str[j]=str[len-1-j];
        str[len-1-j]=c;
    }
}

int main(){
    char a[80];
    printf("Please enter a string: ");
    gets(a);
    reverse(a);       
    printf("The inversed string is: ");
    puts(a);
    getch();
    return 0;
}