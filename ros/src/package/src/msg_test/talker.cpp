#include <ros/ros.h>
#include "package/hello.h" // 包含编译生成的.h 文件

using package::hello;

int main(int argc, char **argv) {
  ros::init(argc, argv, "msg_test_talker");

  // 创建句柄
  ros::NodeHandle handle;
  // 实例化一个 publisher 发布者 发布到话题 msg_test 消息队列为20
  ros::Publisher pub = handle.advertise<hello>("msg_test", 20);

  // 设置发布频率为1
  ros::Rate rate(1);
  // 设置年龄标识数据
  int age = 1;

  while (ros::ok()) {
    // 实例化对象并设置数据
    hello h;
    h.name = "yuri";
    h.age = age++;

    // 发布数据
    pub.publish(h);
    // 调用数据处理函数
    ros::spinOnce();

    // 发布频率
    rate.sleep();
  }
  
  return 0;
}
