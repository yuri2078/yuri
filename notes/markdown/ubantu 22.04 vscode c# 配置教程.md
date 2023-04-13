## ubantu 22.04 vscode配置教程

以下部分内容来自微软[官方文档](https://docs.microsoft.com/zh-cn/dotnet/core/install/linux-ubuntu)

### 安装.net



1.  添加微软密钥

   ```shell
   wget https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
   sudo dpkg -i packages-microsoft-prod.deb
   rm packages-microsoft-prod.deb
   ```

2. 安装sdk

   ```shell
   sudo apt-get update && sudo apt-get install -y dotnet-sdk-6.0
   ```

3. 安装运行时

   ```shell
   sudo apt-get update && sudo apt-get install -y aspnetcore-runtime-6.0
   ```

4. 检查是否安装成功

   输入dotnet 命令没有报错就是成功

   ```shell
   ~/下载 » dotnet                                   
   
   Usage: dotnet [options]
   Usage: dotnet [path-to-application]
   
   Options:
     -h|--help         Display help.
     --info            Display .NET information.
     --list-sdks       Display the installed SDKs.
     --list-runtimes   Display the installed runtimes.
   
   path-to-application:
     The path to an application .dll file to execute.
   
   ```

### 配置vscode

下载c#插件就行了



### 开始第一个项目

1. `mkdir helloCshap `新建一个项目文件夹
2. `code helloCshap`用vscode打开文件夹
3. `dotnet new console`新建控制台项目
4. `dotnet run` 直接运行

### code runner 配置c#

1. 打开code runner 扩展设置
2. `更改原来的 Csharp为"csharp": "cd $dir && dotnet run"`
3. run 直接运行