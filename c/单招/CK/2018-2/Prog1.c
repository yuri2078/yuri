/*----------------------------------------------------------------------
��������ա�
------------------------------------------------------------------------
��Ŀ������Find_replace�Ĺ����ǣ���s1ָ����ַ����в���s2ָ����ַ�������
      ���ҵ�����s3ָ����ַ����滻,��ʹ��������1������������0��
        
�������н����
              s2:test        s3:actual
              This is a actual program and a actual data.
              s2:text        s3:actual
              not found
        
------------------------------------------------------------------------   
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������ݡ�
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
        ��?��;
        while(s1[j]==s2[k]&&s2[k]!='\0')
        {   
            j++;  
            k++;      
        }
/**************************SPACE*************************/           
        if(��?��)
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
