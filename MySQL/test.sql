/* 学生表：Student(Sno,Sname,Ssex,Sage,Sdept)
成绩表：SC(sno,cno,grade)
课程表Course(cno,cname,cpno,credit) */

/* 1.找出至今没有人选修过的课程号，课程名称。 */

select course.cno, course.cname 
    from db_student.course course
    where not exists (
        select * from db_student.sc sc
        where sc.cno = course.cno
    );

/* 2.查询每个学生成绩最高的成绩信息。 */

select sc.sno, sc.cno, course.cname, max(sc.grade)
    from db_student.sc sc join db_student.course course
    on sc.cno = course.cno group by sc.sno
    having max(sc.grade) = (
        select max(scc.grade) from db_student.sc scc  
        where scc.sno = sc.sno);

/* 3.查询超过该课程平均分的成绩信息。 */
select sc.sno, sc.cno, sc.grade
    from db_student.sc sc 
    where grade > (select avg(grade) 
        from db_student.sc scc 
        group by sno 
        having sc.sno = scc.sno
    );

/* 4.查询选课门数最多的学生的学号和姓名。 */

select s.sno, sname 
    from db_student.student s
    where sno = (select sno from db_student.sc sc
    group by sno order by count(*) desc limit 1);



/* 5.查询所有人都选修了的课程号与课程名 */


select * from course
    where not exists (
        select * from student 
            where not exists (
                select * from sc
                    where student.sno = sc.sno
                        and sc.cno = course.cno
            )
    );