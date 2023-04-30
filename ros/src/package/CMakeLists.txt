cmake_minimum_required(VERSION 3.0.2)
project(package)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)


add_message_files(
  FILES
  hello.msg
)


#generate_messages必须在catkin_package前面
generate_messages(
 DEPENDENCIES
)

catkin_package(

  CATKIN_DEPENDS message_runtime
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


add_executable(msg_test_reader src/msg_test/reader.cpp)
target_link_libraries(msg_test_reader
  ${catkin_LIBRARIES}
)

add_executable(msg_test_talker src/msg_test/talker.cpp)
target_link_libraries(msg_test_talker
  ${catkin_LIBRARIES}
)