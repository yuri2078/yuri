#include <ros/ros.h>
#include "package/hello.h"

using package::hello;

// 回调函数,类型需要是 ConstPtr 
void callBack(const hello::ConstPtr &h) {
  ROS_INFO("name -> %s, age -> %d", h->name.c_str(), h->age);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "msg_test_reader");

  // 创建句柄并订阅 mst_test 话题
  ros::NodeHandle handle;
  ros::Subscriber sub = handle.subscribe<hello>("msg_test", 20, callBack);

  
  ros::spin();
  return 0;
}
