#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
struct Snake //定义蛇蛇结构体
{
    short int x; //横坐标
    short int y; //纵坐标
    struct Snake *next; //下一条蛇的地址
};

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

void GameStart() //游戏开始界面
{
    system("mode con cols=150 lines=50"); //设置窗口大小
    for (int i = 0; i < 150; i++)
    {
        printf("■");
    }
    Setxy(65, 15);
    printf("欢迎你来到贪吃蛇游戏");
    HideCursor();
    Setxy(0, 48);
    for (int i = 0; i < 150; i++)
    {
        printf("■");
    }
    Setxy(66, 40);
}

void PrintSnake(struct Snake *head)
{
    while(head)
    {
        Setxy(head->x, head->y);
        printf("■");
        head = head->next;
    }
}

struct Snake * Setsnake(void)
{
    struct Snake *head,*temp; //初始化蛇蛇
    head = (struct Snake *)malloc(sizeof(struct Snake));
    head->x = 10; //起点横坐标
    head->y = 30; //起点纵坐标
    temp = head;
    for (int i = 0; i < 5;i++) //接连生成5个
    {
        temp->next = (struct Snake *)malloc(sizeof(struct Snake));
        temp = temp->next;
        temp->x = 12 + i*2;
        temp->y = 30;
    }
    temp->next = NULL;
    return head; //返回生成的新蛇头
}

void Setmap(void)
{
    system("color fc");
    for (int i = 0; i < 150;i=i+2)
    {
        for (int j = 0; j < 50;j++)
        {
            if(i == 0 || i == 148 || j == 0 || j == 49)
            {
                Setxy(i, j);
                printf("■");
            }
        }
    }
}

void Setfood(struct Snake *food, int flag)
{
    if(flag)
    {
        srand((unsigned)time(NULL));
        food->x = (rand() % 75) * 2;
        food->y = rand() % 50;
        //防止生成到地图上
        while(food->y == 0 || food->y == 49 || food->x == 0 || food->x == 148)
        {
            food->x = (rand() % 75) * 2;
            food->y = rand() % 50;
        }
    }
    else
    {
        Setxy(food->x,food->y);
        printf("■");
    }
}

int CheckSnake(struct Snake * head, struct Snake * tail)
{
    while(head->next)
    {
        //碰到自己和碰到地图都会失败
        if ((head->x == tail->x && head->y == tail->y) || tail->y == 0 || tail->y == 49 || tail->x == 0 || tail->x == 148)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void Relase(struct Snake * head)
{
    struct Snake *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void Game(void) //游戏主体
{
    char ch = 'd'; //默认移动方向为右
    int i = 2, j = 0, point=0;
    GameStart(); //打印开始欢迎界面
    system("pause"); //暂停一下，按任意键开始
    struct Snake *snakeHead, *temp, *tail, *food=(struct Snake *)malloc(sizeof(struct Snake));
    Setfood(food, 1); //生成蛇蛇的食物
    snakeHead = Setsnake(); //生成小蛇蛇
    tail = snakeHead; //计算蛇尾
    while(tail->next)
    {
        tail = tail->next;
    }
    //游戏开始
    while(1)
    {
        system("cls"); //清空屏幕
        Setmap(); //开始打印地图框架
        Setfood(food,0); //打印食物
        if (kbhit()) //检测键盘输入
        {
            ch=getch(); // 将键盘输入赋值给ch，并且不同回车确定
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
        // 每次移动产生新的坐标
        temp = snakeHead; //更改蛇头的坐标使他成为新的蛇尾，不断重复
        snakeHead = snakeHead->next;
        tail->next = temp;
        temp->x = tail->x +i;
        temp->y = tail->y +j;
        tail = tail->next;
        tail->next = NULL;
        if(CheckSnake(snakeHead,tail)) //出现碰撞，游戏结束
        {
            system("cls");
            Setmap();
            Setxy(65, 20);
            printf("game is over\n");
            Setxy(65, 23);
            printf("总共得分: %d 分\n", point);
            break;
        }
        if (food->x == snakeHead->x && food->y == snakeHead->y)
        {
            temp = tail;
            point++; //分数加1
            tail = (struct Snake *)malloc(sizeof(struct Snake));//生成新的蛇尾
            tail->x = temp->x +i; 
            tail->y = temp->y +j;
            temp->next = tail; //蛇尾变成新的蛇尾
            tail->next = NULL; //蛇尾的next为NULL
            Setfood(food, 1); //产生新的蛇头
            Setfood(food, 0); //打印新的蛇头
        }
        PrintSnake(snakeHead); //打印蛇身
        Sleep(50);
    }
    Setxy(65, 26);
    system("pause"); //游戏结束暂停
    Relase(snakeHead); //游戏结束回收小蛇蛇
}

int main(void)
{
    //所有用到的函数
    void GameStart(); //游戏开始界面
    void Setxy(short int x, short int y); //定义设置坐标函数
    void HideCursor(); //隐藏光标
    void Setmap(); //打印地图
    void PrintSnake(struct Snake * head); //打印小蛇蛇
    struct Snake *Setsnake(void); //生成小蛇蛇
    int CheckSnake(struct Snake * head, struct Snake * tail); //检查蛇蛇有没有撞到自己
    void Relase(struct Snake * head); //回收自己产生所有空间

    //运行的函数
    Game(); //开始游戏
    return 0;
}