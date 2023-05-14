/* 字符串函数 */
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

/* 数值函数 */
SELECT ABS(-10);-- 返回-10的绝对值
SELECT CEIL(2.5);-- 返回不小于2.5的最小整数
SELECT FLOOR(2.5);-- 返回不大于2.5的最大整数
SELECT ROUND(3.7);-- 将3.7四舍五入为最接近的整数
SELECT TRUNCATE(3.746, 2);-- 将3.746截断为2位小数
SELECT MOD(10, 3);-- 返回10除以3的余数
SELECT POW(2, 3);-- 返回2的3次幂


/* 日期函数 */
SELECT NOW();-- 返回当前日期和时间
SELECT CURDATE();-- 返回当前日期
SELECT CURTIME();-- 返回当前时间
SELECT DATE_FORMAT(NOW(), '%Y-%m-%d');-- 将日期格式化为 'YYYY-MM-DD' 形式
SELECT DATE_FORMAT(NOW(), '%Y年%m月%d日');-- 将日期格式化为 'YYYY年M月D日' 形式
SELECT DATE_ADD(NOW(), INTERVAL '2 3:00:00' DAY_SECOND);-- 在日期上添加2天和3小时
SELECT DATE_SUB(NOW(), INTERVAL 1 MONTH);-- 从日期中减去1个月
SELECT DATEDIFF('2022-01-01', '2021-12-15');-- 计算两个日期之间的天数

/* 流程函数 */
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
