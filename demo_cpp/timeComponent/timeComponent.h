#ifndef TIMECOMPONENT_H
#define TIMECOMPONENT_H


#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"

using apollo::cyber::TimerComponent;

class My_TimeComponent: public TimerComponent
{
private:
	uint64_t sq;

public:
	bool Init() override;
	bool Proc() override;
};

CYBER_REGISTER_COMPONENT(My_TimeComponent)
#endif