#include<iostream>
#include<windows.h>
#include<conio.h>
#include<deque>
#include<ctime>
#include<stdexcept>
using namespace std;

struct Snake { //蛇类结构体
    char image;
    short x, y; //坐标
};

class snakeGame {
	public:
	snakeGame();
	void printMap();
	void gotoxy(short x, short y) {
		hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
		pos = {x, y};
		SetConsoleCursorPosition(hOut, pos); //移动光标
	}
	void HideCursor() //隐藏光标
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = false; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	}
	void initSnake() { //初始化蛇，可以自行改变
		snake.push_front({'@', width / 2, height / 2});
		for (int i=0; i<2;++i)
			snake.push_back({'+', width/2,static_cast<short>(height/2+i+1)});
	}
	int WrongLocation() { //判断是否食物产生位置与蛇身冲突
		for (Snake body : snake)
			if(body.x == food_x && body.y == food_y) return 0;
		return 1;
	}
	void createFood() {
		do {
			food_x = rand() % (width - 4) + 2;
			food_y = rand() % (height - 2) + 1;
		} while (!WrongLocation());//处理冲突
		gotoxy(food_x,food_y); cout << '*' << endl; //打印食物
	}
	void printSnake();
	inline void clearSnake(Snake &tail) {
    	gotoxy(tail.x, tail.y); cout << ' '; //覆盖蛇尾，不使用清屏函数，避免了闪烁
	}
	void judgeCrash();
	void foodEaten();
	void userInput() {
		switch(char ch; ch=getch()) {
			case 'w':if (dir != 's') dir = ch;break;
			case 'a':if (dir != 'd') dir = ch;break;
			case 's':if (dir != 'w') dir = ch;break;
			case 'd':if (dir != 'a') dir = ch;break;
			case 'v':speed*=0.8;break; case 'b':speed*=1.5;break;
			case ' ':gotoxy(width / 2, height); cout << "游戏已暂停，任意键继续"; getch();
            gotoxy(width / 2, height); cout << "                     "; break;
			default:break;
		}
	}
	private:
	enum MapSize {height = 40,width = 120}; //地图尺寸
	HANDLE hOut; COORD pos;
	char dir; //direction
	bool beg,eatFood=false;
	double speed=200;
	deque<Snake> snake;
	int food_x,food_y;
	int score=0;
};
void snakeGame::foodEaten() { //判断是否吃到食物
	createFood();
	eatFood=true;
	speed*=.8;
	++score;
}
void snakeGame::judgeCrash() { //判断是否撞墙或吃到自己
	int flag=0;
	if (snake.size()>=5) {
		deque<Snake>::iterator iter = snake.begin() + 1;
		int x = (iter-1)->x, y = (iter-1)->y;
		for (; iter != snake.end(); ++iter) {
			if (iter->x == x && iter->y == y) flag=1;
		}}
	if (flag || snake.front().x == 1 || snake.front().x == width - 2 || snake.front().y == 0 || snake.front().y == height - 1)//检测是否撞墙或者是否吃到自身
    {
        gotoxy(width / 2 - 10, height /2);
        cout << "游戏结束！您的分数是: " << score << "分（回车继续）"<<endl;
        while(1) {
            dir = getch();
            if (dir == '\r') break;}
		runtime_error quit("游戏结束，正常退出"); throw quit;
    }
}
void snakeGame::printSnake() { //打印蛇身
    deque<Snake>::const_iterator iter = snake.begin();
    for (; iter <= snake.begin() + 1 && iter < snake.end(); ++iter) {
        gotoxy(iter->x, iter->y); cout << iter->image;
    }
}
void snakeGame::printMap() { //打印地图
	int i;
    for (i = 0; i != width; i += 2) cout << "■"; //这个图案宽度占2，高度占1
    gotoxy(0, 1);
    for (i = 1; i != height; ++i) cout << "■" << endl;
    for (i = 1; i != height; ++i) {
        gotoxy(width - 2, i); cout << "■";}
    gotoxy(0, height - 1);
    for (i = 0; i != width; i += 2) cout << "■";
    cout << "贪吃蛇：1.方向键开始游戏 2.*代表食物 3.空格键暂停游戏\n        4.键入'v'加速    5.键入'b'减速";
}
snakeGame::snakeGame() { //开始游戏
	HideCursor(); srand(static_cast<unsigned int>(time(NULL)));
	beg=true;
	Snake tmp1,tmp2;
	while (1) {
		if(beg) {
			printMap();
			dir = getch();
			initSnake();
			createFood();
			beg = eatFood=false;}
		tmp2=snake.back(); tmp1=snake.front();
		snake.pop_back();
		if (eatFood) {tmp2.image='+'; snake.push_back(tmp2);
		eatFood=false;}
		else 		 clearSnake(tmp2);
		if      (dir == 's') ++tmp1.y;
        else if (dir == 'a') --tmp1.x;
        else if (dir == 'd') ++tmp1.x;
        else 				 --tmp1.y;
		try{judgeCrash();}
		catch(runtime_error &quitSignal) {
			throw quitSignal;
		}
		snake.front().image='+'; snake.push_front(tmp1);
		printSnake();
		Sleep(speed+30);
		if (tmp1.x == food_x && tmp1.y == food_y) 
			foodEaten();
		if(kbhit()) userInput();
	}
}
int main() {
	system("mode con cols=120 lines=42");
	try{
		snakeGame game;
	}
	catch(runtime_error &gameEnd) { //结束
		system("cls");
		cout<<gameEnd.what();
		getch();
	}
}