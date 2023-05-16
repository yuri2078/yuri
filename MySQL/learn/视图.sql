CREATE OR REPLACE VIEW student_view AS SELECT * from db_student.student where ssex = '女'; -- 创建视图
SHOW CREATE VIEW student_view; -- 查看创建视图语句
SELECT * FROM student_view; -- 查询视图数据

/* 修改视图 */
CREATE OR REPLACE VIEW student_view AS SELECT sno, sname from db_student.student where ssex = '女'; -- 修改视图
ALTER VIEW student_view AS SELECT * FROM db_student.student; -- 修改视图


DROP VIEW IF EXISTS student_view; -- 删除视图

SELECT sc.sno, sname, sc.cno, course.cname FROM student, sc, course where sc.sno = student.sno and sc.cno = course.cno;


/* 存储过程 */

-- 创建存储过程
CREATE PROCEDURE count_stu()
BEGIN
    SELECT COUNT(*) from db_student.student;
END;

CALL count_stu(); -- 调用存储过程

-- 查看系统表中的存储过程
SELECT * FROM information_schema.ROUTINES WHERE ROUTINE_SCHEMA = 'db_student';

DROP PROCEDURE IF EXISTS count_stu; -- 删除存储过程


/* 系统变量 */
SHOW [GLOBAL | SESSION] VARIABLES; -- 查看所有系统变量的值
-- 不指定默认SESSION会话变量
SHOW GLOBAL VARIABLES; -- 查看所有全局变量
SHOW SESSION VARIABLES; -- 查看所有会话变量
SHOW VARIABLES LIKE 'variable_name'; -- 模糊搜索变量名
SELECT @@activate_all_roles_on_login; -- 查看指定变量名
/* 重启后变量仍任会除非修改配置文件 */
SET [GLOBAL | SESSION].系统变量名 = 值; -- 设置系统变量名
SET @@GLOBAL.activate_all_roles_on_login = 0; -- 设置系统变量名

/* 用户变量 */
set @my_name = 'yuri'; -- 等号赋值
set @my_age := 20; -- := 赋值
select @java := 'java', @python := 'python'; -- 多个参数赋值
select @my_name, @my_age, @java, @python; -- 打印值

select count(*) into @count_st from db_student.student; -- 通过查询结果赋值


/* 局部变量 */



