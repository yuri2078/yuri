#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
int i = 2, j = 0, len = 6;
class Snake 
{
private:
    int x; //横坐标
    int y; //纵坐标
public:
    Snake(int xx, int yy);
    Snake();
    void PrintSnake(Snake snake[1000]);
    void ChangeSnake(Snake snake[1000]);
    void Setfood(int flag);
    void CheckSnake(Snake snake[1000]);
    void Running(Snake snake[1000]);
    int GameOver(Snake snake[1000]);
};

Snake::Snake(int xx, int yy)
{
    x = xx;
    y = yy;
}

Snake::Snake()
{

}

void Setxy(short int x,short int y) //将光标定位
{
    COORD head = {x, y}; //设置坐标
    HANDLE Cmd = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorPosition(Cmd, head); //设置光标位置
}

void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = FALSE; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

void SetMap(void)
{
    for (int i = 0; i < 100;i=i+2)
    {
        for (int j = 0; j < 50;j++)
        {
            if(i*j == 0 || i == 98 || j == 49)
            {
                Setxy(i, j);
                std::cout << "■";
            }
        }
    }
    Setxy(115, 8);
    std::cout << "欢迎来到贪吃蛇小游戏";
    Setxy(117, 12);
    std::cout << "  W 键 向上移动";
    Setxy(117, 14);
    std::cout << "  S 键 向下移动";
    Setxy(117, 16);
    std::cout << "  A 键 向左移动";
    Setxy(117, 18);
    std::cout << "  D 键 向右移动";
    Setxy(116, 30);
    std::cout << "当前你一共得了 " << len - 6 << " 分！";
}

void Snake::PrintSnake(Snake snake[1000])
{
    for (int i = 0; i < len;i++)
    {
        Setxy(snake[i].x, snake[i].y);
        std::cout << "■";
    }
}

void Snake::ChangeSnake(Snake snake[1000])
{
    for (int k = 0; k < len-1;k++)
    {
        snake[k].x = snake[k+1].x;
        snake[k].y = snake[k+1].y;
    }
    snake[len - 1].x = snake[len - 2].x + i;
    snake[len - 1].y = snake[len - 2].y + j;
}

void Snake::Setfood(int flag)
{
    if(flag)
    {
        srand((unsigned)time(NULL));
        x = (rand() % 50) * 2;
        y = rand() % 50;
        //防止生成到地图上
        while(y * x == 0 || x == 98  || y == 49)
        {
            x = (rand() % 50) * 2;
            y = rand() % 50;
        }
    }
    else
    {
        Setxy(x,y);
        std::cout << "■";
    }
}

void Snake::CheckSnake(Snake snake[1000])
{
    if((x == (snake[len-1].x + i)) && (y == (snake[len-1].y + j)))
    {
        snake[len].x = x;
        snake[len].y = y;
        Setfood(1);
        Setfood(0);
        len++;
    }
}

int Snake::GameOver(Snake snake[1000])
{
    for (int i = 0; i < len - 1;i++)
    {
        if(((x == snake[i].x) && (y == snake[i].y)) || x *y ==0 || x == 98 || y ==49)
        {
            return 1;
        }
    }
    return 0;
}

void Snake::Running(Snake snake[1000])
{
    
    Snake food;
    food.Setfood(1);
    char ch = 'd';
    while(1)
    {
        system("cls");
        SetMap();
        food.Setfood(0);
        if(kbhit())
        {
            ch = getch();
            if(ch == 'w')  //上
            {
                i = 0;
                j = -1;
            }
            else if(ch ==  's') //下
            {
                i = 0;
                j = 1;
            }
            else if(ch ==  'a') //左
            {
                i = -2;
                j = 0;
            }
            else if(ch ==  'd') //右
            {
                i = 2;
                j = 0;
            }
        }
        food.CheckSnake(snake);
        snake[0].ChangeSnake(snake);
        PrintSnake(snake);
        Sleep(300);
        if(snake[len-1].GameOver(snake))
        {
            system("cls");
            SetMap();
            Setxy(44, 30);
            std::cout << "游戏结束！";
            getch();
            break;
        }
    }
}

void GameStart() //游戏开始界面
{
    system("mode con cols=150 lines=50"); //设置窗口大小
    HideCursor();
    SetMap();
    Snake snake[1000] = {
        {20,30},
        {22,30},
        {24,30},
        {26,30},
        {28,30},
        {30,30},
    };
    Setxy(117, 25);
    std::cout << "按下任意键开始游戏";
    getch();
    snake[0].Running(snake);
}

int main()
{
    GameStart();
    return 0;
}