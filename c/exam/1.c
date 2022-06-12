#include <stdio.h>
int main(void)
{
    char s[80],t;
    int i, j;
    char *p;
    p = s;
    gets(s);
    for (i = 0; *(p + i + 1);i++)
    {
        for (j = i + 1; *(p + j);j++)
        {
            if(*(p+i)>*(p+j))
            {
                t = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = t;
            }
        }
    }
    for (i = j = 0; *(p + i);i++)
    {
        if(*(p+i)!=*(p+i+1))
        {
            *(p + j) = *(p + i);
            j++;
        }
    }
    *(p + j) = 0;
    puts(p);
}