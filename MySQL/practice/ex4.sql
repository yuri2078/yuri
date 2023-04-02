select * from miku.student;

select * from miku.name;
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

/* 在选课表SC中插入95211班学生选修C04的选课信息 */