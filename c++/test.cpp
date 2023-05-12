#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "hello");
	ROS_INFO("hello world");
	return 0;
}
