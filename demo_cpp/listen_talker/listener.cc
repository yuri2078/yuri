#include "cyber/demo_protobuf/test_01/student.pb.h"
#include "cyber/cyber.h"

using apollo::cyber::demo_protobuf::Student;

void cp(const std::shared_ptr<Student> &stu)
{
    AINFO << "----- 接收到数据 开始打印数据 -----";
    AINFO << "name : " << stu->name();
    AINFO << "age : " << stu->age();
    for (auto begin = stu->books().begin(); begin != stu->books().end();begin++){
      AINFO << "books : " << *begin;
    }
}

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    AINFO << "订阅方法创建";

    auto listener_node = apollo::cyber::CreateNode("curhui"); //创建监听节点
    auto listener = listener_node->CreateReader<Student>("chatter", cp); //接受到数据会调用cp函数，这里的名字需要和talker对应

    apollo::cyber::WaitForShutdown(); //等待程序结束删除节点
    return 0;
}
