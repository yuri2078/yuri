USE mysql;
SELECT * from user; -- 查询用户
CREATE USER 'yuri'@'localhost'  IDENTIFIED by 'yuri'; 
-- 创建只能在localhost 访问的 密码为 yuri 的用户 yuri 
-- 默认没有任何权限
-- @'%' 表示可以在任意主机访问数据库

ALTER user 'yuri'@'localhost' IDENTIFIED WITH mysql_native_password by  'yuri2078';
-- 修改 用户的密码为 yuri2078 
-- 密码类型为 mysql_native_password

DROP USER 'yuri'@'localhost'; -- 删除用户



/* mysql 权限管理 */
-- ALL 所有权限
-- SELECT 查询权限
-- INSERT 插入数据权限
-- UPDATE 更新数据权限
-- DELETE 删除数据权限
-- ALTER 修改表权限
-- DROP 删除 数据库/表/视图权限
-- CREATE 创建数据库/表/视图权限


SHOW GRANTS FOR 'yuri'@'localhost'; -- 展示所有权限
GRANT SELECT, CREATE  ON yuri.db_student TO 'yuri'@'localhost'
REVOKE UPDATE ON *.* FROM 'yuri'@'localhost';
-- 授予/撤销 用户权限
-- select .. 权限列表
-- ON 数据库名.表名 如果是所有就写*

