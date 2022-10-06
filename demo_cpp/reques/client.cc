#include "cyber/cyber.h"
#include "cyber/demo_cpp/reques/request.pb.h"

using apollo::cyber::demo_cpp::Request;
using apollo::cyber::demo_cpp::Response;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "客户端启动捏";

    auto client_node = apollo::cyber::CreateNode("client"); //建立通信节点
    auto client = client_node->CreateClient<Request,Response>("addints"); //设置客户机

    //防止出现没有参数的情况
    if(argc != 3)
    {
        AINFO << "请输入三个参数";
        return 1;
    }

    //新建接收数据对象
    auto request = std::make_shared<Request>();
    request->set_num_1(atoll(argv[1]));
    request->set_num_2(atoll(argv[2]));

    AINFO << "发送数据 num_1 " << request->num_1() << " num_2 "
            << request->num_2();
            
    auto response = client->SendRequest(request); //发送数据，并且把返回的数据赋值给response
    AINFO << "处理结果为 : " << response->sum(); //打印数据

    apollo::cyber::WaitForShutdown();

    return 0;
}
