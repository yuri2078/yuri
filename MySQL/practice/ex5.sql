/* （1）建立视图IS_STUDENT,视图中包含信息系全体学生的基本信息。（要求限制更新） */
create view IS_STUDENT as select * from student where sdept = '信息系';

/* （2）建立视图CJ_STUDENT,视图中包含所有成绩不及格的学生的学号，姓名，课程名，成绩。 */
create or replace view CJ_STUDENT as select sc.sno, sname, cno, grade from sc, student where (sc.sno = student.sno) and (grade < 60 or grade is null);

/* （3）建立视图AVG_CJ，视图包括学生的学号以及他们的平均成绩，按成绩降序排列。 */
create view AVG_CJ as select sno, avg(grade) from sc group by sno order by 2 desc;

/* （4）根据视图IS_STUDENT，修改该视图中年龄都增加1。观察基本表Student中相应的哪些数据发生了变化。 */
update `IS_STUDENT` set sage = sage + 1;
-- Student 中所有信息系的学生的年龄都增加了1岁

/* （5）在视图IS_STUDENT中插入新的记录，学号为9531103，姓名为张玉，女，21岁，计算机系。（是否能执行？若不行，为什么？） */

insert into `IS_STUDENT` values(9531103,'姓名为张玉', '女', 21, '计算机系');
-- 能够执行

/* （6）根据视图CJ_STUDENT创建视图CJ_TJ，包含课程名，不及格人数，不及格人姓名列表，按照不及格人数降序排列。 */
create or replace view CJ_TJ as SELECT cno,count(sno) , group_concat(sname)  FROM `CJ_STUDENT` group by cno order by 2 desc;


/* （1）在Student表中插入一条数据:
9512101	王红	女	20	外语系 
插入是否成功？为什么？ */

insert into student values(9512101,	'王红',	'女', 20, '外语系');
-- 插入失败因为主键约束不允许重复 9512101 已经存在

/* （2）修改Student表中记录，将学号9512101改为9512103，更改是否成功？若不成功请说出原因。 */
update student set sno = 9512103 where sno = 9512101;
-- 修改失败主键约束不允许重复， 9512103 已经存在

/* （1）在Sc表中插入一条数据：
9512121	C01	NULL

插入是否成功？为什么？ */
insert into sc values(9512121,'C01', NULL);
-- 插入失败，违反外键约束，student 中并没有 9512121

/* （2）修改SC表中记录，将学号为9512101的记录均改为学号9512109，是否更改成功？若不成功请说出原因。 */
update sc set sno = 9512109 where sno = 9512101;
-- 修改失败，违反外键约束，student 中并没有 9512109

/* （3）设置SC表的参照完整性为更新和删除时均为级联。
方法1：在表设计器中修改；
方法2：修改表结构，设置更新与删除参照完整性规则均为级联。请写出SQL语句。 */
--方法2 ：
alter table sc add constraint sno_key foreign key (sno) references student(sno) on update cascade on delete cascade;


/* （4）修改Student表学号9512101为9512109，观察SC表中相应记录是否更新？ */
update student set sno = 9512109 where sno = 9512101;
-- sc 表中的数据也进行了相应的更新

/* （5）在Course表中删除课程代号为C01的记录，观察SC表中选课C01的记录是否删除？ */
delete from course where cno = 'C01';
-- sc表中的数据也被删除了
