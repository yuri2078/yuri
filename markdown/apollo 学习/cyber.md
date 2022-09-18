# apollo Cyber c++ 实现

**使用vscode 环境**

## vscode 插件

1. Bazel 
2. bazel  build工具
3. c/c++ 必要插件
4. docker 链接docker容器
5. jupytr
6. jupytr keymap
7. protobuf 
8. Remote 
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

   