#ifndef MY_COMPONENTS_2_H
#define MY_COMPONENTS_2_H

#include "cyber/component/component.h"

#include "cyber/demo_cpp/components_2/radar.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_cpp::Radar;

class My_components_2 : public Component<Radar, Radar>
{
private:
	std::shared_ptr<apollo::cyber::Writer<Radar>> writer;
	uint64_t sq = 0;

public:
	bool Init() override; 
	bool Proc(const std::shared_ptr<Radar>& front,const std::shared_ptr<Radar>& back) override; 
};

CYBER_REGISTER_COMPONENT(My_components_2) //注册组件

#endif