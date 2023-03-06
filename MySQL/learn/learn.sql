-------- 登陆 mysql --------

-- mysql -h 127.0.0.1 -u root -pyuri2078 
/* 
    -h 指定端口
    -u 指定用户名
    -p 指定密码-不用空格
    exit - quit - \q  退出数据库
    status; 显示当前mysql的version的各种信息
    select version(); 显示当前mysql的version信息
    show global variables like 'port'; 查看MySQL端口号
 */

                                        -------- DDL 语句  数据定义语言 用来定义数据库对象（数据库，表，字段）--------

SHOW DATABASES; -- 查询所有数据库

select database(); -- 查询当前在哪个数据库

create database -- 创建数据库
    if not exists miku -- 如果没有就创建
    default charset utf8mb4; -- 设置字符集 (utf8 占3字节部分字符占4字节，所以使用utf8mb4 占4字节)

drop database -- 删除数据库
    if exists miku; -- 如果数据库存在

use miku; -- 使用（name） 数据库

                                        -------- 关于表格的操作 ---------
create table miku.student ( -- not null下创建表格
  id             int(100) unsigned not null auto_increment primary key,
  password       varchar(32)       not null default '' comment '用户密码',
  reset_password tinyint(32)       not null default 0  comment '用户类型:0-不需要重置密码,1-需要重置密码',
  mobile         varchar(20)       not null default '' comment '手机',
  create_at      timestamp(6)      not null default current_timestamp(6),
  update_at      timestamp(6)      not null default current_timestamp(6) on update current_timestamp(6),
  
  unique index idx_user_mobile(`mobile`) -- 创建唯一索引，不允许重复

  -- null:数据列可包含NULL值；
  -- not null：数据列不允许包含NULL值；
  -- default
  -- primary key：主键；
  -- auto_increment
  -- unsigned：是指数值类型只能为正数；
  -- character set name：指定一个字符集；
  -- comment：对表或者字段说明 注释
)
ENGINE=InnoDB DEFAULT CHARSET=utf8
COMMENT='用户表信息';

show tables; -- 显示当前数据库所有表格
truncate table student; -- 删除表格中所有数据,但是不删除表格
drop table if exists student; -- 如果数据库中存在user_accounts表，就把它从数据库中drop掉
describe student; -- 显示表格的内容
delete from student; -- 清除表中记录







