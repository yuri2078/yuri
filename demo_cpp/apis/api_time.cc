#include "cyber/cyber.h"

using apollo::cyber::Time;

int main(int argc, char const *argv[])
{
	Time t_1; //默认构造函数，获取默认时间 1970.1.1.8：00：000
	Time t_2(6666); //整形构造函数，获取默认时间加上 6666ns
	Time t_3(120.0); //double构造函数，获取默认时间加上 120s

	AINFO << "t_1 : " << t_1;
	AINFO << "t_2 : " << t_2;
	AINFO << "t_3 : " << t_3;
	AINFO << "t_2(s) : " << t_2.ToSecond(); //转换成秒
	AINFO << "t_2(ns) : " << t_2.ToNanosecond(); //转换成纳秒
	AINFO << "t_2(ms) : " << t_2.ToMicrosecond(); //转换成微秒
	AINFO << "t_3(s) : " << t_3.ToSecond();

	//获取最大或者最小时间
	//默认添加的是ns 而ns是long long 类型，所有默认最大值是 2^64 - 1

	AINFO << "max time (s) " << Time::MAX.ToSecond(); //最大时间
	AINFO << "min time (s) " << Time::MIN.ToSecond(); //最小时间
	AINFO << "t_1 is zeor ? " << t_1.IsZero(); //判断是不是0
	AINFO << "t_2 is zeor ? " << t_2.IsZero(); //只有当时间为默认时间时，才会是0


	AINFO << "现在时间 : " << Time::Now(); //返回现在时间
	Time::SleepUntil(Time(Time::Now().ToSecond() + 10));  //休眠 直到 --- 设置的时间
	AINFO << "现在时间 : " << Time::Now();

	AINFO << "系统已经运行了 : " << Time::MonoTime().ToSecond(); //返回系统开机运行的时间，这里返回docker容器启动的时间

	return 0;
}
