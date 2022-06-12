#include <stdio.h>
#include <string.h>
#include <ctype.h>
char * chaZhao(char *p1,char *p2)
{
    char *p3;
    char a, b;
    while(*p1)
    {
        p3 = p2;
        a = tolower(*p1);
        b = tolower(*p3);
        while(a==b&&a&&b)
        {
            p1++;
            p3++;
            a = tolower(*p1);
            b = tolower(*p3);
        }
        if(*p3==0)
            return p1-p3+p2;
        p1++;
    }
    return NULL;
}
int main(void)
{
    char s1[200], s2[200], s3[200]={0};
    gets(s1);
    gets(s2);
    char *p1, *p2, *p3;
    p1 = s1;
    p2 = s2;
    while((p2=chaZhao(p2,p1))!=NULL)
    {
        p3 = p2 + strlen(s1);
        strcpy(s3, p3);
        strcpy(p2, s3);
    }
    puts(s2);
    return 0;
}