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

1. 
2. 
3. 
4. 数据控制语言 (DCL)：Data Control Language，用于授权访问数据库中的对象，如 `GRANT` 和 `REVOKE`。
5. 事务控制语言 (TCL)：Transaction Control Language，用于控制事务的处理，如 `COMMIT`, `ROLLBACK` 和 `SAVEPOINT`。

其中，DDL、DML 和 DQL 是 SQL 中最为常见的语句类型，它们构成了 SQL 查询和数据处理的主要逻辑。

### DDL 语句

> 数据定义语言 (DDL)：Data Definition Language，用于创建、更新或删除数据库中的表和其他对象，如 `CREATE`, `ALTER` 。

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
   ALTER TABLE students ADD COLUMN gender VARCHAR(10);
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
