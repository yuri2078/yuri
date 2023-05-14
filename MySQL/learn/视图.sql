CREATE OR REPLACE VIEW student_view AS SELECT * from db_student.student where ssex = '女'; -- 创建视图
SHOW CREATE VIEW student_view; -- 查看创建视图语句
SELECT * FROM student_view; -- 查询视图数据

/* 修改视图 */
CREATE OR REPLACE VIEW student_view AS SELECT sno, sname from db_student.student where ssex = '女'; -- 修改视图
ALTER VIEW student_view AS SELECT * FROM db_student.student; -- 修改视图


DROP VIEW IF EXISTS student_view; -- 删除视图

SELECT sc.sno, sname, sc.cno, course.cname FROM student, sc, course where sc.sno = student.sno and sc.cno = course.cno;


