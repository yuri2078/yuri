#include "cyber/demo_cpp/timeComponent/timeComponent.h"

bool My_TimeComponent::Init()
{
    AINFO << "定时器组件初始化成功!";
	this->sq = 0;
	return true;
}

bool My_TimeComponent::Proc()
{
	sq++;
	AINFO << "处理数据中" << sq;
	return true;
}