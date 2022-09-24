# apollo Cyber c++ 实现

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

1. 在vscode中打开docker容器 选择 attach visual studio code![](/home/yuri/yuri/markdown/apollo 学习/20220918_132150.png)

2. 在新的vscode中打开容器 选择打开文件夹 选择apollo 目录就行了![](/home/yuri/yuri/markdown/apollo 学习/20220918_132655.png)

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

   ![](/home/yuri/yuri/markdown/apollo 学习/20220918_133854.png)

   ```basic
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
   cc_binary(
       name = "helloworld", #项目名字
       srcs = ["helloworld.cc"], #项目文件
       deps = ["//cyber"], #固定写法
   )
   ```

### 开始构建项目

1. 终端运行 `bazel build cyber/demo_cpp/...` 构建项目下所有文件，终端出现以下内容就是成功![](/home/yuri/yuri/markdown/apollo 学习/20220918_134900.png)

2. 修改cyber /setup.bash 文件  ---- `export GLOG_alsologtostderr=1  #把这里改成 1 原来是0` 大概35行左右

   ![](/home/yuri/yuri/markdown/apollo 学习/20220918_135251.png)

3. 查看bazel-bin/cyber/文件夹下面是不是有一个demo_cpp文件夹，里面有一个hellowrold文件 直接执行就行了

4. 输入`source cyber/setup.bash `命令 令配置立即生效

5. 输入`./bazel-bin/cyber/demo_cpp/helloworld `执行程序 终端输出如图就是成功![](/home/yuri/yuri/markdown/apollo 学习/20220918_135958.png)

   

## bazel 的基本使用

1. 在cyber文件夹下新建demo_base_bazel文件夹

2. 在demo_base_bazel文件夹下 新建 pro1_helloworld 文件夹 用来存放项目

3. 在pro1_helloworld文件夹下 新建WORKSPACE文件标识这是一个bazel项目

4. 在pro1_helloworld 新建 demo_pkt 文件夹存放文件

5. 在demo_pkt文件夹下新建 cpp文件 比如简单打印hello bazel

6. 新建BUILD 文件 输入cc 补全

7. ```cmake
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
   cc_binary(
       name = "hello",
       srcs = ["hello.cc"],
   )
   ```

8. 文件基本目录![](/home/yuri/yuri/markdown/apollo 学习/20220920_183831.png)

9. 新建终端 cd 进 pro1_helloworld 工程目录就行

10. 输入 `bazel build demo_pkt/...`然后编译成功会生成一些文件夹

11. ![](/home/yuri/yuri/markdown/apollo 学习/20220920_184524.png)

12. ![](/home/yuri/yuri/markdown/apollo 学习/20220920_184533.png)

13. 然后进入bazel-bin/demo_pkt/目录运行 hello就行了![](/home/yuri/yuri/markdown/apollo 学习/20220920_184908.png)

### bazel 其余编译方法补全

1. `bazel run demo_pkt:hello`编译并运行 build文件中hello项目
2. `bazel build demo_pkt:hello`只编译 hello
2. 建立WORKSPACE文件的目录为工程根目录

## bazel 实现库依赖

### 实现库的同包依赖

新建demo_lib 文件夹然后新建WORKSPACE 表明根目录 并在里面新建 lib_hello 文件夹，所有文件都在下面

1. 编写头文件get_name.h

   ```c
   #ifndef GET_NAME
   #define GET_NAME
   
   #include <string>
   #include <iostream>
   
   std::string get_name(const std::string &name);
   
   #endif
   ```

2. 编写具体实现代码 get_name.cc

   ```c++
   #include "get_name.h"
   
   std::string get_name(const std::string &name){
      return "hello " + name;
   }
   ```

4. 新建BUILD文件 输入cc 补全 libnary
	```cmake
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
   cc_library(
       name = "getName", #
       srcs = ["get_name.cc"], #具体实现文件
       hdrs = ["get_name.h"], #头文件
   )
   ```

5. cd 进lib_hello 文件夹输入`bazel build ...` 编译库文件

5. 新建helloworld源代码

   ```c++
   #include "get_name.h"
   
   int main(int argc, char const *argv[])
   {
       std::cout << get_name("yuri is yes!") << std::endl;
       return 0;
   }
   ```

6. 更改build文件

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

   

7. 输入 `bazel run :hello_world` 看到输出就是成功

###   实现库的跨包依赖

1. 更目录新建文件夹 用来存放别的文件

2. 新建hello.cc文件

   ```c++
   #include "lib_hello/get_name.h" //必须包含lib目录下的头文件，不能直接包含.h
   
   int main(int argc, char const *argv[])
   {
       std::cout << get_name("yuri is very yes!") << std::endl;
       return 0;
   }
   
   ```

   

3. 新建build文件

   ```cmake
   # https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
   cc_binary(
       name = "hello",
       srcs = ["hello.cc"],
       deps = ["//lib_hello:get_name_lib"], #添加lib_hello文件夹下面build文件夹中的get_name_lib 文件
   )
   ```

   

4. 实现不同包的引用

   1. 被调用的包的build文件添加生声明`package(default_visibility = ["//visibility:public"])`

      表明这个包被所有的包共享

   2. 在被调用的包里添加指定调用包`*visibility* = ["//other_lib:__pkg__"] ` 指定根目录下的文件夹

5. 文件基本目录结构![](/home/yuri/yuri/markdown/apollo 学习/20220920_203052.png)

6. cd 进 目录进行build就行了

## protobuf 的基本使用方式 -- 使用protobuf进行c++ 开发

**protocol buffers （ProtoBuf）是一种语言无关、平台无关、可扩展的序列化结构数据的方法，它可用于（数据）通信协议、数据存储等。**

**Protocol Buffers 是一种灵活，高效，自动化机制的结构数据序列化方法－可类比 XML，但是比 XML 更小（3 ~ 10倍）、更快（20 ~ 100倍）、更为简单。**

**json\xml都是基于文本格式，protobuf是二进制格式。**

### 编写proto并且编译

1. 新建demo_protobuf 文件夹

2. 在文件夹里面新建student.proto 文件

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

3. 编写build文件

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

4. 输入bazel build cyber/demo_protobuf/...既可以编译了

5. 然后就可以看到cc文件了![](/home/yuri/yuri/markdown/apollo 学习/20220921_150249.png)

### 用c++ 使用刚刚编译的proto文件

**main.cc 源代码**

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

**build 文件**

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

输入bazel build ... 编译即可，然后执行就行

![](/home/yuri/yuri/markdown/apollo 学习/20220921_152809.png)

## cyber RT 通信机制

**c/c++实现**

### 话题通信

1. 编写proto 文件也可以用之前的文件

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

2. 编写talker.cc 文件

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

3. 编写listener.cc 文件

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

4. 配置build文件

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

5. 分开终端分别运行talker和listener程序![](/home/yuri/Pictures/截图/20220924_185616.png)

### 服务通信

1. 编写proto文件 需要两个message 一个用来接收，一个用来发送

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

   

2. 编写server.cc 用来处理数据

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

3. 编写client.cc 用来发送数据

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
       auto client = client_node->CreateClient<Request,Response>("addints"); //设置客户机
   
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

   

4. 编写build 文件

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

5. 携带参数运行数据![](/home/yuri/Pictures/截图/20220924_202105.png)
