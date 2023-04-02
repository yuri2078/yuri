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


                                        -------- 表格的操作 ---------
-- 创建表格
create table if not exists miku.name (
    name char(20) primary key comment '姓名'
);         

create table if not exists miku.student ( --如果不存在就创建表
    id int unsigned not null primary key auto_increment comment '学号',
    name char(20) default 'yuri' not null comment '姓名',
    sex char(10) default '女' not null comment '性别',
    foreign key(name) references miku.name(name), -- 从别的表添加约束
    unique index number(`id`) -- 创建唯一索引，不允许重复

    -- null:数据列可包含NULL值；
    -- not null：数据列不允许包含NULL值；
    -- default
    -- primary key：主键；
    -- auto_increment 自增长
    -- unsigned：是指数值类型只能为正数；
    -- character set name：指定一个字符集；
    -- comment：对表或者字段说明 注释
    -- foreign key(键名) references 表名(键名) 从别的表添加约束
);

drop table if exists miku.student; -- 删除表格 [如果存在]
truncate table miku.student; -- 删除表格中所有数据,但是不删除表格
delete from miku.student; -- 清除表中记录
select * from miku.name; -- 查询表中记录

-- 向表中插入数据
insert into miku.name (
    name 
) values ('晓美焰'),
('鹿目圆'),
('沙耶香'),
('左仓杏子'),
('白月初'),
('迪迦');

insert into miku.name set 
    name = '巴麻美'
;


/* 直接插入 */
insert into miku.student (
    id, name, sex
) values (1, '晓美焰', '女'),
(2, '鹿目圆', '女'),
(3, '左仓杏子', '女'),
(4,'白月初', '男'),
(5, '迪迦', '男');

/* 从别的表插入 */
insert into miku.student
select sno, sname, ssex
    from db_student.student;


/* 使用default数据 */
insert into miku.student (
    id, name, sex
) values (1, '晓美焰', '女'),
(2, '鹿目圆', '女'),
(3, '左仓杏子', '女'),
(DEFAULT,'白月初', '男'),
(5, '迪迦', '男');


                                -------- select 操作 --------

select database(); -- 查询当前正在哪个数据库
select name, name from miku.name; -- 从表中选择 name 和 name
select * from miku.student; -- 从表中选择所有数据
select distinct s.sex, n.name from miku.student s, miku.name n where sex = '女' and id in(1,2,3) and id not in(2) and s.name = n.name limit 2;
-- distinct 查询结果会去除重复的
-- s.sex, n.name  显示两个数据
-- miku.student s 给表 miku.student 取别名 s 
-- s.* 查询s 表中 * 数据(全部数据)
-- from miku.student 从这个表中查询
-- where sex = '女' 查询属性为女的
-- and id in(1,2,3) 并且 id 是 1, 2, 3 的
-- and id not in(2) 并且 id 不是 2 的 
-- and s.name = n.name 显示不同字段相等的数据
-- limit 2 只查询 2 条

select * 
    from db_student.student student
    where student.sname like '张_%';
-- like 字符串匹配

select sdept, sname, sage from db_student.student student where sage between 20 and 23 order by sdept asc;
-- order by sex asc 通过sex 排序 asc 升序 desc 降序
-- between 20 and 30 大于等于 20 小于等于 30 not between adn 不在
select * from db_student.course cross join db_student.sc;
-- cross 交叉连接 会产生 course.length x sc.lenght 个数据
-- 也就是笛卡儿积

select * from db_student.student as student inner join db_student.sc as sc on student.sno = sc.sno;
-- 内连接 SELECT * FROM TableA INNER JOIN TableB ON TableA.name = TableB.name 产生的结果是AB的交集
-- as 取别名
-- student inner join sc  将 student 和 sc 进行 内连接
-- on student.sno = sc.sno 连接条件是 他们的sno 相同

select sno, course.cno, cname from db_student.sc sc left join db_student.course course on sc.cno = course.cno;
-- 以某张表为主,取出里面的所有记录, 然后每条与另外一张表进行连接: 不管能不能匹配上条件,最终都会保留: 能匹配,正确保留; 不能匹配,其他表的字段都置空NULL.
-- left 以左边的表为主表 如果右边匹配不上也会保留左边
-- right 以右边的表为主表 如果左边匹配不上也会保留左边

select * from db_student.student where sage = 19 union all select * from db_student.student where ssex = '男';
-- 联合查询 将多个select 查询到的东西进行拼接
-- union 两个选项 union all 保留所有数据 union  distinct 去除重复内容（默认选项）
-- 联合查询只要求字段一样, 跟数据类型无关

-- 查询学生的选课情况
-- 输出学号、姓名、选修的课程门数、选修课程名称（用逗号隔开）
-- 以学号升序排序

select student.sno, student.sname, count(sc.sno), group_concat(course.cname separator ',')
    from db_student.sc sc 
    left join db_student.course course 
        on sc.cno = course.cno
    left join db_student.student student
        on sc.sno = student.sno
    group by sc.sno
    order by sc.sno asc;
    
-- 说明：
-- select: 查询语句
-- student.sno, student.sname: 选择学号和姓名
-- count(sc.sno): 统计选修的课程门数
-- group_concat(course.cname separator ','): 选修的课程名称，用逗号隔开
-- from: 查询的数据来源
-- db_student.sc sc: 表示从 db_student 数据库中的 sc 表中查询数据
-- left join: 表示左连接，将 sc、course、student 三个表连接起来
-- on sc.cno = course.cno / on sc.sno = student.sno: 连接条件，连接课程表和选课表，连接学生表和选课表
-- group by sc.sno: 按照学号分组，统计每个学生选修的课程数和课程名称
-- order by sc.sno asc: 按照学号升序排序


/* UPDATE语句格式 */

UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
update miku.student set sex = '武装直升机' where name = '迪迦'; -- 如果姓名是迪迦，就将性别改成武装直升机


/* UPDATE语句格式 */

UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
delete from miku.name where name in(select sno from db_student.student); -- 删除所有 name 表中所有在 student中出现的数据


