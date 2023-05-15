/* 有student、course、sc表；删除“吴宾”的所有成绩记录 */
delete from sc where sno = (select sno from student where sname = '吴宾');

/* SQL插入：插入一条学生数据（9913101，王红，女） */
insert into student (sno, sname, ssex) values(9913101,'王红','女');

/* 使用insert set 向sc表中插入一条选课记录，姓名为周璐的学生，课程名为数据库原理与应用的课程的选课记录。 */
insert into sc set
    sno = (select sno from student where sname = '周璐'),
    cno = (select cno from course where cname = '数据库原理与应用');

/* 修改计算机系李勇的VB课程成绩为60。 */
update sc set grade = 60 
    where sno = (select sno from student where sname = '李勇' and sdept = '计算机系')
    and cno = (select cno from course where cname = 'VB');

/* 删除“数据库基础”的全部记录（包括课程信息，成绩信息） */
DELETE course, sc FROM course
    JOIN sc ON course.CNO = sc.CNO
    WHERE course.CNAME = '数据库基础'

 /* 插入计算机系学生C01课程的选课记录 */
insert into sc(sno, cno)
    select sno, 'C01' from student
    where sdept = '计算机系';

/* 修改“9512101”的“C01”课程成绩为85 */
update sc set grade = 85 where sno = 9512101 and cno = 'C01';

/* 一次向student表中插入两条记录，其中王大力的系别用缺省值赋值。
 两行数据的学号，姓名，性别，年龄和系别分别如下：
9520103,王敏,女,20,信息系;
9520104,王大力,男,19。 */
insert into student (sno, sname, ssex, sage, sdept)
    values(9520103,'王敏','女',20,'信息系'),
          (9520104,'王大力','男',19, default);

/* 从BOOK表中删除当前无人借阅的图书记录。 */
delete book where not exists(
    select * from borrow where book.bno = borrow.bno
);

/* 有student、course、sc表；修改“张海”的“计算机导论”课程成绩为70 */
update sc set grade = 70 where sno = (
    select sno from student where sname = '张海'
) and cno = (
    select cno from course where cname = '计算机导论'
);

#在课程表Course中插入数据：
/* Cno：C06       Cname：数据结构    Ccredit：5     Semster：4 */
insert into course (CNO, CNAMe, CCREDIT, SEMSTER)
    values('C06', '数据结构',5, 4);

/* Sno：9512102    Sname:刘晨     Ssex：男     Sage:20     Sdept：计算机系 */
insert into student (SNO, SNAME, SSEX, SAGE, SDEPT)
    values (9512102, '刘晨', '男', 20, '计算机系');

/* 将图书信息插入到book表中，其中书号 7, 书名 组合数学, 作者 刘迪, 价格 36.70, 数量 37 */
insert into book (bno, bname, author, price, quantity)
    values (7, '组合数学', '刘迪', 36.70, 37);

/* #将所有学生的年龄增加1岁。 */
update student set SAGE = SAGE + 1;
/* 删除“9531102”学生“C05”课程的成绩记录 */

delete from sc where CNO = 'C05' and SNO = 9531102;

/* 删除计算机系学生的所有成绩记录 */
delete from sc where sno in (
    select sno from student where sdept = '计算机系'
);

#在选课表SC中插入95211班学生选修C04的选课信息。
/* 提示：多行数据插入，插入的数据的sno从student表中查询而来，插入的cno为“C04” */
insert into sc (
    SNO, CNO
) select SNO, 'C04' from student where SNO like '95211%';

/* #修改“王大力”的“计算机导论”课程成绩为70 */
update sc set GRADE = 70 where 
    CNO = (select CNO from course where CNAME = '计算机导论')
    and SNO = (select SNO from student where SNAME = '王大力');

/* 将所有平均分为75分以上的学生的各门课成绩在原来基础上加5分 */
update sc set GRADE = GRADE + 5 
where SNO in(
    select scc.SNO from  (
        select SNO, avg(GRADE) avg_grade from sc 
        group by(sc.SNO)
    )scc where scc.avg_grade > 75
);

/* 修改“高等数学”课程倒数三名,且非空的成绩，在原来分数上减5分 */
update sc set GRADE = GRADE - 5 where
    SNO in (
        select SNO from (
            select SNO from sc where CNO = (
                select SNO from course where CNAME = '高等数学'
            ) and GRADE is not null
            order by GRADE limit 3
        ) scc
    );

create procedure 
