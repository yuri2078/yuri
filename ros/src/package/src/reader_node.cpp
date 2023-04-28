#include <ros/init.h>
#include <ros/node_handle.h>
#include <ros/ros.h>
#include <ros/subscriber.h>
#include <std_msgs/String.h>

// 回调函数
void callBack(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO("msg -> %s", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "reader_node");

  // 创建句柄
  ros::NodeHandle node;

  // 创建订阅者
  ros::Subscriber sub = node.subscribe("chatter", 100, callBack);

  // 启动事件循环让节点一直在一个死循环中处理事件
  ros::spin();
  return 0;
}