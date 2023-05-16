/* 1、MySQL的GRANT语句格式： */
GRANT 权限名 ON 对象名 TO 用户名;

/* MySQL的触发器语句格式 */
CREATE TRIGGER 触发器名字 
{BEFORE | AFTER} {INSERT | UPDATE | DELETE}
ON 表名 
FOR EACH ROW 
BEGIN
	...
END;

/* 3、MySQL的存储过程语句格式： */
CREATE PROCEDURE 存储过程名字(参数列表)
BEGIN
    -- sql 语句
END;

/* （1）创建超级用户admin，具有对所有数据库的所有访问权限，仅限本机连接（密码自行设置），并验证用户和权限设置是否正确。 */
CREATE USER 'admin'@'localhost' IDENTIFIED by 'admin'; -- 新建用户
GRANT ALL PRIVILEGES ON *.* TO 'admin'@'localhost'; -- 授予权限
SHOW GRANTS FOR 'admin'@'localhost'; -- 检查权限


/* ）创建管理员teacher_liu，具有对SC表、IS_STUDENT视图（实验5创建）的增删改查权限，并且具有授权的权限，
允许从任意位置连接（密码自行设置），并验证用户和权限设置是否正确。 */
CREATE USER 'teacher_liu'@'%' IDENTIFIED by 'test'; -- 新建用户
GRANT INSERT, DELETE, UPDATE, SELECT ON SC, IS_STUDENT TO 'teacher_liu'@'%'; -- 授予增删改查权限
GRANT GRANT OPTION ON *.* TO 'teacher_liu'@'%'; -- 授予 授予权限 权限
SHOW GRANTS FOR 'teacher_liu'@'%';

/* （1）创建触发器，插入和更新学生成绩时，限制必须在0-100之间（即成绩值如果超出范围，则设置其值为0 */
create trigger insert_sc
before insert on sc for each row
begin
    if new.grade > 100 or new.grade < 0 then
        set new.grade = 0;
    end if;
end;

create trigger update_sc
    before update on sc for each row
begin
    if new.grade > 100 or new.grade < 0 then
        set new.grade = 0;
    end if;
end;

# 为student表创建一个同结构的备份空表用来存储删除的数据，命名为student_bf。
# 创建student表的删除触发器，每次删除数据，将删除的数据插入到备份表student_bf，以备误删除时数据恢复。
create table student_bf like student; -- 新建表

create trigger delete_stu
after delete on student for each row
begin
    insert into student_bf values(old.sno, old.sname, old.ssex, old.sage, old.sdept);
end;


# （1）建立存储过程course_grade：根据课程名参数，查询该课程的成绩表，包括学号，姓名，成绩，按学号升序排序。
create procedure course_grade(in name varchar(20))
begin
    select sc.sno, sname, grade from sc left join student s on s.sno = sc.sno
        where cno = (select cno from course where cname = name)
        order by sc.sno
    ;
end;

# （2）建立存储过程search_grade：根据姓名和课程名参数，查询该学生相应的课程成绩，若存在成绩，则返回成绩值，否则返回NULL。
create procedure search_grade(in s_name varchar(20), in c_name varchar(10))
begin
    declare sno_ int;
    declare cno_ varchar(20);
    declare grade_ smallint default null;

    set sno_ = (select sno from student where sname = s_name);
    set cno_ = (select cno from course where cname = c_name);
    set grade_ = (select grade from sc where sno_ = sno and cno = cno_);
    select grade_;
end;

# （3）创建存储过程take_course：根据参数学号和课程号，完成选课功能（要求能够根据选课人数加以限制）。检查该学生选课门数是否超过3门，若超过，不插入记录；

create procedure take_course(in my_sno int, in my_cno varchar(10))
begin
    declare course_count int default 0; -- 当前课程选修人数
    declare stu_count int default 0; -- 该学生选修课程数
    declare most_count int default 30; -- 当前课程最多选课人数
    declare is_choose int default 0; -- 当前课程是否已经选了
    set course_count = (select count(*) from sc where cno = my_cno);
    set stu_count = (select count(*) from sc where sno = my_sno);
    set most_count = (select most_people from course where cno = my_cno);
    set is_choose = (select count(*) from sc where sno = my_sno and cno = my_cno);

    if course_count < most_count and stu_count < 3 and is_choose = 0 then
        insert into sc values(my_sno, my_cno, null, null);
    end if;

    if stu_count > 2 then
        select -1;
    elseif course_count = most_count then
        select 0;
    elseif is_choose = 1 then
        select 2;
    else
        select 1;
    end if;
end;



