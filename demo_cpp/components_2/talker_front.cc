#include "cyber/cyber.h"
#include "cyber/demo_cpp/components_2/radar.pb.h"

using apollo::cyber::demo_cpp::Radar;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
	AINFO << "前雷达检测系统初始化成功!!!";
	auto talker_front_node = apollo::cyber::CreateNode("talker_front_node");
	auto talker_front = talker_front_node->CreateWriter<Radar>("front_radar");

	uint64_t sq = 0;

	apollo::cyber::Rate rate(0.25);

	while (apollo::cyber::OK())
	{
		AINFO << "前雷达发送第 " << sq << "条信息";
		std::shared_ptr<Radar> radar = std::make_shared<Radar>();

		radar->set_age(sq);
		radar->set_name("yuri_front");
		radar->set_length(666);

		talker_front->Write(radar);

		sq++;

		rate.Sleep();
	}

	apollo::cyber::WaitForShutdown();

	return 0;
}
