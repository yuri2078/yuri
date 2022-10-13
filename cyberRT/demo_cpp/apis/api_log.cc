#include "cyber/cyber.h"

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]); //初始化日志文件， 默认参数用于文件名，argv0 是文件名

	AINFO << "AINFO 一般信息";
	ADEBUG << "ADEBUG 调试信息"; //仅仅在调试模式输出
	AWARN << "AWARN 警告信息";
	AFATAL << "AFATAL 严重警告信息";
	return 0;
}
