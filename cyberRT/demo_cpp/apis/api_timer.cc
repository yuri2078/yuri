#include "cyber/cyber.h"
#include "cyber/timer/timer.h"

using apollo::cyber::Timer;
int i = 0;

void cp(){
    AINFO << "定时器执行中!  " << ++i;
}

int main(int argc, char const *argv[])
{
	Timer t_1(1000,cp,false);
    //参数 1 设置循环频率 1000就是1000ms 执行1次
    //参数 cp 就是设置循环逻辑
    //参数 3 是否只执行1次

	t_1.Start(); //开启定时器

	sleep(3); //先休眠3s

	t_1.Stop();

	AINFO << "函数停止!";
	return 0;
}
