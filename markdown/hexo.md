# hexo 安装教程

## 安装nodejs

+ 一路下一步
+ nodejs -v 查看安装版本号
+ npm -v 查看 npm 版本号
+ 如果npm 报错 进nodesjs 目录 把npm.cmd文件的第 12行和npm文件的第 23 行替换prefix -g为prefix --location=global

## 安装git

+ 一路下一步
+ git -v 查看安装是否成功

## 注册GitHub

+ 新建一个仓库 名字是 用户名/用户名.github.io -- 固定格式

## 准备开始 -- 1

+ 替换镜像源 npm config set registry ``` https://registry.npm.taobao.org ```

+ 创建一个文件夹 并 右击 在git bash中打开 / win + R  cd 进去

+ npm i hexo-cli -g 安装hexo

+ hexo -v 查看是否成功安装

+ hexo init 初始化hexo 文件夹

+ hexo install 创建hexo

+ hexo g 生成静态文件夹

+ hexo s 建立本地服务器 进网址看看是否成功

+ ctrl + C 退出服务

## 开始 -- 2

+ git config --global user.name "yuri2078" 设置全局用户名 GitHub 的用户名

+ git config --global user.email "yuri2078170658@gmail.com" 设置全局邮箱 GitHub 的邮箱

+ mkdir .ssh 新建ssh 文件夹 -- 可以不建立

+ ssh-keygen -t rsa -C "yuri2078170658@gmail.com" 生成 ssh 文件 一路回车即可

+ 进 c：/用户/用户名/.ssh/   用记事本 打开 id_rsa.pub 全选复制文件

+ 进GitHub 的个人设置 选择 ssh key ， 添加ssh  名字随意 key 为 刚复制的东西

+ ssh -T git@github.com 进行本地连接 -- 出现自己的用户名就是成功 第一回可能会问你yes/on 输入yes就行

+ 修改 博客根目录下 _config.yml 文件 将 deploy 修改为以下 repository 为自己的博客地址

``` :
deploy:
  type: git
  repository: https://github.com/yuri2078/yuri2078.github.io
  branch: main

```

+ hexo new post "fist-blog" 新建第一篇博客

+ 进 博客根目录/source/_posts 下找到文章.md 进行编辑

## 提交

+ hexo g 生成静态文件
+ hexo d 提交到GitHub 随后访问 ``` https://用户名.github.io ```就可以访问了

## 日常使用

+ hexo new page "categories" 添加分类功能
  + categories: - hello world 设置分类
+ hexo new page "tags" 添加标签功能
  + tags: 可以多个

  ```:
    - jQuery
    - 表格
    - 表单验证

  ```

+ hexo new page "about" 添加关于界面
+ hexo new page "contact" 添加联系界面
+ npm i --save hexo-wordcount 安装 统计字数插件  
+ npm install hexo-deployer-git --save 解决git报错d

## 免费cdn

1. 新建github仓库

2. 发布reselss版本

3. `https://cdn.jsdelivr.net/gh/你的用户名/你的仓库名@发布的版本号/文件路径` 访问你的图片
