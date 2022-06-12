#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(void)
{
    int ch;
    printf("hello world\n");
    while(1)
    {
        if(kbhit())
        {
            ch = getch();
            switch(ch)
            {
                case 'h' :
                {
                    
                    printf("输入了h\n");
                    Sleep(500);
                    break;
                }
                default :
                {
                    
                    printf("输入了别的\n");
                    Sleep(500);
                }
            }            
        }
        else 
        {
           
            printf("没有输入\n"); 
            Sleep(500);
        }
    }

    getchar();
    return 0;
}