/* #查询输出“高等数学”课程成绩前三名（不考虑成绩有重复值的情况）的学生的学号，姓名，课程名，系名(sdept)，成绩 */
select sc.sno, sname, cname, sdept , grade
    from sc left join student on sc.sno = student.sno
    left join course on sc.cno = course.cno
    where course.cname = '高等数学' and sc.sno = student.sno order by grade desc limit 3;

/* 统计各门课程选修人数，要求输出课程代号，课程名，有成绩人数（grade不为NULL），最高分，最低分，平均分(取整round函数)，按课程号排序。 */

select sc.cno, cname, count(grade), max(grade), min(grade),  round(avg(grade))
    from sc left join course on sc.cno = course.cno group by cno order by cno;

/* 查询计算机系平均成绩高于70分的学号，姓名、平均成绩，并按平均成绩降序排列 */
select sc.sno, sname, avg(grade) 
    from sc left join student on sc.sno = student.sno
    where sdept = '计算机系'
    group by sno
    having avg(grade) > 70
    order by 3 desc;

/* 查询同时选修了“数据库基础”和“计算机网络”两门课的学生的学号，姓名 */
select sc.sno, sname from student
    inner join sc on sc.sno = student.sno and cno = (select cno from course where cname = '数据库基础')
    inner join sc s on s.sno = student.sno and s.cno = (select cno from course where cname = '计算机网络');

/* 查询选修了课程的学生的学号和姓名，按学号排序。 */
select sno, sname from student
    where  exists(
        select * from sc where sc.sno = student.sno
    )
    order by sno;

/* 查询学生的选课情况，要求输出学号，姓名，课程门数，课程名列表（按课程名升序排列，用下划线_分隔），按照学号升序排序 */
select sc.sno, sname, count(sc.cno), group_concat(course.cname order by course.cname separator '_')
    from sc left join student on sc.sno = student.sno
    left join course on course.cno = sc.cno
    group by(sc.sno)
    order by sc.sno;

/* 查询每个男生的选课门数（要求用嵌套查询实现）要求输出学号、选课门数，并按序号升序排序 */
select sc.sno , count(cno) from sc
    left join student on sc.sno = student.sno
    where sc.sno in(select sno from student where ssex  = '男')
    group by sno
    order by sno;

/* 查询没有同时选修“计算机导论”和“计算机网络”两门课的学生的学号，姓名 */
select distinct sc.sno, sname from sc
    left join student on sc.sno = student.sno
    where sc.sno not in (
        select sc.sno from sc
        where cno in(
            select cno from course where
                cname in('计算机网络','计算机导论')
        )
        group by (sc.sno)
        having count(cno) = 2
    );

/* 查询选修了学号为9521102同学选修的全部课程的学生学号和姓名 */
select sc.sno, sname from sc
    left join student on sc.sno = student.sno
    where cno in(
        select cno from sc where sno = 9521102
    )
    group by sno
    having count(*) = (
        select count(*) 
            from sc where sno =  9521102 
            group by sno
    );

/* 10. 查询95级学生(学号前两位)的选课情况，输出学号、姓名、课程号、成绩（包括未选课的学生信息） */
select student.sno, sname, cno, grade from student
    left join sc on sc.sno = student.sno
    where student.sno like '95%';

/* 11. 查询选课门数最多的学生的学号和姓名 */
select sno, sname from student 
    where sno in (select sno from sc 
                    group by(sno)
                    having count(*) = 
                    (
                        select count(*) from sc
                            group by(sno)
                            order by(count(*)) desc limit 1
                    )
    );

/* 12. 查询每个学生成绩最高的成绩信息 */
select * from sc where grade = (
    select max(grade) from sc c
        where c.sno = sc.sno
);

/* 13. SQL查询：查询同时选修了c01,c02,c03课程学生，输出学号，姓名 */
select sno, sname from student 
    where exists(
        select * from sc 
            where cno in('c01', 'c02', 'c03')
            group by(sc.sno)
            having count(*) = 3 and sc.sno = student.sno
    );

/* 14. 查询每门课程被选修的情况，输出课程号，课程名，被选修次数 */
select course.cno, cname, coalesce(val, 0) from course 
left join (
    select cno, count(*) val from sc group by(cno)
) s on course.cno = s.cno
where val is not null
order by val desc, cno desc;

/* 15. 查询每门课程被选修的情况(包括从未被选修过的课程) */
select course.cno, cname, coalesce(val, 0) from course 
left join (
    select cno, count(*) val from sc group by(cno)
) s on course.cno = s.cno
order by val, cno;

/* 16. 查询选修了c03课程的学生学号和姓名 */
select sno, sname from student
    where exists(
        select * from sc where sc.sno = student.sno and cno = 'c03'
    );

/* 17. 查询没有参加选课的学生，输出系名，学号，姓名，性别，按系名（升序），学号（升序）排序 */
select sdept, sno, sname, ssex from student
    where not exists(
        select * from sc where sc.sno = student.sno
    )
    order by sdept, sno;

/* 18. 查询所有人都选修了的课程号与课程名 */
