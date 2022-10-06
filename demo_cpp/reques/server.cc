#include "cyber/cyber.h"
#include "cyber/demo_cpp/reques/request.pb.h"

using apollo::cyber::demo_cpp::Request;
using apollo::cyber::demo_cpp::Response;

void cp(const std::shared_ptr<Request> &request, const std::shared_ptr<Response> &response)
{
    //设置数据
    int32_t num_1 = request->num_1();
    int32_t num_2 = request->num_2();

    AINFO << "客户端请求的数据是 : num_1 " << num_1 << " num_2 " << num_2;
    
    //设置需要传送出去的参数
    response->set_sum(num_1 + num_2); //设置sum的数数据
}

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    AINFO << "服务端程序启动";

    auto server_node = apollo::cyber::CreateNode("addints");
    auto server = server_node->CreateService<Request, Response>("addints",cp); //设置接收到数据时的处理函数

    apollo::cyber::WaitForShutdown();

    return 0;
}