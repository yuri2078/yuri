#include "cyber/cyber.h"
#include "cyber/demo_protobuf/test_01/student.pb.h"
#include "cyber/record/record_writer.h"

using apollo::cyber::demo_protobuf::Student;
using apollo::cyber::record::RecordWriter;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
	AINFO << "写信息初始化成功!";

	RecordWriter record_wiriter;
	//设置每个文件达到多少kb后新建另外一个文件
	record_wiriter.SetSizeOfFileSegmentation(0);
	//设置每到多少秒钟之后新建另外一个文件
	record_wiriter.SetIntervalOfFileSegmentation(0); 
	//需要写入的文件，文件必须不存在，否则保存捏
	record_wiriter.Open("/apollo/cyber/demo_cpp/tools/mytest.record"); 
	//获得文件名字
	AINFO << "file : " << record_wiriter.GetFile(); 

	//新建话题名称是record
	std::string channel = "chatter"; 
	//第一个是发布话题的名字，第二个是数据类型，第三个参数是消息描述
	record_wiriter.WriteChannel(channel, "apollo.cyber.demo_protobuf.Student","test for record");

    for (size_t i = 0; i < 20; i++)
    {
		//先给消息添加内容
		auto stu = std::make_shared<Student>();
		stu->set_age(i);
		stu->set_name("yuri");
		stu->set_height(i);
		stu->add_books("yuri");
		stu->add_books("终将成为你!");
		stu->add_books("安达与岛村！");

		std::string contant;
		//将消息转化成字符串存进去
		stu->SerializeToString(&contant);
		//写入文件内容，写入序号，以及写入话题
		record_wiriter.WriteMessage(channel,contant,1000 + i);
	}

	//关闭文件
	record_wiriter.Close();

	return 0;
}
