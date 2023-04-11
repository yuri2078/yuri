select * from miku.student;
SELECT * FROM db_student.sc;
select * from db_student.student;

delete from miku.name where name in(select sno from db_student.student);

insert into miku.student
select sno, sname, ssex
    from db_student.student;

insert into miku.name
select sname from db_student.student;

/* INSERT语句格式 */
INSERT INTO table_name (column1, column2, column3, ...)
SELECT column1, column2, column3, ...

/* UPDATE语句格式 */

UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;

/* 1）在学生表Student中插入数据： Sno：9512102	Sname:刘晨	   Ssex：男	Sage:20	Sdept：计算机系 */

INSERT INTO db_student.student 
    (sno, sname, ssex, sage, sdept)
VALUES (9512102, "刘晨", "男", 20,"计算机系");

/* 2）在课程表Course中插入数据： Cno：C06		Cname：数据结构		Ccredit：5		Semster：4 */
INSERT INTO db_student.course
    (cno, cname, ccredit, semster)
VALUES ("C06", "数据结构", 5, 4);

/* 在选课表SC中插入95211班学生选修C04的选课信息 多行数据插入，插入数据中的sno从student表中查询而来，插入的cno为“C04” */

INSERT INTO db_student.sc 
    select sno, 'C04', NULL from db_student.student where sno LIKE "95211%";

/* 将所有学生的年龄增加1岁。 */
UPDATE db_student.student 
    set sage = sage + 1;

/* 修改“9512101”的“C01”课程成绩为85 */

UPDATE db_student.sc
    set grade = 85 where sno = 9512101 and cno = 'C01';


/* 修改“王大力”的“计算机导论”课程成绩为70。 */
UPDATE db_student.sc
    set grade = 70 where 
    sno = (select sno from db_student.student where sname = '王大力') and
    cno = (select cno from db_student.course where cname = '计算机导论');

/* （4）将所有平均分为75分以上的学生的各门课成绩在原来基础上加5分。 */


update db_student.sc 
    set grade = grade + 5
    where sno in (
        select scc.sno from (
            select sno from db_student.sc
            group by(sno)
            having avg(grade) >= 75
        ) scc
    );

/* 修改“高等数学”课程倒数三名成绩，在原来分数上减5分 */
update db_student.sc 
    set grade = grade - 5 
    where sno in (
        select * from (
            select sno from db_student.sc sc
            where cno = (
                select cno from db_student.course
                    where cname = '高等数学'
                    and grade is not null
            )
            order by grade limit 3
        ) scc
    );

/* 删除“9531102”学生“C05”课程的成绩记录 */
delete from db_student.sc 
    where sno = '9531102' 
    and cno = 'C05';

/* 删除“张海”的所有成绩记录 */

delete from db_student.sc
    where sno = (
        select sno from db_student.student
            where sname = '张海'
    );

/* 删除“数据库基础”的全部记录（包括课程信息，成绩信息） */
delete from db_student.sc;
delete from db_student.course;
delete from db_student.student;

/* 导入rental表数据，在customer_id上建立普通索引（通过语句或表设计器均可）
查询customer_id=367的记录，记录查询时间：
有索引情况下的执行时间：
无索引情况下的执行时间： */

SELECT * FROM db_student.sc;
SELECT * FROM db_student.course;
select * from db_student.student;


select * from sc order by cno;

delete from student where sname = 'test';
