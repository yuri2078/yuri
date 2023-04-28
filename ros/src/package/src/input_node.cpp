#include <ros/node_handle.h>
#include <ros/publisher.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "input_node");
  ros::NodeHandle handle;

  ros::Publisher publisher = handle.advertise<std_msgs::String>("chatter", 10);
  while (ros::ok()) {
    char c = std::cin.get();
    std_msgs::String str;
    str.data = c;
    publisher.publish(str);
    ros::spinOnce();
  }
  return 0;
}