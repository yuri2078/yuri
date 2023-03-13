#include <mysql/mysql.h>
#include <iostream>

MYSQL mysql;
MYSQL_RES* res;
MYSQL_ROW row;

int main()
{
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4");
	if (!mysql_real_connect(&mysql, "127.0.0.1", "root", "yuri2078", "miku",
	                        3306, nullptr, 0)) {
		std::cout << "连接失败! " << "错误原因 -> " << mysql_errno(&mysql) << "\n";
	} else {
		std::cout << "连接成功!\n";
	}

	mysql_close(&mysql);
	return 0;
}