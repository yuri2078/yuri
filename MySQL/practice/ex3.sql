
select * from db_student.student;
select * from db_student.course;
select * from db_student.sc order by sno;

select * from db_student.student; -- 查询全体学生信息

/* 查询“信息系”学生的学号，姓名和出生年份 */
select sno, sname, 2023-sage from db_student.student where sdept = '信息系';

/* 查询考试不及格的学生的学号 */
select sno from db_student.sc where grade < 60;

/* 查询无考试成绩的学生的学号和相应的课程号。 */
select distinct sno, cno from db_student.sc where grade is null;

/* 将学生按年龄升序排序 */
select * from db_student.student order by sage asc;

/* 查询选修了课程的学生的学号和姓名 （要求：分别使用连接查询、嵌套子查询完成） */
-- 连接查询
select distinct sc.sno, student.sname 
    from db_student.sc sc left join db_student.student student 
    on sc.sno = student.sno; 
-- 嵌套子查询
select student.sno, student.sname  -- 查找学号，姓名
    from db_student.student student  
    where student.sno in -- 如果学号在 选课列表中
    (select distinct sc.sno from db_student.sc sc); -- 查询选课表中的学号

/* 查询年龄在20-23岁之间的学生的系，姓名，年龄，按照系升序排序。 */
select sdept, sname, sage 
    from db_student.student student 
    where sage between 20 and 23 
    order by sdept asc;

/* 查询选修了“计算机网络”或者“数据库基础”课程的学生的学号，姓名。（要求：分别使用连接查询、嵌套子查询完成） */
-- 连接查询
select sc.sno, student.sname 
    from db_student.sc sc 
    left join db_student.student student on sc.sno = student.sno -- 连接选课学号和学生信息
    left join db_student.course course on sc.cno = course.cno  -- 连接选课代号和课程名字
    where course.cname in ('计算机网络', '数据库基础'); -- 查找选这两门的人

-- 嵌套子查询
select student.sno, student.sname 
from db_student.student student, 
    (select th.sno from -- 将选计算机和数据库的学号选出
        (select sc.sno, course.cname -- 将选课的课程号替换成课名
            from db_student.sc sc, db_student.course course 
            where sc.cno = course.cno) th 
        where th.cname in('计算机网络','数据库基础')) th_2
    where th_2.sno = student.sno;


/* 查询姓“张”的学生的基本信息 */
select * 
    from db_student.student student
    where student.sname like '张_%';


/* 查询学生的选课情况，要求输出学号，姓名，课程门数，课程名列表（用逗号分隔），按照学号升序排序。 */
select student.sno, student.sname, count(sc.sno), group_concat(course.cname separator ',')
    from db_student.sc sc 
    left join db_student.course course -- 添加课程名
        on sc.cno = course.cno
    left join db_student.student student -- 添加姓名
        on sc.sno = student.sno
    group by sc.sno -- 根据学号分组
    order by sc.sno asc; -- 按照学号升序排序
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

/* 查询选修了课程的学生的总人数 */
-- 嵌套查询 谓词 in 
select count(distinct sno) 
    from db_student.sc sc
    where sno in( select sno from db_student.student);

-- 嵌套查询 谓词 exists
select count(distinct sno)
    from db_student.sc sc
    where exists 
    (select * from db_student.sc sc_ where sc_.sno = sc.sno);

/* 统计各门课程选修人数，要求输出课程代号，课程名，选修人数，有成绩人数（grade不为NULL），最高分，最低分，平均分，按课程号排序 */
select sc.cno, cname, count(distinct sno) , count(grade), max(grade), min(grade), avg(grade)
    from db_student.sc sc, db_student.course course
    where sc.cno = course.cno
    group by cno
    order by cno;

/* 统计各门课程的重修人数（包括grade为NULL），要求输出课程代号，重修人数。 */
select cno, count(sno)
    from db_student.sc sc
    where grade < 60 or grade is null
    group by cno;

/* 查询选修通过2门（包括2门）以上的学生的信息，输出学号、选修通过门数、平均成绩，按门数降序排序，若门数相同，按照成绩降序 */
select sno, count(cno), avg(grade)
    from db_student.sc sc
    where grade >= 60
    group by sno
    order by 2 desc, 3 desc;

/* 查询与“王大力”同一个系的学生的基本信息 */
select * from
    db_student.student
    where sdept = (select sdept 
        from db_student.student student
            where sname = '王大力');
    
/* 查询每个学生高于他自己选修平均分的那门课程的成绩，输出学号，课程号，课程成绩，他所有课程的平均分，并按学号升序排列。
（要求：使用基于子查询派生表的查询方法） */

select sno, sc.cno, sc.grade, gra.avg_grade
    from db_student.sc sc,
    (select cno, avg(grade) as avg_grade from
        db_student.sc sc
        group by cno) gra
    where sc.cno = gra.cno and sc.grade > gra.avg_grade
    order by sno asc;

/* 查询没有同时选修“计算机导论”和“计算机网络”两门课的学生的学号，姓名 */

-- 从学生表（student）和子查询 new__ 中查询出满足条件的学生的学号和姓名
select s.sno, s.sname 
    from db_student.student s,
    (
        -- 从子查询 new_ 中查询出选择了课程计算机网络或计算机导论的学生的学号和选课数
        select new_.sno, count(new_.cno) as cno_count
            from (
                -- 从成绩表（sc）和课程表（course）中选择课程名称为计算机网络或计算机导论的学生的学号、课程号和课程名称
                select sno, sc.cno, course.cname
                from db_student.sc sc, db_student.course course
                where sc.cno = course.cno
            ) new_
            where new_.cname in('计算机网络', '计算机导论')
            group by sno
    ) new__
    where s.sno = new__.sno; -- 将学生表（student）和子查询 new__ 中选择的学生的学号进行匹配，输出匹配成功的学生的学号和姓名


/* 查询选修了全部课程的学生的学号，姓名，系名 */
select s.sno, s.sname, s.sdept
    from(select sc.sno, count(cno) as cno_count
            from db_student.sc sc
            group by sno) new, db_student.student s
    where new.sno = s.sno and 
    new.cno_count = (select count(distinct cno) from db_student.course);

/* 输出“高等数学”课程成绩前三名的学生的学号，姓名，系名 */
select * from sc;
select * from course;
select * from student;
select distinct s.sno , s.sname, s.sdept
    from db_student.student s, db_student.sc sc, db_student.course course
    where s.sno = sc.sno and sc.cno = course.cno and course.cname = '高等数学' 
    order by sc.grade desc
    limit 3;

create database study;
use study;

select * from employee;

/* （1）查询总经理、经理以下的职员信息，包括NULL值记录 */
select * from study.employee em 
    where job_title not in('总经理', '经理') 
    or job_title is null;


select * from department;
/* 查询“联荣资产”的客户信息。 */
select * from customer
    where customer_name like ("%联荣资产%");

/* 查询价格5000-6000的“联想”品牌和价格在5000以下的“小米”品牌的产品信息。 */
select * from product
    where product_name like ('%联想%') 
        and price between 5000 and 6000
    or product_name like ('%小米%') and price < 5000;

/* 查询如“GTX950M”/“GTX960M”系列的产品信息。 */
select * from product
    where description like ('%GTX950M%')
    or description like ('%GTX960M%');

/* 统计各年份订单总数，订单总额，按年份降序排列 */
select count(order_id), sum(total_money)
    from payment
    group by year(pay_time)
    order by year(pay_time) desc;

/* 统计2016年各产品的订购数量（降序排列），输出5-10名的统计信息，包括产品ID，订购总数 */

select customer_id, sum(created)
    from payment
    where year(pay_time) = 2016
    group by customer_id
    order by 2 desc
    limit 5, 5;