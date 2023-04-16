/* 1 */
select dept_id, employee_id, employee_name, gender 
    from employee where job_title = '主管' order by dept_id;

/* 2 */
select * from employee where dept_id in(1000,1001,1002) and gender = '男';

/* 3 */
select product_name, price, category_id 
    from product where price between 5000 and 6000 order by price desc;

/* 4 查询成绩表中无成绩的记录，输出学生的学号和相应的课程号 */
select sno, cno from sc
    where grade is null;

/* 5 查询客户“优特电力”的联系信息。（输出联系人contact_name，电话phone) */
select contact_name, phone 
    from customer where customer_name like '%优特电力%';

/* 6 查询选修通过门数超过3门，且平均分在70以上的学生的学号，选修门数，平均成绩，并按平均成绩从高到低排序。 */
select xh, count(*), avg(cj)
    from cj where cj >= 60 group by(xh) 
        having count(*) >= 3 order by 3 desc;

/* 7 查询平均分最高的三个学生的学号，选门数和平均分。 */
select xh, count(*), avg(cj)
    from cj group by(xh)
    order by 3 limit 3;

/* 8 成绩表包括如下列（学号，课程代号，成绩，教师工号），查询查询选课的学生总数 */
select count(distinct xh) from cj;

/* 9 查询无有效成绩的成绩信息，列出学号，课程代号，成绩和教师工号 */
select xh, kcdh, cj, gh
    from cj where cj is null;

/* 10 查询18级学生的成绩信息，列出学号、课程代号、成绩、教师工号 */

select xh, kcdh, cj, gh 
    from cj where xh like '____18%';

/* 11 查询学号为Z09317101的学生的各门课的成绩，列出课程号、成绩 */
select kcdh, cj from cj where xh ='Z09317101';

/* 12 查询课程代号为1301的成绩不及格的学生学号和成绩 */
select xh, cj from cj where kcdh = '1301' and cj < 60;

/* 13 查询没有职位信息的职员 */
select * from employee where job_title is null;

/* 14 查询employee的job_title信息。 */
select job_title from employee;

/* 15 查询课程号为C05的成绩为NULL的记录 */
select * from sc where cno = 'C05' and grade is null;

/* 16 查询数学系女生基本信息 */
select * from student where ssex = '女' and sdept = '数学系';

/* 17 查询订单记录，输出订单日期order_date，顾客编号customer_id，订单总额total_money，订单编号order_id，按照日期升序排序 */
select order_date, customer_id, total_money, order_id from orders order by order_date;

/* 18 查询计算机系平均成绩高于70分的学号，姓名、平均成绩，并按平均成绩降序排列 */

select sc.sno, sname, avg(grade) 
    from sc left join student on sc.sno = student.sno
    where sdept = '计算机系' group by(sno)
    having avg(grade) >= 70 order by 3 desc;

/* 19 查询部门1000的人数 */
select count(*) from employee where dept_id = 1000;

/* 20 查询各个部门人数大于10人的，输出部门编号和人数，并按人数升序排序 */
select dept_id, count(*)
    from employee group by(dept_id)
    having count(*) >10 order by 2 desc;

/* 21 查询姓名中含有“海”的学生的选课信息，要求输出学号、姓名、课程名、成绩 */
select sc.sno, sname, cno, grade
    from sc left join student on sc.sno = student.sno
    where sname like '%海%';

/* 22 查询选修了课程的学生的学号和姓名，按学号排序 */
select sno, sname from student
    where sno in(select sno from sc)
    order by sno;

/* 23 查询现有图书中价格最高的图书（可能不止一种书），输出书名及作者。 */
select bname, author from book
    where price = (select max(price) from book);

/* 24 查询每个男生的选课门数（要求用嵌套查询实现）要求输出学号、选课门数，并按序号升序排序 */
select sno, count(*) from sc group by(sno) order by sno;

/* 25 查询借阅书名为"水浒"书的读者信息，输出姓名及班级。 */

select name, class from card
    where cno in (select cno from borrow 
        where bno = (select bno from book where bname = '水浒')
    );

SELECT student.sno,sname FROM student,sc
WHERE student.sno=sc.sno
GROUP BY sno
HAVING count(*)=(
  SELECT count(*) FROM sc
	GROUP BY sno
	ORDER BY count(*) DESC
	LIMIT 1
);

