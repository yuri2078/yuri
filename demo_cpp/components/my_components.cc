#include "my_components.h"

bool my_components::Init() {
	AINFO << "------------ 初始化中 ------------";
	return true;
}

bool my_components::Proc(const std::shared_ptr<Student>& stu)
{
	AINFO << "数据输出!";
	AINFO << "name : " << stu->name();
	AINFO << "age : " << stu->age();
	for (auto begin = stu->loves().begin(); begin != stu->loves().end(); begin++) {
		AINFO << "loves " << *begin;
	}
	return true;
}
