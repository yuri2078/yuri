/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：若一个数和该数的逆序数相同，就称该数为回文数。对于
      一个非回文数，加上该数的逆序数后，其和可能是回文数。
      如和仍然是非回文数，则有限次重复上述步骤总能得到回
      文数。

      例如，87是非回文数，则
      87+78=165         165 非回文数
      165+561=726       726 非回文数
      726+627=1353     1353 非回文数
      1353+3531=4884   4884 回文数

      主函数main()从文件中读入一个正整数，判断其是否是回
      文数。如果该数是回文，则输出该数，如果不是回文，则
      使用上述算法，求出回文数。

编写程序：
     1、编写int reverse(int x)函数：求参数x的逆序数，并将
        该逆序数返回。

     2、编写int ispalin(int x)函数：判断参数x是否是回文数，
        是回文数，函数返回真，否则函数返回假。

     3、编写int palin(int x)函数：如果参数x是回文数，函数
        返回x; 如果x不是回文数，则根据上述算法求出回文数后，
        返回该回文数。

---------------------------------------------------------
注意：请勿改动主函数main()中的任何语句。
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
int reverse(int x){
/**********Program**********/




/**********  End  **********/
}

int ispalin(int x){
/**********Program**********/




/**********  End  **********/
}

int palin(int x){
/**********Program**********/




/**********  End  **********/
}

void main(){
  int  x, y;
  FILE *fpin,*fpout;
  if((fpin=fopen("input.txt","r"))==NULL){
          printf("Input file open error\n");
          exit(0);
  }
  fscanf(fpin,"%d",&x);
  fclose(fpin);
  y=palin(x);
  printf("initial is %d\n",x);
  printf("palindrome is %d\n",y);
  if((fpout=fopen("data.txt","w"))==NULL){
          printf("Output file open error\n");
          exit(0);
  }
  fprintf(fpout,"initial is %d\n",x);
  fprintf(fpout,"palindrome is %d\n",y);
  fclose(fpout);
}