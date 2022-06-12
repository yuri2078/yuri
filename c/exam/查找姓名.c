#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

void  process(char  *s,char **p)
{
    char *t;
    int f = 1;
    while (f)
    {
        for (int i = 0;*(p+i)!=NULL;i++)
        {
            t = strstr(s, *(p + i));
            f = 0;
            if(t!=NULL)
            {
                f = 1;
                t++;
                for (int j = 0; j < strlen(*(p + i))-1;j++,t++)
                {
                    *t = *t - 32;
                }
                i--;
            }
        }
    }
}

int  main()
{
        char  *nameList[]={"Alice",
                                          "Mary",
                                          "Jack",
                                          "Jerry",
                                          "Alexander",
                                          "Mike",
                                          "Peter",
                                          "Robot",
                                          NULL};
        char  text[100];
        gets(text);
        process(text,nameList);
        puts(text);
        return  0;
}