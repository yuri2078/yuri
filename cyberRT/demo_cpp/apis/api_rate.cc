#include "cyber/cyber.h"
#include "cyber/time/rate.h"

using apollo::cyber::Rate;

int main(int argc, char const *argv[])
{
	Rate r_1(2.0); //使用double类型会将发布频率设置为 2.0，也就是休眠时间 1/2.0 也就是0.5s
	Rate r_2((uint64_t)1000000000); //直接设置休眠时间为多少ns
	apollo::cyber::Duration d_1(5.0);
	Rate r_3(d_1); //直接设置持续时间

	AINFO << "r_1 休眠前时间 " << apollo::cyber::Time::Now();
	r_1.Sleep(); //启动休眠
	AINFO << "r_1 休眠后时间 " << apollo::cyber::Time::Now();
	AINFO << "";
	AINFO << "r_2 休眠前时间 " << apollo::cyber::Time::Now();
	r_2.Sleep();
	AINFO << "r_2 休眠后时间 " << apollo::cyber::Time::Now();
	AINFO << "";
	AINFO << "r_3 休眠前时间 " << apollo::cyber::Time::Now();
	r_3.Sleep();
	AINFO << "r_3 休眠后时间 " << apollo::cyber::Time::Now();
	return 0;
}
