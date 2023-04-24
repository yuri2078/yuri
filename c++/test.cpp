#include <ros/init.h>
#include <ros/node_handle.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "hello");
  ros::NodeHandle n; // 
  return 0;
}