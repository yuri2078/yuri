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

