# ros

## Hello World

```shell
mkdir -p hello/src #创建工作空间
cd hello/src #进入src目录
catkin_create_pkg Hello roscpp rospy std_msgs 
# 创建ros包
# Hello 包名/ 项目名
# roscpp cpp依赖 std_msgs 消息依赖
cd Hello/src
vim Hello_node.cpp 
vim ../CMakeLists.txt 
cd ../../../ # 回到工作目录
catkin_make #编译
```

### Hello_node.cpp

```c++
#include <ros/ros.h>

int main(int argc, char **argv) {
  // 初始化ros包
  ros::init(argc, argv, "Hello_node");
  // 控制台输出
  ROS_INFO("hello wolrd");
  return 0;
}
```

### CMakeLists.txt 

```cmake
cmake_minimum_required(VERSION 3.0.2)
project(Hello)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES Hello
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/Hello.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_node src/Hello_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above

# 后面两句需要把注释取消
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
 )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_Hello.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

```

```
ros-melodic-desktop-full - exit status 8
ros-melodic-kdl-parser-py - exit status 8

ros-melodic-rviz-plugin-tutorials - exit status 8
ros-melodic-desktop - exit status 8
ros-melodic-ros-tutorials - exit status 8
ros-melodic-rqt-pose-view - exit status 8
ros-melodic-forward-command-controller - exit status 8
ros-melodic-controller-manager - exit status 8
ros-melodic-xacro - exit status 8
ros-melodic-rqt-moveit - exit status 8
ros-melodic-rqt-robot-dashboard - exit status 8
ros-melodic-control-toolbox - exit status 8
ros-melodic-compressed-image-transport - exit status 8
ros-melodic-camera-info-manager - exit status 8
ros-melodic-ros-core - exit status 8
ros-melodic-image-transport-plugins - exit status 8
ros-melodic-turtle-actionlib - exit status 8
ros-melodic-theora-image-transport - exit status 8
ros-melodic-turtle-tf2 - exit status 8
ros-melodic-perception-pcl - exit status 8
ros-melodic-geometry - exit status 8
ros-melodic-tf-conversions - exit status 8
ros-melodic-simulators - exit status 8
ros-melodic-laser-assembler - exit status 8
ros-melodic-gazebo-ros-pkgs - exit status 8
ros-melodic-vision-opencv - exit status 8
ros-melodic-position-controllers - exit status 8
ros-melodic-turtle-tf - exit status 8
ros-melodic-joint-state-controller - exit status 8
ros-melodic-librviz-tutorial - exit status 8
ros-melodic-rqt-rviz - exit status 8
ros-melodic-executive-smach - exit status 8
ros-melodic-rviz-python-tutorial - exit status 8
ros-melodic-rqt-bag-plugins - exit status 8
ros-melodic-gazebo-ros-control - exit status 8
ros-melodic-common-tutorials - exit status 8
ros-melodic-controller-interface - exit status 8
ros-melodic-gazebo-ros - exit status 8
ros-melodic-diff-drive-controller - exit status 8
ros-melodic-camera-calibration-parsers - exit status 4
ros-melodic-laser-filters - exit status 8
ros-melodic-robot-state-publisher - exit status 8
ros-melodic-diagnostic-common-diagnostics - exit status 8
ros-melodic-nodelet-core - exit status 8
ros-melodic-ros-base - exit status 8
ros-melodic-rqt-robot-plugins - exit status 8
ros-melodic-rqt-srv - exit status 8
ros-melodic-self-test - exit status 8
ros-melodic-diagnostic-aggregator - exit status 8
ros-melodic-bond-core - exit status 8
ros-melodic-image-pipeline - exit status 8
ros-melodic-laser-pipeline - exit status 8
ros-melodic-rqt-tf-tree - exit status 8
ros-melodic-urdf-sim-tutorial - exit status 8
ros-melodic-compressed-depth-image-transport - exit status 8
ros-melodic-stereo-image-proc - exit status 8
ros-melodic-perception - exit status 8
ros-melodic-urdf-tutorial - exit status 8
ros-melodic-rqt-action - exit status 8
ros-melodic-image-rotate - exit status 8
ros-melodic-camera-calibration - exit status 8
ros-melodic-gazebo-plugins - exit status 8
ros-melodic-pcl-conversions - exit status 8
ros-melodic-depth-image-proc - exit status 8
ros-melodic-image-publisher - exit status 8
ros-melodic-image-view - exit status 8
ros-melodic-rqt-image-view - exit status 8
ros-melodic-rqt-dep - exit status 8
ros-melodic-rqt-reconfigure - exit status 8
ros-melodic-gazebo-dev - exit status 8
ros-melodic-image-common - exit status 8
ros-melodic-transmission-interface - exit status 8
ros-melodic-visualization-tutorials - exit status 8
ros-melodic-viz - exit status 8
ros-melodic-image-proc - exit status 8
ros-melodic-joint-limits-interface - exit status 8
ros-melodic-rqt-web - exit status 8
ros-melodic-diagnostics - exit status 8
ros-melodic-geometry-tutorials - exit status 8
ros-melodic-smach-ros - exit status 8
ros-melodic-pcl-ros - exit status 8
ros-melodic-rqt-common-plugins - exit status 8
ros-melodic-robot - exit status 8

```

