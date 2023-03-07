
/* db—student 数据库创建 */
CREATE DATABASE 
    if NOT EXISTS db_student -- 如果数据库不存在
    CHARSET utf8mb4; -- 设置字符集

USE db_student; -- 使用数据库

-- 创建表格如果表格不存在
CREATE TABLE IF NOT EXISTS db_student.student (
    sno   CHAR(7)  PRIMARY KEY COMMENT '学号',
    sname CHAR(10) NOT NULL COMMENT '姓名',
    ssex  CHAR(2)  COMMENT '性别', 
    sage  SMALLINT COMMENT '年龄',
    sdept VARCHAR(20) DEFAULT '计算机系' COMMENT '所在系'
);
CREATE TABLE IF NOT EXISTS db_student.course (
    cno   CHAR(10)  PRIMARY KEY COMMENT '课程号',
    cname VARCHAR(20) NOT NULL COMMENT '课程名',
    ccredit  SMALLINT COMMENT '学分', 
    semster  SMALLINT COMMENT '学期',
    period SMALLINT COMMENT '学时' 
);

CREATE TABLE IF NOT EXISTS db_student.sc (
    sno   CHAR(7) COMMENT '学号' ,
    cno   CHAR(10) COMMENT '课程号',
    grade SMALLINT COMMENT '成绩',
    FOREIGN KEY(sno) REFERENCES student(sno),
    FOREIGN KEY(cno) REFERENCES course(cno)
);

/* db-spj 数据库创建 */

CREATE DATABASE 
    IF NOT EXISTS db_spj
    CHARSET utf8mb4;

CREATE TABLE IF NOT EXISTS db_spj.s (
    sno CHAR(6) PRIMARY KEY COMMENT '供应商号',
    sname VARCHAR(20) NOT NULL COMMENT '供应商名',
    status VARCHAR(50) COMMENT '供应商状态',
    city VARCHAR(50) COMMENT '所在城市'
);

CREATE TABLE IF NOT EXISTS db_spj.p (
    pno CHAR(6) PRIMARY KEY COMMENT '零件号',
    pname VARCHAR(20) NOT NULL COMMENT '零件名',
    color CHAR(2) COMMENT '颜色',
    weight DECIMAL(9,2) COMMENT '重量'
);

CREATE TABLE IF NOT EXISTS db_spj.j (
    jno CHAR(6) PRIMARY KEY COMMENT '项目号',
    jname VARCHAR(20) NOT NULL COMMENT '项目名',
    city VARCHAR(50) COMMENT '城市'
);

CREATE TABLE IF NOT EXISTS db_spj.spj (
    sno CHAR(6) NOT NULL COMMENT '供应商号',
    pno CHAR(6) NOT NULL COMMENT '零件号',
    jno CHAR(6) NOT NULL COMMENT '项目号',
    qty SMALLINT DEFAULT 100 COMMENT '供应数量'
);

ALTER TABLE db_spj.p ADD guige CHAR(50) COMMENT '规格';

ALTER Table db_student.course MODIFY COLUMN cname VARCHAR(30) NOT NULL COMMENT '课程名';
ALTER Table db_spj.spj ADD FOREIGN KEY(sno) REFERENCES s(sno);
ALTER Table db_spj.spj ADD FOREIGN KEY(pno) REFERENCES p(pno);
ALTER Table db_spj.spj ADD FOREIGN KEY(jno) REFERENCES j(jno);

ALTER Table db_spj.p DROP guige;

ALTER Table db_spj.spj ADD id INT AUTO_INCREMENT PRIMARY KEY;

INSERT INTO db_spj.s (
    sno, sname, status, city
) VALUES (
    'S1', '精益', 20, '天津'
), (
    'S2', '盛锡', 10, '北京'
);

INSERT INTO db_spj.s SET
    sno = 'S1',
    sname = '东方红',
    status = 30,
    city = '北京'
;
-- 插入数据报错,因为 sno 是 PRIMARY KEY 不允许重复

INSERT INTO db_spj.p (
    pno, pname, color, weight
) VALUES (
    'P1', '螺母', '红',	12
), (
    'P2', '螺栓', '绿',	17
), (
    'P3', '螺丝', '黑',	105.5
);
-- 没有报错，能够正常插入数据

INSERT INTO db_spj.j (
    jno, jname, city
) VALUES (
    'J1', '一汽', '北京'
), (
    'J2', '半导体厂', '南京'
), (
    'J3', NULL, '常州' 
);
-- j3报错 因为 janme 不能是NULL

INSERT INTO db_spj.spj (
    sno, pno, jno, qty
) VALUES (
    'S1', 'P1',	'J1', 200	
), (
    'S1', 'P1',	'J1', NULL
), (
    'S2', 'P2',	'J4', NULL
);

-- 插入报错因为 sno pno jno 受前三个表中数据约束
-- 如果j表插入报错   那么 jno 中不存在 j1 和 j4
-- 如果j表插入没报错 那么 jno 中不存在 j4

