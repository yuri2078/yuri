#include <stdio.h>

int my_gets(char* s)
{
	char ch;
	int len = 0;
	//循环接收字符直到遇到\n;
	while ((scanf("%c",&ch) && ch != '\n')) {
		s[len++] = ch;
	}
	s[len] = 0;
	return len;
}

void stringCheck(char* s, char* t)
{
	//分别记录s和t开始万能匹配之前的位置
	char *previous_s, *privious_t;

	//设置flag标识是否开启万能匹配
	int flag = 0;

	
	//当s指向结尾，而t没到结尾且没有*通配符时结束循环
	while (*s || *t) {
		//当*s = *t 或者 遇到通配符？时，继续比较
		if (*s == *t || *s == '?') {
			s++;
			t++;
		//当他们不同，而*s是*号时，进入通配匹配
		} else if (*s == '*') {
		//设置goto跳转语句，当不满足匹配条件时，跳转过来继续匹配
		label:
			previous_s = s++; //记录上一次*号的位置
			flag = 1; //将flag置为1,标识如果匹配失败，则重新匹配

			//当*号后的字符与*t相等 或者遇到* 或者 ?则停止继续向下寻找
			while (*t && *s != *t && *s != '?' && *s != '*') {
				t++;
			}

			//如果到最后也没找到，直接推出循环判断是否匹配成功
			if (!*t && *s != '*') {
				break;
			}
			//如果找到了则将下一个地址存储起来，匹配失败则从这里重新开始
			privious_t = t + 1;

		} else if (flag) {
			//执行到这里就说明遇到*且未匹配成功，更新s和t的地址，重新开始匹配
			s = previous_s;
			t = privious_t;

			//跳转到刚刚的循环继续判断
			goto label;

		} else {

			//不满足以上任何情况则直接退出
			break;
		}
	}
	//判断两个字符串是不是都到两尾部如果是则说明匹配成功
	if (!*s && !*t) {
		printf("yes\n");
    }else {
		printf("no\n");
	}
}

int main(int argc, const char *argv[])
{
	char s[200];
	char t[200];

	//接收数据
	my_gets(s);
	my_gets(t);

	//调用函数就行匹配
	stringCheck(s, t);

    return 0;
}