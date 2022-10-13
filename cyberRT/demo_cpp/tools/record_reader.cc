#include "cyber/record/record_reader.h"
#include "cyber/record/record_message.h"
#include "cyber/cyber.h"

using apollo::cyber::record::RecordMessage;
using apollo::cyber::record::RecordReader;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
    AINFO << "初始化成功！ 正在读取文件---";

	//建立reader需要添加读取的文件目录
	RecordReader record_reader("/apollo/cyber/demo_cpp/tools/mytest.record");

	//设置话题
	std::string channel = "chatter";

	//读取文件中对应话题的内容
	size_t msg_number =  record_reader.GetMessageNumber(channel); //消息条数
	std::string msg_type =  record_reader.GetMessageType(channel); //消息类型
	std::string msg_desc = record_reader.GetProtoDesc(channel); //消息描述

	AINFO << "信息获取成功!";
	AINFO << "总共获取到了 " << msg_number << " 条信息!";
	AINFO << "信息类型 : " << msg_type;
	AINFO << "信息描述 : " << msg_desc;

	//创建整合读取消息的对象
	RecordMessage recore_message;
    for (size_t i = 0; i < msg_number; i++)
    {   
		//读取消息，并且存放起来
		if(record_reader.ReadMessage(&recore_message))
        {
			AINFO << "第 " << i << " 条信息！  "
			      << "  hannel_name : " << recore_message.channel_name //话题名字
			      << "  contant : " << recore_message.content //具体存入的消息内容
                  << "  time :" << recore_message.time; //写入消息时的序号
        }else{
			AINFO << "获取信息失败!";
		}
	}

	return 0;
}
