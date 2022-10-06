#include "cyber/cyber.h"
#include "cyber/parameter/parameter.h"
#include "cyber/parameter/parameter_server.h"

using apollo::cyber::ParameterServer;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "服务端启动\n";

    std::shared_ptr<apollo::cyber::Node> server_node = apollo::cyber::CreateNode("param"); //创建节点
    std::shared_ptr<ParameterServer> server = std::make_shared<ParameterServer>(server_node); //创建话题

    //设置参数
    server->SetParameter(Parameter("age", 18));
    server->SetParameter(Parameter("yuri", "yes"));

    Parameter *parame_1 = new Parameter;
    server->GetParameter("age", parame_1);
    AINFO << parame_1->Name() << " age is " << parame_1->AsInt64() << std::endl;
    server->GetParameter("yuri", parame_1);
    AINFO << parame_1->Name() << " yuri is " << parame_1->AsString() << std::endl;

    AINFO << "获取所有参数 ----- \n";
    std::vector<Parameter> parameter;
    server->ListParameters(&parameter);
    for (auto begin = parameter.begin(); begin != parameter.end();begin++)
    {
        AINFO << "打印 name :" << begin->Name() << "type name : " << begin->TypeName() << std::endl;
        AINFO << "打印所有参数 " << begin->DebugString();
    }

    apollo::cyber::WaitForShutdown();
    delete parame_1;
    return 0;
}
