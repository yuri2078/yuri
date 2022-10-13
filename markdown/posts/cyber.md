---
title: cyber RT 开发教程
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 教程
comments: true
description: 我的爱宛如孤岛之花，不为人知的绽放，不为人知的凋零！
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/6.png'
date: 2022-9-17 18:32:01.587
tags:
    - apollo
keywords:
---

# apollo Cyber c++ 实现

> 前言： 本文是基于赵老师的视频：[CyberRT教程](https://www.bilibili.com/video/BV16U4y1U75F/?spm_id_from=333.999.0.0) ，文中所有东西都是基于arch + vscode  1.72
>
> 建议： 使用前先去cyber/setup.bash 将export GLOG_alsologtostderr=0  这句话修改成1，因为后续的所有内容均在终端中输出，需要将这个日志设置改为1

**使用vscode 环境**

## vscode 插件

1. Bazel 
2. bazel  build工具
3. c/c++ 必要插件
4. docker 连接docker容器
5. jupytr
6. jupytr keymap
7. protobuf 
8. Remote 远程链接docker插件
9. Chinese 中文汉化插件

## 编译第一个hello项目

### 新建文件

1. 在vscode中打开docker容器 选择 attach visual studio code![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_132150.png)

2. 在新的vscode中打开容器 选择打开文件夹 选择apollo 目录就行了![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_132655.png)

3. 在Cyber 文件夹中新建 demo_cpp 文件夹 用来存放以后的cpp代码

4. 新建一个helloworld.cc文件夹

   ```c++
   #include "cyber/cyber.h"
   
   int main(int argc, char const *argv[])
   {
       /* code */
       apollo::cyber::Init(argv[0]);
       AINFO << "hello world";
       return 0;
   }
   
   ```

5. 在个更目录下新建BUILD文件， 输入cc后 自动补全选择cc_binary，删除不要的第三个空的补全，并把具体内容补全

   ![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_133854.png)

   ```basic
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
   cc_binary(
       name = "helloworld", #项目名字
       srcs = ["helloworld.cc"], #项目文件
       deps = ["//cyber"], #固定写法
   )
   ```

### 开始构建项目

1. 终端运行 `bazel build cyber/demo_cpp/...` 构建项目下所有文件，终端出现以下内容就是成功![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_134900.png)

2. 修改cyber /setup.bash 文件  ---- `export GLOG_alsologtostderr=1  #把这里改成 1 原来是0` 大概35行左右

   ![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_135251.png)

3. 查看bazel-bin/cyber/文件夹下面是不是有一个demo_cpp文件夹，里面有一个hellowrold文件 直接执行就行了

4. 输入`source cyber/setup.bash `命令 令配置立即生效

5. 输入`./bazel-bin/cyber/demo_cpp/helloworld `执行程序 终端输出如图就是成功![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220918_135958.png)

   

## bazel 的基本使用

1. 在cyber文件夹下新建demo_base_bazel文件夹

2. 在demo_base_bazel文件夹下 新建 pro1_helloworld 文件夹 用来存放项目

3. 在pro1_helloworld文件夹下 新建WORKSPACE文件标识这是一个bazel项目

4. 在pro1_helloworld 新建 demo_pkt 文件夹存放文件

5. 在demo_pkt文件夹下新建 cpp文件 比如简单打印hello bazel

6. 新建BUILD 文件 输入cc 补全

7. 编辑build文件
    ```cmake
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
   cc_binary(
       name = "hello",
       srcs = ["hello.cc"],
   )
   ```

8. 文件基本目录![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220920_183831.png)

9. 新建终端 cd 进 pro1_helloworld 工程目录就行

10. 输入 `bazel build demo_pkt/...`然后编译成功会生成一些文件夹

11. ![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220920_184524.png)

12. ![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220920_184533.png)

13. 然后进入bazel-bin/demo_pkt/目录运行 hello就行了![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220920_184908.png)

### bazel 其余编译方法补全

1. `bazel run demo_pkt:hello`编译并运行 build文件中hello项目
2. `bazel build demo_pkt:hello`只编译 hello
2. 建立WORKSPACE文件的目录为工程根目录

## bazel 实现库依赖

### 实现库的同包依赖

新建demo_lib 文件夹然后新建WORKSPACE 表明根目录 并在里面新建 lib_hello 文件夹，所有文件都在下面

#### 编写头文件

get_name.h

```c
#ifndef GET_NAME
#define GET_NAME

#include <string>
#include <iostream>

std::string get_name(const std::string &name);

#endif
```

#### 编写具体实现

```c++
#include "get_name.h"

std::string get_name(const std::string &name){
   return "hello " + name;
}
```

#### 新建BUILD文件 

可以 输入cc 补全 libnary

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "getName", #
    srcs = ["get_name.cc"], #具体实现文件
    hdrs = ["get_name.h"], #头文件
)
```

#### 开始构建

cd 进lib_hello 文件夹输入`bazel build ...` 编译库文件

新建helloworld源代码

```c++
#include "get_name.h"

int main(int argc, char const *argv[])
{
    std::cout << get_name("yuri is yes!") << std::endl;
    return 0;
}
```

更改build文件

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "get_name_lib",
    srcs = ["get_name.cc"],
    hdrs = ["get_name.h"],
)


# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "hello_world", #编译的可执行文件名称
    srcs = ["helloWorld.cc"], #需要执行的文件
    deps = [":get_name_lib"], #需要添加的头文件
)
```



输入 `bazel run :hello_world` 看到输出就是成功

###   实现库的跨包依赖

更目录新建文件夹 用来存放别的文件

#### 新建hello.cc文件

```c++
#include "lib_hello/get_name.h" //必须包含lib目录下的头文件，不能直接包含.h

int main(int argc, char const *argv[])
{
    std::cout << get_name("yuri is very yes!") << std::endl;
    return 0;
}

```



#### 新建build文件

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    deps = ["//lib_hello:get_name_lib"], #添加lib_hello文件夹下面build文件夹中的get_name_lib 文件
)
```



#### 实现不同包的引用

1. 被调用的包的build文件添加生声明`package(default_visibility = ["//visibility:public"])`

   表明这个包被所有的包共享

2. 在被调用的包里添加指定调用包`*visibility* = ["//other_lib:__pkg__"] ` 指定根目录下的文件夹

文件基本目录结构![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220920_203052.png)

#### 构建

cd 进 目录进行build就行了

## protobuf 的基本使用方式 

**使用protobuf进行c++ 开发**

**protocol buffers （ProtoBuf）是一种语言无关、平台无关、可扩展的序列化结构数据的方法，它可用于（数据）通信协议、数据存储等。**

**Protocol Buffers 是一种灵活，高效，自动化机制的结构数据序列化方法－可类比 XML，但是比 XML 更小（3 ~ 10倍）、更快（20 ~ 100倍）、更为简单。**

**json\xml都是基于文本格式，protobuf是二进制格式。**

### 编写proto并且编译

#### 编写proto 文件

新建demo_protobuf 文件夹

在文件夹里面新建student.proto 文件

```protobuf
//proto文件主要由三部分组成

//第一部分 proto 的版本号
syntax = "proto2";

//声明包

package apollo.cyber.demo_protobuf;

//声明消息
//使用关键字message 就当class使用就行
//数据分为 字段规则 数据类型 名字 编号

message Student {

    required string name = 1; //required -- 必须要的参数
    optional int64 age = 2; //optional -- 可以省略的参数
    optional double height = 3; 
    repeated string books = 4; //repeated -- 可以输入多个数据
}
```

#### 编写build文件

```cmake
package(default_visibility = ["//visibility:public"]) #使这个包的文件共享

#把proto文档生成为lib文件
proto_library(
    name = "student_proto",
    srcs = ["student.proto"],
)

#把已经有了的proto 文档编译成cc文档
cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"],
)
```

#### 编译

输入bazel build cyber/demo_protobuf/...既可以编译了

然后就可以看到cc文件了![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220921_150249.png)

### 用c++ 使用刚刚编译的proto文件

#### **main.cc 源代码**

```c++
#include "cyber/demo_protobuf/test_01/student.pb.h"

int main(int argc, char const *argv[])
{
    apollo::cyber::demo_protobuf::Student stu; //声明新的对象

    //添加新的数据
    stu.set_name("yuri"); 
    stu.set_age(18);
    stu.set_height(166);
    stu.add_books("终将成为你，安达与岛村");

    //打印数据

    std::cout << "打印数据 ------- \n";
    std::cout << "name : " << stu.name() << std::endl;
    std::cout << "age : " << stu.age() << std::endl;
    std::cout << "height : " << stu.height() << std::endl;
    auto books = stu.books();
    for(auto begin = books.begin(); begin != books.end();begin++){
        std::cout << " " << *begin;
    }
    std::cout << "\n输出结束\n";
    return 0;
}

```

#### **build 文件**

```cmake
package(default_visibility = ["//visibility:public"]) #使这个包的文件共享

#把proto文档生成为lib文件
proto_library(
    name = "student_proto",
    srcs = ["student.proto"],
)

#把已经有了的proto 文档编译成cc文档
cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"],
)


cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":student_cc"],
)
```

#### 构建执行

输入bazel build ... 编译即可，然后执行就行

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220921_152809.png)

## cyber RT 通信机制

**c/c++实现**

### 话题通信

> 话题通信的目的是实现数据的传输。 一方发布数据，然后一方接受数据。二者是同时进行的。并且是一直进行通信的
>
> 实现过程： 发布方发布数据，接收方接收数据

#### 编写proto 文件（信息载体）

也可以用之前的文件

```protobuf
syntax = "proto2";
package apollo.cyber.demo_protobuf;

message Student {

    required string name = 1; //required -- 必须要的参数
    optional int64 age = 2; //optional -- 可以省略的参数
    optional double height = 3; 
    repeated string books = 4; //repeated -- 可以输入多个数据
}
```

#### 编写talker.cc 文件（发布方）

```c++
#include "cyber/cyber.h"
#include "cyber/demo_protobuf/test_01/student.pb.h"

using apollo::cyber::demo_protobuf::Student;
using namespace apollo;
int main(int argc, char const *argv[])
{
    
    apollo::cyber::Init(argv[0]);
    
    auto talker_node = cyber::CreateNode("ergou"); //创建节点 名称为ergou
    auto talker = talker_node->CreateWriter<Student>("chatter"); //创建监听者， 名称为chatter

    uint64_t sq = 0; //设置计数器

    cyber::Rate rate(0.5); //设置发送频率是每秒0.5次

    while(cyber::OK())
    {
        sq++;
        AINFO << "发送第 " << sq << " 条数据\n"; //提示发送数据

        //写入数据
        auto stu = std::make_shared<Student>();
        stu->set_name("yuri");
        stu->set_age(sq);
        stu->set_height(170);
        stu->add_books("终将成为你!");
        stu->add_books("安达与岛村!");

        talker->Write(stu); //写入数据

        rate.Sleep(); //调用睡眠函数
    }

    cyber::WaitForShutdown(); //设置结束后删除节点

    return 0;
}

```

#### 编写listener.cc 文件 （接收方）

```c++
#include "cyber/demo_protobuf/test_01/student.pb.h"
#include "cyber/cyber.h"

using apollo::cyber::demo_protobuf::Student;

void cp(const std::shared_ptr<Student> &stu)
{
    AINFO << "----- 接收到数据 开始打印数据 -----";
    AINFO << "name : " << stu->name();
    AINFO << "age : " << stu->age();
    for (auto begin = stu->books().begin(); begin != stu->books().end();begin++){
      AINFO << "books : " << *begin;
    }
}

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);

    AINFO << "订阅方法创建";

    auto listener_node = apollo::cyber::CreateNode("curhui"); //创建监听节点
    auto listener = listener_node->CreateReader<Student>("chatter", cp); //接受到数据会调用cp函数，这里的名字需要和talker对应

    apollo::cyber::WaitForShutdown(); //等待程序结束删除节点

    return 0;
}
```

#### 配置build文件

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "talker", #项目名字
    srcs = ["talker.cc"], #项目文件
    deps = [
        "//cyber",
        "//cyber/demo_protobuf/test_01:student_cc"
    ], #固定写法
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "listener",
    srcs = ["listener.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_protobuf/test_01:student_cc"
    ], 
)
```

#### 运行

分开终端分别运行talker和listener程序![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220924_185616.png)

### 服务通信

> 服务通信不同与话题通信他是不是一直进行的。他是当有数据传输的时候进行通信。没有的时候就没有，但是当有数据进入的时候需要立马响应。可以理解为 更换目的地之后，你需要立马处理新的数据。

#### 编写proto文件 

需要两个message 一个用来接收，一个用来发送

```protobuf
syntax = "proto2";

package apollo.cyber.demo_cpp;

//用来发送数据，需要提供连个参数，用来相加
message Request {
    required int32 num_1 = 1;
    required int32 num_2 = 2;
}

//接收数据，只用一个参数，用来存储他们的和就行了
message Response {
    required int64 sum = 1;
}
```



#### 编写server.cc文件 （服务端）

 用来处理数据

```c++
#include "cyber/cyber.h"
#include "cyber/demo_cpp/reques/request.pb.h"

using apollo::cyber::demo_cpp::Request;
using apollo::cyber::demo_cpp::Response;

void cp(const std::shared_ptr<Request> &request, const std::shared_ptr<Response> &response)
{
    //设置数据
    int32_t num_1 = request->num_1();
    int32_t num_2 = request->num_2();

    AINFO << "客户端请求的数据是 : num_1 " << num_1 << " num_2 " << num_2;
    
    //设置需要传送出去的参数
    response->set_sum(num_1 + num_2); //设置sum的数数据
}

int main(int argc, char const *argv[])
{
  apollo::cyber::Init(argv[0]);

  AINFO << "服务端程序启动";

  auto server_node = apollo::cyber::CreateNode("addints");
  auto server = server_node->CreateService<Request, Response>("addints",cp); //设置接收到数据时的处理函数

  apollo::cyber::WaitForShutdown();

  return 0;
}

```

#### 编写client.cc 文件（客户端）

用来发送数据

```c++
#include "cyber/cyber.h"
#include "cyber/demo_cpp/reques/request.pb.h"

using apollo::cyber::demo_cpp::Request;
using apollo::cyber::demo_cpp::Response;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "客户端启动捏";

    auto client_node = apollo::cyber::CreateNode("client"); //建立通信节点
    auto client = client_n新建demo_protobuf 文件夹

在文件夹里面新建student.proto 文件ode->CreateClient<Request,Response>("addints"); //设置客户机

    //防止出现没有参数的情况
    if(argc != 3)
    {
        AINFO << "请输入三个参数";
        return 1;
    }

    //新建接收数据对象
    auto request = std::make_shared<Request>();
    request->set_num_1(atoll(argv[1]));
    request->set_num_2(atoll(argv[2]));

    AINFO << "发送数据 num_1 " << request->num_1() << " num_2 "
            << request->num_2();
            
    auto response = client->SendRequest(request); //发送数据，并且把返回的数据赋值给response
    AINFO << "处理结果为 : " << response->sum(); //打印数据

    apollo::cyber::WaitForShutdown();

    return 0;
}
```



#### 编写build 文件

```cmake
package(default_visibility = ["//visibility:public"])

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
proto_library(
    name = "request_proto",
    srcs = ["request.proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_proto_library(
    name = "request_cc",
    deps = [":request_proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_cpp/reques:request_cc"
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_cpp/reques:request_cc"
    ],
)
```

#### 运行

携带参数运行数据![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220924_202105.png)

### 参数

用于共享一些数据，比如车身的最大速度， 长度宽度之类的。最大的特点 ：  共享

#### 编写server端 （服务端）

```c++
#include "cyber/cyber.h"
#include "cyber/parameter/parameter.h"
#include "cyber/parameter/parameter_server.h"

using apollo::cyber::ParameterServer;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "服务端启动\n";

    std::shared_ptr<apollo::cyber::Node> server_node = apollo::cyber::CreateNode("param"); //创建节点
    std::shared_ptr<ParameterServer> server = std::make_shared<ParameterServer>(server_node); //创建话题

    //设置参数
    server->SetParameter(Parameter("age", 18));
    server->SetParameter(Parameter("yuri", "yes"));
	
    //打印参数
    Parameter *parame_1 = new Parameter;
    server->GetParameter("age", parame_1);
    AINFO << parame_1->Name() << " age is " << parame_1->AsInt64() << std::endl;
    server->GetParameter("yuri", parame_1);
    AINFO << parame_1->Name() << " yuri is " << parame_1->AsString() << std::endl;

    AINFO << "获取所有参数 ----- \n";
    std::vector<Parameter> parameter;
    server->ListParameters(&parameter);
    for (auto begin = parameter.begin(); begin != parameter.end();begin++)
    {
        AINFO << "打印 name :" << begin->Name() << "type name : " << begin->TypeName() << std::endl;
        AINFO << "打印所有参数 " << begin->DebugString(); //以字符串形式打印所有参数
    }

    apollo::cyber::WaitForShutdown();
    delete parame_1;
    return 0;
}

```

#### 编写 client端 （客户端）

```c++
#include "cyber/cyber.h"
#include "cyber/parameter/parameter.h"
#include "cyber/parameter/parameter_client.h"

using apollo::cyber::ParameterClient;
using apollo::cyber::Parameter;

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "服务方式启动\n";

    std::shared_ptr<apollo::cyber::Node> client_node = apollo::cyber::CreateNode("param_client"); //创建节点
    std::shared_ptr<ParameterClient> client = std::make_shared<ParameterClient>(client_node,"param"); //创建话题


    Parameter *parame_1 = new Parameter;
    client->GetParameter("age", parame_1); //添加数据
    AINFO << parame_1->Name() << " age is " << parame_1->AsInt64() << std::endl; //打印数据
    client->GetParameter("yuri", parame_1);
    AINFO << parame_1->Name() << " yuri is " << parame_1->AsString() << std::endl;

    AINFO << "获取所有参数 ----- \n";
    std::vector<Parameter> parameter;
    client->ListParameters(&parameter);
    for (auto begin = parameter.begin(); begin != parameter.end();begin++)
    {
      AINFO << "打印 name :" << begin->Name()
            << "type name : " << begin->TypeName() << std::endl;
    }

    apollo::cyber::WaitForShutdown();
    delete parame_1;
    return 0;
}
```

#### build 文件

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "para_server",
    srcs = ["para_server.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter"
    ],
)

cc_binary(
    name = "para_client",
    srcs = ["para_client.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter"
    ],
)
```

#### 运行![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20220928_154835.png)



### 组件( 一 )

> 组件是apollo 非常重要的一部分，他可以处理来自不同部件发送的数据。然后重新整合 发送
>
> 简单来说就是 处理接收的数据，然后进行过滤 计算，然后重新发送出去

1. 编写components 类，继承components 
2. 重写Proc 和 init 函数
3. 编写dag和lunach 文件
4. 编写build 文件
5. 他最多支持 4 消息通道

#### proto文件编写

```protobuf
syntax = "proto2";

package apollo.cyber.demo_cpp;

message Student {
    required string name = 1;
    required int64 age = 2;
    repeated string loves = 3;
}
```

#### 编写talker文件（发布方）

```c++
#include "cyber/cyber.h"
#include "cyber/demo_cpp/components/Student.pb.h"

using apollo::cyber::demo_cpp::Student;
using namespace apollo;
int main(int argc, char const *argv[])
{
    
    apollo::cyber::Init(argv[0]);
    
    auto talker_node = cyber::CreateNode("ergou"); //创建节点 名称为ergou
    auto talker = talker_node->CreateWriter<Student>("chatter"); //创建监听者， 名称为chatter

    uint64_t sq = 0; //设置计数器

    cyber::Rate rate(0.5); //设置发送频率是每秒0.5次

    while(cyber::OK())
    {
        sq++;
        AINFO << "发送第 " << sq << " 条数据\n"; //提示发送数据

        //写入数据
        auto stu = std::make_shared<Student>();
        stu->set_name("yuri");
        stu->set_age(sq);
        stu->add_loves("终将成为你");
        stu->add_loves("安达与岛村");


        talker->Write(stu); //写入数据

        rate.Sleep(); //调用睡眠函数
    }

    cyber::WaitForShutdown(); //设置结束后删除节点

    return 0;
}

```



#### **类头文件编写**

```c++
#ifndef MY_COMPONENTS
#define MY_COMPONENTS

#include "cyber/cyber.h"
#include "cyber/component/component.h"
#include "cyber/demo_cpp/components/Student.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_cpp::Student;

//继承需要添加数据模板
class my_components : public Component<Student> 
{
private:
    /* data */
public:

    bool Init() override; //表示重写函数，初始化函数
    bool Proc(const std::shared_ptr<Student> &stu) override; //数据数据函数
    
};

CYBER_REGISTER_COMPONENT(my_components) //注册组件
#endif
```

#### **cpp函数编写**

```c++
#include "my_components.h"

bool my_components::Init() {
	AINFO << "------------ 初始化中 ------------";
	return true;
}

bool my_components::Proc(const std::shared_ptr<Student>& stu)
{
	AINFO << "数据输出!";
	AINFO << "name : " << stu->name();
	AINFO << "age : " << stu->age();
	for (auto begin = stu->loves().begin(); begin != stu->loves().end(); begin++) {
		AINFO << "loves " << *begin;
	}
	return true;
}

```

#### **launch 文件编写**

```xml
<cyber> 
    <module>
        <name> my moudle</name> <!--模块名字-->
        <dag_conf>/apollo/cyber/demo_cpp/components/cpt.dag</dag_conf> <!-- dag 目录位置-->
        <process_name> my_cpt </process_name>
    </module>
</cyber>
```

#### dag 文件编写

```bash
module_config {

    module_library : "/apollo/bazel-bin/cyber/demo_cpp/components/my_components.so"

    components {

        class_name : "my_components"

        config {
            name : "my_components"
            readers {
                channel : "chatter" 
            }
        }
    }
}
```

#### build 文件编写

```bash

load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
proto_library(
    name = "Student_proto",
    srcs = ["Student.proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_proto_library(
    name = "Student_proto_cc",
    deps = [":Student_proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "my_components_lib",
    srcs = ["my_components.cc"],
    hdrs = ["my_components.h"],
    deps = [
        "//cyber",
        "//cyber/component",
        "//cyber/demo_cpp/components:Student_proto_cc"
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "my_components.so",
    linkshared = True, 
    linkstatic = False,
    deps = [":my_components_lib"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "talker",
    srcs = ["talker.cc"],
    deps = [
        "//cyber",
        ":Student_proto_cc"
    ],
)

filegroup(
    name = "conf",
    srcs = [
        ":cpt.dag",
        ":cpt.launch",
    ],
)

install (
    name = "install",
    data = [
        ":conf",
    ],

    runtime_dest = "cyber/demo_cpp/components",
    targets = [
        ":talker",
        ":my_components.so",
    ],
)
```



#### 运行

1. 使用  `mainboard -d cyber/demo_cpp/components/cpt.dag `运行 dag文件
2. 使用 `cyber_launch start cyber/demo_cpp/components/cpt.launch` 运行 launch 文件
3. 上面随便选一种方式运行就行，然后运行talker 文件就行了。 打开终端就可以看到效果了
4. 如果使用cyber_launch start运行，除了Ctrl c 还可以使用 cyber_launch  stop 命令结合

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221004_194439.png)



### 组件 （二）

> 本次需要实现 两个数据的检测，所以需要两个数据发布方
>
> 这次需要接受双通道的消息，所以需要同步更改dag文件
>
> 到这里，信息就不止一个了，不同的信息有不同的发送频率。比如，talker 1 每两秒发送一次数据，talker 2每 1秒发送一次数据，这里组件会以频率较慢的一个为基础，并且同时获取发送过来的频率较快的那个的数据，并且舍弃掉之前的数据。

#### **编写 proto文件 **

```protobuf
syntax = "proto2";

package apollo.cyber.demo_cpp;

message Radar {
    required string name  = 1;
    required int64 age  = 2;
    optional int64  length  = 3;
}
```

#### 编写两个talker 文件（发布方）

1、前发布者

```c++
#include "cyber/cyber.h"
#include "cyber/demo_cpp/components_2/radar.pb.h"

using apollo::cyber::demo_cpp::Radar;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
	AINFO << "前雷达检测系统初始化成功!!!";
	auto talker_front_node = apollo::cyber::CreateNode("talker_front_node");
	auto talker_front = talker_front_node->CreateWriter<Radar>("front_radar");

	uint64_t sq = 0;

	apollo::cyber::Rate rate(0.25);

	while (apollo::cyber::OK())
	{
		AINFO << "前雷达发送第 " << sq << "条信息";
		std::shared_ptr<Radar> radar = std::make_shared<Radar>();

		radar->set_age(sq);
		radar->set_name("yuri_front");
		radar->set_length(666);

		talker_front->Write(radar);

		sq++;

		rate.Sleep();
	}

	apollo::cyber::WaitForShutdown();

	return 0;
}

```

2、后发布者

```c++
#include "cyber/cyber.h"
#include "cyber/demo_cpp/components_2/radar.pb.h"

using apollo::cyber::demo_cpp::Radar;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
	AINFO << "后雷达检测系统初始化成功!!!";
	auto talker_back_node = apollo::cyber::CreateNode("talker_back_node");
	auto talker_back = talker_back_node->CreateWriter<Radar>("back_radar");

	uint64_t sq = 0;

	apollo::cyber::Rate rate(0.5);

	while (apollo::cyber::OK())
	{
		AINFO << "后面雷达发送第 " << sq << "条信息";
		std::shared_ptr<Radar> radar = std::make_shared<Radar>();

		radar->set_age(sq);
		radar->set_name("yuri_back");
		radar->set_length(666);

		talker_back->Write(radar);

		sq++;

		rate.Sleep();
	}

	apollo::cyber::WaitForShutdown();

	return 0;
}

```



#### 编写类头文件

```c++
#ifndef MY_COMPONENTS_2_H
#define MY_COMPONENTS_2_H

#include "cyber/component/component.h"

#include "cyber/demo_cpp/components_2/radar.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_cpp::Radar;

class My_components_2 : public Component<Radar, Radar> //有两个消息，所有需要两个消息载体
{
private:
	std::shared_ptr<apollo::cyber::Writer<Radar>> writer; //申明一个writer对象，用于发布新的数据
	uint64_t sq = 0; //用来计数，统计执行的次数

public:
	bool Init() override; 
	bool Proc(const std::shared_ptr<Radar>& front,const std::shared_ptr<Radar>& back) override; 
};

CYBER_REGISTER_COMPONENT(My_components_2) //注册组件

#endif
```

#### 编写cc文件

```c++
#include "cyber/demo_cpp/components_2/my_components_2.h"

bool My_components_2::Init()
{
    AINFO << "组件初始化成功";
	this->writer = this->node_->CreateWriter<Radar>("my_components_2"); //初始化时，新建一个writer话题，用于后续写入东西
	return true;
}

bool My_components_2::Proc(const std::shared_ptr<Radar> &front, const std::shared_ptr<Radar> &back)
{
	AINFO << "信息接受成功！正在处理数据";
	std::shared_ptr<Radar> radar = std::make_shared<Radar>();
	radar->set_age(front->age() + back->age());
	radar->set_name("front + back");
	radar->set_length(front->length() + back->length());

	this->writer->Write(radar); //每次执行，写入新的东西 

	AINFO << "处理完毕！ 这是第 " << this->sq++ << " 条数据";

	return true;
}
```

#### 编写dag 文件

```bash
module_config {

    module_library : "/apollo/bazel-bin/cyber/demo_cpp/components_2/my_components_2.so"

    components {

        class_name : "My_components_2" 

        config {
            name : "My_components_2"
            readers {
                channel : "front_radar" 
            }
            readers {
                channel : "back_radar" 
            }
        }
    }
}
```

#### 编写launch 文件

```xml
<cyber> 
    <module>
        <name> my moudle</name> <!--模块名字-->
        <dag_conf>/apollo/cyber/demo_cpp/components/cpt.dag</dag_conf> <!-- dag 目录位置-->
        <process_name> my_cpt </process_name>
    </module>
</cyber>
```

#### 执行

仍然可以输入两个命令进行执行。并且可以使用  cyber_channel list 命令查看当前有多少话题

然后输入cyber_channel echo 话题名字，查看话题内容

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221005_120723.png)

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221005_120703.png)



### 组件（三）

> 定时器组件
>
> 用于每秒钟执行proc 函数，和前面组件的使用大同小异

#### 编写头文件

```c++
#ifndef TIMECOMPONENT_H
#define TIMECOMPONENT_H


#include "cyber/component/timer_component.h"
#include "cyber/cyber.h"

using apollo::cyber::TimerComponent;

class My_TimeComponent: public TimerComponent
{
private:
	uint64_t sq;

public:
	bool Init() override;
	bool Proc() override;
};

CYBER_REGISTER_COMPONENT(My_TimeComponent)
#endif
```

#### 编写具体实现

```c++
#include "cyber/demo_cpp/timeComponent/timeComponent.h"

bool My_TimeComponent::Init()
{
    AINFO << "定时器组件初始化成功!";
	this->sq = 0;
	return true;
}

bool My_TimeComponent::Proc()
{
	sq++;
	AINFO << "处理数据中" << sq;
	return true;
}
```

#### 编写launch文件

```
<cyber> 
    <module>
        <name> my moudle</name> <!--模块名字-->
        <dag_conf>/apollo/cyber/demo_cpp/timeComponent/cpt.dag</dag_conf> <!-- dag 目录位置-->
        <process_name> my_cpt </process_name>
    </module>
</cyber>
```

#### 编写dag文件

interval 表示每秒钟执行多少次proc函数

```bash
module_config {

    module_library : "/apollo/bazel-bin/cyber/demo_cpp/timeComponent/timeComponent.so"

    timer_components {

        class_name : "My_TimeComponent"

        config {
            name : "timeComponent"
            interval : 10
        }
    }
}
```

#### 编写build文件

```bash
load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "timeComponent_lib",
    srcs = ["timeComponent.cc"],
    hdrs = ["timeComponent.h"],
    deps = ["//cyber"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "timeComponent.so",
    linkshared = True,
    linkstatic = False,
    deps = [":timeComponent_lib"],
)

filegroup(
    name = "conf",
    srcs = [
        ":cpt.dag",
        ":cpt.launch",
    ],
)

install (
    name = "install",
    data = [
        ":conf",
    ],

    runtime_dest = "cyber/demo_cpp/timeComponent",
    targets = [
        ":timeComponent.so",
    ],
)
```

#### 执行

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221005_192251.png)

### 开发工具CyberRecord 

> 介绍： 用工具提高开发效率
>
> CyberRecord 用来持久化存储数据，不用一直放在内存当中。可以将他写入到磁盘文件中
>
> 学完之后我们就可以对数据进行 延迟、反复使用，也可以对数据进行二次处理

#### 编写wirter文件

这里的proto文件我选择用前面的，也可以用自己重新生成的

```c++
#include "cyber/cyber.h"
#include "cyber/demo_protobuf/test_01/student.pb.h"
#include "cyber/record/record_writer.h"

using apollo::cyber::demo_protobuf::Student;
using apollo::cyber::record::RecordWriter;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
	AINFO << "写信息初始化成功!";

	RecordWriter record_wiriter;
	//设置每个文件达到多少kb后新建另外一个文件
	record_wiriter.SetSizeOfFileSegmentation(0);
	//设置每到多少秒钟之后新建另外一个文件
	record_wiriter.SetIntervalOfFileSegmentation(0); 
	//需要写入的文件，文件必须不存在，否则保存捏
	record_wiriter.Open("/apollo/cyber/demo_cpp/tools/mytest.record"); 
	//获得文件名字
	AINFO << "file : " << record_wiriter.GetFile(); 

	//新建话题名称是record
	std::string channel = "record"; 
	//第一个是发布话题的名字，第二个是数据类型，第三个参数是消息描述
	record_wiriter.WriteChannel(channel, "apollo.cyber.demo_protobuf.Student","test for record");

    for (size_t i = 0; i < 20; i++)
    {
		//先给消息添加内容
		auto stu = std::make_shared<Student>();
		stu->set_age(18);
		stu->set_name("yuri");
		stu->set_height(i);
		stu->add_books("yuri");
		stu->add_books("终将成为你!");
		stu->add_books("安达与岛村！");

		std::string contant;
		//将消息转化成字符串存进去
		stu->SerializeToString(&contant);
		//写入文件内容，写入序号，以及写入话题
		record_wiriter.WriteMessage(channel,*stu,i);
	}

	//关闭文件
	record_wiriter.Close();

	return 0;
}

```

#### 编写reader文件

```c++
#include "cyber/record/record_reader.h"
#include "cyber/record/record_message.h"
#include "cyber/cyber.h"

using apollo::cyber::record::RecordMessage;
using apollo::cyber::record::RecordReader;

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]);
    AINFO << "初始化成功！ 正在读取文件---";

	//建立reader需要添加读取的文件目录
	RecordReader record_reader("/apollo/cyber/demo_cpp/tools/mytest.record");

	//设置话题
	std::string channel = "record";

	//读取文件中对应话题的内容
	size_t msg_number =  record_reader.GetMessageNumber(channel); //消息条数
	std::string msg_type =  record_reader.GetMessageType(channel); //消息类型
	std::string msg_desc = record_reader.GetProtoDesc(channel); //消息描述

	AINFO << "信息获取成功!";
	AINFO << "总共获取到了 " << msg_number << " 条信息!";
	AINFO << "信息类型 : " << msg_type;
	AINFO << "信息描述 : " << msg_desc;

	//创建整合读取消息的对象
	RecordMessage recore_message;
    for (size_t i = 0; i < msg_number; i++)
    {   
		//读取消息，并且存放起来
		if(record_reader.ReadMessage(&recore_message))
        {
			AINFO << "第 " << i << " 条信息！  "
			      << "  hannel_name : " << recore_message.channel_name //话题名字
			      << "  contant : " << recore_message.content //具体存入的消息内容
                  << "  time :" << recore_message.time; //写入消息时的序号
        }else{
			AINFO << "获取信息失败!";
		}
	}

	return 0;
}

```

#### 编写build文件

```cmake
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "record_writer",
    srcs = ["record_writer.cc"],
    deps = [
        "//cyber/demo_protobuf/test_01:student_cc",
        "//cyber"
    ],
)

cc_binary(
    name = "record_reader",
    srcs = ["record_reader.cc"],
    deps = [
        "//cyber"
    ],
)
```

#### 执行

先执行writer文件写入文件，然后再执行reader文件读取文件内容

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221006_203356.png)

## cyber RT 常用命令

> 应用场景： 提高我们的开发效率。检测节点是否运行正常。判断节点信息发送频率是否符合预期。
>
> 可以使用命令cyber_pp  -h(help) 或者 cyber_pp 命令 -h

```
roleid           5214286195303063771 角色ID
hostname         in-dev-docker 主机
processid        44769 进程号
nodename         ergou 节点名字
msgtype          apollo.cyber.demo_protobuf.Student 发送信息的类型
```



#### cyber_node

> 查询关于节点相关的信息

```
cyber_node list 查看所有节点
cyber_node info ergou 查看ergou的详细信息
cyber_node info -a 查看所有节点信息
```

![](https://cdn.jsdelivr.net/gh/yuri2078/images/apollo/20221007_135438.png)

#### cyber_channel

> 查询关于话题相关的信息

```
cyber_channel list      显示所有正在运行的话题
cyber_channel info      显示某个话题的具体信息
cyber_channel echo      将话题的信息打印到屏幕上
cyber_channel hz        显示话题信息发布的频率
cyber_channel bw        显示话题信息发布的带宽
cyber_channel type      显示话题信息类型
```

#### cyber_service

> 查询关于服务相关的信息

```
cyber_service list      列出所有正在运行的服务
cyber_service info      打印相关服务的信息
```



#### cyber_launch

> 关于launch文件相关的信息

```
cyber_launch start ...launch 启动launch文件
cyber_launch stop  ...launch 关闭launch文件
```



#### cyber_monitor

> 综合类的信息。更灵活的小时话题的相关信息

```
cyber_monitor 直接进去 按 q或者 esc 退出 ---- 默认显示所有话题的发布数据的频率
Option:
   -h print help info
   -c 指定一个话题
   q | Q | Esc -- 退出
   Backspace -- 返回上一步
   h | H -- 输出提示信息

Common Commands for Topology and Channel Message:
   PgDn | d -- 下一页
   PgUp | u -- 上一页

   Up Arrow -- move up one line
   Down Arrow -- move down one line
   Right Arrow -- enter the selected Channel or Repeated Datum
   Left Arrow -- go back to the upper level

   Enter -- 进入指定话题信息显示
   a | A -- the same with Left Arrow key
   d | D -- the same with Right Arrow key
   w | W -- the same with Up Arrow key
   s | S -- the same with Down Arrow key

Commands for Topology message: 消息显示相关问题
   f | F -- 显示消息发布帧率
   t | T --	显示消息发布类型

   Space -- 关闭或打开消息

Commands for Channel:
   i | I -- 显示话题读写相关信息
   b | B -- 显示消息内容

Commands for Channel Repeated Datum:
   n | N -- 重复字段下一个元素 比如多个books
   m | M -- 重复字段上一个元素
   , -- enable|disable to show all repeated items
```



#### cyber_record

> 实现消息的录制和重放

```
info    显示一个已经存在的Record 的文件的信息
play    回放一个Record文件 play -f 文件 回放文件
record  录制一个Record文件 record -a -o 文件 录制为文件
split   分割一个Record文件
recover 复制Record文件 recover -f 文件 -o 文件2 复制文件1命名为文件2

record_file:    cyber/demo_cpp/tools/mytest.record
version:        1.0 版本号
duration:       0.000000 Seconds 录制时间
begin_time:     1970-01-01-08:00:00 开始时间
end_time:       1970-01-01-08:00:00
size:           3802 Bytes (3.712891 KB) 录制大小
is_complete:    true 是否已经结束
message_number: 20 录制的消息个数
channel_number: 1 话题个数
channel_info:   
                record     话题名称                                             20 messages: apollo.cyber.demo_protobuf.Student 消息类型


```

### 常用api

常用api上面都有介绍，下面介绍不怎么用的

api查询链接 ：  [apolloCyberRT](https://cyber-rt.readthedocs.io/en/latest/CyberRT_API_for_Developers.html#timer)

#### time 时间api

```c++
#include "cyber/cyber.h"

using apollo::cyber::Time;

int main(int argc, char const *argv[])
{
	Time t_1; //默认构造函数，获取默认时间 1970.1.1.8：00：000
	Time t_2(6666); //整形构造函数，获取默认时间加上 6666ns
	Time t_3(120.0); //double构造函数，获取默认时间加上 120s

	AINFO << "t_1 : " << t_1;
	AINFO << "t_2 : " << t_2;
	AINFO << "t_3 : " << t_3;
	AINFO << "t_2(s) : " << t_2.ToSecond(); //转换成秒
	AINFO << "t_2(ns) : " << t_2.ToNanosecond(); //转换成纳秒
	AINFO << "t_2(ms) : " << t_2.ToMicrosecond(); //转换成微秒
	AINFO << "t_3(s) : " << t_3.ToSecond();

	//获取最大或者最小时间
	//默认添加的是ns 而ns是long long 类型，所有默认最大值是 2^64 - 1

	AINFO << "max time (s) " << Time::MAX.ToSecond(); //最大时间
	AINFO << "min time (s) " << Time::MIN.ToSecond(); //最小时间
	AINFO << "t_1 is zeor ? " << t_1.IsZero(); //判断是不是0
	AINFO << "t_2 is zeor ? " << t_2.IsZero(); //只有当时间为默认时间时，才会是0


	AINFO << "现在时间 : " << Time::Now(); //返回现在时间
	Time::SleepUntil(Time(Time::Now().ToSecond() + 10));  //休眠 直到 --- 设置的时间
	AINFO << "现在时间 : " << Time::Now();

	AINFO << "系统已经运行了 : " << Time::MonoTime().ToSecond(); //返回系统开机运行的时间，这里返回docker容器启动的时间

	return 0;
}

```

#### duration 持续时间api

```c++
#include "cyber/cyber.h"
#include "cyber/time/duration.h"

using apollo::cyber::Duration;
using apollo::cyber::Time;

int main(int argc, char const *argv[])
{
	Duration d_1(5.0); //创建5s的持续时间
    //别的东西基本和time 相同
	Time t_1(10.0);
	Time t_2(5.0);

	Duration d_2(5 + 1000); //创建5s 加上 1000ns 的持续时间

	AINFO << "d_1 time : " << d_1;
	AINFO << "d_2 time : " << d_2;
	AINFO << "t_1 time : " << t_1;
	AINFO << "d_2 time : " << t_2;

	AINFO << "现在时间是： " << Time::Now();
	d_1.Sleep(); //休眠5s
	AINFO << "现在时间是： " << Time::Now();

	AINFO << "t_1(10.0) + d_1(5.0) : " << t_1 + d_1;  //结果就是10 - 5 
	AINFO << "t_1(10.0) - d_1(5.0) : " << t_1 - d_1;
	AINFO << " d_1 == d_2 ? " << (d_1 == d_2);

	return 0;
}
```

#### rate 休眠api

```c++
#include "cyber/cyber.h"
#include "cyber/time/rate.h"

using apollo::cyber::Rate;

int main(int argc, char const *argv[])
{
	Rate r_1(2.0); //使用double类型会将发布频率设置为 2.0，也就是休眠时间 1/2.0 也就是0.5s
	Rate r_2((uint64_t)1000000000); //直接设置休眠时间为多少ns
	apollo::cyber::Duration d_1(5.0);
	Rate r_3(d_1); //直接设置持续时间

	AINFO << "r_1 休眠前时间 " << apollo::cyber::Time::Now();
	r_1.Sleep(); //启动休眠
	AINFO << "r_1 休眠后时间 " << apollo::cyber::Time::Now();
	AINFO << "";
	AINFO << "r_2 休眠前时间 " << apollo::cyber::Time::Now();
	r_2.Sleep();
	AINFO << "r_2 休眠后时间 " << apollo::cyber::Time::Now();
	AINFO << "";
	AINFO << "r_3 休眠前时间 " << apollo::cyber::Time::Now();
	r_3.Sleep();
	AINFO << "r_3 休眠后时间 " << apollo::cyber::Time::Now();
	return 0;
}
```

#### timer 定时api

```c++
#include "cyber/cyber.h"
#include "cyber/timer/timer.h"

using apollo::cyber::Timer;
int i = 0;

void cp(){
    AINFO << "定时器执行中!  " << ++i;
}

int main(int argc, char const *argv[])
{
	Timer t_1(1000,cp,false);
    //参数 1 设置循环频率 1000就是1000ms 执行1次
    //参数 cp 就是设置循环逻辑
    //参数 3 是否只执行1次

	t_1.Start(); //开启定时器

	sleep(3); //先休眠3s

	t_1.Stop();

	AINFO << "函数停止!";
	return 0;
}
```

#### log 日志api

```c++
#include "cyber/cyber.h"

int main(int argc, char const *argv[])
{
	apollo::cyber::Init(argv[0]); //初始化日志文件， 默认参数用于文件名，argv0 是文件名

	AINFO << "AINFO 一般信息";
	ADEBUG << "ADEBUG 调试信息"; //仅仅在调试模式输出
	AWARN << "AWARN 警告信息";
	AFATAL << "AFATAL 严重警告信息";
	return 0;
}

```

**cyber/setup.bash** 日志文件设置

```bash
export GLOG_log_dir="${APOLLO_ROOT_DIR}/data/log" #设置日志目录
export GLOG_alsologtostderr=1  #设置是否在终端中显示
export GLOG_colorlogtostderr=1 #设置不同级别信息是否用不同颜色打印
export GLOG_minloglevel=0 #设置打印哪种级别日志，参数0-3 0：全部，1 ： 一般以上 2： 只打印warn和fatal 3:只打印fatal
```



### cyber 下的函数

包含在apollo::cyber命名空间下

#### CreateNode 函数

 ```c++
 //函数原型 : 
 std::unique_ptr<Node> CreateNode(const std::string& node_name,const std::string& name_space = "")
 //一般使用
 auto talker_node = cyber::CreateNode("ergou"); 
 ```

### Node 下函数

```c++
auto talker = talker_node->CreateWriter<Student>("chatter");  //创建发布者
auto listener = listener_node->CreateReader<Student>("chatter", cp);  //创建监听者
//当监听到 chatter发送东西的时候，调用cp函数进行处理，cp函数需要传入 数据
auto client = client_node->CreateClient<Request,Response>("addints"); //设置客户机
auto server = server_node->CreateService<Request, Response>("addints",cp); //设置接收到数据时的处理函数
std::shared_ptr<ParameterServer> server = std::make_shared<ParameterServer>(server_node); //创建服务端
std::shared_ptr<ParameterClient> client = std::make_shared<ParameterClient>(client_node,"param"); //创建客户端，需要传入服务端节点号
```

###    
