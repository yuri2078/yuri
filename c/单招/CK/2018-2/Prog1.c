/*----------------------------------------------------------------------
【程序填空】
------------------------------------------------------------------------
题目：函数Find_replace的功能是：在s1指向的字符串中查找s2指向的字符串，若
      能找到就用s3指向的字符串替换,并使函数返回1，否则函数返回0。
        
程序运行结果：
              s2:test        s3:actual
              This is a actual program and a actual data.
              s2:text        s3:actual
              not found
        
------------------------------------------------------------------------   
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int Find_replace(char s1[],char s2[],char s3[])
{   
    int i,j,k,t=0,n;   
    char temp[80];
    for(i=0;s1[i]!='\0';i++)
    {   
        k=0;    
/**************************SPACE*************************/
        【?】;
        while(s1[j]==s2[k]&&s2[k]!='\0')
        {   
            j++;  
            k++;      
        }
/**************************SPACE*************************/           
        if(【?】)
        {    
            for(n=j;s1[n]!='\0';n++)
                temp[n-j]=s1[n];
            temp[n-j]=0;
            for(n=0;s3[n]!='\0';n++)
                s1[n+i]=s3[n];
            s1[n+i]=0;
            i=i+strlen(s3);         
            for(n=0;temp[n]!='\0';n++)
                s1[n+i]=temp[n];
            t=1;
        }
    }
    return t;
}
int main()
{  
    char s1[80]="This is a test program and a test data.";
    char s2[2][10]={"test","text"},s3[10]="actual";     
    int i,k;
    for(i=0;i<2;i++)
    {
        k=Find_replace(s1,s2[i],s3);
        if(k==1)
        {
            printf("s2: %s \t s3:%s\n",s2[i],s3);
            puts(s1);
        }
        else
        {
            printf("s2: %s \t s3:%s\n",s2[i],s3);
            printf("not found\n");
        }
    }
    return 0;
}
