#include "cyber/cyber.h"
#include "cyber/demo_cpp/components/Student.pb.h"

using apollo::cyber::demo_cpp::Student;
using namespace apollo;
int main(int argc, char const *argv[])
{
    
    apollo::cyber::Init(argv[0]);
    
    auto talker_node = cyber::CreateNode("ergou"); //创建节点 名称为ergou
    auto talker = talker_node->CreateWriter<Student>("chatter"); //创建监听者， 名称为chatter

    uint64_t sq = 0; //设置计数器

    cyber::Rate rate(0.5); //设置发送频率是每秒0.5次

    while(cyber::OK())
    {
        sq++;
        AINFO << "发送第 " << sq << " 条数据\n"; //提示发送数据

        //写入数据
        auto stu = std::make_shared<Student>();
        stu->set_name("yuri");
        stu->set_age(sq);
        stu->add_loves("终将成为你");
        stu->add_loves("安达与岛村");


        talker->Write(stu); //写入数据

        rate.Sleep(); //调用睡眠函数
    }

    cyber::WaitForShutdown(); //设置结束后删除节点

    return 0;
}
