#include "cyber/cyber.h"
#include "cyber/parameter/parameter.h"
#include "cyber/parameter/parameter_client.h"

using apollo::cyber::ParameterClient;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "服务方式启动\n";

    std::shared_ptr<apollo::cyber::Node> client_node = apollo::cyber::CreateNode("param_client"); //创建节点
    std::shared_ptr<ParameterClient> client = std::make_shared<ParameterClient>(client_node,"param"); //创建话题


    Parameter *parame_1 = new Parameter;
    client->GetParameter("age", parame_1);
    AINFO << parame_1->Name() << " age is " << parame_1->AsInt64() << std::endl;
    client->GetParameter("yuri", parame_1);
    AINFO << parame_1->Name() << " yuri is " << parame_1->AsString() << std::endl;

    AINFO << "获取所有参数 ----- \n";
    std::vector<Parameter> parameter;
    client->ListParameters(&parameter);
    for (auto begin = parameter.begin(); begin != parameter.end();begin++)
    {
      AINFO << "打印 name :" << begin->Name()
            << "type name : " << begin->TypeName() << std::endl;
    }

    apollo::cyber::WaitForShutdown();
    delete parame_1;
    return 0;
}
