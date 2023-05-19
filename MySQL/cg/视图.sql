# dcddddabbccd -- 选择题

# 建立city值为上海、北京的顾客视图v_customer，包括顾客号、顾客名、联系人姓名、电话和地址。

create or replace view v_customer as
select customer_id,  customer_name, contact_name, phone, address
       from customer where city in('北京', '上海');

# 建立城市为上海的客户2016年的订单信息视图v_order，包括顾客号、顾客名、该顾客2016年的订单数及订单总额。
create view v_order as select order_date, customer.customer_id, customer_name, created, total_money
    from customer left join orders o on customer.customer_id = o.customer_id
    where order_date like '2016%';

# 建立一个视图v_borrow，显示"力学1"班学生的借书信息，列出卡号，姓名和还书日期。
create view v_borrow as select b.cno, name, rdate from
    card left join borrow b on card.cno = b.cno;

# 从视图v_student_c(sno,sname,sage)，删除学号为9521101的学生基本信息。
delete from v_student_c where sno = 9521101;

# 更新视图数据v_student_c(sno,sname,sage)，将学号为9521101的年龄改为21.
update v_student_c set sage = 21 where sno = 9521101;

# 向视图v_student_c(sno,sname,sage)添加数据行，数据如下：
# sno:9521101
# sname:王明
# sage：20
insert into v_student_c (sno, sname, sage) values(9521101, '王明', 20);

# 建立视图v_sc_avg，通过视图可以查看课程号cno，课程名cname，课程平均成绩avggrade。
create view v_sc_avg as select sc.cno, cname, avg(grade) as avggrade
    from sc left join course c on c.cno = sc.cno
    group by cno;

# 建立视图v_sc，通过视图可以查询计算机系学生的成绩信息，包括学号，姓名、课程号，课程名、成绩。
create view v_sc as select sc.sno, sname, sc.cno, cname, grade from sc, student, course
    where sc.sno = student.sno and sc.cno = course.cno and sdept = '计算机系';

# 根据视图cj_student创建视图cj_tj，包含课程名，不及格人数，不及格人姓名列表（按姓名升序，以 | 分割），按照课程名降序排列。
create view cj_tj as select CNO, count(*), group_concat(SNAME order by SNAME separator '|')
    from cj_student group by CNO
    order by CNO desc;

# 建立视图is_student,视图中包含信息系全体学生的基本信息。（要求限制更新）
create view is_student as select * from student where SDEPT = '信息系' with check option ;

# 建立视图avg_cj，视图包括学生的学号以及他们的平均成绩(取整)，按成绩降序排列。
create view avg_cj as select SNO, round(avg(GRADE)) from sc
    group by SNO order by 2 desc;

# 建立视图cj_student,视图中包含所有成绩不及格(含没有成绩)的学生的学号，姓名，课程名，成绩，按成绩降序排序。
create view cj_student as select sc.SNO, SNAME, CNAME, GRADE from sc
    left join student s on s.SNO = sc.SNO
    left join course c on c.CNO = sc.CNO
    where GRADE < 60 or GRADE is null
    order by GRADE desc ;

# 建立计算机系学生信息视图v_student_c，通过视图可以查看sno,sname,sage。
create view v_student_c as select sno, sname, sage from student
    where sdept = '计算机系';
