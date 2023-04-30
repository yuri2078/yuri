# cros

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
source devel/setup.zsh # source 一遍就行
roscore # 先启动这个
rosrun Hello Hello_node 
# Hello package 包名
# Hello_node 节点名
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



## ROS基础



### 常用ros包

| 软件包                        | 内容                                                      |
| ----------------------------- | --------------------------------------------------------- |
| **robot_sim_demo**            | 机器人仿真程序，大部分示例会用到这个软件包                |
| **topic_demo**                | topic通信，自定义msg，包括C++和python两个版本实现         |
| **service_demo**              | service通信，自定义srv，分别以C++和python两种语言实现     |
| **action_demo**               | action通信，自定义action，C++和python两种语言实现         |
| **param_demo**                | param操作，分别以C++和python两种语言实现                  |
| **msgs_demo**                 | 演示msg、srv、action文件的格式规范                        |
| **tf_demo**                   | tf相关API操作演示，tf示例包括C++和python两个版本          |
| **name_demo**                 | 演示全局命名空间和局部命名空间下参数的提取                |
| **tf_follower**               | 制作mybot机器人 实现mybot跟随xbot的功能                   |
| **urdf_demo**                 | 创建机器人urdf模型，在RViz中显示                          |
| **navigation_sim_demo**       | 导航演示工具包，包括AMCL, Odometry Navigation等演示       |
| **slam_sim_demo**             | 同步定位与建图演示，包括Gmapping, Karto, Hector等SLAM演示 |
| **robot_orbslam2_demo**       | ORB_SLAM2的演示                                           |
| **ros_academy_for_beginners** | Metapacakge示例，依赖了本仓库所有的pacakge                |

## 通信架构

### master

> 节点管理器,所有节点都需要向ros master 注册
>
> 各个节点也不认识别的,只有通过master才能认识对方

#### roscore

> 启动ros master `roscre` 

他会一同启动几个包:

1. `mastert` 节点管理器
2. `rosout` 日志输出
3. `parameter server` 参数管理器

### node

> 节点 一个节点就是一个ros进程  是 pkg 文件里的可执行程序实例

#### rosrun

> 运行一个ros 节点

指令格式 `rosrun` [包名] [节点名]

执行`yuri` 包下的 `hello_node` 节点 ---`rosrun yuri hello_node`

#### rosnode

> 可以查看ros节点相关信息

1. `rosnode list` 查看正在运行的节点
2. `rosnode info [节点名]` 查看运行节点的相关信息
3. `rosnode kill [节点名]` 结束某个node 节点 

### launch

> 有多个节点需要打开时就会很麻烦,所以就需要一个launch 文件,一次性启动各个节点\

指令格式 `launch [包名] [launch文件名]`

#### 组成

```xml
<launch> <!-- 根标签 -->

    <node> <!-- 需要启动的node 以及参数 -->
    <include> <!-- 包含其他launch 文件 -->
    <machine> <!-- 指定运行的机器 -->
    <env-loader> <!-- 设置环境变量 -->
    <param> <!-- 定制参数到参数服务器 -->
    <rosparam> <!-- 启动yaml 文件到参数服务器 -->
    <arg> <!-- 定义参数传入到launch 文件中 -->
    <remap> <!-- 设置参数映射 -->
    <group> <!-- 设置命名空间 -->

</launch>
```

#### node

```xml
<launch>
    <node pkg="Hello" type="Hello_node" name="Hello_node" output="screen"/>
</launch>
```

- `pkg `表示包名
- `type` 表示节点类型
- `name` 表示命名 
- `output  `重新定向输出

## 通信方式

### topic

> ros 中的异步通信方式  异步:
>
> (发送者只管发送,不管别人怎么接受) (接受者只管接受,不管是谁发的)
>
> node 间通过 publish-subscribe机制通信

#### rostopic

常用指令

1. `rostopic list` 列出所有topic
2. `rostopic info [topic_name] ` 列出topic 信息
3. `rostopic echo [rostopi_name]` 列出topic 内容
4. `rostopic pub [rostopic_name] ...`  向topic 发送内容

### message 

> topic 内容的通信数据类型 定义在 msg/*.msg

####  消息对照表

| msg类型  | C++对应类型   | Python对应类型 |
| -------- | ------------- | -------------- |
| bool     | uint8_t       | bool           |
| int8     | int8_t        | int            |
| int16    | int16_t       | int            |
| int32    | int32_t       | int            |
| int64    | int64_t       | int，long      |
| uint8    | uint8_t       | int            |
| uint16   | uint16_t      | int            |
| uint32   | uint32_t      | int            |
| uint64   | uint64_t      | int，long      |
| float32  | float         | float          |
| float64  | float         | float          |
| string   | std:string    | str，bytes     |
| time     | ros:Time      | rospy.Time     |
| duration | ros::Duration | rospy.Duration |

#### rosmsg

常用指令

1. `rosmsg list` 列出所有msg
2. `rosmsg show [msg_name]` 显示msg 内容

### topic + message 示例

> 使用topic + message 自定义数据类型通信实例

#### 目录结构

```
ros 工作空间
	 -- build  build 文件夹
	 -- devel  devel 文件夹
	 -- package 包
			-- include
			-- launch
			-- msg
				-- hello.msg
			-- src
				-- talker.cpp 
				-- reader.cpp
			-- CMakeLists.txt
			
```

#### msg 文件

需要在 包/msg 文件夹下 所以需要在包下新建msg 文件夹

```c++
string name
int16 age
```

#### talker.cpp

> 需要包含msg 生成的头文件 ,一般是包名/msg文件名.h

```c++
#include <ros/ros.h>
#include "package/hello.h" // 包含编译生成的.h 文件

using package::hello;

int main(int argc, char **argv) {
  ros::init(argc, argv, "msg_test_talker");

  // 创建句柄
  ros::NodeHandle handle;
  // 实例化一个 publisher 发布者 发布到话题 msg_test 消息队列为20
  ros::Publisher pub = handle.advertise<hello>("msg_test", 20);

  // 设置发布频率为1
  ros::Rate rate(1);
  // 设置年龄标识数据
  int age = 1;

  while (ros::ok()) {
    // 实例化对象并设置数据
    hello h;
    h.name = "yuri";
    h.age = age++;

    // 发布数据
    pub.publish(h);
    // 调用数据处理函数
    ros::spinOnce();

    // 发布频率
    rate.sleep();
  }
  
  return 0;
}

```

#### reader.cpp

```c++
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

```

#### xml 文件

需要在包的xml 文件中增加两行依赖

```xml
 <build_depend>message_generation</build_depend>
 <exec_depend>message_runtime</exec_depend>
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.0.2)
project(package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation # 添加这个
)


add_message_files(
  FILES
  hello.msg
)


#添加下面这个
#generate_messages必须在catkin_package前面
generate_messages(
 DEPENDENCIES
)

# 添加这个
catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


# 两个节点
add_executable(msg_test_reader src/msg_test/reader.cpp)
target_link_libraries(msg_test_reader
  ${catkin_LIBRARIES}
)

add_executable(msg_test_talker src/msg_test/talker.cpp)
target_link_libraries(msg_test_talker
  ${catkin_LIBRARIES}
)
```

#### 运行

首先需要source 一下文件

然后你可以运行`roscore` 或者编写`launch` 文件进行运行

运行结果:

```bash

[ INFO] [1682837989.693616266]: name -> yuri, age -> 2
[ INFO] [1682837990.693973701]: name -> yuri, age -> 3
[ INFO] [1682837991.693691557]: name -> yuri, age -> 4
[ INFO] [1682837992.693674520]: name -> yuri, age -> 5
[ INFO] [1682837993.693485060]: name -> yuri, age -> 6
[ INFO] [1682837994.693620069]: name -> yuri, age -> 7

```

