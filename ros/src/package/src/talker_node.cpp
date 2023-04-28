#include <ros/node_handle.h>
#include <ros/publisher.h>
#include <ros/rate.h>
#include <ros/ros.h>
#include <sstream>
#include <std_msgs/String.h>

int main(int argc, char *argv[]) {
  // 初始化ros
  ros::init(argc, argv, "talker_node");

  ros::NodeHandle node; // 创建句柄

  // 创建发布者
  ros::Publisher talker = node.advertise<std_msgs::String>("chatter", 100);

  ros::Rate rate(1); // 设置循环每秒钟循环一次

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "发布的第 -> " << ++count << " 条消息!";
    msg.data = ss.str();

    // 发布消息
    ROS_INFO("%s", ss.str().c_str());
    talker.publish(msg);

    // 等待回调函数 比如将数据让别的函数进行处理
    // 将数据分发出去
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
