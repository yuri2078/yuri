#include <ros/ros.h>

int main(int argc, char **argv) {
  // 初始化ros
  ros::init(argc, argv, "Hello_node");
  //打印日志
  ROS_INFO("Hello world");
  return 0;
}