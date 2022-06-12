#include <graphics.h>
int main()
{
    initgraph(600, 600); //设置长宽

//画图形
    circle(100,100,50); //没有填充的圆
    fillcircle(300,100,50); //有填充的圆
    solidcircle(500,100,50); //边框是实线的圆
    ellipse(10, 20, 10, 10); //椭圆
    

    closegraph(); //关闭窗口
    return 0;
}