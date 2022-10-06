#include "cyber/demo_cpp/components_2/my_components_2.h"

bool My_components_2::Init()
{
    AINFO << "组件初始化成功";
	this->writer = this->node_->CreateWriter<Radar>("my_components_2");
	return true;
}

bool My_components_2::Proc(const std::shared_ptr<Radar> &front, const std::shared_ptr<Radar> &back)
{
	AINFO << "信息接受成功！正在处理数据";
	std::shared_ptr<Radar> radar = std::make_shared<Radar>();
	radar->set_age(front->age() + back->age());
	radar->set_name("front + back");
	radar->set_length(front->length() + back->length());

	this->writer->Write(radar);

	AINFO << "处理完毕！ 这是第 " << this->sq++ << " 条数据";

	return true;
}