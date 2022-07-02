# git命令
## 全局设置
+ ``` git config --global user.name "yuri2078" ``` 设置用户名
+ ``` git config --global user.email "yuri2078170658@gmail.com" ``` 设置邮箱账号
+ ``` git config --global http.sslVerify "false" ``` 取消全局验证
+ 取消全局代理
    + ``` git config --global --unset http.proxy ``` 
    +  ``` git config --global --unset https.proxy ```

## 常用命令
+ ``` git add file-name ``` 添加指定文件
+ ``` git add . ``` 添加目录下所有文件
+ ``` git commit -a ``` 提交文件 然后进行编辑
+ ``` git commit -m "main" ``` 提交文件并以 “main” 作为提交
+ ``` git branch -M main ``` 新建分支
+ ``` git push -u origin main ``` 推送文件到main 分支
+ ``` git log ``` 查看历史提交日志
+ ``` git reset --hard commit_id ``` 回退到某个版本
+ ``` git push main ``` 推送到远程 main 分支

 