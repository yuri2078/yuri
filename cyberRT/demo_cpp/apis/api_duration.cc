#include "cyber/cyber.h"
#include "cyber/time/duration.h"

using apollo::cyber::Duration;
using apollo::cyber::Time;

int main(int argc, char const *argv[])
{
	Duration d_1(5.0); //创建5s的持续时间
    //别的东西基本和time 相同
	Time t_1(10.0);
	Time t_2(5.0);

	Duration d_2(5 + 1000); //创建5s 加上 1000ns 的持续时间

	AINFO << "d_1 time : " << d_1;
	AINFO << "d_2 time : " << d_2;
	AINFO << "t_1 time : " << t_1;
	AINFO << "d_2 time : " << t_2;

	AINFO << "现在时间是： " << Time::Now();
	d_1.Sleep(); //休眠5s
	AINFO << "现在时间是： " << Time::Now();

	AINFO << "t_1(10.0) + d_1(5.0) : " << t_1 + d_1;  //结果就是10 - 5 
	AINFO << "t_1(10.0) - d_1(5.0) : " << t_1 - d_1;
	AINFO << " d_1 == d_2 ? " << (d_1 == d_2);

	return 0;
}

