#include <stdio.h>
int main(void)
{
    int x,s;
    int q;
    char c,h;
    //4+4-4*7+5=
    scanf("%d%c", &x, &c);
    if(c=='*'||c=='/')
    {
        q = x;
        h = c;
        scanf("%d%c", &x, &c);
        if(h=='*')
            s = q * x;
        else
            s = q / x;
    }
    else
        s = x;
    while(c!='=')
    {
        q = x;
        h = c;
        scanf("%d%c", &x, &c);
        if(h=='+')
        {
            if(c!='*'&&c!='/')
            {
                s = s  + x;
            }
            else if(c=='*')
            {
                q = x;
                h = c;
                scanf("%d%c", &x, &c);
                s = s + q * x;
            }
            else 
            {
                q = x;
                h = c;
                scanf("%d%c", &x, &c);
                s = s + q / x;
            }
        }
        if(h=='-')
        {
            if(c!='*'&&c!='/')
            {
                s = s  - x;
            }
            else if(c=='*')
            {
                q = x;
                h = c;
                scanf("%d%c", &x, &c);
                s = s - q * x;
            }
            else 
            {
                q = x;
                h = c;
                scanf("%d%c", &x, &c);
                s = s - q / x;
            }
        }
    }
    printf("%d", s);
    return 0;
}