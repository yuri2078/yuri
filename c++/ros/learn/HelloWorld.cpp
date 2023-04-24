#include <ros/ros.h>

int main(int argc, char **argv) {
  // 初始化ros包
  ros::init(argc, argv, "Hello_node");
  // 控制台输出
  ROS_INFO("hello wolrd");
  return 0;
}