cmake_minimum_required(VERSION 3.0.2)
project(package)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)


# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )




catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES package
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(hello_node src/hello_node.cpp)
target_link_libraries(hello_node
  ${catkin_LIBRARIES}
)

add_executable(input_node src/input_node.cpp)
target_link_libraries(input_node
  ${catkin_LIBRARIES}
)

add_executable(reader_node src/reader_node.cpp)
target_link_libraries(reader_node
  ${catkin_LIBRARIES}
)


add_executable(talker_node src/talker_node.cpp)
target_link_libraries(talker_node
  ${catkin_LIBRARIES}
)