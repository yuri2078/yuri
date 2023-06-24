# mysql  数据库基础





## mysql 登陆

```bash
mysql -h hostname -u username -p
```

其中：

- `-h`：表示连接的主机名或 IP 地址；
- `-u`：表示登录的用户名；
- `-p`：表示登录密码，同时也会提示你输入密码

## SQL 语句分类

### DDL 语句

> 数据定义语言 (DDL)：Data Definition Language，用于创建、更新或删除数据库中的表和其他对象，如 `CREATE`, `ALTER` 

1. `CREATE`

   用于在数据库中创建新的表、视图、索引或存储过程。

   示例：创建一个名为 `students` 的表，包含 `id`、`name`、`age` 三列的数据。

   ```sql
   CREATE TABLE students (
       id INT NOT NULL,
       name VARCHAR(20) NOT NULL,
       age INT NOT NULL,
       PRIMARY KEY (id)
   );
   ```

2. `ALTER`

   用于修改数据库中的表、视图、索引或存储过程。

   示例：向 `students` 表中添加一列 `gender`。

   ```sql
   ALTER TABLE students ADD COLUMN gender VARCHAR(10); #添加列
   ALTER TABLE student ADD PRIMARY KEY (sno); #给student 添加主键
   ALTER TABLE student DROP PRIMARY KEY; #删除student 的主键
   ```

3. `DROP`

   用于删除数据库中的表、视图、索引或存储过程。

   示例：删除 `students` 表。

   ```sql
   DROP TABLE students;
   ```

4. `TRUNCATE`

   用于删除表中的所有行，但不删除表本身。

   示例：删除 `students` 表中的所有数据。

   ```sql
   TRUNCATE TABLE students;
   ```

5. `COMMENT`

   用于给数据库中的对象（如表、列等）添加注释信息。

   示例：给 `students` 表中的 `id` 列添加注释。

   ```sql
   COMMENT ON COLUMN students.id IS '学生编号';
   ```

6. `RENAME`

   用于重命名数据库中的表、视图、索引或存储过程。

   示例：将 `students` 表重命名为 `new_students`。

   ```sql
   RENAME TABLE students TO new_students;
   ```

7. `GRANT`

   用于授权其他用户对数据库中的对象进行访问、修改、删除等操作权限。

   示例：将 `students` 表的 `INSERT` 权限授予给 `user1` 用户。

   ```sql
   GRANT INSERT ON students TO user1;
   # 将查询SC 表的权限授予用户U1，并允许该用户将此权限授予其他用户。实现此功能的SQL
   GRANT SEIECT ON SC TO U1 WITH GRANT OPTION
   ```

8. `REVOKE`

   用于收回其他用户对数据库中的对象的操作权限。

   示例：收回 `user1` 用户对 `students` 表的 `INSERT` 权限。

   ```sql
   REVOKE INSERT ON students FROM user1;
   ```

### DML 语句

> 数据操纵语言 (DML)：Data Manipulation Language，用于操纵表中的数据，如 `SELECT`, `INSERT`, `UPDATE` 和 `DELETE`。

1. `SELECT`

   用于从数据库中查询数据。

   示例：查询 `students` 表中所有学生的信息。

   ```sql
   SELECT * FROM students;
   ```

2. `INSERT`

   用于向数据库中插入新的数据。

   示例：向 `students` 表中插入一条新的学生信息。

   ```sql
   INSERT INTO students (id, name, age) VALUES (1, '张三', 20);
   ```

3. `UPDATE`

   用于修改数据库中已有的数据。

   示例：将 `students` 表中学号为 1 的学生姓名修改为 '李四'。

   ```sql
   UPDATE students SET name = '李四' WHERE id = 1;
   ```

4. `DELETE`

   用于删除数据库中已有的数据。

   示例：删除 `students` 表中学号为 1 的学生信息。

   ```sql
   DELETE FROM students WHERE id = 1;
   ```

5. `MERGE`

   可以根据指定条件判断是否进行插入或更新操作。

   示例：向 `students` 表中插入一条新的学生信息，如果该学生已存在，则更新其信息。

   ```sql
   MERGE INTO students s
   USING (SELECT 1 id, '张三' name, 20 age FROM dual) t
   ON (s.id = t.id)
   WHEN MATCHED THEN
     UPDATE SET s.name = t.name, s.age = t.age
   WHEN NOT MATCHED THEN
     INSERT (id, name, age) VALUES (t.id, t.name, t.age);
   ```

### DQL 语句

> 数据查询语言 (DQL)：Data Query Language，用于查询表中的数据，如 `SELECT` 和 `FROM`。

1. `SELECT`

   用于从数据库中查询数据。

   示例：查询 `students` 表中所有学生的信息。

   ```sql
   SELECT * FROM students;
   ```

2. `INSERT INTO`

   用于向数据库中插入新的数据。

   示例：向 `students` 表中插入一条新的学生信息。

   ```sql
   INSERT INTO students (id, name, age) VALUES (1, '张三', 20);
   ```

3. `UPDATE`

   用于修改数据库中已有的数据。

   示例：将 `students` 表中学号为 1 的学生姓名修改为 '李四'。

   ```sql
   UPDATE students SET name = '李四' WHERE id = 1;
   ```

4. `DELETE`

   用于删除数据库中已有的数据。

   示例：删除 `students` 表中学号为 1 的学生信息。

   ```sql
   DELETE FROM students WHERE id = 1;
   ```

5. `CREATE TABLE`

   用于创建新的数据库表格。

   示例：在数据库中创建一个名为 `courses` 的表格。

   ```sql
   CREATE TABLE courses (
       id INT PRIMARY KEY,
       name VARCHAR(20),
       teacher VARCHAR(20),
       credit FLOAT
   );
   ```

6. `ALTER TABLE`

   用于修改数据库表格结构。

   示例：向 `courses` 表中添加一列 `category`。

   ```sql
   ALTER TABLE courses ADD category VARCHAR(20);
   ```

7. `DROP TABLE`

   用于删除已有的数据库表格。

   示例：删除 `courses` 表格。

   ```sql
   DROP TABLE courses;
   ```

### DCL 语句

>  DCL（数据控制语言）是 SQL 中用于控制数据访问权限和安全性的指令集。以下是其中几个常用的 DCL 指令的解析：

GRANT

`GRANT` 用于向某个用户或用户组授予特定的权限，例如 SELECT、INSERT、UPDATE 或 DELETE。

语法：`GRANT privilege_name ON object_name TO {user_name | public | role_name};`

示例：

```sql
GRANT SELECT, INSERT ON my_table TO user1;
```

上述代码为 user1 授予 my_table 表的 SELECT 和 INSERT 权限。

REVOKE

`REVOKE` 用于撤销一条或多条用户或用户组的权限。

语法：`REVOKE privilege_name ON object_name FROM {user_name | public | role_name};`

示例：

```sql
REVOKE SELECT ON my_table FROM user1;
```

上述代码为 user1 取消 my_table 表的 SELECT 权限。

DENY

`DENY` 用于拒绝一条或多条用户或用户组的权限。

语法：`DENY privilege_name ON object_name TO {user_name | public | role_name};`

示例：

```sql
DENY INSERT ON my_table TO user1;
```

上述代码拒绝 user1 在 my_table 表上执行 INSERT 操作。

 CREATE USER

`CREATE USER` 用于创建一个新用户。

语法：`CREATE USER user_name [IDENTIFIED BY password];`

示例：

```sql
CREATE USER user1 IDENTIFIED BY 'passw0rd';
```

上述代码创建一个名为 user1 的新用户，并将密码设置为 "passw0rd"。

ALTER USER

`ALTER USER` 用于更改现有用户的权限或密码。

语法：`ALTER USER user_name [IDENTIFIED BY [CURRENT_PASSWORD] new_password];`

示例：

```sql
ALTER USER user1 IDENTIFIED BY 'new_passw0rd';
```

上述代码更改 user1 用户的密码为 "new_passw0rd"。

注意，有些数据库管理系统可能会在 `ALTER USER` 命令中支持更多选项。因此，在使用此命令时，应查阅特定系统的文档以查看所有可用选项

#### 示例

> 创建超级用户admin，具有对所有数据库的所有访问权限，仅限本机连接（密码自行设置），并验证用户和权限设置是否正确

```sql
CREATE USER 'admin'@'localhost' IDENTIFIED by 'admin'; -- 新建用户
GRANT ALL PRIVILEGES ON *.* TO 'admin'@'localhost'; -- 授予权限
SHOW GRANTS FOR 'admin'@'localhost'; -- 检查权限
```

```sql
/* ）创建管理员teacher_liu，具有对SC表、IS_STUDENT视图（实验5创建）的增删改查权限，并且具有授权的权限，
允许从任意位置连接（密码自行设置），并验证用户和权限设置是否正确。 */
CREATE USER 'teacher_liu'@'%' IDENTIFIED by 'test'; -- 新建用户
GRANT INSERT, DELETE, UPDATE, SELECT ON SC, IS_STUDENT TO 'teacher_liu'@'%'; -- 授予增删改查权限
GRANT GRANT OPTION ON *.* TO 'teacher_liu'@'%'; -- 授予 授予权限 权限
SHOW GRANTS FOR 'teacher_liu'@'%';
```



## 常用语句

### SHOW

1. `SHOW DATABASES`

   用于显示 MySQL 数据库中所有可用的数据库。

   格式：`SHOW DATABASES;`

   示例：

   ```sql
   SHOW DATABASES;
   ```

   输出：

   ```sql
   +--------------------+
   | Database           |
   +--------------------+
   | information_schema |
   | mysql              |
   | performance_schema |
   | sys                |
   | test_db            |
   +--------------------+
   ```

2. `SHOW TABLES`

   用于显示数据库中所有可用的表格。

   格式：`SHOW TABLES;`

   示例：

   ```sql
   SHOW TABLES;
   ```

   输出：

   ```
   +----------------------+
   | Tables_in_test_db     |
   +----------------------+
   | customers            |
   | orders               |
   | products             |
   +----------------------+
   ```

3. `SHOW COLUMNS`

   用于显示表格中的列信息。

   格式：`SHOW COLUMNS FROM table_name;`

   示例：

   ```sql
   SHOW COLUMNS FROM customers;
   ```

   输出：

   ```
   +---------+-------------+------+-----+---------+----------------+
   | Field   | Type        | Null | Key | Default | Extra          |
   +---------+-------------+------+-----+---------+----------------+
   | id      | int         | NO   | PRI | NULL    | auto_increment |
   | name    | varchar(50) | YES  |     | NULL    |                |
   | email   | varchar(50) | YES  |     | NULL    |                |
   | country | varchar(50) | YES  |     | NULL    |                |
   +---------+-------------+------+-----+---------+----------------+
   ```

4. `SHOW INDEX`

   用于显示表格中的索引信息。

   格式：`SHOW INDEX FROM table_name;`

   示例：

   ```sql
   SHOW INDEX FROM customers;
   ```

   输出：

   ```
   +-----------+------------+-----------+--------------+-------------+-----------+-------------+----------
   | Table     | Non_unique | Key_name  | Seq_in_index | Column_name | Collation | Cardinality | Sub_part 
   +-----------+------------+-----------+--------------+-------------+-----------+-------------+----------
   | customers |          0 | PRIMARY   |            1 | id          | A         |           3 |     NULL 
   | customers |          1 | email_idx |            1 | email       | A         |           3 |     NULL 
   +-----------+------------+-----------+--------------+-------------+-----------+-------------+----------
   ```

   注意：`SHOW INDEX` 关键字仅在 MySQL/MariaDB 数据库系统中可用。在 Oracle 和 SQL Server 等其他数据库管理系统中，请查看相应的文档来了解它们使用的特定指令

### ALTER 

> `ALTER` 指令用于修改已存在的数据库表结构。

以下是 `ALTER` 指令的格式及详细信息：

1. `ALTER TABLE ADD COLUMN`

   用于向表中添加新的列。

   格式：`ALTER TABLE table_name ADD COLUMN column_name data_type;`

   示例：

   ```sql
   ALTER TABLE customers ADD COLUMN phone VARCHAR(20);
   ```

   注意: `ADD COLUMN` 子句是风格最为统一和约定俗成的。但是因为支持数据库管理系统的差异，实际使用时应该先查看相应的文档来学习具体语法。

2. `ALTER TABLE MODIFY COLUMN`

   用于修改表中已有的列的数据类型和约束。

   格式：`ALTER TABLE table_name MODIFY COLUMN column_name new_data_type;`

   示例：

   ```sql
   ALTER TABLE customers MODIFY COLUMN email VARCHAR(50) NOT NULL;
   ```

   注意：`MODIFY COLUMN` 用于修改数据类型，还有其他选项，如 `DEFAULT` 和 `NOT NULL` 等。

3. `ALTER TABLE DROP COLUMN`

   用于删除表中的列。

   格式：`ALTER TABLE table_name DROP COLUMN column_name;`

   示例：

   ```sql
   ALTER TABLE customers DROP COLUMN phone;
   ```

4. `ALTER TABLE RENAME TO`

   用于修改数据库表的名称。

   格式：`ALTER TABLE old_table_name RENAME TO new_table_name;`

   示例：

   ```sql
   ALTER TABLE customers RENAME TO clients;
   ```

5. `ALTER TABLE ADD CONSTRAINT`

   用于添加表中新的约束。

   格式：`ALTER TABLE table_name ADD CONSTRAINT constraint_name constraints_definition;`

   示例：

   ```sql
   ALTER TABLE orders ADD CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES customers (id);
   ```

   注意：`ADD CONSTRAINT` 用于添加任何类型的约束。它可以增加唯一性约束、外键约束、主键约束或检查约束等

### DROP 

> `DROP` 指令用于删除数据库中的对象，比如表、索引、数据列等。

以下是 `DROP` 指令的格式及详细信息：

1. `DROP TABLE`

   用于删除数据库中的一个表。

   格式：`DROP TABLE table_name;`

   示例：

   ```sql
   DROP TABLE customers;
   ```

2. `DROP INDEX`

   用于删除数据库中的一个索引。

   格式：`DROP INDEX index_name ON table_name;`

   示例：

   ```sql
   DROP INDEX email_idx ON customers;
   ```

3. `DROP COLUMN`

   用于删除表中的一个列。

   格式：`ALTER TABLE table_name DROP COLUMN column_name;`

   示例：

   ```sql
   ALTER TABLE customers DROP COLUMN phone;
   ```

4. `DROP CONSTRAINT`

   用于删除表中的一个约束。

   格式：`ALTER TABLE table_name DROP CONSTRAINT constraint_name;`

   示例：

   ```sql
   ALTER TABLE orders DROP CONSTRAINT fk_customer;
   ```

5. `DROP VIEW`

   用于删除一个视图。

   格式：`DROP VIEW view_name;`

   示例：

   ```sql
   DROP VIEW customer_view;
   ```

6. `DROP FUNCTION`

   用于删除一个函数。

   格式：`DROP FUNCTION function_name;`

   示例：

   ```sql
   DROP FUNCTION calculate_discount;
   ```

7. `DROP PROCEDURE`

   用于删除一个存储过程。

   格式：`DROP PROCEDURE procedure_name;`

   示例：

   ```sql
   DROP PROCEDURE get_customer_orders;
   ```

## DQL 语句执行顺序

执行顺序如下：

1. FROM 子句

   在执行查询前，需要指定要从哪个表中获取数据。这是通过 FROM 子句来实现的。

2. JOIN 子句

   如果在查询中使用了 JOIN 子句来联接多张表，则需要在 FROM 子句后使用 JOIN 子句。

3. WHERE 子句

   一旦指定了要查询的表和任何联接操作，WHERE 子句就会用于筛选表中的数据。

4. GROUP BY 子句

   如果查询需要按一个或多个列来分组数据，则可以使用 GROUP BY 子句。

5. HAVING 子句

   如果需要在已分组的数据上进一步筛选数据，则可以使用 HAVING 子句。

6. SELECT 子句

   完成了 WHERE、GROUP BY 和 HAVING 子句之后，可以使用 SELECT 子句来指定要返回的列。

7. ORDER BY 子句

   最后，可以使用 ORDER BY 子句以特定的方式对返回的数据进行排序。

注意，尽管 WHERE 和 HAVING 子句的作用相似，但 WHERE 子句在 GROUP BY 子句之前执行，而 HAVING 子句在 GROUP BY 子句之后执行。这就是为什么 HAVING 子句可以引用聚合函数（如 COUNT、SUM 等），而 WHERE 子句不行。

## 函数

### 字符串函数

1. `LENGTH(str)`：返回字符串 `str` 的字符数。
2. `LEFT(str, len)`：返回字符串 `str` 的前 `len` 个字符。
3. `RIGHT(str, len)`：返回字符串 `str` 的后 `len` 个字符。
4. `SUBSTRING(str, pos, len)`：返回字符串 `str` 从位置 `pos` 开始的长度为 `len` 的子字符串。
5. `CONCAT(str1, str2, ..., strN)`：将多个字符串连接为���个字符串。
6. `REPLACE(str, from_str, to_str)`：将字符串 `str` 中的所有 `from_str` 替换为 `to_str`。
7. `UCASE(str)` 或 `UPPER(str)`：将字符串 `str` 转换为大写字母。
8. `LCASE(str)` 或 `LOWER(str)`：将字符串 `str` 转换为小写字母。
9. `TRIM([{BOTH | LEADING | TRAILING} [trim_str] FROM] str)`：从字符串 `str` 的开头和结尾删除指定的 `trim_str` 字符。如果未指定 `trim_str`，则删除空格。
10. `LPAD(str, len, pad_str)`：使用 `pad_str` 在左侧填充字符串 `str`，使其成为长度为 `len` 的字符串。
11. `RPAD(str, len, pad_str)`：使用 `pad_str` 在右侧填充字符串 `str`，使其成为长度为 `len` 的字符串。

```sql
SELECT LENGTH('Hello, World!');-- 计算字符串长度
SELECT LEFT('Hello, World!', 3);-- 返回字符串的前三个字符
SELECT RIGHT('Hello, World!', 6);-- 返回字符串中的第6个字符及其后面的所有字符
SELECT SUBSTRING('Hello, World!', 8, 4);-- 返回字符串中从第8个字符开始的4个字符
SELECT CONCAT('Hello', ', ', 'World', '!');-- 连接多个字符串
SELECT REPLACE('Hello, World!', ',', '.');-- 将字符串中的所有逗号替换为句号
SELECT UPPER('Hello, World!');-- 转换字符串为大写字符
SELECT TRIM('   Hello, World!   ');-- 从字符串中删除开头和结尾的空格字符
SELECT LPAD('1234', 10, '0');-- 在字符串的左侧填充零，使其成为长度为10的字符串
SELECT RPAD('Hello', 20, ' ');-- 在字符串的右侧填充空格，使其成为长度为20的字符串
```

### 数值函数

1. `ABS(x)`：返回 x 的绝对值。
2. `CEILING(x)` 或 `CEIL(x)`：返回不小于 x 的最小整数。
3. `FLOOR(x)`：返回不大于 x 的最大整数。
4. `ROUND(x)`：将 x 四舍五入为最接近的整数。
5. `TRUNCATE(x, d)`：将 x 截断为 d 位小数。
6. `MOD(x, y)` 或 `%`：返回 x 除以 y 的余数。
7. `POW(x, y)` 或 `POWER(x,y)`：返回 x 的 y 次幂。

```sql
SELECT ABS(-10);-- 返回-10的绝对值
SELECT CEIL(2.5);-- 返回不小于2.5的最小整数
SELECT FLOOR(2.5);-- 返回不大于2.5的最大整数
SELECT ROUND(3.7);-- 将3.7四舍五入为最接近的整数
SELECT TRUNCATE(3.746, 2);-- 将3.746截断为2位小数
SELECT MOD(10, 3);-- 返回10除以3的余数
SELECT POW(2, 3);-- 返回2的3次幂
```



### 日期函数

1. `NOW()`：返回当前日期和时间。

2. `CURDATE()`：返回当前日期。

3. `CURTIME()`：返回当前时间。

4. `DATE_FORMAT(date, format)`：将日期格式化为特定的字符串格式。

5. `DATE_ADD(date, INTERVAL expr unit)`：向日期添加指定的时间间隔。

6. `DATE_SUB(date, INTERVAL expr unit)`：从日期中减去指定时间间隔。

7. `DATEDIFF(date1, date2)`：计算两个日期之间的天数。

8. ```sql
   SELECT NOW();-- 返回当前日期和时间
   SELECT CURDATE();-- 返回当前日期
   SELECT CURTIME();-- 返回当前时间
   SELECT DATE_FORMAT(NOW(), '%Y-%m-%d');-- 将日期格式化为 'YYYY-MM-DD' 形式
   SELECT DATE_FORMAT(NOW(), '%Y年%m月%d日');-- 将日期格式化为 'YYYY年M月D日' 形式
   SELECT DATE_ADD(NOW(), INTERVAL '2 3:00:00' DAY_SECOND);-- 在日期上添加2天和3小时
   SELECT DATE_SUB(NOW(), INTERVAL 1 MONTH);-- 从日期中减去1个月
   SELECT DATEDIFF('2022-01-01', '2021-12-15');-- 计算两个日期之间的天数
   ```

### 流程函数

1. `IF(condition, if_true, if_false)`：如果 condition 为真，则返回 if_true，否则返回 if_false。
2. `CASE expression WHEN value THEN result [WHEN ...] [ELSE default] END`：根据 expression 的结果返回对应的 result，如果没有匹配，则返回 default。
3. `NULLIF(expr1, expr2)`：如果 expr1 等于 expr2，则返回 NULL，否则返回 expr1。
4. `COALESCE(expr1, expr2, ...)`：返回第一个非 NULL 表达式的值。

```sql
-- 如果 score > 60，则返回 '及格'，否则返回 '不及格'
SELECT IF(score > 60, '及格', '不及格') as result FROM student;

-- 根据 score 的值返回不同的分数段
SELECT CASE WHEN score >= 90 THEN '优秀'
            WHEN score >= 80 THEN '良好'
            WHEN score >= 70 THEN '一般'
            WHEN score >= 60 THEN '及格'
            ELSE '不及格' END as result FROM student;

-- 如果 name 等于 'Tom'，则返回 NULL，否则返回 name
SELECT NULLIF(name, 'Tom') as result FROM student;

-- 返回第一个非 NULL 的值
SELECT COALESCE(phone, email, address) as contact FROM student;
```

## 约束

### PRIMARY KEY 约束

在 SQL 语句中创建 PRIMARY KEY 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype PRIMARY KEY,
  ...
);
```

例如，创建一个名为 users 的表，其中 id 列是主键：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  email VARCHAR(100)
);
```

使用 PRIMARY KEY 约束会确保 id 列的值唯一。此外，主键列还可以被用于创建 FOREIGN KEY 约束。

### FOREIGN KEY 约束

在 SQL 语句中创建 FOREIGN KEY 约束的语法为：

```sql
CREATE TABLE table_name1 (
  column1 datatype1,
  column2 datatype2,
  ...,
  FOREIGN KEY (column1) REFERENCES table_name2(columnX)
);
```

例如，创建一个名为 orders 的表，其中 customer_id 列是引用 customers 表的主键 id 的外键：

```sql
CREATE TABLE orders (
  id INT PRIMARY KEY,
  order_number VARCHAR(20),
  customer_id INT,
  FOREIGN KEY (customer_id) REFERENCES customers(id)
);
```

使用 FOREIGN KEY 约束来创建两个表之间的关联，可以确保数据的一致性和完整性。例如，如果 customers 表中的 id 列被删除，那么 orders 表中的与之对应的 customer_id 列也会被删除。

#### 更新删除行为

在创建一个外键约束时，你需要指定更新和删除行为，以决定当关联表的主键发生变化时应如何更新或删除与其相关的外键行。常用的更新和删除行为有以下几种：

1. `CASCADE`：即级联，当关联表中的主键发生变化时，相关的外键行也会被更新或删除。例如，当 customers 表中的某个记录被删除时，orders 表中与之相关的 customer_id 列的外键行也会被删除。
2. `SET NULL`：即将外键列设置为 NULL。当关联表中的主键发生变化时，相关的外键行中的外键列都会被设为 NULL。例如，当 customers 表中的某个记录被删除时，orders 表中与之相关的 customer_id 列的外键列都会被设为 NULL。
3. `RESTRICT`：即限制，当关联表中的主键发生变化时，外键行依赖其变化而无法更新或删除。例如，当尝试删除某个 customers 表中的记录时，如果其与 orders 表中的某些记录出现了引用关系，那么该删除操作就会被限制。
4. `NO ACTION`：当关联表中的主键发生变化时，不采取任何行动。这个行为和 RESTRICT 一样，并且是一些数据库系统默认的行为。

以下是一个在 SQL 中实现 `CASCADE` 更新和删除行为的例子：

```sql
-- 在 customers 表的 id 列上创建主键
CREATE TABLE customers (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  email VARCHAR(100)
);

-- 在 orders 表的 customer_id 列上创建外键，并指定 CASCADE 更新和删除行为
CREATE TABLE orders (
  order_number VARCHAR(20) PRIMARY KEY,
  customer_id INT,
  FOREIGN KEY (customer_id) REFERENCES customers(id)
    ON UPDATE CASCADE
    ON DELETE CASCADE
);
```

#### 更新外界约束

可以使用 ALTER TABLE 语句来更新外键约束，并指定新的级联规则。下面是一个例子，将 orders 表中 customer_id 外键的级联更新规则从 CASCADE 改为 SET NULL：

```sql
ALTER TABLE orders
DROP FOREIGN KEY fk_orders_customers;

ALTER TABLE orders ADD CONSTRAINT fk_orders_customers
FOREIGN KEY (customer_id) REFERENCES customers(id)
ON UPDATE SET NULL ON DELETE SET NULL;
```

在 SQL 中，如果想要更新外键约束的级联规则，必须先删除原有的外键约束，然后使用 ADD CONSTRAINT 语句重新创建新的约束。在创建新的约束时，需要指定新的级联规则，将 ON UPDATE 和 ON DELETE 参数设置为新的规则。如上面的代码所示，我们使用 SET NULL 作为新的级联规则。

### NOT NULL 约束

在 SQL 语句中创建 NOT NULL 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype NOT NULL,
  column2 datatype,
  column3 datatype,
  ...
);
```

例如，要求创建一个名为 users 的表，其中 name 和 email 列不能为空：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50) NOT NULL,
  age INT,
  email VARCHAR(100) NOT NULL
);
```

使用 NOT NULL 约束可以限制列不能有 NULL 值。在上面的例子中，如果尝试向 users 表中插入一个带有 NULL name 或 NULL email 的行，会导致错误。

### UNIQUE 约束

在 SQL 语句中创建 UNIQUE 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype,
  column2 datatype,
  column3 datatype,
  ...,
  UNIQUE (column1, column2, ...),
  ...
);
```

例如，创建名为 users 的表，其中 email 列的值必须是唯一的：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  email VARCHAR(100) UNIQUE
);
```

使用 UNIQUE 约束可以保证列中所有的值都是唯一的。在此示例中，如果尝试向 users 表中插入一个带有已经存在的 email 的行，会导致错误。

### CHECK 约束

在 SQL 语句中创建 CHECK 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype,
  column2 datatype,
  column3 datatype,
  ...,
  CHECK (column1 > value),
  ...
);
```

例如，创建名为 users 的表，其中 age 列必须大于 18：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT CHECK (age > 18),
  email VARCHAR(100)
);
```

使用 CHECK 约束可以检查列中的值是否符合指定的条件。在此示例中，如果尝试向 users 表中插入一个 age 小于或等于 18 的行，会导致错误。

### DEFAULT 约束

在 SQL 语句中创建 DEFAULT 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype DEFAULT default_value,
  column2 datatype,
  column3 datatype,
  ...
);
```

例如，创建名为 users 的表，其中 age 列将默认值设置为 25：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT DEFAULT 25,
  email VARCHAR(100)
);
```

使用 DEFAULT 约束可以在插入数据时为列提供默认值。在此示例中，如果插入一行不包含 age 列，该列的值将自动设置为 25。

### INDEX 约束

在 SQL 语句中创建 INDEX 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype,
  column2 datatype,
  column3 datatype,
  ...,
  INDEX index_name (column1, column2, ...),
  ...
);
```

例如，创建名为 users 的表，并在名为 email 的列上创建索引：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  email VARCHAR(100),
  INDEX idx_email (email)
);
```

使用 INDEX 约束可以在列上创建索引，加快数据检索速度。

### AUTO_INCREMENT 约束

在 SQL 语句中创建 AUTO_INCREMENT 约束的语法为：

```sql
CREATE TABLE table_name (
  column1 datatype AUTO_INCREMENT,
  column2 datatype,
  column3 datatype,
  ...
);
```

例如，创建名为 users 的表，并将 id 列设置为自动递增：

```sql
CREATE TABLE users (
  id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(50),
  age INT,
  email VARCHAR(100)
);
```

使用 AUTO_INCREMENT 约束可以指定列的值自动递增，常用于表的主键中。在此示例中，每次插入一行都会自动为 id 列赋予一个唯一的递增值。

## 视图

> 在 MySQL 中，视图是基于一个或多个数据库表的查询结果可以看作是虚拟表的结果集。视图在创建时并不包含实际的数据，而是每次查询时动态生成数据，因此视图可以看作是一个动态查询结果的快照。视图与表类似，也有自己的结构和字段，可以用SELECT语句定义。不同的是，视图只是存储在数据库中的一个虚拟表，不存储逻辑数据。视图使用SELECT语句定义，查询语法与SELECT语句相似。使用视图可以简化复杂查询，并且可以通过视图控制对表的访问权限。

### 创建视图

在 MySQL 中，创建视图的基本语法如下：

```sql
CREATE [OR REPLACE] VIEW 视图名称[(列名列表)] AS SELECT语句 [WITH [CASCADED | LOCAL] CHECK OPTION] 
```

- `OR REPLACE` ： 指定创建或者替换一个视图，可以省略

```sql
CREATE VIEW view_name AS
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

其中，`view_name` 是视图的名称，`column1, column2, ...` 是视图的字段名，因为视图的字段岗位是根据 SELECT 语句中的查询结果自动生成的。`table_name` 是视图所基于的表名，可以是一个表或多张表的 JOIN 结果。 `condition` 是可选的，指定了基于哪些行创建视图。

以下是一个例子，创建了一个基于 employees 表的视图：

```sql
CREATE VIEW high_paid_employees AS
SELECT employee_id, first_name, last_name, salary
FROM employees
WHERE salary > 10000;
```

以上语句创建了一个名为 high_paid_employees 的视图，它包含 employee_id、first_name、last_name 和 salary 四个字段的数据。这个视图基于 employees 表，并只包含了薪水超过 10000 的员工的记录。

### 查询视图

如果要查看 MySQL 数据库中已经创建的视图，可以使用以下命令：

```sql
SHOW FULL TABLES IN database_name WHERE TABLE_TYPE LIKE 'VIEW';
```

其中，`database_name` 是数据库的名称，该命令将显示该数据库中的所有视图。

或者，可以直接用以下语句查看某个视图的创建语句：

```sql
SHOW CREATE VIEW view_name;
```

其中，`view_name` 是视图的名称。该语句将显示创建该视图的完整 SQL 语句。

查询视图数据 ： 

```sql
SELECT * FROM student_view; -- 视图名
```

### 修改视图

#### 方法一

```sql
CREATE OR REPLACE VIEW 视图名称[(列名列表)] AS SELECT语句 [WITH [CASCADED | LOCAL] CHECK OPTION] 
```

必须加上`OR REPLACE`

#### 方法二

在 MySQL 中，可以使用 `ALTER VIEW` 语句来修改已经存在的视图。`ALTER VIEW` 语句的语法如下：

```sql
ALTER VIEW view_name AS 
SELECT ...
FROM ...
WHERE ...;
```

其中，`view_name` 是要修改的视图的名称，`SELECT`、`FROM` 和 `WHERE` 子句是对视图的新查询规则。

例如，假设我们已经创建了一个名为 `high_paid_employees` 的视图，现在要将该视图的查询规则更改为显示所有的员工记录，我们可以使用以下命令：

```sql
ALTER VIEW high_paid_employees AS 
SELECT employee_id, first_name, last_name, salary
FROM employees;
```

上述命令将覆盖原来的视图定义，将查询规则更改为从 `employees` 表中选择 `employee_id`、`first_name`、`last_name` 和 `salary` 四个字段。

需要注意的是，如果视图被引用了，则修改视图的同时可能会对依赖该视图的查询产生影响，所以在修改视图之前需要谨慎考虑，确保修改不会对其他查询产生负面影响。

### 删除视图

```sql
DROP VIEW [IF EXISTS] 视图名称 视图名称
```

### 检查选项

> 我们如果直接向视图中插入数据他会直接将数据插入到基表中，但是如果我们视图只显示 id < 20 的数据，你插入id 为30的也会成功，但是这与我们在视图中插入数据的想法相悖，所以我们有了检查选项

#### WITH CASCADED CHECK OPTION

>  如果定义视图的查询条件被违反，则不允许将更新操作应用于该视图及其所有基础表。如果创建视图时不指定检查选项，则默认为不启用检查选项。

以下是使用 `WITH CASCADED CHECK OPTION` 检查选项创建视图的示例：

```sql
CREATE VIEW v_1 AS SELECT * FROM table WHERE id < 20; -- 没有check 约束
CREATE VIEW v_2 AS SELECT * FROM v_1 WHERE id > 10 WITH CHECK CASCADED OPTION; -- 递归检查不论上面有没有约束
CREATE VIEW v_3 AS SELECT * FROM v_2 WHERE id > 45;

INSERT INTO v_1 VALUES(30); -- 不论插入多少都会成功因为他没有加上约束
INSERT INTO v_2 VALUES(3); -- 插入失败，不满足 id > 10 的约束
INSERT INTO v_2 VALUES(30); -- 插入失败， 满如自己 id > 10 但是不满足他依赖的v_1 id < 20 的依赖
INSERT INTO v_3 VALUES(30); -- 插入失败， 自己不会检查， 但是他依赖的v_2 会检查 不满足v_2 的依赖
INSERT INTO v_3 VALUES(15); -- 插入成功， 自己不会检查， 并且满足他依赖的v_2 的条件
```

注意：

1. 他会向下检查所有视图条件 不论有没有加上check option 
2. 他会检查自己本身符合不符合条件
3. 如果不加检查选项他不会检查自身条件，但是会检查他所依赖视图的条件
4. 如果他所依赖的视图有 `CASCADED` 那么会顺带检查所有依赖的视图

#### WITH LOCAl CHECK OPTION

> `WITH LOCAL CHECK OPTION` 检查选项是用于创建可更新视图的一种约束条件，该选项比 `WITH CHECK OPTION` 更加严格。当使用 `WITH LOCAL CHECK OPTION` 检查选项创建视图时，它会检查在视图定义中使用的所有 WHERE 子句和 JOIN 子句是否能够保证视图中数据的约束条件。如果 WHERE 子句或 JOIN 子句无法约束视图中的行，则不允许向视图插入数据。

下面是使用 `WITH LOCAL CHECK OPTION` 创建一个视图的示例：

```sql
CREATE VIEW v_1 AS SELECT * FROM table WHERE id < 20;
CREATE VIEW v_2 AS SELECT * FROM v_1 WHERE id > 10 WITH CHECK LOCAL OPTION;
CREATE VIEW v_3 AS SELECT * FROM v_2 WHERE id > 45;

INSERT INTO v_1 VALUES(30); -- 不论插入多少都会成功因为他没有加上约束
INSERT INTO v_2 VALUES(3); -- 插入失败，不满足 自己 id > 10 的约束
INSERT INTO v_2 VALUES(30); -- 插入成功， 满如自己 id > 10 ，但是他的依赖 v_1 并没有检查选项，所以不检查
INSERT INTO v_3 VALUES(30); -- 插入成功， 自己不会检查，满足他所依赖的v_2
```

需要注意的是，`WITH LOCAL CHECK OPTION` 检查选项仅适用于对视图进行插入操作。对于更新或删除操作，视图的检查选项与其定义时的情况相同。此外，`WITH LOCAL CHECK OPTION` 检查选项只能应用于可更新的视图，即对基础表进行更新操作时能够影响视图的结果。

注意：

1. `local` 检查会检查自己
2. 他不会检查他所依赖的 但是并没有检查选项的视图

### 视图的更新 

在 MySQL 中，视图是虚拟表，它并不存储数据，而是基于基础表动态生成数据。因此，在视图上进行的更新操作实际上将会对基础表进行更新。下面我们将介绍如何在 MySQL 中更新视图。

对于可更新的视图，我们可以使用 `UPDATE` 命令更新视图中的数据，语法如下：

```sql
UPDATE view_name SET column_name = new_value WHERE condition;
```

其中，`view_name` 是要更新的视图的名称，`column_name` 是要更新的列的名称，`new_value` 是要更新的新值，`condition` 是要更新的行的条件。

需要注意的是，当我们更新视图中的数据时，MySQL 将会自动更新基础表中对应的数据。此外，如果更新操作违反基础表中的任何约束条件，MySQL 将会像更新普通表一样返回错误。

我们也可以通过 `DELETE` 命令来删除视图中的数据，语法如下：

```sql
DELETE FROM view_name WHERE condition;
```

其中，`view_name` 是要删除数据的视图的名称，`condition` 是要删除的行的条件。

需要注意的是，当我们删除视图中的数据时，MySQL 将会自动删除基础表中对应的数据。此外，如果删除操作违反基础表中的任何约束条件，MySQL 将会像删除普通表一样返回错误。

需要特别注意的是，不是所有的视图都是可更新的。可更新的视图必须符合一些限制，例如：

- 视图中必须至少包含来自一个表的一列可更新列；
- 视图中不能包含以下任何一项：`DISTINCT`、`GROUP BY`、`HAVING`、`UNION`、子查询、聚合函数；
- 视图必须根据主键或唯一键定义；
- 视图没有使用 `WITH CHECK OPTION` 选项。

如果视图不符合上述限制，则将无法进行更新操作。

## 存储过程

> MySQL存储过程是一种预编译的数据库对象，由SQL语句和控制语句组成，可以在MySQL服务器上保存和执行。存储过程通常用于执行特定的数据操作，以及在MySQL中实现业务逻辑和数据操作的安全性和一致性。

存储过程具有以下优点：

1. 提高性能 - 存储过程能够在MySQL服务器上编译和缓存，可以在不影响应用程序性能的情况下快速执行。
2. 提高可重用性 - 存储过程可以在MySQL服务器上创建一次，然后在多个查询中多次调用，提高了代码可重用性和维护性。
3. 提高安全性 - 存储过程可以对关键数据进行权限控制和过滤，从而提高了数据库的安全性和完整性。
4. 提高一致性 - 存储过程可以保证所有的操作都在一个事务内完成，从而保证了数据库数据的一致性。

### 创建存储过程

```sql
-- 创建名为 get_employee 的存储过程
CREATE PROCEDURE 存储过程名字(参数列表)
BEGIN
    -- sql 语句
END;
```

###  调用存储过程

```sql
-- 调用存储过程并传入参数 'Sales'
CALL 名称(参数)
```

### 查看存储过程

```sql
SHOW CREATE PROCEDURE procedure_name;
```

其中，`procedure_name`是要查看的存储过程名称。

```sql
DESCRIBE get_employee;
```

或者：

```sql
SELECT * FROM information_schema.ROUTINES WHERE ROUTINE_SCHEMA = '数据库名';
```

### 删除存储过程

```sql
DROP PROCEDURE [IF EXISTS] procedure_name;
```

其中，`procedure_name`是要删除的存储过程名称。如果使用了`IF EXISTS`选项，则表示只在该存储过程存在时才进行删除，否则不会报错。

### 变量

> 在MySQL的存储过程中，变量可以用来存储和处理数据。MySQL支持声明和使用三种类型的变量：

- 局部变量（Local Variable）：在存储过程中声明和使用的变量，仅在该存储过程内部有效。
- 用户变量（User-defined Variable）：以@符号开头定义的变量，在整个会话期间有效。
- 系统变量（System Variable）：MySQL中内置的变量，用于设置和管理系统行为。

#### 系统变量

> 系统变量可以分为全局变量和会话变量

- 全局变量（Global Variable）：指在MySQL服务器启动时被创建，被整个MySQL服务器进程共享的变量。全局变量的值可以在MySQL服务器运行期间修改，但对所有MySQL连接和会话都可见，即对整个MySQL系统生效。
- 会话变量（Session Variable）：指在MySQL连接建立后在MySQL会话期间创建的变量，仅对当前MySQL连接和会话有效。会话变量的值在MySQL连接和会话期间可以随时修改，但不会跨连接和会话传递。

```sql
SHOW [GLOBAL | SESSION] VARIABLES; -- 查看所有系统变量的值
-- 不指定默认SESSION会话变量
SHOW GLOBAL VARIABLES; -- 查看所有全局变量
SHOW SESSION VARIABLES; -- 查看所有会话变量
SHOW VARIABLES LIKE 'variable_name'; -- 模糊搜索变量名
SELECT @@activate_all_roles_on_login; -- 查看指定变量名
/* 重启后变量仍任会除非修改配置文件 */
SET [GLOBAL | SESSION].系统变量名 = 值; -- 设置系统变量名
SET @@GLOBAL.activate_all_roles_on_login = 0; -- 设置系统变量名
```

注意： 

1. `GLOBAL` 是全局变量 `SESSION` 是局部变量，不声明 默认就是这个
2. 设置的系统变量和会话变量重启mysql 服务后都会更新，除非修改配置文件

#### 用户变量

```sql
set @my_name = 'yuri'; -- 等号赋值
set @my_age := 20; -- := 赋值
select @java := 'java', @python := 'python'; -- 多个参数赋值
select @my_name, @my_age, @java, @python; -- 打印值

select count(*) into @count_st from db_student.student; -- 通过查询结果赋值
```

注意：

1. 使用 `=` 和 `:=` 都是一样的，但是推荐 `:=`  防止 和 `=` 比较冲突
2. 使用`set` 和 `select` 都可以进行赋值，和多个参数赋值
3. 将插叙结果进行赋值的时候只能使用`select`
4. 不用声明直接使用，如果没有`set` 获得的值是`null`不会报错

#### 局部变量

> 在MySQL存储过程中，局部变量（Local Variable）是在存储过程中声明和使用的变量，仅在该存储过程内部有效。他的作用范围是他的`begin`和`end` 语句内部

```sql
DECLARE 变量名 变量类型 [DEFAULT initial_value];
SET 变量名 := 值  
```

其中，`variable_name`是变量的名称，`data_type`是变量的数据类型，`initial_value`是变量的初始值，是可选参数。

#### 参数

> 在MySQL存储过程中，参数可以使用`IN`、`OUT`和`INOUT`关键字进行定义。这三个关键字分别表示输入参数、输出参数和输入输出参数。

具体来说，它们的区别如下：

- `IN`：输入参数，用于将某个值传递给存储过程中的语句块。在存储过程内，IN参数的值不允许更改，只能被读取使用，这是该参数的限制。
- `OUT`：输出参数，用于将存储过程中的执行结果返回给调用者。在调用存储过程之前，必须先事先声明变量来接收输出参数的值。OUT参数必须在存储过程中被显式地赋值。调用过程结束后，该参数的值会保存到调用者中声明的变量中。
- `INOUT`：也是输入输出参数，表示该参数可以作为输入和输出。调用过程需要先事先声明变量来作为 INOUT 参数的值传递给存储过程。在存储过程中，该参数可被修改，存储过程执行完成后，参数值会被更新到该参数的引用处。

示例：

下面是一个简单的存储过程，演示了如何定义和使用各种类型的参数：

```sql
CREATE PROCEDURE test_proc (in/out/inout 参数名 参数类型)
CREATE PROCEDURE test_proc (IN a INT, OUT b INT, INOUT c INT)
BEGIN
    -- a 是输入参数，b 是输出参数，c 是输入输出参数
    -- 根据输入参数 a 的值计算 b 和 c 的值
    SET b = a * 2;
    SET c = c + 10;
END;
```

在这个例子中，我们定义了一个存储过程`test_proc`，该过程接受三个参数：`a`是输入参数，`b`是输出参数，`c`是输入输出参数。

在存储过程内部，我们根据输入参数`a`的值计算了输出参数`b`和输入输出参数`c`的值。需要注意的是，我们对输入输出参数`c`的值进行了修改。该参数的初始化值是由调用者传递进来的，因此，存储过程将更改其值并将其返回给调用者。

在调用存储过程`test_proc`时，必须先事先声明变量来接收输出参数`b`和输入输出参数`c`的值。例如：

```sql
DECLARE b INT;
DECLARE c INT DEFAULT 10;
CALL test_proc(5, @b, @c);
SELECT @b, @c;
```



#### IF语句

> IF语句用于根据某个条件判断执行不同的语句块。例如：

```sql
CREATE PROCEDURE test_proc (IN num INT)
BEGIN
    -- 定义局部变量 result
    DECLARE result VARCHAR(10);
    -- 判断 num 的值，设置 result
    IF num > 0 THEN
        SET result = 'positive';
    ELSEIF num < 0 THEN
        SET result = 'negative';
    ELSE
        SET result = 'zero';
    END IF;
    -- 打印 result
    SELECT result;
END;
```

在这个例子中，我们使用了`IF`语句根据传入参数的值设置一个局部变量`result`。如果`num`大于0，则将`result`设为`'positive'`；如果小于0，则设为`'negative'`；否则设为`'zero'`。最后，我们使用`SELECT`语句将`result`返回。

#### CASE语句

> CASE语句是IF语句的另一种表达方式，用于根据某个表达式的值选择执行不同的语句块。例如：

```sql
CREATE PROCEDURE test_proc (IN grade INT)
BEGIN
    -- 定义局部变量 result
    DECLARE result VARCHAR(10);
    -- 根据 grade 的值设置 result
    CASE grade
        WHEN 1 THEN SET result = 'A';
        WHEN 2 THEN SET result = 'B';
        WHEN 3 THEN SET result = 'C';
        ELSE SET result = 'unknown';
    END CASE;
    -- 打印 result
    SELECT result;
END;
```

在这个例子中，我们使用了`CASE`语句根据传入参数的值设置一个局部变量`result`。如果`grade`等于1，则将`result`设为`'A'`；如果等于2，则设为`'B'`；如果等于3，则设为`'C'`；否则设为`'unknown'`。最后，我们使用`SELECT`语句将`result`返回。

#### WHILE循环语句

> WHILE循环语句可用于反复执行某个语句块，直到某个条件不满足为止。例如：

```sql
CREATE PROCEDURE test_proc ()
BEGIN
    -- 定义局部变量 sum 和 i
    DECLARE sum INT DEFAULT 0;
    DECLARE i INT DEFAULT 1;
    -- 计算1到10之间整数的和
    WHILE i <= 10 DO
        SET sum = sum + i;
        SET i = i + 1;
    END WHILE;
    -- 打印结果
    SELECT sum;
END;
```

在这个例子中，我们使用了`WHILE`循环语句计算1到10之间整数的和。我们定义了两个局部变量`sum`和`i`，将`sum`初始化为0，将`i`初始化为1。在`WHILE`循环中，我们一直将`i`增加1，并将`i`添加到`sum`中，直到`i`大于10为止。最后，我们使用`SELECT`语句将`sum`返回。

需要注意的是，`WHILE`循环和`LOOP`循环语句的用法类似，但它们的语句块结构有所不同。具体来说，`WHILE`循环是在条件满足时执行语句块，而`LOOP`循环是先执行语句块，再判断条件是否满足。在使用这些循环语句时，需要避免死循环的情况。

#### REPEAT 循环

> 在MySQL存储过程中，`REPEAT`循环是一种基于条件的循环语句，它允许用户在满足特定条件下重复执行语句块。

具体来说，`REPEAT`循环首先执行一遍语句块，然后检查循环条件。如果条件为真，则重复执行语句块，直到条件为假为止。

下面是一个使用`REPEAT`循环的简单存储过程示例，用于计算整数`n`的阶乘：

```sql
CREATE PROCEDURE factorial (IN n INT, OUT result INT)
BEGIN
    DECLARE i INT Default 1;
    SET result = 1;
    REPEAT
        SET result = result * i;
        SET i = i + 1;
    UNTIL i > n
    END REPEAT;
END;
```

在这个例子中，我们使用了`REPEAT`循环来计算整数`n`的阶乘。我们定义了一个局部变量`i`，将其初始化为1，定义了输出参数`result`，将其初始化为1。

在`REPEAT`循环中，我们将`result`乘以`i`的值，并将`i`增加1。每次循环时，我们检查`i`是否大于`n`，如果是，则终止循环。最后，我们将计算结果存储在输出参数`result`中返回。

需要注意的是，在使用`REPEAT`循环时，需要注意循环条件的设置，以避免死循环的情况。

#### LOOP 循环

> 在MySQL存储过程中，`LOOP`循环语句也是一种基于条件的循环语句，与`REPEAT`语句类似，都是按条件重复执行语句块。具体来说，`LOOP`循环会在每次循环之后检查循环条件，如果条件为真，则继续执行语句块，直到条件为假为止。`LOOP`循环一般与`IF`语句搭配使用，以实现更为复杂的逻辑运算。

下面是一个简单的存储过程示例，演示如何使用`LOOP`循环来计算两个数的最大公约数：

```sql
CREATE PROCEDURE get_gcd (IN a INT, IN b INT, OUT gcd INT)
BEGIN
    DECLARE temp INT;
    -- 确保 a 大于 b
    IF b > a THEN
        SET temp = a;
        SET a = b;
        SET b = temp;
    END IF;
    -- 循环计算最大公约数
    LOOP
        SET temp = a % b;
        IF temp = 0 THEN
            SET gcd = b;
            LEAVE;
        END IF;
        SET a = b;
        SET b = temp;
    END LOOP;
END;
```

- 使用`leave` 退出循环 类似`break`
- 使用`iterate` 跳过循环，类似`continue`

#### CURSOR

在这个例子中，我们定义了一个存储过程`get_average_salary`，该过程接受一个名为`dept_name`的输入参数，表示需要查询的员工所在部门。我们还定义了一个名为`average_salary`的输出参数，用于存储计算结果。

在存储过程主体中，我们定义了一些局部变量，包括`total_salary`（总工资）、`num_employees`（员工数量）、`emp_id`（员工ID）、`emp_name`（员工姓名）和`emp_salary`（员工工资）。我们还使用`DECLARE`语句声明了一个名为`emp_cursor`的游标，用于查询指定部门中所有员工的信息。

在存储过程主体的下一部分，我们使用`OPEN`语句打开游标，并在循环中使用`FETCH`语句从游标中读取每一行数据。我们使用`IF`语句检查是否已经处理完所有行，如果是，则跳出循环。否则，我们将记录的工资累加到`total_salary`变量中，并递增`num_employees`变量的值，以便进行平均工资计算。最后，我们使用`CLOSE`语句关闭游标，并将计算结果存储在输出参数`average_salary`中返回。

需要注意的是，在使用游标时，需要注意游标的打开、读取、关闭等操作，以免出现资源泄漏或其他错误。另外，在处理大量数据时，使用游标可能会对性能产生较大影响，应该谨慎使用。

#### HANDLER

> 在MySQL存储过程中，`HANDLER`是一种用于处理SQL异常的语句，可以捕获和处理存储过程中发生的异常情况，以便于存储过程可以做出适当的反应。具体来说，`HANDLER`语句通常与游标（Cursor）一起使用，用于捕获查询结果集中的异常情况，如记录不存在、查询超时或键冲突等。

下面是一个使用`HANDLER`语句处理存储过程中的异常情况的示例：

```sql
CREATE PROCEDURE find_employee (IN emp_id INT)
BEGIN
    DECLARE emp_name VARCHAR(50);
    DECLARE found_count INT Default 0;
    DECLARE emp_cursor CURSOR FOR SELECT name FROM employees WHERE id=emp_id;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET found_count = 0;
    OPEN emp_cursor;
    FETCH emp_cursor INTO emp_name;
    IF found_count=0 THEN
        SELECT "Employee not found!" AS message;
    ELSE
        SELECT emp_name AS message;
    END IF;
    CLOSE emp_cursor;
END;
```

在这个例子中，我们定义了一个存储过程`find_employee`，该过程接受一个名为`emp_id`的输入参数，表示需要查找的员工ID。

在存储过程主体中，我们定义了一些局部变量，包括`emp_name`（员工姓名）和`found_count`（符合条件的记录数量）。我们还使用`DECLARE HANDLER`语句声明了一个名为`CONTINUE HANDLER`的异常处理程序，用于处理查询结果集中的 NOT FOUND 异常情况。

在存储过程主体的下一部分，我们使用`OPEN`语句打开游标，并在循环中使用`FETCH`语句从游标中读取每一行数据。如果找到符合条件的行，则将`found_count`变量设置为1，否则不做修改。最后，我们根据`found_count`的值选择显示“Employee not found!”或员工姓名。最后使用`CLOSE`语句关闭游标。

需要注意的是，在使用`HANDLER`语句时，需要注意异常处理程序的设置和存储过程的反应，以满足实际需求，并保证存储过程的正确性和可靠性。

### 存储函数

> 在MySQL中，存储函数（Stored Function）是一种查询操作，它们可返回单个值，这个值可以是数值、字符串或日期等。存储函数与存储过程类似，但是存储函数必须返回一个结果。与存储过程不同的是，存储函数可以用于SQL语句中的表达式中，以及在查询中作为计算列。存储函数还可以使用SELECT语句调用。

下面是一个简单的存储函数示例，用于计算两个数的加法运算：

```sql
CREATE FUNCTION add_numbers (num1 INT, num2 INT) 
RETURNS INT DETERMINISTIC -- 函数确定性
BEGIN
    DECLARE result INT;
    SET result = num1 + num2;
    RETURN result;
END;
```

在这个例子中，我们定义了一个名为`add_numbers`的存储函数，该函数接受两个输入参数`num1`和`num2`，用于表示两个数。

在函数体内，我们定义了一个名为`result`的局部变量，用于存储计算结果。我们将`num1`和`num2`相加，并将结果存储在`result`变量中。

最后，我们使用`RETURN`语句将`result`的值返回给调用者。

使用该函数的例子：

```sql
SELECT add_numbers(2, 3);
```

该语句将返回结果`5`。可以看到，存储函数可以像普通函数一样调用，也可以在SQL语句中直接使用。

#### 函数确定性

> 在MySQL存储函数中，函数的确定性（determinism）是指函数对于相同的输入，是否总是返回相同的结果。根据函数的不同实现和使用情况，函数可以被定义为不同的确定性类型，包括：

1. 非确定性函数（`NON-DETERMINISTIC`）：对于相同的输入，不能保证总是返回相同的结果。例如，使用当前时间戳作为函数参数的函数，可能每次执行都会返回不同的结果。
2. 确定性但有可能产生副作用的函数（`DETERMINISTIC, NO SQL`）：对于相同的输入，总是返回相同的结果，但是函数可能会执行一些与SQL语句无关的操作（如调用文件系统，修改全局变量等）。
3. 纯粹的确定性函数（`DETERMINISTIC, READS SQL DATA`）：对于相同的输入，总是返回相同的结果，而且在执行过程中只从数据库中读取数据，不会修改数据。
4. 纯粹的确定性函数（`DETERMINISTIC, CONTAINS SQL`）：对于相同的输入，总是返回相同的结果，而且在执行过程中会包含一些非查询的SQL操作（如变量赋值，条件判断等），但不会修改数据。
5. 纯粹的确定性函数（`DETERMINISTIC, NO SQL`）：对于相同的输入，总是返回相同的结果，而且在执行过程中不包含任何SQL操作，也不会对全局变量进行修改。

需要注意的是，确定性函数（无论是纯粹的还是带有副作用的）在查询缓存中缓存的时间更长，可以帮助提高查询性能。然而，在查询中使用带有副作用的函数可能会导致误解，影响数据的一致性或安全性，因此需要谨慎使用。

## 触发器

> 触发器（Trigger）是MySQL中的一种数据库对象，用于在数据库表上创建操作的响应。当指定的表上发生某些操作（如INSERT、UPDATE、DELETE等），触发器会自动执行一个预定义的操作序列。

#### 创建触发器

在MySQL中，触发器可以定义在表之前或之后，可以定义在行之前或之后。它可以用于进行数据验证、自动机器人、历史记录、审计和日志记录等操作。触发器的语法如下所示：

```sql
CREATE TRIGGER trigger_name 
{BEFORE | AFTER} {INSERT | UPDATE | DELETE}
ON table_name 
FOR EACH ROW  -- 行级触发器 (只要有修改的行，每行都会出触发)
BEGIN
	...
END;
```

其中，触发器名称是自定义的，而且必须在数据库内唯一。`BEFORE`或`AFTER`关键字指定触发器执行时间，`INSERT`、`UPDATE`或`DELETE`指定了触发操作的类型。`table_name`是要监视的表名。`FOR EACH ROW`指示此触发器为每个操作行执行一次。`trigger_body`是在触发器执行时要执行的SQL语句序列。

以下是一个简单的触发器示例，当在`employee`表中插入新行时，将向`history`表中插入一条记录：

```sql
CREATE TRIGGER emp_insert_trigger 
AFTER INSERT
ON employee
FOR EACH ROW 
BEGIN
    INSERT INTO history (user_id, operation, table_name, data) 
    VALUES (USER(), 'INSERT', 'employee', NEW.id);
END;
```

在这个例子中，我们创建了一个名为`emp_insert_trigger`的触发器，当在`employee`表中插入新行时，会向`history`表中插入一条记录。插入操作的用户名以及新插入数据的`id`字段值将包含在插入记录中。

需要注意的是，触发器在数据库中既可以是有用的，也可以是有害的。合理的使用触发器可以帮助完成许多有用和自动化的任务，而滥用或错误地使用触发器可能会导致性能问题、数据的不一致，或其他负面影响。因此，在使用触发器时应该考虑到所有的使用场景和风险，并仔细规划和实现触发器。

#### 触发器类型

- `INSERT` 触发器，`NEW` 表示将要或者已经新增的数据
- `UPDATE` 触发器，`OLD` 表示修改之前的数据，`NEW` 表示将要或者已经修改的数据
- `DELET` 触发器， `OLD` 表示已经删除的数据

#### 查看/删除触发器

查看触发器 `SHOW TRIGGERS;` 

删除触发器：

```sql
DROP TRIGGERS [数据库名].触发器名;
```

