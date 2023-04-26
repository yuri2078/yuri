cmake_minimum_required(VERSION 3.0.2)
project(yuri)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

add_executable(Hello_node src/Hello_node.cpp)
add_executable(talker_node src/talker_node.cpp)
add_executable(reader_node src/reader_node.cpp)


target_link_libraries(Hello_node
  ${catkin_LIBRARIES}
)

target_link_libraries(talker_node
  ${catkin_LIBRARIES}
)

target_link_libraries(reader_node
  ${catkin_LIBRARIES}
)
